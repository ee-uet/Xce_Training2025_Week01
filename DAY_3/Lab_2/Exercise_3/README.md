# Number Guessing Game

## Problem
Create a Bash script that:
- Generates a random number between 1 and 10.
- Asks the user to guess the number.
- Provides hints if the guess is **too low** or **too high**.
- Repeats until the user guesses correctly.

## Approach
- Use `$RANDOM` to generate a random number in the range [1–10].
- Initialize `guess` to `0`.
- Run a `while` loop until the guess equals the random number.
- Compare the guess:
  - If less than the number → print *"Your guess is lower"*.
  - If greater than the number → print *"Your guess is higher"*.
  - Else → print *"Your guess is right"* and exit.

## How to Run
1. Save the script as `E2_3.sh`.
2. Make it executable:
   ```bash
   chmod +x E2_3.sh
    ./E2_3.sh

## Example Run
 ./guess_game.sh
Guess a number between 1 and 10:
Enter guess number: 
5
Your guess is higher
Enter guess number: 
2
Your guess is lower
Enter guess number: 
3
Your guess is right

## Known Limitations

Only works for numbers between 1 and 10.

Does not handle non-numeric input (e.g., entering "abc" causes an error).

Random number range is fixed (not configurable).