
---

# C Program: Pointer Basics (Task 1)

## Problem

This program demonstrates different pointer-related concepts in C through three subtasks:

1. **Task 1.1** – Basic pointer usage:

   * Declare an integer variable and a pointer to it.
   * Access and modify the variable using the pointer.

2. **Task 1.2** – Swap two integers:

   * Implement a `swap` function that swaps values of two integers using pointers.

3. **Task 1.3** – Pointer arithmetic on arrays:

   * Take an array as input.
   * Print elements using pointer arithmetic.
   * Calculate and print the sum of elements.
   * Reverse the array in place using pointers.

## Approach

### Task 1.1

* Create an integer variable `n`.
* Create a pointer `ptr` to `n`.
* Print the value of `n` directly and through the pointer.
* Modify `n` through the pointer and print again.

### Task 1.2

* Use a `swap` function that takes two integer pointers.
* Use a temporary variable to swap values.

### Task 1.3

1. Declare an integer array and read values from user input.
2. Use a pointer to traverse and print elements via pointer arithmetic.
3. Compute the sum of all elements.
4. Reverse the array in place using pointer swaps.
5. Print the reversed array.

### Key Concepts Used

* **Pointers** – Direct memory access and dereferencing.
* **Pass by Reference** – Using pointers to modify variables outside a function.
* **Pointer Arithmetic** – Traversing arrays via pointers instead of indices.
* **In-Place Operations** – Reversing arrays without extra memory.

## How to Run

1. Save the code into a file named `task1.c`.

2. Compile the program:

   ```bash
   gcc -o task1 task1.c
   ```

3. Run the program:

   ```bash
   ./task1
   ```

## Examples

### Example Run

```
n = 10
n = 10
n = 20
a = 5 , b = 10
a = 10 , b = 5
Enter element0: 1
Enter element1: 2
Enter element2: 3
Enter element3: 4
Enter element4: 5
Enter element5: 6
Enter element6: 7
Enter element7: 8
Enter element8: 9
1 2 3 4 5 6 7 8 9 
Sum = 45
9 8 7 6 5 4 3 2 1
```

## Known Limitations

* The array size is fixed at 9 elements; it is not dynamically allocated.
* No input validation for non-integer inputs.
* Reverse function works only for the fixed array length in this program.

## What I Verified

* Pointer dereferencing and modification in **Task 1.1**.
* Swapping integers works correctly in **Task 1.2**.
* Pointer arithmetic correctly accesses and reverses array elements in **Task 1.3**.
* Edge case verified: reversal works for both odd and even-sized arrays.

## Sources & AI Usage

The program was written manually for practice. AI was used to generate this `README.md`

---
