# Restoring Division (RISC-V Assembly + C)

This project implements the **restoring division algorithm** in both:
- **RISC-V Assembly** (`task_1_as.s`)
- **C implementation** (`task_1.c`)

It also provides a `Makefile` to build and run both versions using the RISC-V toolchain and Spike simulator.

---
## Approach

Algorithm (Restoring Division)

The algorithm divides an unsigned integer dividend by a divisor using bitwise shifts and subtraction:

Initialize:

A = 0 (remainder)

Q = dividend

M = divisor

Repeat for n bits (e.g., 32 times for 32-bit division):

Left shift A and bring down MSB of Q.

Left shift Q.

Subtract M from A.

If result is negative → restore A and clear LSB of Q.

Else → keep A and set LSB of Q.

After loop, Q = quotient, A = remainder.

## Files

- `task_1_as.s` → Restoring division written fully in RISC-V Assembly.
- `task_1.c` → Restoring division written in C (compiled with RISC-V GCC).
- `start.s` → Startup file required for C programs when building bare-metal.
- `link.ld` → Linker script used for building RISC-V executables.
- `Makefile` → Automates build, run, debug, and cleanup.

---

## Requirements

- **RISC-V Toolchain**  
  (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`, `riscv64-unknown-elf-gcc`)
- **Spike Simulator** (`spike`)
- **Proxy Kernel** (`pk`) – needed to run C programs with `main()`.

---

## Build Instructions

### 1. Build Assembly version
```bash
make task_1_as

2.Build Assembly + Startup version
make task_1

3. Build C version
make task_1_c

## Run Programs

Run Assembly only:

make run1


Run C file Assembly :

make run2

Debugging

To debug with Spike (view instruction commits):

Assembly:

make debug1


C file Assembly:

make debug2

Clean Build Files
make clean

## Example

Dividend = 37

Divisor = 5

Expected Result:
Quotient = 7
Remainder = 2

Both the assembly and C implementations produce the same result.

## Limitations

Unsigned only: This implementation works only for unsigned integers. Signed division needs extra handling for negative numbers.

Fixed bit-width: Algorithm assumes 32-bit operands. For 64-bit, loop count and register usage must be modified.

Inefficiency: Requires one iteration per bit (32 cycles for 32-bit). Modern CPUs use faster division algorithms (non-restoring, SRT, Newton-Raphson).

Divide by zero: No check for divisor = 0, which would cause incorrect results.

No overflow handling: Edge cases like maximum dividend (0xFFFFFFFF) with divisor = 1 are not optimized.

Bare-metal only: The assembly version is written for bare-metal execution under Spike, not for Linux user space.

## Sources & AI Usage

This RISC-V assembly division code was AI-assisted (ChatGPT). I used AI to understand:

How to implement division using shifting and subtraction (restoring division).

How to track quotient (t2) and remainder (t3) while processing each bit.

How to use looping with bit count (t4) for 32-bit division.

How to finalize the quotient and remainder and terminate using .tohost.

The algorithm structure was explained by AI.

## What I Verified

I verified the correctness by:

Using dividend = 25, divisor = 3.

Output quotient = 8, remainder = 1.

Checked edge cases:

Dividend smaller than divisor (e.g., 2 ÷ 5) → quotient = 0, remainder = 2.

Dividend = 0 → quotient = 0, remainder = 0.

Divisor = 1 → quotient equals dividend, remainder = 0.

Verified that the loop runs exactly 32 iterations (for 32-bit numbers).

Ensured program terminates cleanly with .tohost.

## link for youtube video
https://youtu.be/6ToR6vuRb3M?si=sXBUJZK9qFnS2D5T