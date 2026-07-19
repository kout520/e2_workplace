# GDB script to load AI model weights into SDRAM
# Run this in e2 Studio: Debugger Console → type: source load_model.gdb
# OR in Debug Configuration → Startup → Run Commands → add this command

# Model weights address in SDRAM (from .map file)
set $model_addr = 0x680065c0

# Load the binary file
restore D:/e2_workplace/RA8P1_TEST_AI/model_weights.bin binary $model_addr

echo Model weights loaded successfully\n
