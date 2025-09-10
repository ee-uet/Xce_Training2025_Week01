# Problem
Write a program that accepts two integers from the command line and prints their sum.
#
**Approach**  
- The program takes two integers as command-line arguments when running the program.

- argv[1] and argv[2] store the input numbers as strings.

- Use the function atoi() (ASCII to integer) to convert strings to integers.

- Calculate the sum of the two integers.

- Print the result using printf().

This demonstrates how to accept input from the command line and convert string inputs to integers for calculations.
#
**How to run**  
Open terminal (or WSL) and navigate to the folder where your program is saved.

- Compile the program using gcc:  
    gcc code.c -o program
- Run the program with two numbers as command-line arguments:  
   ./program 5 7
#
**Example**  
Command:

./program 5 7


Execution steps:

- argv[1] = "5" (string) → converted to integer using atoi() → 5

- argv[2] = "7" (string) → converted to integer using atoi() → 7

Sum = 5 + 7 = 12
#
**AI Usage / What I Verified**

- I understood from AI how command-line arguments (argc and argv) work.

- I also learned how the atoi() function converts string arguments to integers.

