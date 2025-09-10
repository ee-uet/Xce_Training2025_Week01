# RISC-V Assembly Lab

## Overview

This RISC-V assembly lab contains programs demonstrating fundamental assembly concepts including arithmetic operations, function calls, recursion, array manipulation, sorting algorithms, and advanced division techniques using the Spike RISC-V simulator.

## Structure

```
Day05_RiscvAssembly_Spike/
├── example
├── problem1
|   ├── lab6_p1.s
|   └── Makefile
├── problem2
|   ├── lab6_p2.s
|   └── Makefile
├── problem3
|   ├── lab6_p3.s
|   └── Makefile
├── problem4
|   ├── lab6_p4.s
|   └── Makefile
├── problem5
|   ├── lab6_p5.s
|   └── Makefile
├── task1
|   ├── lab6_t1.s
|   ├── lab6_t1.c
|   └── Makefile
├── task2
|   ├── lab6_t2.s
|   ├── lab6__t2.c
|   └── Makefile
└── task3
    ├── lab6_t3.s
    ├── lab6__t3.c
    └── Makefile
```

## Tasks

### Problem 1 - Absolute Difference
**Problem**: Calculate absolute difference between two numbers and store result in memory.
**Approach**: Use branch instructions to check sign, negate if negative, then store bytes in memory starting at 0x10000000.

### Problem 2 - Count Ones in Binary
**Problem**: Count number of 1s in binary representation of a number.
**Approach**: Use bitwise AND with 1, right shift, and loop through all bits while counting.

### Problem 3 - Recursive Factorial
**Problem**: Calculate factorial using recursive function calls.
**Approach**: Implement stack-based recursion with proper stack frame management using function prologue and epilogue.

### Problem 4 - Array Reversal
**Problem**: Reverse array elements in-place.
**Approach**: Use two pointers from start and end, swap elements, move pointers inward until they meet.

### Problem 5 - Insertion Sort
**Problem**: Sort array using insertion sort algorithm.
**Approach**: Iterate through array, insert each element in correct position among previously sorted elements.

### Task 1 - Restoring Division
**Problem**: Implement restoring division algorithm.
**Approach**: Use bit-by-bit division with remainder restoration when negative.

### Task 2 - Bit Manipulation
**Problem**: Set or clear specific bit in a number.
**Approach**: Use shift operations and bitwise OR/AND operations for bit setting/clearing.

### Task 3 - Non-Restoring Division
**Problem**: Implement non-restoring division algorithm.
**Approach**: Use conditional addition/subtraction without restoring remainder at each step.

## How to Run

### Prerequisites
```bash
# Install RISC-V toolchain and Spike simulator
sudo apt-get install gcc-riscv64-unknown-elf spike
```

### Compilation and Execution
```bash
# Compile and run specific program
make PROG=lab6_p1 run

# Debug with Spike
make PROG=lab6_p1 debug

# Compile C to assembly
make ARG=lab6_t1 gcc

# Clean build files
make clean
```

### Individual Commands
```bash
# Assemble
riscv64-unknown-elf-as -o lab6_p1.o lab6_p1.s

# Link
riscv64-unknown-elf-ld -T link.ld -o lab6_p1 lab6_p1.o

# Run with Spike
spike lab6_p1
```

## Examples

### Problem 1 - Absolute Difference
```assembly
li t1, 5        # First number
li t2, 7        # Second number
sub t3, t1, t2  # Calculate difference
blt t3, zero, negate  # Branch if negative
```

### Problem 4 - Array Reversal
```assembly
reverse_array:
    mv t3, a0             # Save start address
    
while:
    bge a0, a1, return    # Check if pointers crossed
    lw t0, 0(a0)          # Load from start
    lw t1, 0(a1)          # Load from end
    sw t0, 0(a1)          # Store start value at end
    sw t1, 0(a0)          # Store end value at start
    addi a0, a0, 4        # Move start pointer forward
    addi a1, a1, -4       # Move end pointer backward
    j while
```

### Task 1 - Restoring Division
```assembly
restoring_division:
    slli t0, t0, 1        # R = R << 1
    or t0, t0, s2         # R = R | msb
    sub t0, t0, t2        # R = R - divisor
    blt t0, zero, restore # Restore if negative
    or t3, t3, s0         # Set quotient bit
```

### Task 2 - Bit Manipulation
```assembly
bit_manipulation:
    beq a3, zero, clear_op # Check operation type
    sll a3, a3, a1        # Shift bit position
    or a0, a0, a3         # Set bit using OR
    ret

clear_op:
    addi a3, a3, 1        # Make mask
    sll a3, a3, a1        # Shift to position
    not a3, a3            # Invert mask
    and a0, a0, a3        # Clear bit using AND
    ret
```
