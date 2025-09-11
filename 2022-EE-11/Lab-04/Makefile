# Configuration
AS = riscv64-unknown-elf-as
CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
CFLAGS = -march=rv64i -mabi=lp64 -Wall -O2
SPIKE = spike
DIR ?= code  # User can override with DIR=<directory>
PROG ?= program  # Default program name, can be overridden
LINKER_SCRIPT = link.ld

# Default target - builds both executable and compiled assembly
all: $(DIR)/$(PROG) $(DIR)/$(PROG)_comp.s

# Rule to create directory if it doesn't exist
$(DIR):
	mkdir -p $(DIR)

# Rule to assemble and link the .s file into executable
$(DIR)/$(PROG): $(DIR)/$(PROG).s $(DIR)
	cd $(DIR) && $(AS) -o $(PROG).o $(PROG).s
	cd $(DIR) && $(LD) -T ../$(LINKER_SCRIPT) -o $(PROG) $(PROG).o

# Rule to compile .c file to assembly with _comp.s suffix
$(DIR)/$(PROG)_comp.s: $(DIR)/$(PROG).c $(DIR)
	cd $(DIR) && $(CC) $(CFLAGS) -S -o $(PROG)_c.s $(PROG).c

# Rule to run with Spike
run: $(DIR)/$(PROG)
	cd $(DIR) && $(SPIKE) $(PROG)

# Rule to debug with Spike
debug: $(DIR)/$(PROG)
	cd $(DIR) && $(SPIKE) -d --log-commits $(PROG)

# Clean up
clean:
	rm -f $(DIR)/*.o $(DIR)/$(PROG) $(DIR)/*_comp.s

# Help section
help:
	@echo "RISC-V Assembly and C Build System"
	@echo "=================================="
	@echo ""
	@echo "USAGE:"
	@echo "  make [target] [DIR=<directory>] [PROG=<program_name>]"
	@echo ""
	@echo "PARAMETERS:"
	@echo "  DIR   - Directory containing source files (default: code)"
	@echo "  PROG  - Program name without extension (default: program)"
	@echo ""
	@echo "TARGETS:"
	@echo "  all           - Build both executable and compiled assembly (default)"
	@echo "  <DIR>/<PROG>  - Build executable from <PROG>.s assembly file"
	@echo "  <DIR>/<PROG>_comp.s - Compile <PROG>.c to assembly output"
	@echo "  run           - Run executable with Spike RISC-V simulator"
	@echo "  debug         - Debug executable with Spike (with logging)"
	@echo "  clean         - Remove all generated files"
	@echo "  help          - Show this help message"
	@echo ""
	@echo "EXAMPLES:"
	@echo "  make                              # Build code/program from code/program.s and code/program.c"
	@echo "  make DIR=test PROG=hello          # Build test/hello from test/hello.s and test/hello.c"
	@echo "  make run DIR=test PROG=hello      # Run test/hello with Spike"
	@echo "  make debug DIR=mydir PROG=sample  # Debug mydir/sample with Spike"
	@echo "  make clean DIR=test               # Clean test directory"
	@echo ""
	@echo "REQUIRED FILES:"
	@echo "  <DIR>/<PROG>.s  - Assembly source file"
	@echo "  <DIR>/<PROG>.c  - C source file"
	@echo "  link.ld         - Linker script (in project root)"
	@echo ""
	@echo "OUTPUT FILES:"
	@echo "  <DIR>/<PROG>         - Executable program"
	@echo "  <DIR>/<PROG>_comp.s  - Assembly generated from C source"
	@echo "  <DIR>/<PROG>.o       - Object file (intermediate)"

.PHONY: all run debug clean help
