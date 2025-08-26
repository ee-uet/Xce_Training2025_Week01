# Makefile for C to RISC-V Assembly Conversion
# Compiler tools
CC = riscv64-unknown-elf-gcc
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld

# Source files (without extension)
C_SOURCES = $(wildcard *.c)
TARGETS = $(C_SOURCES:.c=)

# Default target: convert all C files to assembly
all: $(addsuffix _compiled.S, $(TARGETS)) $(addsuffix _compiled_opt.S, $(TARGETS))

# Convert C to RISC-V assembly (no optimization)
%_compiled.S: %.c
	$(CC) -S -O0 -fverbose-asm -o $@ $<
	@echo "Generated: $@ (no optimization)"

# Convert C to RISC-V assembly (with optimization)
%_compiled_opt.S: %.c
	$(CC) -S -O2 -fverbose-asm -o $@ $<
	@echo "Generated: $@ (with optimization)"

# Additional: also create object files from generated assembly
%_compiled.o: %_compiled.S
	$(AS) -o $@ $<

%_compiled_opt.o: %_compiled_opt.S
	$(AS) -o $@ $<

# Build executables from generated assembly
%_compiled.elf: %_compiled.o
	$(LD) -o $@ $<

%_compiled_opt.elf: %_compiled_opt.o
	$(LD) -o $@ $<

# Clean up
clean:
	rm -f *.o *.S *.elf

# Show available targets
help:
	@echo "Available targets:"
	@echo "  all              - Convert all .c files to assembly (O0 and O2)"
	@echo "  <name>_compiled.S    - Convert specific .c file to assembly (no optimization)"
	@echo "  <name>_compiled_opt.S - Convert specific .c file to assembly (with optimization)"
	@echo "  clean            - Remove all generated files"
	@echo ""
	@echo "Available C files: $(C_SOURCES)"

.PHONY: all clean help