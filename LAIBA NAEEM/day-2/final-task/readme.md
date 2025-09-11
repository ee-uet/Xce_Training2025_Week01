# Problem
●	Write C code to implement Booth's multiplication algorithm.  
●	The function should take two signed integers as input and return their product.  
●	Use bit manipulation operators for efficient multiplication.  
●	Write a test function to verify the correctness of your Booth multiplier function.  

#
**Approach**

- First,  implemented a bitwise addition function that adds two numbers without using the + operator. This is needed for Booth’s algorithm.

-  then implemented Booth’s multiplication algorithm for signed 16-bit integers.

- Initialized A = 0 (accumulator) and Q_1 = 0 (extra bit).

- Repeated for the number of bits (n = 16):

- Checked the least significant bit of Q and Q_1 to decide whether to add, subtract, or do nothing.

- Performed an arithmetic right shift on the combined A and Q.

- Updated Q_1 for the next iteration.

- Finally, combined A and Q to get the final signed 32-bit product.

- Tested the algorithm with positive and negative numbers to verify correct signed multiplication.

Note: I used int16_t for inputs and int32_t for the final product to handle the full range of signed multiplication without overflow.
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**  
Output of my code:  
5 * 3 = 15  
-4 * 6 = -24  
-4 * 6 = -24  
-7 * -2 = 0  
#
**Knowm Limitations**  
The current implementation is designed to work for 16-bit signed inputs and produces a 32-bit product. Multiplying numbers larger than the intended bit-width may cause overflow or incorrect results.
#
**Resources and References**  
1. Studied the Booth’s Multiplication Algorithm using Google and YouTube to understand the theory and step-by-step working.

2. Used AI assistance to better understand how to implement the arithmetic shifting and bitwise operations in code.
