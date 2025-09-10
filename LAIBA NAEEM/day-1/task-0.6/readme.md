# Problem
Write a program that:
- 	Reads 5 integers from the user and stores them in a file (numbers.txt).
- 	Reads back the integers from the file and prints them on the console.
#
**Approach**
- First, the program asks the user to enter 5 integers and stores them in an array.

- The program opens a file named numbers.txt in write mode.

- It writes all 5 integers into the file using fprintf().

- The file is then closed to save the data.

- Next, the program opens the same file in read mode.

- It reads the integers one by one using fscanf() and prints them on the screen.

- Finally, the file is closed after reading.

This demonstrates basic file input/output operations in C.
##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
*Example*
1. User enters the numbers: 10 25 7 18 3

2. Program opens numbers.txt in write mode and writes the numbers:

3. File content after writing: 10 25 7 18 3

4. Program closes the file.

5. Program opens numbers.txt in read mode.

6. Program reads numbers one by one using fscanf():

   - Reads 10 ; prints 10

   - Reads 25 ; prints 25

   - Reads 7 ; prints 7

   - Reads 18 ; prints 18

   - Reads 3 ; prints 3

Program closes the file.
#
**AI Usage / What I Verified**

- I understood the difference between fscanf and scanf, and between fprintf and printf using Google and AI.

- Learned how to read from and write to a file in C.

- Verified the syntax and behavior of file input/output.
