# Task 0.8 — Enumerations

## Problem
- Define an `enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };`
- Write a program that takes a number (1–7) as input.
- Print the corresponding weekday name.

## Approach
1. Declare an `enum` to represent days of the week (0–6 internally).
2. Convert user input (1–7) into an enum value by subtracting 1.
3. Use a `switch` statement to map the enum to the weekday name.
4. Print "Invalid input" if the user enters a number outside 1–7.

## How to Run
    ```bash
    gcc t8.c -o t8
    ./t8
    
## Known Limitations
- Only accepts integers as input (no error handling for non-numeric input).


