## PROBLEM: # Bit Manipulation in RISC-V Assembly  

The task is to write a RISC-V assembly program that can **set** or **clear** any bit in a 32-bit number.  
- A given number (`x1`) is modified based on the bit position (`x2`) and an operation selector (`x3`).  
- If `x3 = 0`, the bit is **cleared**.  
- If `x3 ≠ 0`, the bit is **set**.

---
## Approach
1. Load the 32-bit number into a register.  
2. Load the bit position into another register.  
3. Create a mask by left-shifting `1` by the given bit position.  
4. If `x3 = 0`, perform **bit clear** using `AND` with inverted mask.  
5. If `x3 ≠ 0`, perform **bit set** using `OR` with the mask.  
6. Write the final result back to the register.  
7. Signal program completion by writing to the `tohost` symbol.

## How to Run

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
- To get the assembly file built by toolchain, run this command.
  ```
  riscv64-linux-gnu-gcc -S program.c -o program_toolchain.s

# Examples

- Example 1: Setting a Bit
```
Input: x1 = 32 (0b100000), x2 = 6, x3 = 1
Operation: Set the 6th bit.
Output: x1 = 96 (0b1100000)
```
- Example 2: Clearing a Bit
```
Input: x1 = 32 (0b100000), x2 = 5, x3 = 0
Operation: Clear the 5th bit.
Output: x1 = 0 (0b000000)
```

## Known Limitations

- Only works with 32-bit unsigned integers.

## Manual vs Toolchain-Generated Assembly 

### Manual Assembly
- Direct low-level implementation in RISC-V.
- Uses only registers, no stack.
- Minimal instructions (shift + OR/AND).
- Very small and optimized for speed/area.
- Ends by writing to `tohost`.

### Toolchain-Generated Assembly
- Produced from C code (`clear_set_bit.c`).
- Creates stack frame.
- Stores variables in memory instead of registers.
- Includes extra instructions (`sext.w`, `not`, etc.) for safety.
- Uses `printf`, adding heavy overhead and `.rodata` strings.
- Larger code size, more instructions.
  
### Conclusion:


 - `Manual assembly = compact and efficient`
 - `Toolchain assembly = portable but heavier`


## Sources & AI Usage

- Command to get assembly file built by toolchain - `ChatGPT`.
- Got some help to compare the manually written assembly code with the toolchain-generated assembly code-`ChatGPT`.