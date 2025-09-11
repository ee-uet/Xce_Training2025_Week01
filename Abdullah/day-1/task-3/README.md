# Task 3: Control Structures

## Problem
Implement two programs:
1. **Fibonacci Sequence**: Print the first n terms of the Fibonacci sequence using a for loop (n is user input)
2. **Guessing Game**: Computer generates a random number between 1–100, user repeatedly guesses until correct with "Too High" or "Too Low" hints

## Approach

### Fibonacci Sequence
1. Get number of terms from user
2. Initialize first two terms (0, 1)
3. Use for loop to calculate and print subsequent terms
4. Handle special cases for first two terms

### Guessing Game
1. Generate random number between 1-100 using `rand()`
2. Use do-while loop for repeated guessing
3. Provide hints (Low/High) based on guess
4. Count attempts and display final result

## How to Run

### Fibonacci Sequence
```bash
gcc -o fibonacci fibonacci.c
./fibonacci
```

### Guessing Game
```bash
gcc -o guessing_game guessing_game.c
./guessing_game
```

## Example Output

### Fibonacci Sequence
```
Enter the number of terms: 7
0 
1 
1 
2 
3 
5 
8 
```

### Guessing Game
```
Guess the number (1-100): 50
Low! Try again: 75
High! Try again: 62
Low! Try again: 68
Congratulations! You've guessed the number 68 in 4 attempts.
```

## Design Notes
- Fibonacci uses iterative approach with for loop
- Random number generation seeded with current time
- Do-while ensures at least one guess attempt

## Assumptions & Edge Cases
- Fibonacci: Assumes positive integer input for n
- Guessing Game: Assumes valid integer input for guesses
- Random seed ensures different numbers each run

## Known Limitations
- No input validation for negative numbers in Fibonacci
- No bounds checking for guesses in guessing game
- Fibonacci sequence printed with line breaks (one number per line)

## Sources & AI Usage
- Original template code from lab manual
- Standard library functions used: `rand()`, `srand()`, `time()`
- Searched Google for syntax of `n = rand() % 100 + 1;` and usage.
- No AI assistance for core algorithms