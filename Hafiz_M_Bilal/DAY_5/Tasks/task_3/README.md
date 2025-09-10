# Non-Restoring Division (RISC-V Assembly + C)

This project demonstrates **non-restoring division** for unsigned integers using both:

- **C Implementation** (`non_restoring_division.c`)
- **RISC-V Assembly Implementation** (`non_restoring_division.S`)

It also provides a `Makefile` to assemble, link, run, and debug the programs using the RISC-V toolchain and Spike simulator.

---
## Approach
Algorithm (Non-Restoring Division)

Initialize:

A = 0 (Accumulator)

Q = dividend

M = divisor

n = 32 (bit-width)

Repeat for each bit (MSB to LSB):

Shift A left by 1 and bring in MSB of Q.

If A < 0, A = A + M; else A = A - M.

Shift Q left by 1.

If A >= 0, set LSB of Q to 1; else set to 0.

After loop, if A < 0, correct A = A + M.

Result:

quotient = Q

remainder = A

C implementation mirrors this logic using bitwise operators and signed checks.

## Files

- `non_restoring_division.c` → C implementation of the algorithm.
- `non_restoring_division.S` → Assembly implementation callable from `_start`.
- `start.s` → Startup file for bare-metal C execution.
- `link.ld` → Linker script for building RISC-V executables.
- `Makefile` → Automates build, run, debug, and clean targets.

---

## Requirements

- **RISC-V Toolchain** (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`, `riscv64-unknown-elf-gcc`)
- **Spike Simulator** (`spike`)

---

## Build Instructions

### 1. Build Assembly version
```bash
## Run Programs

Run Assembly only:

make run1


Run c file Assembly:

make run2

debug Assembly only:

make debug1


debug c file Assembly:

make debug2

##Example

Dividend: 50, Divisor: 7

C result:

Quotient = 7

Remainder = 1

Assembly result: Same values stored in registers a0 (quotient) and a1 (remainder). 

## Limitations

Unsigned division only: Negative dividends or divisors are not supported.

Fixed 32-bit integers: Algorithm is hardcoded for 32-bit numbers; larger numbers require modification.

Bare-metal only: Assembly version is designed for Spike; not portable to standard Linux without syscall modifications.

Performance: Bit-by-bit iterative method; not optimized for speed.

No input validation: No runtime check for division by zero.

## Sources & AI Usage

This non-restoring division code was AI-assisted (ChatGPT). I used AI to understand:

How to implement non-restoring division using bit shifts and conditional addition/subtraction.

How to track quotient (a0) and remainder (a1) across iterations.

How to manage sign handling for the remainder (A register) in each loop iteration.

How to exit cleanly using the .tohost memory-mapped section.

The structure was AI-guided.

What I Verified

I verified the correctness by:

Running with dividend = 50, divisor = 7 → quotient = 7, remainder = 1.

Tested edge cases:

Dividend smaller than divisor → quotient = 0, remainder = dividend.

Dividend = 0 → quotient = 0, remainder = 0.

Divisor = 1 → quotient equals dividend, remainder = 0.

Ensured loop runs 32 iterations for 32-bit numbers.

Checked that the program exits cleanly via .tohost.

## link for you tube video
https://youtu.be/f6A3ySUdT80?si=fBYNKNULm-Knteuv