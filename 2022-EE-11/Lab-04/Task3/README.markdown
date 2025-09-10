# RISC-V Assembly: Iterative Factorial Calculator

## Problem
This RISC-V assembly program computes the factorial of a given number (5) iteratively and is designed to run on the Spike RISC-V simulator. The result is stored in a register, and the program signals completion for Spike.

## Approach
The program:
- Implements a `factorial` function that calculates the factorial of an input number in `a0` iteratively.
- Handles edge cases (n ≤ 0 and n = 1) by returning 1.
- Uses a loop to multiply numbers from 1 to n.
- Includes Spike-specific exit code.

## Walkthrough
1. **Text Section** (`_start`):
   - Loads 5 into `a0` (`li a0, 5`) as the input for factorial.
   - Calls the `factorial` function (`jal factorial`).
   - Stores the result in `t0` (`mv t0, a0`).
   - Signals Spike to exit by loading 1 into `t0` and storing it in `tohost` (`sd t0, (t1)`).
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
2. **Factorial Function**:
   - Checks edge cases:
     - If `a0 ≤ 0` (`blez a0, fact_return_one`), returns 1.
     - If `a0 = 1` (`beq a0, t0, fact_return_one`), returns 1.
   - Initializes:
     - `t1 = a0` (counter, n).
     - `t2 = 1` (result accumulator).
   - **Loop** (`fact_loop`):
     - Multiplies `t2 = t2 * t1` (`mul t2, t2, t1`).
     - Decrements `t1` (`addi t1, t1, -1`).
     - Continues if `t1 != 0` (`bnez t1, fact_loop`).
   - Moves `t2` to `a0` (`mv a0, t2`) and returns (`ret`).
3. **Tohost Section**:
   - Defines `tohost` and `fromhost` as 64-bit variables for Spike communication.

## How to Run
1. **Prerequisites**: Requires a RISC-V toolchain (`riscv64-unknown-elf-gcc`) and Spike simulator.
2. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c factorial.S -o factorial.o
   ```
3. **Link**:
   ```bash
   riscv64-unknown-elf-ld factorial.o -o factorial
   ```
4. **Run with Spike**:
   ```bash
   spike factorial
   ```
5. **Inspect Result**:
   - The result (120 for n=5) is in `a0` (and `t0` after `_start`). Use a debugger or modify the program to output `a0` for verification.

## Examples
### Sample Run
For input `n = 5`:
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c factorial.S -o factorial.o
$ riscv64-unknown-elf-ld factorial.o -o factorial
$ spike factorial
```
- Computes `5! = 5 * 4 * 3 * 2 * 1 = 120`.
- Stores 120 in `a0` and `t0`.
- Exits via `tohost` signal.

To verify, use a debugger to check `a0`/`t0` or add output instructions.

## Syntactical Shorthands Explained
- `.section .text`: Defines the code section.
- `.global _start`: Declares `_start` as the entry point.
- `li reg, imm`: Loads an immediate value into `reg`.
- `jal label`: Jumps to `label` and links the return address.
- `mv dest, src`: Moves `src` to `dest`.
- `blez reg, label`: Branches to `label` if `reg ≤ 0`.
- `beq reg1, reg2, label`: Branches to `label` if `reg1 = reg2`.
- `mul dest, src1, src2`: Multiplies `src1` and `src2`, storing in `dest`.
- `addi reg, src, imm`: Adds immediate to `src`, storing in `reg`.
- `bnez reg, label`: Branches to `label` if `reg != 0`.
- `ret`: Returns to the caller (jumps to return address).
- `la reg, label`: Loads the address of `label` into `reg`.
- `sd reg, offset(base)`: Stores a 64-bit doubleword from `reg` to memory.
- `j 1b`: Jumps to the nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines a section for Spike communication.
- `.align 3`: Aligns data to a 2^3 (8-byte) boundary.
- `.dword`: Allocates a 64-bit integer.