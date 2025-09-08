# Task 0.2 – Simple Calculator Using Switch Case

## Problem
Write a C program that:
- Takes two integers as input.
- Accepts an operator (`+`, `-`, `*`, `/`, `%`) from the user.
- Performs the corresponding arithmetic operation using a switch-case.
- Handles invalid operators and division/modulo by zero cases.

## Approach
1. Prompt the user to input two integers (`a` and `b`).
2. Prompt the user to enter an operator.
3. Use a `switch` statement to perform the selected operation:
   - Addition (`+`)
   - Subtraction (`-`)
   - Multiplication (`*`)
   - Division (`/`) → check for division by zero.
   - Modulo (`%`) → check for modulo by zero.
4. If the operator is invalid, print an error message.

## How to Run
Compile and run using GCC:
```bash
gcc task_2.c -o task_2
./task_2



## Example Output
Enter First number  10
Enter Second number 5
Enter Operator +, -, *, /, %,
+
Result of 10 + 5 = 15

## Known Limitations

Only works with integers, not floating-point numbers.

Division and modulo operations will fail if the second number is zero.

Input validation is minimal; non-numeric input may cause unexpected behavior.