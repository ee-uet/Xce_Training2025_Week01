# Problem
Write a recursive function factorial(int n) that calculates factorial.
#
**Approach**

1. First, the program asks the user to enter a number n.

2. A function factorial(n) is used to calculate the factorial.

3. The factorial function works like this:

   - If n is 0, it returns 1 (because 0! = 1). Otherwise, it multiplies n with factorial(n-1). This means the function calls itself repeatedly with n-1, then n-2, then n-3, and so on, until it reaches 0.
  Each call returns a value that is multiplied by the previous n, building up the factorial.

4. The final result is sent back to the main program.

5. The program prints the factorial of the entered number.

##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
**Example**
1. User enters 5

2. Program calls factorial(5)

   - Since 5 != 0, it calculates 5 * factorial(4)

   - Program calls factorial(4)

   - Since 4 != 0, it calculates 4 * factorial(3)

   - Program calls factorial(3)

   - Since 3 != 0, it calculates 3 * factorial(2)

   - Program calls factorial(2)

   - Since 2 != 0, it calculates 2 * factorial(1)

   - Program calls factorial(1)

   - Since 1 != 0, it calculates 1 * factorial(0)

   - Program calls factorial(0)

   - Since 0 == 0, it returns 1

3. The returned values are multiplied step by step:

   - factorial(1) = 1 * 1 = 1

   - factorial(2) = 2 * 1 = 2

   - factorial(3) = 3 * 2 = 6

   - factorial(4) = 4 * 6 = 24

   - factorial(5) = 5 * 24 = 120

Final output = 120.
#
**Known Limitations**   
If the user enters a negative number, the program crashes because factorial is only defined for 0 or positive numbers.
This is what I get when I tried to enter to negative number:  
Enter a number: -3  
Segmentation fault (core dumped).

