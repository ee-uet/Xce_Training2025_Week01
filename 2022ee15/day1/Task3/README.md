# Task 0.3 — Control Structures

## Problem
1. **Fibonacci Sequence**
   - Print the first `n` terms of the Fibonacci sequence using a `for` loop.
   - `n` is taken from user input.

2. **Guessing Game**
   - Computer generates a random number between 1–100.
   - User guesses repeatedly until correct.
   - Program responds with **"Too High"** or **"Too Low"** hints.

## Approach
- **Fibonacci**: Use a loop and two variables (`a`, `b`) to generate terms.
- **Guessing Game**: Use `rand()` with `srand(time(0))` to generate random numbers.  
  Continue prompting until the guess is correct.

## How to Run
    ```bash
    gcc t3.c -o t3
    ./t3
    
## Example Run
    Running Fibonacci Task:
    Enter n: 5
    result: 0
    result: 1
    result: 1
    result: 2
    result: 3

    Running Guessing Game:
    Guess the number: 50
    Too Low
    Guess the number: 75
    Too High
    Guess the number: 68
    Correct Guess
    
## Known Limitations
- Fibonacci sequence may overflow if n is very large (since int type is used).

## Sources and AI
- Concepts of Fibonacci and random number generation checked online (C programming references).

