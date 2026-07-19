#!/usr/bin/env python3
"""
播放 .raw PCM 音频文件
用法: python play_raw.py recordings/01_00_001.raw
"""

import sys
import struct
import wave
import os

SAMPLE_RATE = 16700  # 实际采样率 (GPT1=234 → ~16.7kHz)

def raw_to_wav(raw_path, wav_path=None):
    """将 .raw 转为 .wav，然后用系统播放器打开"""
    if wav_path is None:
        wav_path = raw_path.replace('.raw', '_play.wav')

    data = open(raw_path, 'rb').read()
    n_samples = len(data) // 2

    with wave.open(wav_path, 'wb') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(SAMPLE_RATE)
        wf.writeframes(data)

    print(f"→ {wav_path}  ({n_samples} samples, {n_samples/SAMPLE_RATE:.1f}s)")
    return wav_path

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("用法: python play_raw.py <文件.raw>")
        print("示例: python play_raw.py recordings/01_00_001.raw")
        sys.exit(1)

    raw_file = sys.argv[1]
    if not os.path.exists(raw_file):
        print(f"文件不存在: {raw_file}")
        sys.exit(1)

    wav = raw_to_wav(raw_file)
    print(f"播放: {wav}")
    os.startfile(wav)  # Windows 默认播放器打开
