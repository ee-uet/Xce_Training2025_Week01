## PROBLEM: Factorial Calculation in RISC-V Assembly 
Implement a program in RISC-V assembly to calculate the **factorial** of a given number.  

The factorial of `n` (denoted as `n!`) is defined as:  
`n! = n × (n-1) × (n-2) × ... × 1`
with the base case `0! = 1`.  

## Approach  
- Load the input number (`n`) into `t0`.  
- Initialize the result (`t1`) to `1`.  
- Loop until `t0` becomes `0`:  
  - Multiply result with `t0`.  
  - Decrement `t0`.  
- Final result is stored in `a0`.  
- Use the `.tohost` section to signal Spike simulator.  

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

Input: `5` → Output: `120`

Input: `0` → Output: `1`

Input: `3` → Output: `6`

## Known Limitations

- Input is hardcoded inside the program (li t0, <number>).
- For large inputs (>20), factorial overflows 64-bit registers.

