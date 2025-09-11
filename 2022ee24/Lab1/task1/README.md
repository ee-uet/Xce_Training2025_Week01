
---

# C Program: Data Types and Type Casting (Task 1)

## Problem

The goal of this task is to demonstrate the usage of various data types in C and how to perform type casting. The program will:

1. Declare variables of different data types: `int`, `float`, `double`, and `char`.
2. Print their sizes using the `sizeof` operator.
3. Demonstrate type casting by converting a `double` to an `int`.

## Approach

This task introduces basic C data types and their sizes. The program:

1. Declares an `int`, `float`, `double`, and `char` variable and initializes them with example values.
2. Uses the `sizeof` operator to print the sizes of these variables.
3. Demonstrates type casting by converting a `double` value to an `int`.

### Key Concepts Used:

* **`int`**: Integer type, used for storing whole numbers.
* **`float`**: Floating-point type, used for decimal numbers with single precision.
* **`double`**: Double-precision floating-point type, used for higher precision floating-point numbers.
* **`char`**: Character type, used for storing individual characters.
* **Type Casting**: Converting one data type to another, like converting a `double` to an `int`.

## How to Run

To run this program:

1. Copy the code into a file named `task1.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task1 task1.c
   ```
3. Run the compiled executable:

   ```bash
   ./task1
   ```

## Examples

After running the program, the output will display the sizes of the data types and demonstrate type casting:

```text
size of var1: 4
size of var2: 4
size of var3: 8
size of var4: 1
var2 = 10.000000
var3 = 3.333333
var3 = 3    \type casted to int
```

* The size of `var1` (an `int`) is typically 4 bytes on most systems.
* The size of `var2` (a `float`) is also 4 bytes.
* The size of `var3` (a `double`) is typically 8 bytes.
* The size of `var4` (a `char`) is 1 byte.
* The program casts the `double` value `var3` to an `int`, printing its truncated integer value (`3`).

## Known Limitations

* The program assumes that the system's architecture follows typical sizes for these data types (e.g., 4 bytes for `int` and `float`, 8 bytes for `double`, and 1 byte for `char`). These sizes can vary on different platforms.
* The program demonstrates type casting but does not handle potential errors like overflow when casting larger numbers or precision loss in floating-point operations.

## Sources & AI Usage

The program was written from scratch to demonstrate fundamental concepts in C. The code logic and explanation are based on standard practices for working with data types and type casting in C. AI assistance was used to help structure this `README.md`.

---

