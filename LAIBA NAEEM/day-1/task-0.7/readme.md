# Problem
- Write a program that demonstrates:  
 AND &, OR |, XOR ^, NOT ~, and bit-shifting <<, >>.  
  
- Write a function that checks if a number is power of 2 using bitwise operators only.
#
**Approach**
- Declare two integers a and b to demonstrate bitwise operations, and another integer j to check for power of 2.

- Perform bitwise AND, OR, XOR, NOT, and left shift operations on a and b.

- To check if a number is a power of 2, use (i & (i-1)) == 0.

- This works because a number that is a power of 2 has only one bit set in binary. Subtracting 1 flips all bits to the right of that bit. ANDing with the original number gives 0 if there was only one bit set.

- Print the results of all operations and indicate whether the number is a power of 2.
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
#
**Example**  
**Bitwise operations between a and b**
a = 4  
b = 5    
a & b = 4  
a | b = 5  
a ^ b = 1  
~a = -5  
~b = -6  
a << 1 = 8    
b << 1 = 10  
**Power of 2 check**  
Example 1:  
- j = 8; binary = 1000  
- 8 - 1 = 7; binary 0111  
- 1000 & 0111 = 0000   
- So 8 is power of two.  

Example 2:  
- j = 5; binary = 0101  
- 5 - 1 = 4; binary 0100  
- 0101 & 0100 = 0100  
- So 5 is not power of two.
#
**AI Usage / What I Verified**

- I searched on Google to understand how to check if a number is a power of 2.

- Verified the logic by testing examples in the program to see it works correctly for both power-of-two and non-power-of-two numbers.

