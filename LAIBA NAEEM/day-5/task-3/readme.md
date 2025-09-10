# Problem
Write an assembly program for non-restoring 32-bit unsigned division in RISC-V assembly language.
- Write a C code for the same purpose.
- 	Use the toolchain to build the assembly file from your C file. 
-	Compare the two assembly files. Which is more optimized? 
Run both on spike and see their working

#
**Approach**
1. Understand the Algorithm

   - First, I studied the non-Restoring Division Algorithm using Google and YouTube.

   - I made sure I understood each step:

    - Initialize remainder R = 0 and quotient Q = dividend.

    - Shift left R and Q in each iteration.

    - R >= 0, subtract the divisor M from R; if R < 0, restore R by adding M back.
    - If R >= 0 after the operation, set the least significant bit (LSB) of Q to 1

2. C Code

    - Implemented the algorithm in C for a small fixed number of bits (n = 4).

    - Used bitwise operations to shift and combine bits correctly.

    - Printed quotient and remainder to verify correctness.
3. Assembly code
4. Wrote my own RISC-V assembly manually, following the same algorithm.
#
**How tu run**  
**Assembly code**  
1.	Assemble and link your code: Use these commands to assemble and link your code with the new linker script:
riscv64-unknown-elf-as -o example.o example.s, 
riscv64-unknown-elf-ld -T link.ld -o example example.o
2.	Run your code with Spike:  
spike example
3.	For debugging  
spike -d example
4.	Or you may use the following command to see the result too:  
spike -d –log-commits example  

**Convert C code to Assembly**
Generate your assembly file from C file using the command:
gcc -S task1.c -o task1.s

**C code**
- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**  
Input:  
Dividend (Q) = 13  
Divisor  (M) = 4  
Number of bits (n) = 4  
Initialization:  
R = 0
Q = 13 (binary 1101)
M = 4  (binary 0100)
- Iteration 1:
1. Shift left A and Q  A = 0001, Q = 1010

2. Since A >= 0  Subtract M  A = 1 - 4 = -3

3. A < 0  Do not set Q LSB,  Q LSB = 0
- Iteration 2:

1. Shift left A and Q  A = 1011, Q = 0100

2. A < 0  Add M , A = -5 + 4 = -1

3. A < 0 , Q LSB = 0

- Iteration 3:
1. Shift left A and Q , A = 1110, Q = 1000

2. A < 0 → Add M , A = -2 + 4 = 2

3. A >= 0 , Set Q LSB = 1

- Iteration 4:

1. Shift left A and Q , A = 0001, Q = 1001

2. A >=  0  Subtract M , A = 5 - 4 = 1

3. A > 0  Q LSB = 1
   
Final Output:
R = 0001  , Q = 0011
#
**Known Limitations**
The program uses a fixed number of bits (n = 32 in my C code). It will not work correctly for larger numbers without adjusting n.
#
**AI/verification**

While testing my code, I was getting wrong answers for some inputs. I realized the issue was with the remainder register A. After checking with AI, I concluded that A should be declared as signed (int) so it can temporarily hold negative values during the division process. After this change, the code worked correctly and gave the right quotient and remainder.