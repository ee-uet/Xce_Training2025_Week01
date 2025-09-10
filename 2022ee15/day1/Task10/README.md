# Task 0.10 — Command Line Arguments

## Problem
- Write a program that accepts **two integers** from the command line and prints their **sum**.  
- Example:  
  ```bash
  ./a.out 5 7
  Output: Sum is 12

## Approach
- Use argc and argv to access command line arguments.
- Convert arguments from strings to integers using atoi().
- Add the two integers and print the result.

## Example Run
    $ gcc t10.c -o t10
    $ ./t10 15 20
    Sum is 35
    
## Known Limitations
- No error handling if arguments are not valid integers.
- Program requires exactly two integers — extra arguments are ignored.

## Sources & AI Usage
- Checked standard C library functions atoi() for string-to-int conversion.
