# RISC-V Assembly Exercise: Count Set Bits

## Problem
The task is to:
- Count the number of `1`s in a binary number using **RISC-V assembly**.
- Use basic instructions: `andi`, `add`, `srli`, and conditional branches.
- Store the result in register `t0`.

## Approach
1. **Initialize registers**:
```asm
li a0, 0b101101  # Binary number to count set bits
li t0, 0          # Counter initialized to 0
Loop to count set bits:

loop:
    andi t1, a0, 1  # Isolate LSB
    add t0, t0, t1  # Increment counter if LSB is 1
    srli a0, a0, 1  # Right shift to next bit
    bnez a0, loop   # Continue if remaining bits exist
Exit for Spike:


li t0, 1
la t1, tohost
sd t0, (t1)
j 1b  # Infinite loop if Spike does not exit
Memory mapping: The .tohost section communicates with Spike for program exit.

## How to Run
Assemble and link the program:
make

Run on Spike:
make run

Debug with commit logging:
make debug

Clean generated files:
make clean

Example Output
For the binary number 0b101101:

t0 = 4  # Number of set bits
Spike exits successfully after writing to the .tohost address.

## Known Limitations
Requires riscv64-unknown-elf-as/ld toolchain.

Designed specifically for Spike; may not work on other simulators or hardware.

No console output; result is stored in register t0.