# Makefile for RISC-V Assembly Exercises
 
# Compiler and emulator
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
  
# Default target
all: $(PROG)
 
# Rule to assemble and link
$(PROG): $(PROG).s
	@echo "Compiling ...."
	$(AS) -o $(PROG).o $<
	@echo "Linking ...."
	$(LD) -T link.ld -o $@ $(PROG).o
 
# Rule to run with Spike
run: $(PROG)
	$(SPIKE) $(PROG)
 
# Rule to debug with Spike
debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)
#---------------------------------------------------------------

#----------------------------------------------------------------

gcc: $(ARG)

$(ARG): $(ARG).s
	@echo "building executable...."
	riscv64-unknown-elf-gcc -nostdlib -o $@ $(ARG).s
$(ARG).s: $(ARG).c
	@echo "compiling..."
	riscv64-unknown-elf-gcc -nostdlib -S -o $(ARG).s $(ARG).c
clean_gcc: 
	rm -f $(ARG).s $(ARG)

#-----------------------------------------------------------------
# Clean up
clean:
	rm -f *.o $(PROG)
 
.PHONY: all run debug clean