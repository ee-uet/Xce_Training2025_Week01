# Task 0.4 — Functions

## Problem
1. Implement a function `isPrime(int n)` that returns **1 if prime**, otherwise **0**.
2. Use it to print all prime numbers between 1–100.
3. Implement a **recursive factorial function** `factorial(int n)`.

## Approach
- **Prime Numbers**: Loop through numbers from 1–100, use `isPrime()` to check and print.
- **Factorial**: Use recursion:
  - `factorial(0) = 1`
  - `factorial(n) = n * factorial(n-1)`

## How to Run
    ```bash
    gcc t4.c -o t4
    ./t4
    
## Example Run
    Prime numbers between 1 and 100:
    2   3   5   7   11   13   17   19   ...   97
    Factorial of 5 = 120

## Known Limitations
- Factorial grows very fast and will overflow for n > 12 when using int.

## Sources and AI
- Concepts of prime checking and recursion verified from online references.

