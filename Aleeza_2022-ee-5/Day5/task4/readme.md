## PROBLEM: Implement a program to reverse an array in-place.
Implement a program in RISC-V assembly that **reverses an array in-place**. 
## Approach  
- Load the starting address of the array into register `t0`.  
- Compute the ending address (`t2`) using the array length × 4 (since each integer is 4 bytes).  
- Swap the elements pointed to by `t0` (start) and `t2` (end).  
- Increment `t0` forward and decrement `t2` backward until the pointers meet.  
- Final reversed array is stored in the same memory.
- After execution, the array stored at label array will be reversed in memory.

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

Input: `[1, 2, 3, 4, 5]`
Output: `[5, 4, 3, 2, 1]`

Input: `[10, 20, 30]`
Output: `[30, 20, 10]`

## Known Limitations

- Array length is hardcoded (li t1, 5).
- Works only for arrays of 32-bit integers (.word).

## Sources & AI Usage
Fixed some logical errors using `ChatGPT`

