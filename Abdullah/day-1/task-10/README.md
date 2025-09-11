# Task 10: Command Line Arguments

## Problem
Write a program that accepts two integers from the command line and prints their sum.
Example: ./a.out 5 7 → Output: Sum = 12

## Approach
1. Use argc and argv parameters in main function
2. Convert string arguments to integers using atoi()
3. Calculate sum of the two numbers
4. Print the result

## How to Run

### Compilation
```bash
gcc -o cmd_args cmd_args.c
```

### Execution
```bash
./cmd_args 5 7
```

## Example Output
```
Sum is 12
```

## Command Line Arguments
- argv[0]: Program name
- argv[1]: First integer (as string)
- argv[2]: Second integer (as string)

## Design Notes
- Uses atoi() to convert string arguments to integers
- Assumes exactly 2 arguments are provided
- Simple addition operation with result display

## Assumptions & Edge Cases
- Assumes user provides exactly 2 command line arguments
- Assumes arguments are valid integers
- No bounds checking on argc parameter

## Known Limitations
- No validation for number of arguments
- No error handling for invalid integer strings
- atoi() returns 0 for invalid input (ambiguous with actual 0)
- No input validation or usage instructions

## Error Scenarios Not Handled
- Too few arguments: `./cmd_args 5` (would cause undefined behavior)
- Too many arguments: `./cmd_args 1 2 3 4` (extra arguments ignored)
- Non-numeric arguments: `./cmd_args abc def` (would result in sum = 0)

## Sources & AI Usage
- Original template code from lab manual
- Standard command line argument processing
- atoi() function from stdlib.h
- No AI assistance for argument parsing logic