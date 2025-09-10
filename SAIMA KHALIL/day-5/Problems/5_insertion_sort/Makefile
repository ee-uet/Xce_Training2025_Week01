# Compiler and tools
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike

# Program name passed from terminal, default = "absolute"
PROG ?= insertion

all: $(PROG)

$(PROG): $(PROG).s
	$(AS) -o $(PROG).o $<
	$(LD) -T linker.ld -o $@ $(PROG).o
#riscv64-unknown-elf-as -o array.o array.s
#riscv64-unknown-elf-ld -T linker.ld -o array array.o
run: $(PROG)
	$(SPIKE) $(PROG)

debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)

clean:
	rm -f *.o $(PROG)

.PHONY: all run debug clean
