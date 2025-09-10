# RISC-V Assembly and C: Restoring Division Algorithm

## Problem
This project includes two implementations of the restoring division algorithm for unsigned integers:
- `e1.s`: A RISC-V assembly program (`e1.s`) that performs 8-bit division of 57 by 10, storing the quotient and remainder.
- `e1.c`: A C program that implements a 32-bit restoring division algorithm and tests it with multiple cases.

Both programs are designed to run in a RISC-V environment, with `e1.s` tailored for the Spike simulator.

## Approach
- **e1.s (RISC-V Assembly)**:
  - Implements an 8-bit restoring division algorithm using a shift-and-subtract method.
  - Takes dividend (57) and divisor (10), processes them as 8-bit values, and returns quotient and remainder.
  - Uses Spike-specific exit code for simulation.
- **e1.c (C)**:
  - Implements a 32-bit restoring division algorithm in a reusable function (`restoring_divide`).
  - Tests the function with various input pairs and verifies results via printf.

## Walkthrough
### e1.s (RISC-V Assembly)
1. **Data Section**:
   - No data section is used; inputs are hardcoded in `_start`.
2. **Text Section** (`_start`):
   - Loads dividend (57) into `a0` and divisor (10) into `a1` (`li` instructions).
   - Calls `divide` function (`jal divide`).
   - Signals Spike to exit by storing 1 in `tohost` (`sd t0, (t1)`).
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
3. **Divide Function**:
   - Masks inputs to 8 bits (`andi t0, a0, 0xFF` for dividend, `andi t1, a1, 0xFF` for divisor).
   - Initializes remainder (`t2 = 0`) and counter (`t3 = 8`) for 8-bit processing.
   - **Loop** (8 iterations):
     - Shifts remainder (`t2`) left by 1 (`slli t2, t2, 1`).
     - Extracts MSB of quotient (`t0`) and places it in LSB of remainder (`or t2, t2, t4`).
     - Shifts quotient left (`slli t0, t0, 1`).
     - Subtracts divisor from remainder (`sub t2, t2, t1`).
     - If result is negative (`bltz t2, negative`), restores remainder (`add t2, t2, t1`); else sets LSB of quotient to 1 (`ori t0, t0, 1`).
     - Decrements counter (`addi t3, t3, -1`) and loops if not zero (`bnez t3, loop`).
   - Returns quotient in `a0` and remainder in `a1`, masked to 8 bits.
4. **Tohost Section**:
   - Defines `tohost` and `fromhost` for Spike communication.

### e1.c (C)
1. **Structure**:
   - Defines `DivResult` struct to hold quotient and remainder.
2. **Restoring Divide Function**:
   - Takes 32-bit dividend and divisor as inputs.
   - Initializes quotient (`0`) and remainder (`0`).
   - Processes 32 bits in a loop (i = 31 to 0):
     - Shifts remainder left and adds MSB of dividend (`remainder = (remainder << 1) | ((temp_dividend >> 31) & 1)`).
     - Shifts dividend left (`temp_dividend <<= 1`).
     - If remainder ≥ divisor, subtracts divisor and sets corresponding quotient bit (`quotient |= (1U << i)`).
   - Returns quotient and remainder in a `DivResult` struct.
3. **Main Function**:
   - Defines test cases: `{100, 7}, {1000, 13}, {0xFFFFFFFF, 2}, {42, 1}, {15, 3}, {17, 5}`.
   - Iterates through test cases, calls `restoring_divide`, and prints quotient, remainder, and verification (`quotient * divisor + remainder`).

## How to Run
### Prerequisites
- RISC-V toolchain (`riscv64-unknown-elf-gcc`, `riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`).
- Spike simulator for `e1.s`.
- `link.ld` linker script for `e1.s` (must be provided in the parent directory).

### e1.s (Assembly)
1. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e1.s -o e1.o
   ```
2. **Link**:
   ```bash
   riscv64-unknown-elf-ld -T link.ld e1.o -o e1
   ```
3. **Run with Spike**:
   ```bash
   spike e1
   ```
4. **Inspect Result**:
   - For dividend=57, divisor=10, expect quotient=5, remainder=7 in `a0` and `a1`.
   - Use a debugger or modify the program to output `a0` (quotient) and `a1` (remainder).

### e1.c (C)
1. **Compile**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e1.c -o e1_c
   ```
2. **Run** (on a RISC-V emulator or native system with printf support):
   ```bash
   ./e1_c
   ```
   Or with Spike if linked appropriately:
   ```bash
   spike e1_c
   ```
3. **Output**:
   - Prints quotient, remainder, and verification for each test case.

## Examples
### e1.s Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e1.s -o e1.o
$ riscv64-unknown-elf-ld -T link.ld e1.o -o e1
$ spike e1
```
- Computes 57 ÷ 10: quotient=5, remainder=7.
- Result in `a0` (5) and `a1` (7). Verify with a debugger.

### e1.c Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e1.c -o e1_c
$ ./e1_c
Divide 100 by 7:
  Quotient: 14
  Remainder: 2
  Verification: 14 * 7 + 2 = 100

Divide 1000 by 13:
  Quotient: 76
  Remainder: 12
  Verification: 76 * 13 + 12 = 1000

Divide 4294967295 by 2:
  Quotient: 2147483647
  Remainder: 1
  Verification: 2147483647 * 2 + 1 = 4294967295

Divide 42 by 1:
  Quotient: 42
  Remainder: 0
  Verification: 42 * 1 + 0 = 42

Divide 15 by 3:
  Quotient: 5
  Remainder: 0
  Verification: 5 * 3 + 0 = 15

Divide 17 by 5:
  Quotient: 3
  Remainder: 2
  Verification: 3 * 5 + 2 = 17
```

## Syntactical Shorthands Explained
### e1.s (Assembly)
- `.section .text`: Defines the code section.
- `.globl _start, divide`: Declares `_start` and `divide` as global symbols.
- `li reg, imm`: Loads immediate value into `reg`.
- `jal label`: Jumps to `label`, saving return address.
- `andi reg, src, imm`: Bitwise AND with immediate, storing in `reg`.
- `slli reg, src, imm`: Shifts `src` left by `imm` bits.
- `srli reg, src, imm`: Shifts `src` right by `imm` bits.
- `or reg, src1, src2`: Bitwise OR of `src1` and `src2`.
- `sub reg, src1, src2`: Subtracts `src2` from `src1`.
- `bltz reg, label`: Branches if `reg < 0`.
- `ori reg, src, imm`: Bitwise OR with immediate.
- `bnez reg, label`: Branches if `reg != 0`.
- `ret`: Returns to caller.
- `sd reg, offset(base)`: Stores 64-bit doubleword to memory.
- `j 1b`: Jumps to nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines Spike communication section.
- `.align 3`: Aligns to 8-byte boundary.
- `.dword`: Allocates 64-bit integer.

### e1.c (C)
- `typedef struct { ... } DivResult`: Defines struct for quotient and remainder.
- `uint