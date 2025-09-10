
---

# C Program: Macros and Student Records with File I/O (Task 3)

## Problem

This program demonstrates two main concepts in C:

1. **Task 3.1: Macros**

   * Implements macros for square, maximum of 2–4 numbers, and character case conversion.
   * Demonstrates how macros work with integer and character values.

2. **Task 3.2: Struct and File I/O**

   * Defines a `Student` structure with name, roll number, and GPA.
   * Stores 5 students in an array.
   * Finds and prints the student with the **highest GPA**.
   * Saves student records to a file (`students.txt`).
   * (Optional extension: read back records and print).

## Approach

### Task 3.1: Macros

* `SQUARE(x)` – Expands to `x*x`.
* `MAX2(a,b)` – Returns the maximum of two numbers using the ternary operator.
* `MAX3(a,b,c)` – Uses `MAX2` to find the maximum of three numbers.
* `MAX4(a,b,c,d)` – Uses `MAX3` to find the maximum of four numbers.
* `TO_UPPER(c)` – Converts a lowercase character to uppercase (ASCII-based).

### Task 3.2: File I/O with Structs

1. Define a `struct Student` containing:

   * `char name[50]`
   * `int roll`
   * `float gpa`
2. Initialize an array of 5 students.
3. Traverse array to find the student with the highest GPA.
4. Write all student records to `students.txt`.
5. Print the highest GPA on the console.

### Key Concepts Used

* **Macros** for inline code expansion.
* **Structs** for organizing student records.
* **File I/O (`fopen`, `fprintf`, `fclose`)** for saving student data.

## How to Run

1. Save the program in a file named `task3.c`.
2. Compile with GCC:

   ```bash
   gcc -o task3 task3.c
   ```
3. Run the program:

   ```bash
   ./task3
   ```

## Examples

### Example Run

```
Square of 5 = 25
Max2(5,6) = 6
Max3(5,6,17) = 17
Max4(5,6,17.8) = 17
To_UPPER(z) = Z
highest GPA = 3.8
```

### Output in `students.txt`

```
Name: x
Roll: 1
GPA: 3.000000

Name: y
Roll: 2
GPA: 3.800000

Name: z
Roll: 3
GPA: 3.200000

Name: a
Roll: 4
GPA: 3.100000

Name: b
Roll: 5
GPA: 3.600000
```

## Known Limitations

* `SQUARE(x)` macro does not use parentheses, so `SQUARE(a+1)` expands incorrectly (`a+1*a+1`).

## What I Verified

* Macro expansion correctness with integers and characters.
* GPA comparison logic works and finds the maximum GPA correctly.
* File writing produces the expected `students.txt` output.

## Sources & AI Usage

The program was written manually. AI assistance was used to prepare this `README.md` 

---
