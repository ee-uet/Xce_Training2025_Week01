# Booth Multiplier — Sequential Booth Algorithm in C

## Problem
Implement Booth's multiplication algorithm in C:
- Write a function that multiplies two signed 32-bit integers using Booth's algorithm.
- Handle edge cases (positive, negative, zero, INT_MIN/INT_MAX).
- Provide unit tests to verify correctness.

## Approach
- Implement a 64-bit bitwise adder helper `add64()` using XOR/AND carry propagation so add operations are explicit.
- Use `two_complement64()` to compute two's complement of the multiplicand when needed.
- Maintain `AC` (accumulator) and `Q` (multiplier) as signed 64-bit values to preserve sign during shifts.
- Use a `__int128` combined register to perform an arithmetic right shift of `AC:Q` reliably and extract back `AC` and `Q`.
- Run 32 iterations (n = 32) following Booth's decision table using `Q0` and `Q-1`.
- Combine final `AC` (upper 32 bits) and `Q` (lower 32 bits) into a 64-bit result.

## How to Run
1. **Compile**
    ```bash
    gcc booth_multiplier.c -o out
    ./out
    
## Test Cases
    6 * 3 → 18
    -6 * 3 → -18
    6 * -3 → -18
    -6 * -3 → 18
    0 * 12345 → 0
    67890 * 0 → 0
    0 * 0 → 0
    123 * 1 → 123
    -123 * 1 → -123
    123 * -1 → -123
    -123 * -1 → 123
    INT_MAX * 1 → INT_MAX
    INT_MIN * 1 → INT_MIN
    INT_MAX * INT_MAX → large 64-bit product
    
## Known Limitations
1. Uses __int128 for combined shifting — requires a compiler that supports __int128 (GCC / Clang on typical Linux toolchains).

## Sources & AI Usage
1. Checked Booth's algorithm descriptions and logic for __int128 for combined shifting.
