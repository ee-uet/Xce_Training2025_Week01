# RISC-V Assembly: Count Set Bits (Hamming Weight)

## Problem
This RISC-V assembly program counts the number of set bits (1s) in a 32-bit integer (`N = 15`) and stores the result in `Count`. It is designed to run on the Spike RISC-V simulator.

## Approach
The program:
- Defines `N` (input, 15) and `Count` (output, initially 0) in the `.data` section.
- Uses Brian Kernighan's algorithm to count set bits in the `.text` section.
- Stores the result in `Count` and signals completion for Spike.

## Walkthrough
1. **Data Section**:
   - `N: .word 15`: Stores the input integer (15, binary: `1111`).
   - `Count: .word 0`: Reserves space for the bit count.
2. **Text Section** (`_start`):
   - Loads `N` into `a0` and `Count` into `a1` using `la` (load address) and `lw` (load word).
   - **Loop**:
     - Computes `a2 = a0 - 1` (`addi a2, a0, -1`).
     - Performs `a0 = a0 & (a0 - 1)` (`and a0, a0, a2`), clearing the least significant set bit.
     - Increments `a1` (`addi a1, a1, 1`) to count the cleared bit.
     - Continues if `a0 != 0` (`bnez a0, loop`).
   - Stores the final count (`a1`) in `Count` using `sw` (store word).
3. **Spike Exit Code**:
   - Loads 1 into `t0` and stores it in `tohost` (`sd t0, (t1)`) to signal completion.
   - Enters an infinite loop (`j 1b`) if Spike does not exit.
4. **Tohost Section**:
   - Defines `tohost` and `fromhost` as 64-bit variables for Spike communication.

## How to Run
1. **Prerequisites**: Requires a RISC-V toolchain (`riscv64-unknown-elf-gcc`) and Spike simulator.
2. **Assemble**:
   ```bash
   riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c bitcount.S -o bitcount.o
   ```
3. **Link**:
   ```bash
   riscv64-unknown-elf-ld bitcount.o -o bitcount
   ```
4. **Run with Spike**:
   ```bash
   spike bitcount
   ```
5. **Inspect Result**:
   - The result is stored at the memory address of `Count`. Use a debugger or modify the program to output `a1` for verification.

## Examples
### Sample Run
For `N = 15` (binary: `1111`):
```bash
$ riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -c bitcount.S -o bitcount.o
$ riscv64-unknown-elf-ld bitcount.o -o bitcount
$ spike bitcount
```
- The program counts the set bits in 15 (`1111` has 4 ones).
- Stores `4` in `Count`.
- Exits via `tohost` signal.

To verify, use a debugger to check the `Count` memory location or modify the program to output `a1`.

## Syntactical Shorthands Explained
- `.section .data`: Defines the data section for initialized variables.
- `.word`: Allocates a 32-bit integer.
- `.global _start`: Declares `_start` as the program entry point.
- `.section .text`: Defines the code section.
- `la reg, label`: Loads the address of `label` into `reg`.
- `lw reg, offset(base)`: Loads a 32-bit word from `base + offset` into `reg`.
- `addi reg, src, imm`: Adds an immediate value to `src`, storing in `reg`.
- `and reg, src1, src2`: Performs bitwise AND of `src1` and `src2`, storing in `reg`.
- `bnez reg, label`: Branches to `label` if `reg` is not zero.
- `sw src, offset(base)`: Stores a 32-bit word from `src` to `base + offset`.
- `li reg, imm`: Loads an immediate value into `reg`.
- `sd reg, offset(base)`: Stores a 64-bit doubleword from `reg` to memory.
- `j 1b`: Jumps to the nearest backward label `1` (infinite loop).
- `.section .tohost`: Defines a section for Spike communication.
- `.align 3`: Aligns data to a 2^3 (8-byte) boundary.
- `.dword`: Allocates a 64-bit integer.