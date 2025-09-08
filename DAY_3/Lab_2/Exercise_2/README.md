# Multiplication Table (First 10 Multiples)

## Problem
Write a Bash script that:
- Takes a number as a command-line argument.
- Prints the first **10 multiples** of that number in a formatted way.

## Approach
- Accept the number from `$1` (first positional argument).
- Use a `for` loop from `1` to `10`.
- Multiply the given number with the loop index using Bash arithmetic `$((...))`.
- Print the result in the format `num * i = product`.

## How to Run
1. Save the script as `E2_2.sh`.
2. Make it executable:
   ```bash
   chmod +x E2_2.sh
    ./E2_2.sh 5

## Examples
 ./multiples.sh 5
First 10 multiple of 5 is
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
5 * 4 = 20
5 * 5 = 25
5 * 6 = 30
5 * 7 = 35
5 * 8 = 40
5 * 9 = 45
5 * 10 = 50

## Known Limitations

Only works if you provide a number as an argument.

No input validation for non-numeric values (e.g., ./multiples.sh abc will throw an error).

Prints only the first 10 multiples (not configurable).