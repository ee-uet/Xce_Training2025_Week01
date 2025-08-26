# -------- RISC-V Assembly Lab Makefile -------
  PROG ?= helloword              # override: make PROG=abs_diff run

AS      := riscv64-unknown-elf-as
LD      := riscv64-unknown-elf-ld
OBJDUMP := riscv64-unknown-elf-objdump
SPIKE   := spike

ASFLAGS := -march=rv64imac -mabi=lp64 -g
LDFLAGS := -T link.ld

SRC_DIR := src
BUILD_DIR := build

all: $(BUILD_DIR)/$(PROG)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# assemble .S -> .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S | $(BUILD_DIR)
	$(AS) $(ASFLAGS) -o $@ $<

# link .o -> ELF
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o link.ld
	$(LD) $(LDFLAGS) -o $@ $<

run: $(BUILD_DIR)/$(PROG)
	$(SPIKE) $<

debug: $(BUILD_DIR)/$(PROG)
	# NOTE: use two hyphens here (not an en dash)
	$(SPIKE) -d --log-commits $<

sections: $(BUILD_DIR)/$(PROG)
	$(OBJDUMP) -h $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run debug clean sections

