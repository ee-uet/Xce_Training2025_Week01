# Task 5.2 – Dynamic Array Extension with realloc

## Problem
Write a C program that:
1. Dynamically allocates memory for an integer array of user-defined size.
2. Allows the user to input initial elements.
3. Extends the array using `realloc` by asking for extra elements.
4. Prints both the original and extended arrays.
5. Frees the allocated memory.

---

## Approach
- Used `malloc` to allocate memory for `n` integers.
- Collected `n` elements from the user.
- Used `realloc` to extend the array to size `n + m`.
- Stored the new `m` elements at the end of the array.
- Printed the full extended array.
- Freed allocated memory using `free()`.

---

## How to Run
1. Save code in `task5_2.c`.
2. Compile:
   ```bash
   gcc task5_2.c -o task5_2
   ./task5_2

## Example Run
Input:
Enter number of elements of an array: 3
Enter 1th number: 10
Enter 2th number: 20
Enter 3th number: 30
Original array: 10 20 30
Enter number of Extra elements to append in an array: 2
Enter 4th number: 40
Enter 5th number: 50

Output:
Original array: 10 20 30
Extended array: 10 20 30 40 50


## Known Limitations & Edge Cases

If malloc or realloc fails → prints error message and exits function.

If m = 0 → array remains unchanged.

Works with any positive n.