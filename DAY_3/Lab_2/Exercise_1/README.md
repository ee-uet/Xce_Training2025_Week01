# Even or Odd Checker (Bash Script)

## Problem
Write a Bash script that:
- Takes a number as input (via command-line argument).
- Determines whether the number is **even** or **odd**.
- Prints the result.

## Approach
- Accept the number using the positional parameter `$1`.
- Use the modulo operator (`%`) to check the remainder when dividing by 2.
- If remainder = 0 → **Even**, else → **Odd**.
- Print the result using `echo`.

## How to Run
1. Save the script as `evenodd.sh`.  
2. Make it executable:
   ```bash
   chmod +x E2_1.sh
    ./E2_1.sh 10

## Examples
$ ./evenodd.sh 10
Number is even

$ ./evenodd.sh 7
Number is Odd

## Known Limitations

Requires exactly one argument (the number).

Only works with integers (no float support in Bash arithmetic).

No error handling for non-numeric inputs (e.g., ./evenodd.sh abc will cause an error).