# Task 0.9 — Structures (Intro)

## Problem
- Define a `struct Point { int x; int y; };`.
- Write a program that:
  - Takes two points as input.
  - Calculates the **Euclidean distance** between them.

## Approach
1. Create a `struct Point` to hold `x` and `y` coordinates.
2. Ask the user for two points (`p1`, `p2`).
3. Use the distance formula:
    distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
4. Print the result with 3 decimal precision.

## How to Run
    ```bash
    gcc t9.c -o t9 -lm   # -lm is required for math functions
    ./t9
    
## Example Run
    Enter coordinates of p1(x y): 1 2
    Enter coordinates of p2(x y): 4 6
    Euclidean Distance is 5.000

## Known Limitations
- No input validation (non-integer input may cause errors).
    
## Sources & AI Usage
- Distance formula from online.
