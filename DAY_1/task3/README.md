# Task 0.3 – Fibonacci Sequence and Number Guessing Game

## Problem
This task contains two parts:
1. **Fibonacci Sequence**  
   - Take an integer `n` as input.  
   - Print the Fibonacci sequence up to `n` terms.  

2. **Guessing Game**  
   - Generate a random number between 0 and 100.  
   - Ask the user to guess until the correct number is entered.  
   - Provide hints: "too low" or "too high".  
   - Display the number of attempts when guessed correctly.  

## Approach

### Fibonacci
1. Read input `n`.  
2. Initialize variables for tracking previous terms.  
3. Use a loop to print Fibonacci terms.  
4. Handle the first two terms separately, then generate further terms using the relation:  
F(n) = F(n-1) + F(n-2)


### Guessing Game
1. Use `rand() % 101` to generate a random number between 0–100.  
2. Take user guesses in a loop until correct.  
3. After each guess:  
- If guess < random → print "too low".  
- If guess > random → print "too high".  
- If guess == random → print success message with attempt count.  

## How to Run
Compile and run using GCC:
```bash
gcc fibonacci.c -o fibonacci
./fibonacci


gcc guessing_game.c -o guessing_game
./guessing_game

## Example Output
Enter number 5
The Fibonacci sequence up to 5th terms is:  0 1 1 2 3 

Enter your guess number 50
The guess is too high
Enter your guess number 20
The guess is too low
Enter your guess number 30
The guess is too low
Enter your guess number 25
You guess the correct number in 4th attempts

## Known Limitations

Fibonacci logic is not optimal; the variable updates are unconventional. For larger n, results may not be accurate.

Guessing game does not use srand(time(0)); the random number will repeat between runs.

Input validation is missing (non-integer input may crash the program).