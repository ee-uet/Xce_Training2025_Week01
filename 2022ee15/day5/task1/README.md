# Restoring Division 

## Problem
- Implement restoring division to compute quotient and remainder for unsigned 32-bit operands.
- Build both:
  - `division` — compiled from the provided C code (produces assembly when compiled).
  - `t1` — handwritten RISC-V assembly implementation.
- Compare generated assembly (from the C toolchain) vs handwritten assembly for optimization.
- Run both programs on Spike to verify behavior.

## Files
- `division.c` — C implementation of restoring division (provided).
- `t1.s` — handwritten RISC-V assembly (provided).
- `Makefile` — builds both targets (`t1` and `division`) and provides run/debug targets.

## How to Run
- Build everything:
  ```bash
  make run1
  make run2
  make debug1
  make debug2
  
## Test Cases
Example: Dividend = 13, Divisor = 3
Quotient = 4
Remainder = 1
Both handwritten and C-compiled versions should produce the same result.

## Known Limitations
1. Inputs (dividend = 13, divisor = 3) are hardcoded in both codes.
2. No user input/output handling, only HTIF exit to Spike.
3. Only works for non-zero divisors (no divide-by-zero handling).

## Sources & AI Usage
1. Checked the restoring division algorithm and equivalent C implementations online.
