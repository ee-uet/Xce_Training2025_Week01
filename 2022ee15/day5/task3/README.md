# Non-Restoring Division — C and Handwritten RISC-V Assembly

## Problem
- Implement non-restoring division to compute quotient and remainder for unsigned 32-bit operands.
- Provide two implementations:
  - `division_nonrestoring.c` — C implementation (provided).
  - `nonrestoring.s` — handwritten RISC-V assembly implementation (provided).
- Use the toolchain to generate assembly from the C code and compare the compiler-generated assembly with your handwritten assembly for optimization.
- Run both versions on Spike and verify results.

## Approach
- Maintain an accumulator `A`, dividend register `Q`, and divisor `M`.
- For each of 32 iterations:
  - Shift `A` left, bring in MSB of `Q`.
  - If previous `A` was negative, `A = A + M`; else `A = A - M`.
  - Shift `Q` left and set its LSB to 1 if `A >= 0`, otherwise clear it.
- After loop, if `A < 0`, restore remainder with `A = A + M`.
- Use HTIF `/tohost` to signal the end of program execution under Spike.

## How to Run
- Build both targets (assuming your Makefile has appropriate rules):
  ```bash
  make run1
  make run2
  make debug1
  make debug2
 
## Known Limitations
1. Inputs are hardcoded in both files (no runtime inputs).
2. No divide-by-zero handling. Behavior is undefined if divisor == 0.

## Sources & AI Usage
1. Checked non-restoring division algorithm examples and C semantics online.

