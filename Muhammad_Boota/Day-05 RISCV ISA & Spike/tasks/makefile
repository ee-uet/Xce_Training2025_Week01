# Makefile for RISC-V Assembly Exercises
# Compiler and emulator
PROG=clear_bit
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
# Default target
all: $(PROG)
$(PROG): $(PROG).s
	$(AS) -march=rv64g $(PROG).s -o $(PROG).o
	$(LD) -T link.ld -o $@ $(PROG).o
# Rule to run with Spike
run: $(PROG)
	$(SPIKE) $(PROG)
# Rule to debug with Spike
debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)
# Clean up
clean:
	rm -f *.o $(PROG)
.PHONY: all run debug clean
