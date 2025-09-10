# Problem
Define a struct Point { int x; int y; };
- Write a program that takes two points and calculates the Euclidean distance between them.
#
**Approach**
- Define a struct Point with two members: x and y to represent coordinates.

- Ask the user to enter the coordinates of two points (x1, y1 and x2, y2).

- Use the Euclidean distance formula: 
   distance = sqrt((x2.x - x1.x)^2 + (x2.y - x1.y)^2)


- Calculate the distance using the sqrt() function from math.h.

- Print the result.

This demonstrates how structures can store related data together and how to use them in calculations.
#
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
#
**Example**  
x1 = 2, y1 = 3  
x2 = 5, y2 = 7  
distance = sqrt((5 - 2)^2 + (7 - 3)^2)
Euclidean distance = 5.000000
