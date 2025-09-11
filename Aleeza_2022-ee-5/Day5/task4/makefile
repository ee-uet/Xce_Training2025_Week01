# Program name
PROG = assemblyprob4

# Tools
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
# Default target
all: $(PROG).elf

# Assemble and link
$(PROG).elf: $(PROG).s link.ld
	$(AS) -o $(PROG).o $(PROG).s
	$(LD) -T link.ld -o $@ $(PROG).o

# Run with Spike (bare-metal)
run: $(PROG).elf
	$(SPIKE) $(PROG).elf

# Clean build files
clean:
	rm -f *.o *.elf

.PHONY: all run clean
