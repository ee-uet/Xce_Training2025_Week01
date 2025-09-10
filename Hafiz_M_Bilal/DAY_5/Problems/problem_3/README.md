# RISC-V Assembly Exercise: Factorial Calculation

## Problem
Write a RISC-V assembly program that:
- Computes the factorial of a given number (`n!`).
- Uses a loop with multiplication and decrement instructions.
- Stores the final result in a register.

Example:  
For `n = 5`, the output should be `120`.

## Approach
1. **Initialization**:
```asm
li a0, 5     # Input number (n)
li t0, 1     # Result initialized to 1
Loop for factorial:

loop:
    mul t0, t0, a0     # Multiply result by current number
    addi a0, a0, -1    # Decrement number
    bnez a0, loop      # Repeat until a0 = 0


Exit for Spike:

li t0, 1
la t1, tohost
sd t0, (t1)
j 1b  # Infinite loop if Spike does not exit


The final factorial result is stored in t0.

## How to Run

Assemble and link:

make


Run with Spike:

make run


Debug with Spike:

make debug


Clean build:

make clean

## Example Output

For input 5:

t0 = 120  # Factorial of 5


Spike halts after writing to .tohost.

## Known Limitations

Input number is hardcoded (li a0, <value>); no runtime user input.

Factorial grows quickly; result may overflow 32-bit register for n > 12.

Works specifically with the Spike RISC-V simulator.

Output is stored in a register, not printed to console.