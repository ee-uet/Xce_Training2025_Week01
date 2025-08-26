PROG = my_program
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
  
all: $(PROG)

$(PROG): $(PROG).s
	$(AS) -o $(PROG).o $<
	$(LD) -T linker.ld -o $@ $(PROG).o

run: $(PROG)
	$(SPIKE) $(PROG)

debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)
  
# Clean up
clean:
	rm -f *.o $(PROG)

.PHONY: all run debug clean
