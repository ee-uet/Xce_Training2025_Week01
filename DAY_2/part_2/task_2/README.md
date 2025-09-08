# Task – Palindrome Checker (Case-Insensitive)

## Problem
Write a C program to check whether a given string is a **palindrome** (reads the same forwards and backwards), ignoring case.

---

## Approach
1. Implemented a custom `my_strlen` to calculate string length without using `<string.h>`.
2. Used two pointers:
   - One starting at the **beginning** of the string.
   - One starting at the **end** of the string.
3. Compare characters while moving inward:
   - Convert both to lowercase using `tolower` for **case-insensitive** comparison.
   - If mismatch → return `0` (Not a palindrome).
4. If all characters match → return `1` (Palindrome).

---

## How to Run
1. Save code in a file, `task2_2.c`.
2. Compile:
   ```bash
   gcc task2_2.c -o task2_2
    ./task2_2

## Example Output
Palindrome? Yes 

## Limitations

Spaces, punctuation, and special characters are not ignored (e.g., "A man a plan a canal Panama" will return No).

Works only on null-terminated C strings.