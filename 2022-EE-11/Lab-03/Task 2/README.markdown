# Bash Script: Number Operations and Guessing Game

## Problem
This Bash script performs three tasks: checks if a number is even or odd, calculates the first 10 multiples of a number, and implements a number guessing game.

## Approach
The script is divided into three sections:
- **Even/Odd Checker**: Takes a number and determines if it's even or odd.
- **Multiples Calculator**: Computes and displays the first 10 multiples of a given number.
- **Guessing Game**: Generates a random number (1–10) and prompts the user to guess it, providing feedback until correct.

## How to Run
1. **Prerequisites**: Requires a Unix-like environment (e.g., Linux, macOS, WSL) with Bash.
2. **Save the Script**: Save as `script.sh`.
3. **Make Executable**: Run:
   ```bash
   chmod +x script.sh
   ```
4. **Execute**: Run the script:
   ```bash
   ./script.sh
   ```
5. **Follow Prompts**: Enter a number for even/odd check, another for multiples, and guesses for the game. Press Enter to exit.

## Examples
### Sample Run
```bash
$ chmod +x script.sh
$ ./script.sh
Enter a number: 4
Even

Enter a number: 3
The 1st 10 multiples of 3 are:
3
6
9
12
15
18
21
24
27
30

This is a guessing game, enter a number: 5
Too low!
Guess: 7
Too high!
Guess: 6
You got it! The number was 6

Enter to exit.
```

## Syntactical Shorthands Explained
- `#!/bin/bash`: Shebang specifying Bash as the interpreter.
- `read -p "Prompt: " var`: Reads input with a prompt (`-p`) into variable `var` (e.g., `num`, `guess`).
- `(( $num % 2 == 0 ))`: Arithmetic test in double parentheses to check if `num` is even (modulo 2 equals 0).
- `$num`: Variable substitution to access `num`'s value.
- `if ...; then ...; else ...; fi`: Conditional structure for even/odd logic and guessing game.
- `for (( i=1; i<=10; i++ ))`: C-style for loop to iterate from 1 to 10.
- `$((num * i))`: Arithmetic expansion to compute multiples.
- `RANDOM % 10 + 1`: Generates random number (1–10) using Bash’s `RANDOM` variable.
- `[ $guess -lt $num ]`: Test command to compare `guess` and `num` (`-lt`: less than, `-gt`: greater than).
- `while true`: Infinite loop, broken by `break` when the guess is correct.
- `echo`: Outputs text or variables to the console; standalone `echo` adds a blank line.