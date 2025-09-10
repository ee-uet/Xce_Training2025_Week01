AS     = riscv64-unknown-elf-as
LD     = riscv64-unknown-elf-ld
CC     = riscv64-unknown-elf-gcc
SPIKE  = spike

# Programs
PROG1  = non_restoring_division
PROG2  = non_restoring_division_generated

# Default target builds both
all: $(PROG1) $(PROG2)

# --- Build hand-written assembly version ---
$(PROG1): $(PROG1).s
	$(AS) -o $(PROG1).o $<
	$(LD) -T linker.ld -o $@ $(PROG1).o

# --- Build generated version from C code ---
$(PROG2).s: non_restoring_division.c
	$(CC) -S -O2 $< -o $@

$(PROG2): start.s $(PROG2).s
	$(AS) -o start.o start.s
	$(AS) -o $(PROG2).o $(PROG2).s
	$(LD) -T linker.ld -o $@ start.o $(PROG2).o

# Run with Spike
run1: $(PROG1)
	$(SPIKE) $(PROG1)

run2: $(PROG2)
	$(SPIKE) $(PROG2)

# Debug with Spike
debug1: $(PROG1)
	$(SPIKE) -d --log-commits $(PROG1)

debug2: $(PROG2)
	$(SPIKE) -d --log-commits $(PROG2)

# Clean up
clean:
	rm -f *.o $(PROG1) $(PROG2) $(PROG2).s

.PHONY: all run1 run2 debug1 debug2 clean
