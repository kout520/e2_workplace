"""Send model_weights.bin to RA8P1 via UART, then write to OSPI flash.
Usage: python send_model.py [COM_PORT]
Default: COM3, 115200 baud
"""
import serial, struct, sys, os

PORT = sys.argv[1] if len(sys.argv)>1 else 'COM3'
BAUD = 115200
BIN_PATH = os.path.join(os.path.dirname(__file__), 'model_weights.bin')

def send():
    with open(BIN_PATH, 'rb') as f:
        data = f.read()
    print(f'Model: {len(data)} bytes ({len(data)/1024/1024:.1f} MB)')

    ser = serial.Serial(PORT, BAUD, timeout=5)
    print(f'Connected to {PORT}')

    # Send 4-byte size (little-endian)
    ser.write(struct.pack('<I', len(data)))
    print(f'Sent size: {len(data)}')

    # Send data in chunks
    CHUNK = 4096
    for i in range(0, len(data), CHUNK):
        chunk = data[i:i+CHUNK]
        ser.write(chunk)
        if i % (CHUNK*64) == 0:
            pct = i*100//len(data)
            print(f'  Progress: {pct}% ({i}/{len(data)})')
    print('  Progress: 100%')

    # Wait for verification
    print('Waiting for MCU to write OSPI flash...')
    resp = ser.read(100)
    if resp:
        print(f'MCU says: {resp.decode(errors="ignore")}')

    ser.close()
    print('Done! Reboot the MCU to load model from OSPI.')

if __name__ == '__main__':
    send()
