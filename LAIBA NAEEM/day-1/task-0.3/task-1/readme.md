# Problem
Write a C program that print the first n terms of the Fibonacci sequence using a for loop (n is user input).
##
**Approach**
- first I ask the user how many numbers they want in the fibonacci sequence.

- I start with 0 and 1 because fibonacci always begins from these two.

- I use a loop to keep adding the last two numbers to get the next one.

- I print each number as the loop goes on.

- I update the values so the next number can be calculated correctly.
##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
**Example**  

user enters 5. 
Program starts with x = 0 and y = 1.

Following are the steps for execution:

- print 0: then z = 0 + 1 = 1, update x = 1, y = 1

- print 1: then z = 1 + 1 = 2, update x = 1, y = 2

- print 1: then z = 1 + 2 = 3, update x = 2, y = 3

- print 2: then z = 2 + 3 = 5, update x = 3, y = 5

- print 3: then z = 3 + 5 = 8, update x = 5, y = 8
##
**Known Limitations**  
if the user enters 0 or a negative number, the program will just not print anything useful (because fibonacci needs positive numbers).