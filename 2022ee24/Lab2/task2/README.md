
---

# C Program: Custom String Functions & Palindrome Checker (Task 2)

## Problem

This program reimplements common string handling functions in C using **pointers** instead of `<string.h>`.
It also includes a **palindrome checker** (case-insensitive).

The program demonstrates:

1. `my_strlen` – Custom string length function.
2. `my_strcpy` – Custom string copy function.
3. `my_strcmp` – Custom string comparison function (case-insensitive).
4. `is_palindrome` – Checks if a string is a palindrome.

## Approach

### Functions Implemented

1. **`my_strlen(const char *s)`**

   * Iterates through the string until the `'\0'` terminator is reached.
   * Returns the length of the string.

2. **`my_strcpy(char *dest, const char *src)`**

   * Copies characters from `src` to `dest` until `'\0'` is reached.

3. **`my_strcmp(const char *s1, const char *s2)`**

   * Compares two strings character by character.
   * Case-insensitive: treats `'a'` and `'A'` as equal by ignoring differences of 32 in ASCII values.
   * Returns `0` if equal, otherwise returns the difference between mismatched characters.

4. **`is_palindrome(const char *s)`**

   * Uses `my_strlen` to get string length.
   * Allocates a reversed copy of the string using `malloc`.
   * Compares original and reversed string with `my_strcmp`.
   * Returns `1` if palindrome, otherwise `0`.

### Key Concepts Used

* **Pointer Arithmetic** – Traverse and manipulate strings without array indexing.
* **Dynamic Memory Allocation (`malloc`, `free`)** – Create reversed string buffer.
* **Case-Insensitive Comparison** – Handles upper/lowercase differences.

## How to Run

1. Save the code into a file named `task2.c`.
2. Compile with GCC:

   ```bash
   gcc -o task2 task2.c
   ```
3. Run the program:

   ```bash
   ./task2
   ```

## Examples

### Example Run

```
Len = 5
Copied: World
-3
Palindrome? Yes
```

Explanation:

* `"Hello"` length is 5.
* `"World"` successfully copied.
* `my_strcmp("aDc","adg")` → returns `-3` (difference between `'c'` and `'g'`).
* `"Mam"` is identified as a palindrome (case-insensitive).

## Known Limitations

* `is_palindrome` uses extra memory (reversed string) instead of in-place comparison.
* No handling for spaces, punctuation, or non-alphabetic characters in palindrome check.

## What I Verified

* **my\_strlen** – Works correctly for typical strings.
* **my\_strcpy** – Verified copying basic strings.
* **my\_strcmp** – Correctly detects case-insensitive differences.
* **is\_palindrome** – Works for simple alphabetic palindromes (e.g., `"Mam"`, `"Racecar"`).

## Sources & AI Usage

The program logic was written manually. AI assistance was used to generate this `README.md`

---
