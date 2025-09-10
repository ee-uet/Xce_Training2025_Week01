# Basic C Programming Lab

## Overview
This C programming lab contains 10 programming tasks covering fundamental C concepts including data types, control structures, functions, file I/O, bit manipulation, enums, structures, and command-line arguments. Each task demonstrates practical programming techniques and core C language features.

## Tasks

### Task 01 - Data Types and Type Casting
**Problem**: Demonstrate different data types in C and show type casting effects.
**Approach**: Declare variables of different types (int, float, double, char), print their memory sizes using `sizeof()`, and demonstrate type casting between different data types including integer-to-float, float-to-integer, and character-to-ASCII conversions.

### Task 02 - Calculator with Switch-Case
**Problem**: Create a basic calculator that performs arithmetic operations.
**Approach**: Use `scanf()` to get an operator and two integers, then use a switch-case statement to perform the requested operation (+, -, *, /). Includes division by zero error handling and invalid operator checking.

### Task 03 - Fibonacci Sequence & Guessing Game
**Problem**: Generate Fibonacci sequence for n terms and create a number guessing game.
**Approach**: 
- **Fibonacci**: Use iterative approach with three variables to generate sequence efficiently
- **Guessing Game**: Generate random number (1-100) using `rand()`, use do-while loop with conditional feedback for user guesses

### Task 04 - Prime Number Operations
**Problem**: Check if a number is prime and find all primes between 1-100.
**Approach**: Implement efficient primality test using `isPrime()` function that checks divisibility only up to √n using `sqrt()` from math library. Display all prime numbers in the specified range.

### Task 05 - String and Array Operations
**Problem**: Reverse a string without library functions and find the second largest element in an array.
**Approach**: 
- **String Reversal**: Manual string reversal using two-pointer technique with character swapping
- **Second Largest**: Single-pass algorithm tracking both largest and second-largest elements, handles edge cases for duplicate values

### Task 06 - File Input/Output
**Problem**: Write integers to a file and read them back to demonstrate file I/O operations.
**Approach**: Use `fopen()`, `fprintf()`, `fscanf()`, and `fclose()` for file operations. Write predefined integer array to "my_numbers.txt" and read back to verify file operations.

### Task 07 - Bitwise Operations
**Problem**: Demonstrate various bitwise operations and implement power-of-2 checker.
**Approach**: Show AND (&), OR (|), XOR (^), NOT (~), left shift (<<), and right shift (>>) operations with binary explanations. Implement efficient power-of-2 check using bit manipulation trick: `(n & (n-1)) == 0`.

### Task 08 - Enumerations
**Problem**: Map numbers (1-7) to days of the week using enums.
**Approach**: Define `enum Weekday` starting from 1 (Monday) to 7 (Sunday) and use switch-case for user input mapping with error handling for invalid inputs.

### Task 09 - Structures and Mathematical Calculations
**Problem**: Calculate Euclidean distance between two points using structures.
**Approach**: Define `Point` structure with x and y coordinates, use distance formula √[(x₂-x₁)² + (y₂-y₁)²] with `sqrt()` and `pow()` functions from math library.

### Task 10 - Command Line Arguments
**Problem**: Accept two integers as command-line arguments and calculate their sum.
**Approach**: Use `argc` and `argv[]` parameters with argument count validation, convert strings to integers using `atoi()`, and display usage instructions for incorrect input.

## How to Run

### Compilation
```bash
gcc -o lab1 lab1.c -lm
```
*Note: The `-lm` flag is required to link the math library for `sqrt()` and `pow()` functions.*

### Running
Uncomment the desired task function(s) in `main()` and compile:
```bash
./lab1
```

### For Command Line Arguments (Task 10)
```bash
./lab1 25 35
```

## Code Structure
- Each task is implemented as a separate function (`task01_datatypes()`, `task02_calculator()`, etc.)
- Helper functions: `isPrime()` for prime checking, `factorial()` for recursive factorial calculation
- All task functions are commented out in `main()` - uncomment specific tasks to run them
- Uses `srand(time(NULL))` for random number generation in guessing game

## Examples

### Task 01 - Data Types
```
Output:
An integer uses: 4 bytes
A float uses: 4 bytes
A double uses: 8 bytes
A character uses: 1 byte

Now for some type casting magic!
When we cast int 10 to a float, we get: 10.00
When we cast float 20.50 to an int, we lose the decimal and get: 20
Casting the character 'A' to an integer gives its ASCII value: 65
```

### Task 02 - Calculator
```
Input:
Please enter the operation you'd like to perform (+, -, *, /): +
Now, enter two numbers, separated by a space: 15 4

Output:
15 plus 4 is 19
```

### Task 03 - Guessing Game
```
Output:
guess the num
What's your guess? 50
That's too low! Try again.
What's your guess? 75
Your guess is a bit too high! Try again.
What's your guess? 62
You got it! The number was 62. It only took you 3 tries!
```

### Task 07 - Bitwise Operations
```
Output:
Our numbers are x = 5 (binary: 0101) and y = 3 (binary: 0011)

ANDing x and y: 1
ORing x and y: 7
XORing x and y: 6
Flipping the bits of x: -6
Shifting x left by 1 bit (x * 2): 10
Shifting x right by 1 bit (x / 2): 2

Enter a number to see if it's a power of 2: 8
Yes! 8 is a power of 2.
```

### Task 09 - Euclidean Distance
```
Input:
Enter the X and Y coordinates for the first point: 1 2
Enter the X and Y coordinates for the second point: 4 6

Output:
The distance between your two points is: 5.00
```

## Features
- Comprehensive error handling for user inputs
- Memory-efficient algorithms
- Modular code structure with reusable functions
- Educational comments and user-friendly output messages
- Demonstrates both basic and advanced C programming concepts