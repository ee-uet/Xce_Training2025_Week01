# RISC-V Assembly: Insertion Sort

## Problem
This RISC-V assembly program sorts an array of 32-bit integers (`test_array = [64, 34, 25, 12, 22, 11, 90, 5]`) in ascending order using the insertion sort algorithm. It is designed to run on the Spike RISC-V simulator.

## Approach
The program:
- Defines an array (`test_array`) and its size (`array_size = 8`) in the `.data` section.
- Implements an `insertion_sort` function in the `.text` section to sort the array in place.
- Handles edge cases (arrays with size < 2).
- Uses Spike-specific exit code to signal completion.

## Walkthrough
1. **Data Section**:
   - `test_array: .word 64, 34, 25, 12, 22, 11, 90, 5`: Defines an array of 8 integers.
   - `array_size: .word 8`: Stores the array size.
2. **Text Section** (`_start`):
   - Loads the array address into `a0` (`la a0, test_array`).
   - Loads the array size into `a1` (`lw a1, array_size`).
   - Calls `insertion_sort` (`jal insertion_sort`).
   - Signals Spike to exit by loading 1 into `t0` and storing it in `tohost` (`sd t0, (t1)`).
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
3. **Insertion Sort Function**:
   - Checks if size < 2 (`blt a1, t0, sort_done`); if true, returns as the array is already sorted.
   - **Outer Loop** (`outer_loop`):
     - Initializes `t0 = i = 1` (current index).
     - Exits if `i >= size` (`bge t0, a1, sort_done`).
     - Loads `key = arr[i]` into `t2` using address calculation (`slli t1, t0, 2; add t1, a0, t1; lw t2, 0(t1)`).
     - Sets `j = i - 1` (`t3`).
   - **Inner Loop** (`inner_loop`):
     - Exits if `j < 0` (`bltz t3, insert_key`) or if `arr[j] <= key` (`ble t5, t2, insert_key`).
     - Shifts `arr[j]` to `arr[j+1]` (`sw t5, 0(t6)`).
     - Decrements `j` (`addi t3, t3, -1`) and continues.
   - **Insert Key**:
     - Inserts `key` at `arr[j+1]` after incrementing `j` (`addi t3, t3, 1`).
     - Increments `i` (`addi t0, t0, 1`) and continues the outer loop.
   - Returns (`ret`) when sorting is complete.
4. **Tohost Section**:
   - Defines `tohost` and `fromhost` as 64-bit variables for Spike communication.

## How to Run
1. **Prerequisites**: Requires a RISC-V toolchain (`riscv64-unknown-elf-gcc`) and Spike simulator.
2. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c insertion_sort.S -o insertion_sort.o
   ```
3. **Link**:
   ```bash
   riscv64-unknown-elf-ld insertion_sort.o -o insertion_sort
   ```
4. **Run with Spike**:
   ```bash
   spike insertion_sort
   ```
5. **Inspect Result**:
   - The array is sorted in place to `[5, 11, 12, 22, 25, 34, 64, 90]`. Use a debugger or modify the program to output the array for verification.

## Examples
### Sample Run
For `test_array = [64, 34, 25, 12, 22, 11, 90, 5]`:
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c insertion_sort.S -o insertion_sort.o
$ riscv64-unknown-elf-ld insertion_sort.o -o insertion_sort
$ spike insertion_sort
```
- Sorts the array to `[5, 11, 12, 22, 25, 34, 64, 90]` in memory.
- Exits via `tohost` signal.

To verify, use a debugger to inspect the memory at `test_array` or add output instructions.

## Syntactical Shorthands Explained
- `.section .data`: Defines the data section for initialized variables.
- `.word`: Allocates 32-bit integers (e.g., array elements, size).
- `.section .text`: Defines the code section.
- `.global _start`: Declares `_start` as the entry point.
- `la reg, label`: Loads the address of `label` into `reg`.
- `lw reg, offset(base)`: Loads a 32-bit word from `base + offset` into `reg`.
- `jal label`: Jumps to `label` and links the return address.
- `blt reg1, reg2, label`: Branches to `label` if `reg1 < reg2`.
- `bge reg1, reg2, label`: Branches to `label` if `reg1 >= reg2`.
- `bltz reg, label`: Branches to `label` if `reg < 0`.
- `ble reg1, reg2, label`: Branches to `label` if `reg1 <= reg2`.
- `slli reg, src, imm`: Shifts `src` left by `imm` bits, storing in `reg`.
- `add reg, src1, src2`: Adds `src1` and `src2`, storing in `reg`.
- `lw reg, offset(base)`: Loads a 32-bit word from memory.
- `sw src, offset(base)`: Stores a 32-bit word to memory.
- `addi reg, src, imm`: Adds immediate to `src`, storing in `reg`.
- `li reg, imm`: Loads an immediate value into `reg`.
- `sd reg, offset(base)`: Stores a 64-bit doubleword to memory.
- `j label`: Jumps to `label`.
- `ret`: Returns to the caller.
- `j 1b`: Jumps to the nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines a section for Spike communication.
- `.align 3`: Aligns data to a 2^3 (8-byte) boundary.
- `.dword`: Allocates a 64-bit integer.