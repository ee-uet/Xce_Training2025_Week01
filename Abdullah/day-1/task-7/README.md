# Task 7: Bitwise Operations

## Problem
Write a program that demonstrates:
- AND &, OR |, XOR ^, NOT ~, and bit-shifting <<, >>
- Example: Given x = 5, y = 9, show results of x & y, x | y, etc.
- Write a function that checks if a number is power of 2 using bitwise operators only

## Approach
1. Initialize two integer variables (x=8, y=16)
2. Demonstrate all bitwise operations with these values
3. Get user input for power of 2 checking
4. Use bitwise trick: (n & (n-1)) == 0 for power of 2 check

## How to Run

### Compilation
```bash
gcc -o bitwise_ops bitwise_ops.c
```

### Execution
```bash
./bitwise_ops
```

## Example Output
```
x & y 0
x | y = 24
x ^ y = 24
~x = -9
x << 1 = 16
x >> 1 = 4
Enter number: 8
8 number is the power of 2
```

## Design Notes
- Uses predefined values x=8, y=16 for demonstrations
- Power of 2 check uses efficient bitwise method
- Demonstrates all basic bitwise operations

## Bitwise Operations Explained
- **AND (&)**: Returns 1 if both bits are 1
- **OR (|)**: Returns 1 if at least one bit is 1  
- **XOR (^)**: Returns 1 if bits are different
- **NOT (~)**: Flips all bits (bitwise complement)
- **Left Shift (<<)**: Shifts bits left, equivalent to multiply by 2
- **Right Shift (>>)**: Shifts bits right, equivalent to divide by 2

## Power of 2 Algorithm
A number n is power of 2 if:
- n > 0 AND
- (n & (n-1)) == 0

This works because powers of 2 have only one bit set, and subtracting 1 flips all bits after and including that bit.

## Assumptions & Edge Cases
- Handles positive numbers for power of 2 check
- Zero and negative numbers correctly identified as not power of 2

## Known Limitations
- No input validation for integer input
- Hardcoded demonstration values

## Sources & AI Usage
- Original template code from lab manual
- Classic bitwise power of 2 checking algorithm
- Looked on Google for power of 2 checking method and bitwise operations syntax
- No AI assistance for bitwise operations logic