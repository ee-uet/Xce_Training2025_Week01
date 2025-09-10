# C Program: Number Guessing Game

## Overview
1. **Number Guessing Game**  
   - Generates a random number between `0` and `100`.  
   - The user keeps guessing until the correct number is entered.  
   - The program provides hints (`Too Low` / `Too High`) after each guess.  

---

## Code Structure
- `task03_guessing_game()`  
  - Uses `rand() % 101` to generate a random number between `0` and `100`.  
  - Loops until the user guesses correctly.  
  - Handles invalid guesses (numbers outside the range `1–100`) with an error message.  
  - Gives feedback if the guess is lower or higher than the target.  

- `main()`  
  - Calls `srand(time(0))` to ensure a new random sequence each run.  
  - Run both task Guessing Game.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task3B.c -o task3B
./task3B
