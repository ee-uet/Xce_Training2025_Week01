
---

# C Program: Bitwise Operations & Power of 2 Check (Task 7)

## Problem

This program demonstrates the use of **bitwise operators** in C and includes a bonus task to check if a number is a power of 2.

It performs the following:

1. Reads two integers `x` and `y`.
2. Demonstrates bitwise **AND**, **OR**, **NOT**, and **left shift**.
3. Asks the user for another integer and checks if it is a power of 2.

## Approach

1. Read integers `x` and `y` from the user.
2. Compute:

   * `x & y` → Bitwise AND
   * `x | y` → Bitwise OR
   * `~x` → Bitwise NOT
   * `x << 2` → Left shift by 2
3. Read another integer from the user.
4. Check if the number is a power of 2 using the condition:

   ```
   (n > 0) && ((n & (n-1)) == 0)
   ```

   * If true → number is a power of 2.
   * Otherwise → not a power of 2.

### Key Concepts Used

* **Bitwise AND (`&`)**: Compares bits and returns 1 if both are 1.
* **Bitwise OR (`|`)**: Compares bits and returns 1 if at least one is 1.
* **Bitwise NOT (`~`)**: Flips all bits.
* **Bitwise Shift (`<<`)**: Shifts bits to the left by given positions.
* **Power of 2 Check**: Uses the property that powers of 2 have only one bit set.

## How to Run

To run this program:

1. Copy the code into a file named `task7.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task7 task7.c
   ```
3. Run the compiled executable:

   ```bash
   ./task7
   ```

## Examples

### Example 1: Bitwise Operations

```
Enter x: 5
Enter y: 3
x & y = 1
x | y = 7
~x = -6
x<<2 = 20
```

### Example 2: Power of 2 Check

```
is a power of 2: 16
is a power of 2
```

### Example 3: Not a Power of 2

```
is a power of 2: 18
is not a power of 2
```

## Known Limitations
* Input is not validated (non-integer input may cause errors).


## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to prepare this `README.md`

---
