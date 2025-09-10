# Problem 
- 	Define an enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
 -	Write a program that takes a number (1–7) as input and prints the corresponding weekday.
#
**Approach**
- Define an enum called weekdays to represent days of the week with numbers 1 to 7.

- Ask the user to enter a number between 1 and 7.

- Used a switch statement to match the entered number with the enum values.

- Print the corresponding day of the week based on the number.

This demonstrates how enums can be used to map numbers to meaningful names in C.
#
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
#
**Example**  
User enters 3

- Program checks 3 in the switch statement

- Matches WED (Wednesday)

- Prints Wednesday

User enters 6

- Program checks 6 in the switch statement

- Matches SAT (Saturday)

- Prints Saturday
