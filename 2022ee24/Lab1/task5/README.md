
---

# C Program: Reverse String & Find Second Largest (Task 5)

## Problem

This program implements two tasks:

1. **Reverse String**
   Reverses a user-input string without using built-in string library functions.

2. **Find Second Largest Element**
   Finds and prints the largest and second-largest elements in a fixed integer array.

## Approach

### Reverse String

1. Read a string from the user into a character array.
2. Manually calculate its length by looping until `'\0'` is encountered.
3. Swap characters from the beginning and the end moving inward.
4. Print the reversed string.

### Second Largest Element

1. Define an array of 10 integers: `{1,2,3,4,5,90,7,8,6,10}`.
2. Find the maximum (`max1`) by scanning the array once.
3. Find the second largest (`max2`) by scanning again, ignoring the maximum value.
4. Print both the largest and the second-largest elements.

### Key Concepts Used

* **String Manipulation**: Implemented manually without `strlen()` or `strrev()`.
* **Loops**: Used to find string length and to traverse arrays.
* **Swapping**: For reversing strings in-place.
* **Max-Finding**: Using two passes to determine the largest and second largest values.

## How to Run

To run this program:

1. Copy the code into a file named `task5.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task5 task5.c
   ```
3. Run the compiled executable:

   ```bash
   ./task5
   ```

## Examples

### Example 1: Reverse String

```
Enter string: hello
olleh
```

### Example 2: Second Largest

```
2nd largest number: 10
largest number: 90
```

## Known Limitations

* The string buffer size is fixed at 20 characters, so longer input will cause buffer overflow.
* The `scanf("%s", ...)` stops reading at spaces, so multi-word strings are not reversed correctly.
* The array is hardcoded; the program does not take dynamic input for array size or values.
* The current approach uses two passes over the array to find largest and second largest; it could be optimized to a single pass.

## What I Verified

* **Edge Cases**:

  * Empty string input still works (prints nothing).
  * Strings with odd/even length reverse correctly.
  * Array correctly identifies `90` as largest and `10` as second largest.
* **Complexity**:

  * Reverse string runs in **O(n)**.
  * Largest/second-largest finder runs in **O(n)** with two passes.
* **Constraints**:

  * Array limited to fixed size of 10.

## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to write this `README.md` and analyze edge cases and limitations.

---
