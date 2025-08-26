# Compiler and emulator
CC = riscv64-unknown-elf-gcc
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike

# Default program name
PROG ?= fib.s

# Default target
all: $(PROG)

# Rule to compile C
%.o: %.c
	$(CC) -c -o $@ $<

# Rule to assemble
%.o: %.S
	$(AS) -o $@ $<

# Rule to link
$(PROG): $(PROG).o linker.ld
	$(LD) -T linker.ld -o $@ $(PROG).o

# Run with Spike
run: $(PROG)
	$(SPIKE) $(PROG)

# Debug with Spike
debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)

# Clean up
clean:
	rm -f *.o $(PROG)

.PHONY: all run debug clean
