# Basic C Programming

## Overview

This C programming lab contains 10 programming tasks covering data types, control structures, functions, file I/O, bit manipulation, enums, structures, and command-line arguments.

## Tasks

### Task 0.1 - Data Types and Type Casting
**Problem**: Demonstrate different data types in C and show type casting effects.
**Approach**: Declare variables of different types (int, float, double, char), print their sizes using `sizeof()`, and demonstrate integer division vs float division.

### Task 0.2 - Calculator with Switch-Case
**Problem**: Create a basic calculator that performs arithmetic operations.
**Approach**: Use `scanf()` to get two integers and an operator, then use a switch-case statement to perform the requested operation.

### Task 0.3 - Fibonacci Sequence & Guessing Game
**Problem**: Generate sum of first n natural numbers and create a number guessing game.
**Approach**: Use a loop to calculate cumulative sum. Generate random numbers and use loops with conditional statements for the guessing game.

### Task 0.4 - Prime Number Operations
**Problem**: Check if a number is prime and find all primes between 1-100.
**Approach**: Implement an efficient primality test checking divisibility only up to √n, then use it to filter primes in a range.

### Task 0.5 - String and Array Operations
**Problem**: Reverse a string without library functions and find the second largest element in an array.
**Approach**: Manual string reversal using character swapping. Single-pass algorithm to track largest and second-largest elements.

### Task 0.6 - File Input/Output
**Problem**: Write integers to a file, read them back, and create a prime analysis file.
**Approach**: Use `fopen()`, `fprintf()`, `fscanf()`, and `fclose()` for file operations.

### Task 0.7 - Bitwise Operations
**Problem**: Demonstrate various bitwise operations and check if a number is a power of 2.
**Approach**: Use AND, OR, XOR, NOT, and shift operators. Implement power-of-2 check using bit shifting.

### Task 0.8 - Enumerations
**Problem**: Map numbers (1-7) to days of the week using enums.
**Approach**: Define an enum for weekdays and use switch-case for mapping.

### Task 0.9 - Structures and Mathematical Calculations
**Problem**: Calculate Euclidean distance between two points.
**Approach**: Define a Point structure and use the distance formula with `sqrt()` and `pow()` functions.

### Task 0.10 - Command Line Arguments
**Problem**: Accept two integers as command-line arguments and print their sum.
**Approach**: Use `argc` and `argv[]` parameters, convert strings to integers using `atoi()`.

## How to Run

### Compilation
```bash
gcc -o lab1 lab1.c -lm
```

### Running
```bash
./lab1
```

### For Command Line Arguments (Task 0.10)
```bash
./lab1 25 35
```

## Examples

### Task 0.2 - Calculator
```
Input:
enter 1st value: 15
enter 2st value: 4
enter which operation you want: +

Output:
sum = 19
```

### Task 0.3 - Guessing Game
```
Output:
Guess the number between 1 and 100!
Enter your guess: 50
Too Low! Try again.
Enter your guess: 75
Too High! Try again.
Enter your guess: 62
Correct!
```

### Task 0.8 - Enum Weekday
```
Input:
Enter a number between 1 to 7: 3

Output:
Wednesday
```

### Task 0.9 - Euclidean Distance
```
Input:
Enter the coordinates of 1st point: 1 2
Enter the coordinates of 2nd point: 4 6

Output:
Euclidean Distance = 5.00
```
