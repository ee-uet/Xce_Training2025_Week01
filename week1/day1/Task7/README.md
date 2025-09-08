# Task 0.7 — Bitwise Operations

## Problem
1. Demonstrate the use of:
   - **AND (&)**
   - **OR (|)**
   - **XOR (^)**
   - **NOT (~)**
   - **Bit shifts (<<, >>)**
2. Write a function that checks if a number is a power of 2 using bitwise operators only.

## Approach
- Given `x = 5` and `y = 9`, print results of all bitwise operators.  
- To check power of 2:  
  - Use the property: A number `n` is power of 2 **iff** `(n & (n-1)) == 0` and `n > 0`.

## How to Run
    ```bash
    gcc t7.c -o t7
    ./t7
    
## Example Run
    x & y = 1
    x | y = 13
    x ^ y = 12
    ~x = -6
    x << 1 = 10
    x >> 1 = 2
    Enter any Integer: 16
    16 is a power of 2

## Known Limitations
- Uses int only (may not handle very large numbers).
- Negative inputs for power-of-2 check return "NOT power of 2".

## Sources & AI Usage
- The idea of checking (n & (n-1)) == 0 for power of 2 is a known bitwise trick.
