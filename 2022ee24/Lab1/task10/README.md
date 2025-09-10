
---

# C Program: Command-Line Sum (Task 10)

## Problem

This program demonstrates how to use **command-line arguments** in C.
It accepts **two integers** as command-line arguments, computes their sum, and prints the result.

## Approach

1. Use `argc` (argument count) and `argv` (argument vector) to access command-line arguments.
2. Validate that only two arguments are provided (besides the program name).
3. Convert the string arguments to integers using `atoi()`.
4. Compute the sum and display it.

### Key Concepts Used

* **Command-Line Arguments (`argc`, `argv`)**: To pass values when running the program.
* **`atoi()` Function**: Converts strings to integers.
* **Basic Input Validation**: Ensures only two arguments are provided.

## How to Run

1. Copy the code into a file named `task10.c`.
2. Compile the program:

   ```bash
   gcc -o task10 task10.c
   ```
3. Run the program with two integer arguments:

   ```bash
   ./task10 12 8
   ```

## Examples

### Example 1: Valid Input

```
$ ./task10 5 10
sum = 15
```

### Example 2: Too Many Arguments

```
$ ./task10 5 10 20
Error! only 2 arguments can be passed
sum = 15
```

*(Note: The program still computes the sum of the first two arguments.)*

### Example 3: Negative Numbers

```
$ ./task10 -7 3
sum = -4
```

## Known Limitations

* No error handling for missing arguments (e.g., running `./task10` without numbers may cause undefined behavior).
* No validation for non-numeric inputs (e.g., `./task10 a b` will return `0` since `atoi("a") = 0`).
* Still prints a sum even when more than two arguments are given (uses only the first two).

## What I Verified

* Program correctly reads two integers and prints their sum.
* Works with both positive and negative integers.
* Detects when too many arguments are given.

## Sources & AI Usage

The program was written manually. AI assistance was used to prepare this `README.md`

---
