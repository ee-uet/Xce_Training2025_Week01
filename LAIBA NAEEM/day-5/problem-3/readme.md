# Problem
Implement a program to calculate the factorial of a number.
#
**Approach**

1. Initialize number

   - Load the number (here 5) into t0.

   - Copy it into t1. This will hold the running factorial result.

   - Set t2 = t0 - 1.  This will be used to multiply step by step.

2. Loop (factorial calculation)

   - Check if t2 is zero. if yes, factorial is complete.

   - If not zero:

    - Multiply t1 = t1 * t2.

    - Decrease t2 by 1.

    - Jump back to repeat.

3. Finish

   - When loop ends, the final result is in t1.

   - Store the result into memory at label a.
#
**How to run**

3.	Assemble and link your code: Use these commands to assemble and link your code with the new linker script:
riscv64-unknown-elf-as -o example.o example.s, 
riscv64-unknown-elf-ld -T link.ld -o example example.o
4.	Run your code with Spike:  
spike example
5.	For debugging  
spike -d example
6.	Or you may use the following command to see the result too:  
spike -d –log-commits example
#
**Example**  
The program starts with t0 = 5.

1. Copy t0 into t1. factorial result starts as 5.

2. Set t2 = 4.

3. Loop multiplies step by step:

   t1 = 5 × 4 = 20

   t1 = 20 × 3 = 60

   t1 = 60 × 2 = 120

   t1 = 120 × 1 = 120. Then stop.

4. Final result 
  The factorial result 120 is stored in memory at label a.
#
**Known limitations**  
The program always uses fixed number. It does not take input from the user or from memory.
