# Problem
Write a C program that:
-	Declare variables of type int, float, double, char.
-	Print their values and sizes using the sizeof operator.
- Demonstrate type casting (e.g., int → float, float → int).
##
**Approach**
- First, I declared variables of type int, float, double, and char.
- Then, I printed their values to show how they are stored.
- I used the sizeof operator to display how many bytes each data type takes in memory.
- Finally, I demonstrated type casting by:
  - Converting a float into a double.
  - Converting a char into an int (to show its ASCII value).
##
**How to run**
- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
##
**Example**

 integer = 65  
 float = 0.800000  
 character = a  
 double = 0.990000  
size of integer = 4 bytes  
size of float = 4 bytes   
size of character = 1 bytes  
size of double = 8 bytes  
float to double = 0.800000  
character to int = 97  
integer to character = A  
##
**Known Limitations**  
When converting an integer to a character, the integer must fall within the valid ASCII range.
For letters:
- Uppercase letters (A–Z): ASCII codes 65 to 90
- Lowercase letters (a–z): ASCII codes 97 to 122
#
**Resources**  
Did by myself.
   .

