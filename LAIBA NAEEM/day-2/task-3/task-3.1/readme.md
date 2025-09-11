# Problem
Write macros for:
-	SQUARE(x)
-	MAX(a,b)
-	MAX(a,b,c)
-	MAX(a,b,c,d)
-	TO_UPPER(c) (convert char to uppercase if lowercase).
Demonstrate with test cases.

#
**Approach**

- Use preprocessor macros to perform common operations without functions:

- SQUARE(x) to calculate the square of a number.

- MAX2, MAX3, MAX4 to find the maximum of 2, 3, or 4 numbers.

- TO_UPPER(c) to convert a lowercase character to uppercase.

- Demonstrate each macro with test values in a separate function task3_1_macros().
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**  
SQUARE(5) = 25  
MAX2(3,7) = 7  
MAX3(3,7,5) = 7  
MAX4(3,7,5,10) = 10  
g to G  
A to A  
#
**Resources and References**  
1. While implementing these functions, I referred to the lab slides to understand pointer usage.
2. Used AI to understand how to convert lowercase letters to uppercase using ASCII values for the TO_UPPER macro.
