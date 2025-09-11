# Problem
Write an assembly program for restoring division algorithm in RISC-V assembly language.
 - Use the toolchain to build the assembly file from your C file. 
 - Compare the two assembly files. Which is more optimized? 
 - Run both on spike and see their working.
#
**Approach**
1. Understand the Algorithm

   - First, I studied the Restoring Division Algorithm using Google and YouTube.

   - I made sure I understood each step:

    - Initialize remainder R = 0 and quotient Q = dividend.

    - Shift left R and Q in each iteration.

    - Subtract the divisor M from R.

    - If R < 0, restore R by adding M back; else set the least significant bit (LSB) of Q to 1.

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
1. Shift left R and Q R = 0001, Q = 1010

2. Subtract M: R = 0001 - 1010 = -3

3. Restore R: R = -3 + 4 = 1

4. Q LSB = 0
- Iteration 2:
1. Shift left R and Q R = 0011, Q = 0100

2. Subtract M: R = 3 - 4 = -1

3. Restore R: R = -1 + 4 = 3

4. Q LSB = 0
- Iteration 3:
1. Shift left R and Q R = 0110, Q = 1000

2. Subtract M: R = 6 - 4 = 2

3. Q LSB = 1
- Iteration 4:
1. Shift left R and Q R = 0101, Q = 0010

2. Subtract M: R = 5 - 4 = 1

3. Q LSB = 1  
   
Final Output:
R = 0001  , Q = 0011
#
**Known Limitations**
The program uses a fixed number of bits (n = 4 in my C code). It will not work correctly for larger numbers without adjusting n.
#
**AI/verification**
1. Google / YouTube – To understand the Restoring Division Algorithm step by step.

2. AI Assistance – To understand the bitwise shifting and logic in the code.

After understanding, I implemented the C code and then wrote the RISC-V assembly myself.