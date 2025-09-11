## PROBLEM: Absolute Difference in RISC-V Assembly

Implement a program in RISC-V assembly to calculate the **absolute difference** between two numbers. The result must always be non-negative regardless of which number is larger.  

## Approach  
1. Load two numbers into registers (`t0` and `t1`).  
2. Subtract them (`t2 = t0 - t1`).  
3. If the result is **greater than or equal to 0**, keep it.  
4. Otherwise, negate the result to make it positive.  
5. Store a "test passed" signal into the `tohost` memory-mapped location for Spike simulation.  
6. Enter an infinite loop to keep the program stable.  

This follows a simple **branch + negate** logic to handle 

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


## Examples

For numbers:
```
40 and 15 → difference = 25

15 and 40 → difference = 25
```
The result is always positive, regardless of order.

## Known Limitations

The numbers are hardcoded into the program. To change them, we must modify the li t0, value and li t1, value instructions.
