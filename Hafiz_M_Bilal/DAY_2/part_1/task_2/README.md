# Task 1.2 – Swap Two Integers Using Pointers

## Problem
- Write a function to swap the values of two integers using pointers.  
- Print the values before and after swapping to verify correctness.  

---

## Approach
1. Define a function `swap(int *a, int *b)` that takes two integer pointers.  
2. Print the initial values of the integers (before swap).  
3. Use a temporary variable to swap values through pointers:
   - `temp = *b`  
   - `*b = *a`  
   - `*a = temp`  
4. Print the updated values (after swap).  
5. In `main()`, declare two integers, initialize them, and call `swap()` by passing their addresses.  

---

## How to Run
1. Save the code in a file, e.g., `task1_2.c`.  
2. Compile the program:  
   ```bash
    gcc task1_2.c -o task1_2
    ./task1_2

## Example Output
Before swap
int_1: 5
int_2: 10
After swap
int_1: 10
int_2: 5

## Known Limitations

Only works for integers (not generalized for other data types).

No input from user; values are hardcoded in main().

Swapping through pointers requires valid memory addresses (no NULL checks).