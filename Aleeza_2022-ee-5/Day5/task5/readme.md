## PROBLEM: # Insertion Sort in RISC-V Assembly

Implement the **Insertion Sort** algorithm in RISC-V assembly to sort an array of integers in ascending order.  

## Approach  
- Start from the **second element** (`i = 1`), treating the first element as a sorted subarray.  
- Extract the current element (`key = array[i]`).  
- Compare `key` with elements to its left and shift all greater elements one position to the right.  
- Insert the `key` into its correct position in the sorted subarray.  
- Repeat until all elements are placed correctly.  

### Registers Used  
- `t0` → base address of array  
- `t1` → number of elements in array  
- `t2` → outer loop index (`i`)  
- `a2` → key element (`array[i]`)  
- `a3` → inner loop index (`j`)  
- `a6` → current element for comparison (`array[j]`) 

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

Input: `[5, 2, 9, 1, 5, 6]`
Output: `[1, 2, 5, 5, 6, 9]`

Input: `[10, -2, 4, 0]`
Output: `[-2, 0, 4, 10]`

## Known Limitations

- Array size (t1) is hardcoded in the program.
- Only works on 32-bit integers (.word).

## Sources & AI Usage
- Reviewd the algorithm [insertion-sort](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/).
- Fixed some logical errors using `ChatGPT`

