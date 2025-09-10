# C Programming Tasks

## Problem
This project implements a collection of fundamental C programming tasks to demonstrate key concepts such as data types, arithmetic operations, control structures, functions, file I/O, bitwise operations, enums, structs, and command-line arguments.

## Approach
Each task is implemented as a separate function in a single C file (`main.c`):
- **Task 0.1**: Displays sizes of basic data types and demonstrates type casting.
- **Task 0.2**: Implements a switch-case calculator for basic arithmetic operations.
- **Task 0.3**: Generates Fibonacci sequence and includes a number guessing game.
- **Task 0.4**: Identifies prime numbers and calculates factorials recursively.
- **Task 0.5**: Reverses a string and finds the second largest element in an array.
- **Task 0.6**: Performs file I/O to write and read integers.
- **Task 0.7**: Demonstrates bitwise operations (AND, OR, XOR, NOT, shifts).
- **Task 0.8**: Maps numbers to days of the week using an enum.
- **Task 0.9**: Calculates Euclidean distance between two points using structs.
- **Task 0.10**: Processes command-line arguments to compute their sum.

The program uses standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `math.h`) and is structured for clarity and modularity.

## How to Run
1. **Prerequisites**: Ensure you have a C compiler (e.g., `gcc`) installed.
2. **Compile**: Run the following command in the terminal:
   ```bash
   gcc -o tasks main.c -lm
   ```
   Note: The `-lm` flag links the math library for functions like `sqrt`.
3. **Execute**: Run the compiled program:
   ```bash
   ./tasks
   ```
   To test command-line arguments for Task 0.10:
   ```bash
   ./tasks 10 20
   ```
4. **Output**: The program executes all tasks sequentially, printing results to the console. For the guessing game, follow prompts to input guesses.

## Examples
### Sample Run
```bash
$ gcc -o tasks main.c -lm
$ ./tasks
Integer size:    4
Float Size:      4
Double Size:     8
Char Size:       1
Quotient:        10
The first two terms of the sequence are 1.
The 3th term is: 2
...
Guess a number between 1 and 100: 50
Too low!
...
2 is prime.
...
Factorial of 5 = 120
Reversed string: !dlroW ,olleH
Second largest element:  45
Integers read from file:
23
...
AND:    1
...
Wednesday
Distance:       5.000000
Command line arguments:
Argument 0: ./tasks
```

### Command-Line Argument Example
```bash
$ ./tasks 15 25
...
Command line arguments:
Argument 0: ./tasks
Argument 1: 15
Argument 2: 25
Sum of 15 and 25 is: 40
```