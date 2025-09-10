# Task 1.2 — Swap two integers using pointers

## Problem
Write a program to swap two integers using pointers:
- Implement a function `swap(int *a, int *b)` that exchanges the values of two integers.
- Demonstrate the swap in `main()` with example variables.

## Approach
- Use pointers so that changes in the function are reflected in the original variables.
- Store the first value in a temporary variable.
- Assign the second value into the first variable.
- Move the temporary value into the second variable.

## How to Run
1. **Compile the program**:
   ```bash
   gcc task1_2.c -o out
   
2. **Run the executable:**
    ./out

## Test Cases
1. Initial test
Input: x = 5, y = 10
Expected: After swap, x = 10, y = 5
2. Equal numbers
Input: x = 7, y = 7
Expected: After swap, x = 7, y = 7 (no change)
3. Negative values
input: x = -3, y = 12
Expected: After swap, x = 12, y = -3

## Example Output
Before swap: x = 5, y = 10
After swap: x = 10, y = 5

## Known Limitations
1. Works only for integers. For other data types, the function would need adjustment or use of void *.
2. Does not handle arrays or structures (this is a simple demonstration).

