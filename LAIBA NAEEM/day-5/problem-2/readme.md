# Problem
Implement a function to count the number of set bits in a 32-bit word. 
#
**Approach**

1. Initialize values

    - Load a 32-bit binary number into t1.

    - Set t2 = 0  this will hold the count of 1 bits.

    - Set t4 = 32  loop will run 32 times (for each bit).

2. Loop through each bit

   - Use andi t3, t1, 1 to check the least significant bit (LSB).

   - If LSB is 1, increase the counter (t2 = t2 + 1).

   - Shift the number right by 1 (srli t1, t1, 1) to check the next bit.

    - Decrease loop counter t4.

   - Repeat until all 32 bits are checked.

3. Finish

   - After the loop, t2 contains the total number of 1 bits.

   - Store this result into memory at label a.
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
Input = 10110111001101010010011111001010  
Loop checks each bit one by one (from right to left).Whenever it finds a 1, it increases the counter t2.
After 32 shifts, all bits are checked.
In this examplete there are 18 ones.
So, the final value of t2 will be 18.

#
**Known limitations**  
 The program always uses fixed number. It does not take input from the user or from memory.
