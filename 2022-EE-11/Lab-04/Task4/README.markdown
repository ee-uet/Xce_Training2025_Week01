# RISC-V Assembly: Array Reversal

## Problem
This RISC-V assembly program reverses an array of 32-bit integers (`reverse_array = [1, 2, 3, 4, 5, 6, 7, 8]`) in place and is designed to run on the Spike RISC-V simulator.

## Approach
The program:
- Defines an array (`reverse_array`) and its size (`reverse_size = 8`) in the `.data` section.
- Implements a `reverse_array_func` function in the `.text` section to reverse the array in place using two pointers.
- Handles edge cases (arrays with size < 2).
- Includes Spike-specific exit code.

## Walkthrough
1. **Data Section**:
   - `reverse_array: .word 1, 2, 3, 4, 5, 6, 7, 8`: Defines an array of 8 integers.
   - `reverse_size: .word 8`: Stores the array size.
2. **Text Section** (`_start`):
   - Loads the array address into `a0` (`la a0, reverse_array`).
   - Loads the array size into `a1` (`lw a1, reverse_size`).
   - Calls `reverse_array_func` (`jal reverse_array_func`).
   - Signals Spike to exit by loading 1 into `t0` and storing it in `tohost` (`sd t0, (t1)`).
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
3. **Reverse Array Function**:
   - Checks if size < 2 (`blt a1, t0, reverse_done`); if true, returns as no reversal is needed.
   - Initializes:
     - `t0` as the left pointer (`mv t0, a0`).
     - `t1` as the right pointer: computes `(size-1) * 4` (`slli t1, t1, 2`) and adds to array base (`add t1, a0, t1`).
   - **Loop** (`reverse_loop`):
     - Exits if left pointer ≥ right pointer (`bgeu t0, t1, reverse_done`).
     - Loads left (`lw t2, 0(t0)`) and right (`lw t3, 0(t1)`) values.
     - Swaps values using `sw` (store word).
     - Increments left pointer (`addi t0, t0, 4`) and decrements right pointer (`addi t1, t1, -4`).
     - Continues (`j reverse_loop`).
   - Returns (`ret`).
4. **Tohost Section**:
   - Defines `tohost` and `fromhost` as 64-bit variables for Spike communication.

## How to Run
1. **Prerequisites**: Requires a RISC-V toolchain (`riscv64-unknown-elf-gcc`) and Spike simulator.
2. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c reverse.S -o reverse.o
   ```
3. **Link**:
   ```bash
   riscv64-unknown-elf-ld reverse.o -o reverse
   ```
4. **Run with Spike**:
   ```bash
   spike reverse
   ```
5. **Inspect Result**:
   - The array is reversed in place to `[8, 7, 6, 5, 4, 3, 2, 1]`. Use a debugger or modify the program to output the array for verification.

## Examples
### Sample Run
For `reverse_array = [1, 2, 3, 4, 5, 6, 7, 8]`:
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c reverse.S -o reverse.o
$ riscv64-unknown-elf-ld reverse.o -o reverse
$ spike reverse
```
- Reverses the array to `[8, 7, 6, 5, 4, 3, 2, 1]` in memory.
- Exits via `tohost` signal.

To verify, use a debugger to inspect the memory at `reverse_array` or add output instructions.

## Syntactical Shorthands Explained
- `.section .data`: Defines the data section for initialized variables.
- `.word`: Allocates 32-bit integers (e.g., array elements, size).
- `.section .text`: Defines the code section.
- `.global _start`: Declares `_start` as the entry point.
- `la reg, label`: Loads the address of `label` into `reg`.
- `lw reg, offset(base)`: Loads a 32-bit word from `base + offset` into `reg`.
- `jal label`: Jumps to `label` and links the return address.
- `blt reg1, reg2, label`: Branches to `label` if `reg1 < reg2`.
- `mv dest, src`: Moves `src` to `dest`.
- `addi reg, src, imm`: Adds immediate to `src`, storing in `reg`.
- `slli reg, src, imm`: Shifts `src` left by `imm` bits, storing in `reg`.
- `add reg, src1, src2`: Adds `src1` and `src2`, storing in `reg`.
- `bgeu reg1, reg2, label`: Branches to `label` if `reg1 ≥ reg2` (unsigned).
- `lw reg, offset(base)`: Loads a 32-bit word from memory.
- `sw src, offset(base)`: Stores a 32-bit word to memory.
- `j label`: Jumps to `label`.
- `ret`: Returns to the caller.
- `li reg, imm`: Loads an immediate value into `reg`.
- `sd reg, offset(base)`: Stores a 64-bit doubleword to memory.
- `j 1b`: Jumps to the nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines a section for Spike communication.
- `.align 3`: Aligns data to a 2^3 (8-byte) boundary.
- `.dword`: Allocates a 64-bit integer.