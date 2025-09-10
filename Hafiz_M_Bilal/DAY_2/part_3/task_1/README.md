# Task 3.1 – Macros Demonstration

## Problem
Write a C program that demonstrates the use of **macros** for:
1. Calculating the square of a number.
2. Finding maximum of 2, 3, and 4 numbers.
3. Converting a lowercase character to uppercase.

---

## Approach
- Defined the following macros:
  - `SQUARE(x)` → computes square of `x`.
  - `MAX2(a,b)` → returns maximum of two values.
  - `MAX3(a,b,c)` → uses nested `MAX2` to find maximum of three.
  - `MAX4(a,b,c,d)` → uses `MAX3` and `MAX2` to find maximum of four.
  - `TO_UPPER(c)` → converts a lowercase character to uppercase, leaves other characters unchanged.
- Demonstrated macros with test cases inside `task3_1_macros()`.

---

## How to Run
1. Save code in a file, `task3_1.c`.
2. Compile:
   ```bash
   gcc task3_1.c -o task3_1
    ./task3_1

## Example Output
SQUARE(5) = 25
MAX2(5, 10) = 10
MAX3(5, 10, 3) = 10
MAX4(5, 10, 3, 15) = 15
TO_UPPER('a') = A
TO_UPPER('Z') = Z

## Known Limitations

SQUARE(x) can give unexpected results if x is an expression (e.g., SQUARE(1+2) → expands incorrectly).

TO_UPPER only works for ASCII lowercase letters ('a'–'z').

MAX macros may evaluate arguments multiple times, causing side effects if arguments contain function calls or increments.