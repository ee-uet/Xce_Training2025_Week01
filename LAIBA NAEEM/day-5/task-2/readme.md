# Problem
Write an assembly program for setting or clearing any bit in a 32-bit number in RISC-V assembly language.
 - Write a C code for the same purpose.
 - Use the toolchain to build the assembly file from your C file. 
 - Compare the two assembly files. Which is more optimized? 
 - Run both on spike and see their working.

#
**Approach**
1. Understand the Algorithm

    - First, I studied bit manipulation operations (setting and clearing a bit) using Google.

    - I understood how to: Set a bit: Use bitwise OR (|) with a mask 1 << position. 
    Clear a bit: Use bitwise AND (&) with the negated mask ~(1 << position).

2. C Code

   -    Implemented the algorithm in C to test it with user input:

   - Read values a and b.

   - Read positions to set and clear.

   - Apply bitwise operations to get the final result.

   - Printed the results to verify correctness.
3. Assembly Code
  Then wrote my own RISC-V assembly manually, following the same algorithm.
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
a = 0b1010   (decimal 10)  
b = 0b1101   (decimal 13)   
Set bit position = 1  
Clear bit position = 2  
Set bit:
1010 & 0010 = 1010  
Clear bit:
1101 & 1011 = 1001
#
**Known Limitations**
The assembly program uses fixed bit positions for setting and clearing.
It cannot accept dynamic input for bit positions at runtime.
#
**AI/verification**

 AI Assistance – To understand the bitwise shifting and logic in the code.

After understanding, I implemented the C code and then wrote the RISC-V assembly myself.