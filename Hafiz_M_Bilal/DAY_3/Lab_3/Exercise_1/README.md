# Factorial Calculator (Recursive Bash Script)

## Problem
Write a Bash script to calculate the factorial of a given number using recursion.

## Approach
- Define a recursive function `fict()`:
  - Base case: If `n <= 1`, return 1.
  - Recursive case: `n * factorial(n-1)`.
- Read user input.
- Call the function and display the factorial.

## How to Run
1. Save the script as `E3_1.sh`.
2. Make it executable:
   ```bash
   chmod +x E3_1.sh
   ./E3_1.sh

## Example Run
 ./factorial.sh
Enter number
5
Factorial of 5 is: 120

## Known Limitations

Only works with positive integers.

For very large inputs (e.g., >20), recursion depth or integer overflow may cause incorrect results.

Does not handle invalid input (like letters or negative numbers).
