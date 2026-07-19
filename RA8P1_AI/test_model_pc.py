"""
PC 端测试 best-int8 模型 + 摄像头
用法: 对准白底黑字数字4, 观察分数变化
"""
import cv2, numpy as np, tensorflow as tf, os, time

TFLITE = r"D:\e2_workplace\RA8P1_AI\best-int8.tflite"
if not os.path.exists(TFLITE):
    print(f"NOT FOUND: {TFLITE}")
    exit(1)

print(f"Loading: {TFLITE}")
interpreter = tf.lite.Interpreter(model_path=TFLITE)
interpreter.allocate_tensors()
inp_info = interpreter.get_input_details()[0]
out_info = interpreter.get_output_details()[0]

INP_H, INP_W = inp_info['shape'][1], inp_info['shape'][2]
INP_DTYPE = inp_info['dtype']
OUT_SIZE = out_info['shape'][1] if len(out_info['shape']) > 1 else out_info['shape'][0]
print(f"Input:  {inp_info['shape']} ({INP_DTYPE})")
print(f"Output: {out_info['shape']}  ({OUT_SIZE} bytes)")
print(f"\n=== 按 Q 退出, S 截图保存 ===")

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("摄像头未找到!")
    exit(1)

fc, streak = 0, 0
while True:
    ret, frame = cap.read()
    if not ret: break
    fc += 1
    t0 = time.time()

    # 预处理: 居中裁剪 + 缩放
    fh, fw = frame.shape[:2]
    sz = min(fw, fh)
    cx, cy = (fw - sz)//2, (fh - sz)//2
    crop = frame[cy:cy+sz, cx:cx+sz]
    rgb = cv2.cvtColor(crop, cv2.COLOR_BGR2RGB)
    resized = cv2.resize(rgb, (INP_W, INP_H))

    # 输入
    inp_data = resized.astype(np.uint8)
    if INP_DTYPE == np.int8:
        inp_data = (inp_data.astype(np.int32) - 128).astype(np.int8)
    interpreter.set_tensor(inp_info['index'], np.expand_dims(inp_data, 0))
    interpreter.invoke()
    out = interpreter.get_tensor(out_info['index']).flatten().astype(int)

    # 解析: 找 E2 A5(0xE2,0xA5) 和 78 5C(0x78,0x5C) 标记
    scores = []
    for d in range(OUT_SIZE // 12):
        s_off = d * 12 + 6
        if s_off + 5 < OUT_SIZE:
            if out[s_off+2] == 0x78 and out[s_off+3] == 0x5C:
                sc = int(out[s_off+4])
                scores.append(sc)

    best = max(scores) if scores else -999
    infer_ms = (time.time() - t0) * 1000

    # 时间滤波
    if best >= 124: streak += 1
    else: streak = 0

    # 显示
    color = (0, 255, 0) if streak >= 3 else (0, 0, 255)
    status = f"DIGIT!" if streak >= 3 else ("waiting..." if streak > 0 else "none")
    cv2.putText(frame, f"F:{fc} {status} top={best} ({infer_ms:.0f}ms)",
                (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, color, 2)
    cv2.putText(frame, "Q=quit S=save", (10, 60),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (128,128,128), 1)
    cv2.imshow("best-int8 PC Test", frame)

    # 控制台输出
    if streak >= 3 or fc % 30 == 0:
        print(f"F:{fc:4d}  best={best:4d}  streak={streak}  {infer_ms:.0f}ms")

    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break
    elif key == ord('s'):
        fn = f"capture_{fc}.jpg"
        cv2.imwrite(fn, frame)
        print(f"  Saved: {fn}")

cap.release()
cv2.destroyAllWindows()
