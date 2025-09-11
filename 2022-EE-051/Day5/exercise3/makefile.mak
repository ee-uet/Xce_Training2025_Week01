# Makefile for RISC-V Assembly Exercises

# Compiler and emulator
AS     = riscv64-unknown-elf-as
LD     = riscv64-unknown-elf-ld
SPIKE  = spike

# Program name
PROG   = exercise3

# Default target
all: $(PROG).elf

# Rule to assemble and link
$(PROG).elf: $(PROG).s
	$(AS) -o $(PROG).o $(PROG).s
	$(LD) -T linker.ld -o $(PROG).elf $(PROG).o

# Rule to run with Spike
run: $(PROG).elf
	$(SPIKE) $(PROG).elf

# Rule to debug with Spike
debug: $(PROG).elf
	$(SPIKE) -d --log-commits $(PROG).elf

# Clean up
clean:
	rm -f *.o $(PROG).elf

.PHONY: all run debug clean
