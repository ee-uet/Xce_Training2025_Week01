
## Problem
- **t2_1:** Check if a number (argument) is even or odd  
- **t2_2:** Print first 10 multiples of a given number (input)  
- **t2_3:** Guessing game with random number between 1–10  

## Approach
- Used `if-else` with modulo to check even/odd  
- Used `for` loop and `$(( ))` arithmetic for multiples  
- Used `while true` + `RANDOM` for guessing game, giving hints  

## How to Run
1. **Make scripts executable:**
   ```bash
   chmod +x t2_1 t2_2 t2_3
2. **Run each task:**
Even/Odd:
    ./t2_1 7
Multiples:
    ./t2_2
Guessing game:
    ./t2_3
    
## Test Cases
t2_1
$ ./t2_1 4
    Number is even
$ ./t2_1 7
    Number is odd

t2_2
$ ./t2_2
    Enter Number: 5
    5
    10
    ....
    45
    50

t2_3
$ ./t2_3
    Guess the number: 8
    TOO HIGH
    Guess the number: 3
    TOO LOW
    Guess the number: 5
    Correct Guess!

## Known Limitations
1. t2_1 assumes argument is provided and numeric
2. t2_2 always prompts interactively (cannot pass arg directly)
3. t2_3 runs indefinitely until correct guess

