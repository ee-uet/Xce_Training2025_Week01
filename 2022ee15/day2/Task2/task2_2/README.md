# Task 2.2 — Palindrome Checker (Case-Insensitive)

## Problem
Write a program that checks if a given string is a **palindrome**.  
- A palindrome reads the same forwards and backwards.  
- Ignore case (e.g., "Level" and "MadAm" should count as palindromes).  

## Approach
- Use two pointers: one at the start, one at the end.  
- Skip to the last valid character before `'\0'`.  
- Compare characters while moving `start` forward and `end` backward.  
- Use `tolower()` to make the comparison case-insensitive.  

## How to Run
1. **Compile the program:**
   ```bash
   gcc task2_2.c -o out
2. **Run the executable:**
    ./out

## Test Cases
1. Palindrome word
Input: "Level"
Expected: Palindrome
2. Non-palindrome
Input: "Hello"
Expected: Not Palindrome
3. Mixed case palindrome
Input: "MadAm"
Expected: Palindrome

## Example Output
'Level' is Palindrome
'Hello' is Not Palindrome
'MadAm' is Palindrome

## Known Limitations
1. Only works for single words (does not ignore spaces or punctuation).
2. Assumes valid null-terminated strings.

