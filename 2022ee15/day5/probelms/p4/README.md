# Problem 4: Reverse an Array (RISC-V Assembly)

## Problem Statement
Implement a RISC-V assembly program to reverse an array in-place.

## Approach
- Use two pointers:
  - **t0** points to the start of the array.
  - **t4** points to the last element of the array.
- Swap elements at these two positions.
- Move `t0` forward and `t4` backward after each swap.
- Stop when `t0 >= t4`.

This ensures the array is reversed in-place.

## Code Explanation
- `.data` section defines the array and its length.
- `t0` starts at the beginning of the array.
- `t4` is computed as the address of the last element.
- Inside the loop:
  - Compare `t0` and `t4` to decide when to stop.
  - Swap elements between `t0` and `t4`.
  - Increment/decrement pointers to continue.
- When the loop ends, the array is reversed.

## How to Run
    ```bash
    make run
    make debug
    
## Known Limitations
1. Array length must be defined in .data as a word.
2. Works only for word-sized elements.

## Sources & AI
1. Used AI help to confirm the correct placement of the loop termination condition (bge t0, t4, done).
2. Took the concept of defining the array and its length in the .data section.

