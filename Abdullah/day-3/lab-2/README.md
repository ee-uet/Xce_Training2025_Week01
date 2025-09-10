# Lab 2: Control Structures

## Problem
1. **If-Else Statement (Exercise 2.1)**: Check if a number is even or odd using conditional statements
2. **For Loop (Exercise 2.2)**: Print first 10 multiples of a number using for loop iteration
3. **While Loop (Exercise 2.3)**: Implement a guessing game with random number generation and while loop

## Approach

### Even/Odd Checker
1. Accept number as command-line argument
2. Use modulo operator to check remainder when divided by 2
3. Use if-else to determine and print result

### Multiples Generator
1. Accept number as command-line argument
2. Use for loop to iterate from 1 to 10
3. Calculate and print each multiple

### Guessing Game
1. Generate random number between 1-10 using RANDOM
2. Use while loop for repeated guessing
3. Provide "higher" or "lower" hints until correct guess

## How to Run

### Make Scripts Executable
```bash
chmod +x *.sh
```

### Even/Odd Checker
```bash
./even_odd.sh 7
./even_odd.sh 8
```

### Multiples Generator
```bash
./multiples.sh 5
```

### Guessing Game
```bash
./guessing_game.sh
```

## Example Output

### Even/Odd Checker
```
your number is EVEN    # for even numbers
Your number is not even    # for odd numbers
```

### Multiples Generator
```
First 10 multiples of 5:
5
10
15
20
25
30
35
40
45
50
```

### Guessing Game
```
Guess the number between 1 and 10: 5
Your guess is low
Try Again: 8
Your guess is high
Try Again: 7
You guessed correctly!
```

## Design Notes
- Even/odd uses modulo arithmetic for efficiency
- For loop uses brace expansion {1..10} for clean iteration
- Random number generation uses RANDOM variable with range calculation

## Key Concepts Demonstrated
- **Conditional Logic**: if-else statements for decision making
- **Modulo Operation**: `$(($1 % 2))` for even/odd checking
- **For Loop**: `{1..10}` range expansion
- **While Loop**: Continuous iteration until condition met
- **Random Numbers**: `$RANDOM` with range calculation
- **User Interaction**: Multiple read prompts in loop


## Assumptions & Edge Cases
- Scripts assume numeric command-line arguments
- Guessing game handles only integer inputs
- Random number range properly calculated to avoid bias

## Known Limitations
- No validation for non-numeric command-line arguments
- Guessing game doesn't handle non-integer input gracefully
- Even/odd checker message could be more consistent

## Algorithm Details

### Random Number Generation
```bash
num=$((RANDOM % (max - min + 1) + min))
```
This ensures uniform distribution within the specified range.

### For Loop vs While Loop
Original script incorrectly used while loop for multiples. Fixed to use for loop as required by exercise specification.

## Sources & AI Usage
- Original template code from lab manual
- Standard bash control structure patterns
- Random number generation techniques from Google
