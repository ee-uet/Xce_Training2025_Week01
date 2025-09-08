# Task Y: Sequential Multiplier in C with Unit Tests

## Problem
- Implement Booth's multiplication algorithm in C.
- Use separate helper functions for shifting and adding so function-call flow can be visualized.
- The function should take two signed 32-bit integers and return their 64-bit product.
- Use bit-manipulation operators for efficient multiplication.
- Provide unit tests covering positive, negative, zero, multiplication by 1/0 and edge cases (including `INT_MIN`).

## Approach
- Implement a 64-bit bitwise adder helper (`add64`) using XOR/AND carry iterations to avoid relying on `+` (makes the add operation visible).
- Implement `two_compliment64` to compute two's complement in 64-bit space.
- Implement `arithmetic_right_shift` to shift the combined `AC:Q` register. This final version uses a `__int128` intermediate to reliably preserve sign during arithmetic right shifts and avoid corner-case bugs (e.g., `INT_MIN`).
- Use `n = 32` iterations of Booth's algorithm:
  - Inspect `Q0` and `Q1` to decide add/subtract.
  - Use `add64()` for arithmetic.
  - Perform an arithmetic right shift of `AC:Q`.
- Combine the final `AC` (upper 32 bits) and `Q` (lower 32 bits) into a signed 64-bit result and return it.
- Provide `test_booth()` which runs a set of canonical test cases and prints expected vs actual results.

## How to Run
1. **Compile the program:**
   ```bash
   gcc -std=c11 -O2 -Wall -Wextra booth_multiplier.c -o out
2. **Run the tests:**
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
INT_MIN * 1 → INT_MIN (fixed via 64-bit internals + __int128 shift)
INT_MAX * INT_MAX → large 64-bit product (verify expected value)

## Example Output
6 * 3 = 18 (expected 18)
-6 * 3 = -18 (expected -18)
...
INT_MIN * 1 = -2147483648 (expected -2147483648)
INT_MAX * INT_MAX = 4611686014132420609 (expected 4611686014132420609)

## Known Limitations
1. Implementation assumes int64_t and __int128 are supported by your compiler (GCC/Clang support this).
2. Uses fixed n = 32 bit width for the Booth algorithm. To support other widths adjust n and types accordingly.
3. add64() operates in 64-bit; detecting overflow beyond 64-bit (true mathematical overflow) is not implemented.
4. This is an educational implementation; in production use hardware multiply or compiler intrinsics for performance/robustness.

## Sources & AI Usage
1. Implementation follows standard descriptions of Booth's algorithm.
2. I used __int128 for robust sign-preserving shifts to handle edge cases like INT_MIN.
3. Minor assistance from ChatGPT was used to review edge cases and style; all logic and verification were validated by running unit tests locally.

