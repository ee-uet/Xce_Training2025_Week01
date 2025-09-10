# RISC-V Assembly: Absolute Difference Calculator

## Problem
This RISC-V assembly program (`t1.S`) calculates the absolute difference between two 32-bit integers (`num1` and `num2`) and stores the result in memory (`result`). It is designed to run on the Spike RISC-V simulator.

## Approach
The program:
- Defines two input values (`num1 = 15`, `num2 = 7`) and a variable (`result`) in the `.data` section.
- Computes the absolute difference `|num1 - num2|` in the `.text` section using subtraction and conditional branching.
- Stores the result in memory and prepares it for output.
- Includes Spike-specific exit code to signal completion.

## Walkthrough
1. **Data Section**:
   - `num1: .word 15`: Stores 15 as a 32-bit integer.
   - `num2: .word 7`: Stores 7 as a 32-bit integer.
   - `result: .word 0`: Reserves space for the output.
2. **Text Section** (`_start`):
   - Loads `num1` into `a0` and `num2` into `a1` using `la` (load address) and `lw` (load word).
   - Computes `num1 - num2` (stored in `t1`) and `num2 - num1` (stored in `t2`).
   - Uses `bge` (branch if greater than or equal) to compare `a0` (`num1`) and `a1` (`num2`).
   - If `num1 >= num2`, moves `t1` (`num1 - num2`) to `a2`; otherwise, moves `t2` (`num2 - num1`) to `a2`.
   - Stores `a2` in `result` using `sw` (store word).
   - Sets `a0` to the result for output.
3. **Spike Exit Code**:
   - Loads 1 into `t0` and stores it in `tohost` to signal completion.
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
4. **Tohost Section**:
   - Defines `tohost` and `fromhost` as 64-bit variables for Spike communication.

## How to Run
1. **Prerequisites**: Requires a RISC-V toolchain (`riscv64-unknown-elf-gcc`) and Spike simulator.
2. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c t1.S -o t1.o
   ```
3. **Link**:
   ```bash
   riscv64-unknown-elf-ld t1.o -o t1
   ```
4. **Run with Spike**:
   ```bash
   spike t1
   ```
5. **Inspect Result** (optional):
   - The result is stored at the memory address of `result`. Use a debugger or modify the program to print `a0` for verification.

## Examples
### Sample Run
For `num1 = 15` and `num2 = 7`:
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c t1.S -o t1.o
$ riscv64-unknown-elf-ld t1.o -o t1
$ spike t1
```
- The program computes `|15 - 7| = 8`.
- Stores `8` in `result` and sets `a0 = 8`.
- Exits via `tohost` signal.

To verify, modify the program to output `a0` or use a debugger to check the `result` memory location.

## Syntactical Shorthands Explained
- `.section .data`: Defines the data section for initialized variables.
- `.word`: Allocates a 32-bit integer.
- `.global _start`: Declares `_start` as the program entry point.
- `.section .text`: Defines the code section.
- `la t0, label`: Loads the address of `label` into register `t0`.
- `lw reg, offset(base)`: Loads a 32-bit word from memory at `base + offset` into `reg`.
- `sub reg, src1, src2`: Subtracts `src2` from `src1`, storing the result in `reg`.
- `bge src1, src2, label`: Branches to `label` if `src1 >= src2`.
- `mv dest, src`: Moves the value in `src` to `dest`.
- `sw src, offset(base)`: Stores the value in `src` to memory at `base + offset`.
- `li reg, imm`: Loads an immediate value into `reg`.
- `sd reg, offset(base)`: Stores a 64-bit doubleword from `reg` to memory.
- `j 1b`: Jumps to the nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines a section for Spike communication.
- `.align 3`: Aligns data to a 2^3 (8-byte) boundary.
- `.dword`: Allocates a 64-bit integer.