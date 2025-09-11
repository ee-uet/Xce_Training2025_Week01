# Task 2: Operators and Expressions - Calculator

## Problem
Write a program that takes two integers as input, performs all arithmetic operations (+, -, *, /, %), and extends into a simple calculator using switch statement where user chooses the operation symbol.

## Approach
1. Get two integer inputs from user
2. Get operator choice from user
3. Use switch-case structure to perform selected operation
4. Display result with appropriate message

## How to Run

### Compilation
```bash
gcc -o task02_calculator task02_calculator.c
```

### Execution
```bash
./task02_calculator
```

## Example Output
```
Enter 1st Integer: 
15
Enter 2nd Integer: 
3
Enter operator symbol (ADD, SUB, MUL, DIV, REM): 
+
Performing Addition
The result is: 18
```

## Design Notes
- Uses character input for operator selection
- Switch-case handles all basic arithmetic operations
- Integer division is performed (no decimal results)
- Modulo operation shows remainder

## Assumptions & Edge Cases
- Assumes valid integer input
- Division by zero not explicitly handled in original code
- Uses integer arithmetic (truncates decimal results)


## Sources & AI Usage
- Original template code from lab manual
- No AI assistance used for core logic
- Documentation structure enhanced