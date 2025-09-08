# RISC-V Assembly Exercise: Simple Subtraction

## Problem
The task is to:
- Implement a basic arithmetic operation in **RISC-V assembly**.
- Load two integers into registers `a0` and `a1`.
- Compute their difference and store it in `a2`.
- Properly exit the program when run on the **Spike simulator**.

## Approach
1. **Load values into registers**:
   ```asm
   li a0, 15   # Load 15 into register a0
   li a1, 10   # Load 10 into register a1
Perform subtraction:

sub a2, a0, a1  # a2 = a0 - a1


Exit for Spike:

li t0, 1
la t1, tohost
sd t0, (t1)
j 1b  # Infinite loop if Spike does not exit


Memory mapping: The .tohost section communicates with Spike for program exit.

## How to Run

Assemble and link the program:

make


Run the program on Spike:

make run


Debug with Spike using commit logging:

make debug


Clean generated files:

make clean

## Example Output

The program performs:

a0 = 15
a1 = 10
a2 = 5  # Result of a0 - a1


Spike exits successfully after writing to the .tohost address.

## Known Limitations

Requires riscv64-unknown-elf-as/ld toolchain.

Program designed for Spike; may not run correctly on other simulators or actual hardware without modifications.

No I/O or printing; results are stored in registers only.