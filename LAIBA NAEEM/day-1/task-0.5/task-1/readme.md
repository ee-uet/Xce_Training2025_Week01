# Problem
Write a function to reverse a string without using library functions.
#
**Approach**
1. First, the program asks the user to enter a string.

2. The string is stored in an array of characters.

3. The program calculates the length of the string using strlen().

4. Then it runs a loop starting from the last character to the first character.

5. Inside the loop, each character is printed one by one.

This way, the string is displayed in reverse order without using any special library function for reversing.
#

**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
#
**Example:** 
  
User enters the string: Hello World

Program stores it in an array: string = ['H','e','l','l','o',' ','W','o','r','l','d']

Program calculates length: strlen(string) = 11

Loop runs from last index 10 down to 0:

- i = 10, print d

- i = 9, print l

- i = 8, print r

- i = 7, print o

- i = 6, print W

- i = 5, print space

- i = 4, print o

- i = 3, print l

- i = 2, print l

- i = 1, print e

- i = 0, print h  


Final Output: dlroW olleH

**AI Usage / What I Verified**

- I checked how the program handles spaces between characters.

- Verified that the program correctly reverses the string even when it contains spaces, like "Hello World".

- Tested different inputs with multiple spaces to make sure the reversal works for all characters.
