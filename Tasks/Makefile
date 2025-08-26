AS     = riscv64-unknown-elf-as
LD     = riscv64-unknown-elf-ld
SPIKE  = spike

# Programs
PROG1  = task_3_as
PROG2  = task_3

# Default target builds both
all: $(PROG1) $(PROG2)

# --- Build restoring_division ---
$(PROG1): $(PROG1).s
	@$(AS) -o $(PROG1).o $<
	@$(LD) -T link.ld -o $@ $(PROG1).o

# --- Build restoring_division_generated (needs start.s) ---
$(PROG2): start.s $(PROG2).s
	@$(AS) -o start.o start.s
	@$(AS) -o $(PROG2).o $(PROG2).s
	@$(LD) -T link.ld -o $@ start.o $(PROG2).o

# Run with Spike
run1: $(PROG1)
	@$(SPIKE) $(PROG1)

run2: $(PROG2)
	@$(SPIKE) $(PROG2)

# Debug with Spike
debug1: $(PROG1)
	@$(SPIKE) -d --log-commits $(PROG1)

debug2: $(PROG2)
	@$(SPIKE) -d --log-commits $(PROG2)

# Clean up
clean:
	@rm -f *.o $(PROG1) $(PROG2)

.PHONY: all run1 run2 debug1 debug2 clean