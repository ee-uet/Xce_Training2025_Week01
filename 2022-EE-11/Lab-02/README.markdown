# C Programming Tasks: Pointers, Arrays, and Advanced Concepts

## Problem
This project implements a series of C programming tasks focusing on pointers, arrays, strings, preprocessors, file I/O, linked lists, dynamic memory allocation, and Booth's multiplication algorithm. It demonstrates advanced C concepts for educational purposes.

## Approach
The tasks are organized into five parts, implemented as functions in a single C file (`main.c`):
- **Part 1: Pointer Basics and Arithmetic**
  - Task 1.1: Demonstrates pointer usage and modification.
  - Task 1.2: Swaps integers using pointers and bitwise XOR.
  - Task 1.3: Uses pointer arithmetic to process and reverse an array.
- **Part 2: Pointers and Arrays/Strings**
  - Implements custom `strlen`, `strcpy`, `strcmp`, and a case-insensitive palindrome checker using pointers.
- **Part 3: Preprocessor & File I/O**
  - Task 3.1: Uses macros for squaring, finding max values, and converting to uppercase.
  - Task 3.2: Handles student data with file I/O, storing and retrieving the top student by GPA.
- **Part 4: Advanced Challenge**
  - Implements a linked list with insertion, deletion, and printing functionality.
- **Part 5: Dynamic Memory Allocation**
  - Task 5.1: Dynamically allocates an array, computes sum and average.
  - Task 5.2: Extends an array using `realloc`.
  - Task 5.3: Tracks memory allocations to detect leaks.
- **Final Task: Booth's Multiplication**
  - Implements Booth's algorithm for multiplication using bitwise operations, with test cases for various scenarios.

The program uses standard C libraries (`stdio.h`, `string.h`, `stdlib.h`).

## How to Run
1. **Prerequisites**: Ensure a C compiler (e.g., `gcc`) is installed.
2. **Compile**: Run the following command:
   ```bash
   gcc -o tasks main.c
   ```
3. **Execute**: Run the compiled program:
   ```bash
   ./tasks
   ```
   The program executes the Booth's multiplication test by default. To test other tasks, uncomment the relevant function calls in `main()`.
4. **Interactive Tasks**:
   - Task 3.2 requires inputting student data (name, roll, GPA).
   - Task 4.1 provides a menu-driven linked list interface.
   - Task 5.1 and 5.2 require inputting array sizes and elements.

## Examples
### Sample Run (Booth's Multiplication)
```bash
$ gcc -o tasks main.c
$ ./tasks
AC: 0, QR: 12
Booth Multiply: 3 * 4 = 12
AC: 0, QR: 12
Booth Multiply: -3 * -4 = 12
AC: 0, QR: 0
Booth Multiply: 0 * 4 = 0
AC: -1953, QR: 138547332
Booth Multiply: -1000000 * 2000 = -2000000000
AC: 0, QR: 1
Booth Multiply: 2147483647 * 2147483647 = 1
```

### Example: Task 1.3 (Array Processing)
Uncomment `task1_3(arr, 5);` with `int arr[5] = {1, 2, 3, 4, 5};`:
```
Array elements: 1 2 3 4 5
Sum: 15
Reversed array: 5 4 3 2 1
```

### Example: Task 4.1 (Linked List)
Uncomment `task4_1_linkedlist();`:
```
1. Insert at beginning
2. Delete value
3. Print list
4. Exit
Enter your choice: 1
Enter value to insert: 10
Enter your choice: 1
Enter value to insert: 20
Enter your choice: 3
20 -> 10 -> NULL
Enter your choice: 4
Exiting...
```