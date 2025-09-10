# RISC-V Assembly and C: Bit Manipulation Operations

## Problem
This project includes two implementations of bit manipulation functions:
- `e2.s`: A RISC-V assembly program that performs bit set and clear operations on a 32-bit number (0x12345678), setting bit 4 and clearing bit 6, designed for the Spike simulator.
- `e2.c`: A C program that implements bit set, clear, get, and toggle functions, with comprehensive tests and binary output for verification.

## Approach
- **e2.s (RISC-V Assembly)**:
  - Implements `set_bit` and `clear_bit` functions to manipulate specific bits in a 32-bit number.
  - Tests these functions by setting bit 4 and clearing bit 6 of 0x12345678.
  - Includes additional utility functions (`get_bit`, `toggle_bit`) for testing.
  - Uses Spike-specific exit code.
- **e2.c (C)**:
  - Implements `set_bit`, `clear_bit`, `get_bit`, and `toggle_bit` functions for 32-bit numbers.
  - Includes a `print_binary` helper to display binary representations.
  - Tests operations with multiple cases and verifies results via printf.

## Walkthrough
### e2.s (RISC-V Assembly)
1. **Text Section** (`_start`):
   - Loads test number 0x12345678 into `t0`.
   - Calls `set_bit` with `a0 = 0x12345678`, `a1 = 4` (bit position), stores result in `t1`.
   - Calls `clear_bit` with `a0 = t1`, `a1 = 6`, stores result in `t2`.
   - Signals Spike to exit by storing 1 in `tohost`.
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
2. **Set Bit Function**:
   - Validates bit position (0-31) (`bltu t0, a1, invalid_bit_pos`).
   - Creates mask `1 << bit_position` (`sll t0, t0, a1`).
   - Sets bit using OR (`or a0, a0, t0`).
   - Returns result in `a0`.
3. **Clear Bit Function**:
   - Validates bit position (0-31).
   - Creates mask `~(1 << bit_position)` (`not t0, t0`).
   - Clears bit using AND (`and a0, a0, t0`).
   - Returns result in `a0`.
4. **Utility Functions**:
   - `get_bit`: Extracts bit value (0 or 1) at position `a1` using shift and mask.
   - `toggle_bit`: Toggles bit at position `a1` using XOR.
   - `invalid_bit_pos`/`invalid_bit_pos_get`: Return unchanged number or -1 for invalid positions.
5. **Tohost Section**:
   - Defines `tohost` and `fromhost` for Spike communication.

### e2.c (C)
1. **Functions**:
   - `set_bit`: Sets bit at `bit_position` using `| (1U << bit_position)`.
   - `clear_bit`: Clears bit using `& ~(1U << bit_position)`.
   - `get_bit`: Returns bit value (0 or 1) using `(number >> bit_position) & 1`.
   - `toggle_bit`: Toggles bit using `^ (1U << bit_position)`.
   - `print_binary`: Prints 32-bit number in binary with spaces every 4 bits.
   - All functions validate bit position (0-31), returning unchanged number or -1 if invalid.
2. **Main Function**:
   - Tests with `test_number = 0x12345678`:
     - Sets bit 4, prints result and binary, verifies bit 4.
     - Clears bit 6 from result, prints result and binary, verifies bit 6.
     - Toggles bit 31, prints result and binary, verifies bit 31.
   - Multiple operations test:
     - Starts with 0, sets bits 0, 8, 16, 31, clears bit 16, prints final binary.

## How to Run
### Prerequisites
- RISC-V toolchain (`riscv64-unknown-elf-gcc`, `riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`).
- Spike simulator for `e2.s`.
- `link.ld` linker script for `e2.s` (in parent directory of `DIR`).

### e2.s (Assembly)
1. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e2.s -o e2.o
   ```
2. **Link**:
   ```bash
   riscv64-unknown-elf-ld -T link.ld e2.o -o e2
   ```
3. **Run with Spike**:
   ```bash
   spike e2
   ```
4. **Inspect Result**:
   - Input: 0x12345678 (binary: 00010010 00110100 01010110 01111000).
   - Set bit 4: 0x12345678 | 0x10 = 0x12345678 (bit 4 already 1).
   - Clear bit 6: 0x12345678 & ~0x40 = 0x12345638.
   - Result in `t2`/`a0`. Use a debugger to verify.

### e2.c (C)
1. **Compile**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e2.c -o e2_c
   ```
2. **Run** (on RISC-V emulator or system with printf support):
   ```bash
   ./e2_c
   ```
3. **Output**:
   - Prints results, binary representations, and bit values for each test.

## Examples
### e2.s Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c e2.s -o e2.o
$ riscv64-unknown-elf-ld -T link.ld e2.o -o e2
$ spike e2
```
- Sets bit 4 of 0x12345678 (no change, bit 4 is 1).
- Clears bit 6, resulting in 0x12345638.
- Result in `a0`/`t2`. Verify with debugger.

### e2.c Sample Run
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -O2 e2.c -o e2_c
$ ./e2_c
=== Bit Operations Test ===
Original number: 0x12345678
Binary: 0001 0010 0011 0100 0101 0110 0111 1000

Setting bit 4:
Result: 0x12345678
Binary: 0001 0010 0011 0100 0101 0110 0111 1000
Bit 4 value: 1

Clearing bit 6 from the result:
Result: 0x12345638
Binary: 0001 0010 0011 0100 0101 0110 0011 1000
Bit 6 value: 0

Toggling bit 31:
Result: 0x92345638
Binary: 1001 0010 0011 0100 0101 0110 0011 1000
Bit 31 value: 1

=== Multiple Operations Test ===
Starting with 0x00000000
After setting bit 0: 0x00000001
After setting bit 8: 0x00000101
After setting bit 16: 0x00010101
After setting bit 31: 0x80010101
After clearing bit 16: 0x80000101
Final binary: 1000 0000 0000 0000 0000 0001 0000 0001
```

## Syntactical Shorthands Explained
### e2.s (Assembly)
- `.section .text`: Defines code section.
- `.globl _start, set_bit, clear_bit`: Declares global symbols.
- `li reg, imm`: Loads immediate into `reg`.
- `mv dest, src`: Moves `src` to `dest`.
- `jal label`: Jumps to `label`, saving return address.
- `bltu reg1, reg2, label`: Branches if `reg1 < reg2` (unsigned).
- `sll reg, src, imm`: Shifts `src` left by `imm`.
- `or reg, src1, src2`: Bitwise OR.
- `and reg, src1, src2`: Bitwise AND.
- `not reg, src`: Bitwise NOT.
- `srl reg, src, imm`: Shifts `src` right by `imm`.
- `andi reg, src, imm`: AND with immediate.
- `ori reg, src, imm`: OR with immediate.
- `xor reg, src1, src2`: Bitwise XOR.
- `ret`: Returns to caller.
- `sd reg, offset(base)`: Stores 64-bit doubleword.
- `j 1b`: Jumps to backward label `1`.
- `.section .tohost`: Spike communication section.
- `.align 3`: Aligns to 8-byte boundary.
- `.dword`: Allocates 64-bit integer.

### e2.c (C)
- `uint32_t`: 32-bit unsigned integer.
- `1U`: Unsigned 1 for shifts.
- `<<`, `>>`: Bitwise shift operators.
- `|`, `&`, `^`, `~`: Bitwise OR, AND, XOR, NOT.
- `printf`: Prints formatted output.
- `for (int i = 31; i >= 0; i--)`: Iterates over bits.
- `(number >> i) & 1`: Extracts bit value.