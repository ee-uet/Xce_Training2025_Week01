# Problem
-	Write a program that takes two integers as input.
-	Perform all arithmetic operations: +, -, *, /, %.
-	Extend into a simple calculator using switch statement:
	- User chooses the operation symbol (+ - * /
	- %)
    - The program executes the selected operation.
##
**Approach**
- Take Input:  
Ask the user to enter two integer numbers (x and y).  
  Ask the user to enter an operation symbol (+, -, *, /, %).

- Perform All Operations:  

  First, directly calculate and display results of addition, subtraction, multiplication, division, and modulus.

- Use Switch-Case:

  Based on the operator entered by the user, use a switch statement to perform only that operation.

  Example: If the user enters +, the program prints the sum of x and y.

- Output the Result:

  Print the answer of the selected operation.
##
**How to run**
- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
##
**Example**
x = 4  
y = 5  
x + y = 9  
x - y = -1  
x * y = 20  
x / y = 0  
x % y = 4  
Enter operation:+  
x + y = 9  
##
**Known Limitations**   
If the user enters y = 0 and chooses division (/) or modulus (%), the program will give an error or undefined result (because division by zero is not allowed in mathematics).  
**Example**
when i run the my code with y = 0 i got the error.  
x = 8  
y = 0  
x + y = 8  
x - y = 8  
x * y = 0  
Floating point exception (core dumped).

