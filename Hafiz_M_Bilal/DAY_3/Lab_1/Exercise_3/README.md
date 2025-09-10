# Sum of Two Numbers (Bash Script)

## Problem
Write a Bash script that:
1. Accepts two numbers as command-line arguments.
2. Adds them together.
3. Displays the result.

## Approach
- Use **positional parameters** `$1` and `$2` to capture the numbers passed to the script.  
- Perform arithmetic using the built-in `$((...))` syntax in Bash.  
- Print the sum with `echo`.

## How to Run
1. Save the script as `sum.sh`.  
2. Make it executable:
   ```bash
   chmod +x E1_3.sh
    ./E1_3.sh

## Examples
 ./sum.sh 5 7
Sum of 5 and 7 is: 12

 ./sum.sh 10 25
Sum of 10 and 25 is: 35

## Known Limitations

Requires exactly two arguments. If fewer or more are given, the behavior may be incorrect.

Works only with integers (no floating-point support in standard Bash arithmetic).

No validation for non-numeric input. Example: ./sum.sh 5 abc will cause an error.