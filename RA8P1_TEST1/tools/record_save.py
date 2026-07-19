#!/usr/bin/env python3
"""
INMP441 录音保存工具 — PC 端
===============================
从串口接收 RA8P1 发来的 PCM16 原始音频，保存为 .raw 或 .wav 文件

用法:
  1. 修改下面的串口号和波特率
  2. python record_save.py
  3. 在串口终端按任意键触发 RA8P1 录音
  4. 脚本自动保存为 recordings/xxx.raw 和 xxx.wav

依赖: pip install pyserial
      (可选) pip install soundfile  # 用于保存 WAV
"""

import serial
import struct
import os
import time
import sys
from datetime import datetime

# ==================== 配置 ====================
SERIAL_PORT = "COM22"        # 改成你的串口号 (设备管理器里看)
BAUD_RATE   = 115200        # 波特率
SAMPLE_RATE = 16700         # 实际采样率 (GPT1=234 → ~16.7kHz)
BITS        = 16            # 位深
CHANNELS    = 1             # 声道数
OUTPUT_DIR  = "recordings"  # 输出目录

# 标签设置 (每次录音前会询问, 直接回车用默认)
DEFAULT_SPEAKER = "01"      # 说话人 ID
DEFAULT_COMMAND = "00"      # 指令 ID

# ==================== 初始化 ====================
os.makedirs(OUTPUT_DIR, exist_ok=True)

def read_until(ser, marker, timeout=30):
    """读取直到出现指定标记, 返回标记前的所有数据"""
    ser.timeout = 0.1
    buf = b""
    t0 = time.time()
    while time.time() - t0 < timeout:
        ch = ser.read(1)
        if ch:
            buf += ch
            m = marker.encode()
            idx = buf.find(m)
            if idx >= 0:
                # 返回标记之前的数据, 标记之后的数据留在 buf 中
                before = buf[:idx]
                after  = buf[idx + len(m):]
                return before, after
    return None, None

def save_raw(data, filename):
    with open(filename, 'wb') as f:
        f.write(data)
    print(f"  RAW saved: {filename} ({len(data)} bytes)")

def save_wav(raw_data, filename, sr, bits, ch):
    """保存为 WAV 格式 (简洁版, 不依赖额外库)"""
    import wave
    with wave.open(filename, 'wb') as wf:
        wf.setnchannels(ch)
        wf.setsampwidth(bits // 8)
        wf.setframerate(sr)
        wf.writeframes(raw_data)
    print(f"  WAV saved: {filename}")

def get_filename(speaker, cmd, seq):
    """生成文件名: 01_00_001.raw"""
    return f"{speaker}_{cmd}_{seq:03d}"

def get_next_seq(speaker, cmd):
    """自动查找下一个序号"""
    existing = [f for f in os.listdir(OUTPUT_DIR)
                if f.startswith(f"{speaker}_{cmd}_") and f.endswith('.raw')]
    if not existing:
        return 1
    nums = []
    for f in existing:
        try:
            nums.append(int(f.split('_')[-1].split('.')[0]))
        except:
            pass
    return max(nums) + 1 if nums else 1

# ==================== 主循环 ====================
def main():
    print(f"打开串口 {SERIAL_PORT} @ {BAUD_RATE}...")
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
    except Exception as e:
        print(f"无法打开串口: {e}")
        print("请修改 SERIAL_PORT 为正确的串口号")
        return 1

    print(f"串口已打开, 等待 RA8P1 就绪...")
    time.sleep(1)
    ser.reset_input_buffer()

    # 显示 RA8P1 启动信息
    print()
    t0 = time.time()
    while time.time() - t0 < 3:
        chunk = ser.read(4096)
        if chunk:
            print(chunk.decode('utf-8', errors='replace'), end='', flush=True)

    print()
    print("=" * 50)
    print("  INMP441 录音保存工具")
    print("=" * 50)
    print("  操作: 输入说话人和指令ID → 自动触发录音 → 自动保存")
    print("  输入 'q' 退出")
    print("=" * 50)

    while True:
        print()
        speaker = input(f"说话人ID [{DEFAULT_SPEAKER}]: ").strip() or DEFAULT_SPEAKER
        if speaker.lower() == 'q':
            break
        command = input(f"指令ID   [{DEFAULT_COMMAND}]: ").strip() or DEFAULT_COMMAND
        if command.lower() == 'q':
            break

        seq = get_next_seq(speaker, command)
        fname = get_filename(speaker, command, seq)
        print(f"→ 文件名: {fname}  (序号 {seq})")

        # 清空缓冲区, 发送触发字符
        ser.reset_input_buffer()
        ser.reset_output_buffer()
        time.sleep(0.2)
        ser.write(b'r')  # 发送 'r' 触发录音
        ser.flush()
        print("→ 已发送触发, 录音中...")

        # 显示录音文本输出, 直到收到 "EXPORT"
        buf = b""
        ser.timeout = 0.2
        t0 = time.time()
        while b"EXPORT" not in buf and (time.time() - t0) < 10:
            chunk = ser.read(4096)
            if chunk:
                buf += chunk
                # 打印文本部分
                text = chunk.decode('utf-8', errors='replace')
                print(text, end='', flush=True)

        # 在 buf 中搜索同步字 0xAA55AA55
        SYNC = b'\x55\xAA\x55\xAA'  # little-endian: 0xAA55AA55
        sync_pos = buf.find(SYNC)
        if sync_pos < 0:
            # 同步字还没到, 继续读
            t0 = time.time()
            while sync_pos < 0 and (time.time() - t0) < 5:
                chunk = ser.read(256)
                if chunk:
                    buf += chunk
                    sync_pos = buf.find(SYNC)
        if sync_pos < 0:
            print("  错误: 未找到同步字")
            continue

        # 同步字后 4 字节 = 采样数, 再之后 = PCM 数据
        after_sync = buf[sync_pos + 4:]  # 跳过同步字
        if len(after_sync) < 4:
            after_sync += ser.read(4 - len(after_sync))

        num_samples = struct.unpack('<I', after_sync[:4])[0]
        expected_bytes = num_samples * 2
        print(f"\n  采样数: {num_samples}, 期望字节: {expected_bytes}")

        # 同步字+计数之后的数据 = PCM 开头
        raw_data = after_sync[4:]

        # 继续读剩余 PCM 数据
        ser.timeout = 5
        t0 = time.time()
        while len(raw_data) < expected_bytes and (time.time() - t0) < 60:
            need = expected_bytes - len(raw_data)
            chunk = ser.read(min(need, 4096))
            if chunk:
                raw_data += chunk
            if len(raw_data) % 16384 == 0 and len(raw_data) > 0:
                print(f"  接收: {len(raw_data)} / {expected_bytes} bytes")

        print(f"  实际接收: {len(raw_data)} bytes")
        if len(raw_data) < expected_bytes:
            print(f"  ⚠ 数据不完整!")

        # 保存
        raw_path = os.path.join(OUTPUT_DIR, fname)
        save_raw(raw_data, raw_path)
        wav_name = fname.replace('.raw', '.wav')
        wav_path = os.path.join(OUTPUT_DIR, wav_name)
        try:
            save_wav(raw_data, wav_path, SAMPLE_RATE, BITS, CHANNELS)
        except Exception as e:
            print(f"  WAV 保存失败: {e}")
        print(f"  ✅ 完成! 播放: start {wav_path}")

    ser.close()
    print("退出。")
    return 0

if __name__ == '__main__':
    sys.exit(main())



