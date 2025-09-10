# Task 1.3 — Pointer arithmetic on arrays

## Problem
Create a program that:
- Declares an array of integers.
- Prints all elements using pointer arithmetic.
- Calculates the sum of all elements.
- Reverses the array in-place using pointers.

## Approach
- Use a pointer (`ptrarr`) to traverse the array with arithmetic (`ptrarr + i`).
- For summation, iterate through the array and accumulate values.
- For reversal, use two pointers (`start` and `end`) and swap elements until they meet in the middle.

## How to Run
1. **Compile the program:**
   ```bash
   gcc task1_3.c -o out
   
2. **Run the executable:**
   ./out

## Test Cases
1. Default array {1,2,3,4,5}
Expected output:
Array: 1   2   3   4   5
Sum of array elements: 15
Reversed Array: 5   4   3   2   1
2. Array with all same elements {7,7,7}
Sum should be 21.
Reversal should not change the array.
3. Array with negative numbers {-1, 2, -3, 4}
Sum should be 2.
Reversed array should be {4, -3, 2, -1}.

## Example Output
Array: 1   2   3   4   5
Sum of array elements: 15
Reversed Array: 5   4   3   2   1

## Known Limitations
1. Array size is hardcoded; does not accept user input.
2. Only works for integer arrays; does not generalize to floats/structs without changes.
3. Reversal is in-place; original array order is lost.

