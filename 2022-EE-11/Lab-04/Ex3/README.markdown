# RISC-V Assembly and C: Non-Restoring Division Algorithm

## Problem
This project includes two implementations of the non-restoring division algorithm for unsigned integers:
- `e3.s`: A RISC-V assembly program that performs 8-bit division of 57 by 10, returning the quotient and remainder, designed for the Spike simulator.
- `e3.c`: A C program that implements a 32-bit non-restoring division algorithm, taking user input for dividend and divisor, and printing the quotient, remainder, and verification.

## Approach
- **e3.s (RISC-V Assembly)**:
  - Implements an 8-bit non-restoring division algorithm using shift-and-subtract/add operations.
  - Takes dividend (57) and divisor (10), processes them as 8-bit values, and returns quotient and remainder.
  - Includes Spike-specific exit code.
- **e3.c (C)**:
  - Implements a 32-bit non-restoring division algorithm in a reusable function.
  - Accepts user input for dividend and divisor, handles division by zero, and prints results with verification.

## Walkthrough
### e3.s (RISC-V Assembly)
1. **Text Section** (`_start`):
   - Loads dividend (57) into `a0` and divisor (10) into `a1` (`li` instructions).
   - Calls `divide` function (`jal divide`).
   - Signals Spike to exit by storing 1 in `tohost` (`sd t0, (t1)`).
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
2. **Divide Function**:
   - Masks inputs to 8 bits (`andi t0, a0, 0xFF` for dividend, `andi t1, a1, 0xFF` for divisor).
   - Initializes remainder (`t2 = 0`) and counter (`t3 = 8`) for 8-bit processing.
   - **Loop** (8 iterations):
     - Shifts remainder (`t2`) left by 1 (`slli t2, t2, 1`).
     - Extracts MSB of quotient (`t0`) and places it in LSB of remainder (`or t2, t2, t4`).
     - Shifts quotient left (`slli t0, t0, 1`).
     - Checks if remainder is negative (`bltz t2, add`):
       - If negative, adds divisor (`add t2, t2, t1`).
       - If non-negative, subtracts divisor (`sub t2, t2, t1`).
     - Sets quotient LSB to 1 if result is non-negative (`ori t0, t0, 1`), else 0.
     - Decrements counter (`addi t3, t3, -1`) and loops if not zero (`bnez t3, loop`).
   - Adjusts remainder if negative (`add t2, t2, t1`).
   - Returns quotient in `a0` and remainder in `a1`, masked to 8 bits.
3. **Tohost Section**:
   - Defines `tohost` and `fromhost` for Spike communication.

### e3.c (C)
1. **Division Function**:
   - Takes 32-bit dividend (`Q`) and divisor (`M`).
   - Initializes remainder (`A = 0`) and iterates 32 times:
     - Shifts `A` left and adds MSB of `Q` (`A = (A << 1) | ((Q >> 31) & 1)`).
     - Shifts `Q` left (`Q = Q << 1`).
     - If `A` is negative, adds `M`; else subtracts `M`.
     - Sets `Q` LSB to 0 if result is negative, else 1.
   - Adjusts remainder if negative (`A = (A < 0) ? (A + M) : A`).
   - Prints remainder, quotient, and verification (`A + Q * M`).
2. **Main Function**:
   - Prompts user for dividend (`Q`) and divisor (`M`) via `scanf`.
   - Checks for division by zero.
   - Calls `division` and prints results.

## How to Run
### Prerequisites
- RISC-V toolchain (`riscv64-unknown-elf-gcc`, `riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`).
- Spike simulator for `e3.s`.
- `link.ld` linker script for `e3.s` (in parent directory of `DIR`).

### e3.s (Assembly)
1. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e3.s -o e3.o
   ```
2. **Link**:
   ```bash
   riscv64-unknown-elf-ld -T link.ld e3.o -o e3
   ```
3. **Run with Spike**:
   ```bash
   spike e3
   ```
4. **Inspect Result**:
   - For dividend=57, divisor=10, expect quotient=5, remainder=7 in `a0` and `a1`.
   - Use a debugger or modify the program to output `a0` (quotient) and `a1` (remainder).

### e3.c (C)
1. **Compile**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e3.c -o e3_c
   ```
2. **Run** (on a RISC-V emulator or system with stdio support):
   ```bash
   ./e3_c
   ```
   - Enter dividend and divisor when prompted.
3. **Output**:
   - Prints quotient, remainder, and verification.

## Examples
### e3.s Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e3.s -o e3.o
$ riscv64-unknown-elf-ld -T link.ld e3.o -o e3
$ spike e3
```
- Computes 57 ÷ 10: quotient=5, remainder=7.
- Result in `a0` (5) and `a1` (7). Verify with a debugger.

### e3.c Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e3.c -o e3_c
$ ./e3_c
Enter Dividend (Q): 57
Enter Divisor (M): 10
Remainder: 7
Quotient: 5
Check: 57
```
- For dividend=57, divisor=10, outputs quotient=5, remainder=7, verification=57.

## Syntactical Shorthands Explained
### e3.s (Assembly)
- `.section .text`: Defines code section.
- `.globl _start, divide`: Declares global symbols.
- `li reg, imm`: Loads immediate into `reg`.
- `jal label`: Jumps to `label`, saving return address.
- `andi reg, src, imm`: Bitwise AND with immediate.
- `slli reg, src, imm`: Shifts `src` left by `imm`.
- `srli reg, src, imm`: Shifts `src` right by `imm`.
- `or reg, src1, src2`: Bitwise OR.
- `bltz reg, label`: Branches if `reg < 0`.
- `bgez reg, label`: Branches if `reg >= 0`.
- `sub reg, src1, src2`: Subtracts `src2` from `src1`.
- `add reg, src1, src2`: Adds `src1` and `src2`.
- `ori reg, src, imm`: Bitwise OR with immediate.
- `bnez reg, label`: Branches if `reg != 0`.
- `ret`: Returns to caller.
- `sd reg, offset(base)`: Stores 64-bit doubleword.
- `j 1b`: Jumps to backward label `1`.
- `.section .tohost`: Spike communication section.
- `.align 3`: Aligns to 8-byte boundary.
- `.dword`: Allocates 64-bit integer.

### e3.c (C)
- `int`: 32-bit integer type.
- `<<`, `>>`: Bitwise shift operators.
- `|`, `&`, `~`: Bitwise OR, AND, NOT.
- `scanf`: Reads user input.
- `printf`: Prints formatted output.
- `while(n > 0)`: Iterates 32 times.
- `(A < 0) ? ... : ...`: Conditional expression.