# Set / Clear Bit — C and Handwritten RISC-V Assembly

## Problem
- Write a program that can **set** or **clear** any bit in a 32-bit number.
- Provide both:
  - `t2.c` — C implementation.
  - `set_bit.s` — handwritten RISC-V assembly implementation.
- Build the C program to assembly using the toolchain, compare generated assembly vs handwritten, and run both on Spike to test.

## Approach
- Create a mask by shifting `1` left by the target bit index.
- To set a bit: `value |= (1 << bit)`.
- To clear a bit: `value &= ~(1 << bit)`.
- Implement the same logic in assembly using `slli` (shift left logical), `or`, `and`, and bitwise NOT (assembler pseudoinstruction `not` or `xori ...,-1`).
- Signal completion with the `tohost` mechanism so Spike can detect program end.

## How to Run
- Build C version (produces `division`-style program in your Makefile pattern; adapt as needed):
  ```bash
  make run1
  make run2
  make debug1
  make debug2
  
## Known Limitations
1. Programs use hardcoded bit indices (3 and 5) and a hardcoded initial value; adapt code to accept different bits as needed.

## Sources & AI Usage
1. Verified bit-manipulation idiom (value |= (1<<bit), value &= ~(1<<bit)) online.

