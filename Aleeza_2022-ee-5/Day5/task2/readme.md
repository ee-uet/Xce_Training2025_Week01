## PROBLEM: Implement a function to count the number of set bits in a 32-bit word.

## Approach  
- Load a **32-bit input number** into `t0`.  
- Initialize a **counter** in `t1` to `0`.  
- Repeatedly:  
  - Check the least significant bit (LSB) with `andi`.  
  - Add it to the counter.  
  - Shift the number right by 1 (`srli`).  
- Stop when the number becomes `0`.  
- Final count is stored in `a0`.  
- Signal completion via the `tohost` section for Spike.  

This approach is essentially a **bitwise loop** that inspects all bits. 


## How to run
Spike (the RISC-V ISA Simulator) was installed using the manual.  
For compilation, the `riscv64-unknown-elf-*` toolchain was used.

**`link.ld` linker script** provided in the manual was used along with the following **Makefile**:
```
# Program name
PROG = filename


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
```

- To run assembly code using spike
  
  First of all, write the name of your file in makefile
  `PROG = filename`. 
  Then run these commands in terminal
  ```
  make
  make run
  spike -d --log-commits filename.elf
  ```

## Examples

`0xF1F0F0F0` → binary has 13 set bits.

`0xFFFFFFFF` → 32 set bits.

`0x00000000` → 0 set bits.

---
## Known Limitations

The input value is hardcoded in the program. To test with a different value, modify the instruction
`li t0, <your_number>`.
