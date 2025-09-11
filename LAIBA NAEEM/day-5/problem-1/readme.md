# Problem
Implement a program to calculate the absolute difference between two numbers.
#
**Approach**

- First,  load two numbers into registers x3 and x1.

- 
  Subtract one number from the other: x2 = x3 - x1. This might give a negative result. If the result (x2) is negative,  change it to positive using the neg instruction. Now x2 always has the absolute difference.

- Store the result in memory

- Load the address of variable a (or some memory location) and store the result x2 there.

- Exit the program

- Finally, write a value to tohost (used in RISC-V test environment) to signal program end.
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
1. Input values  
First number = 30  
Second number = 40

2. Steps performed by program  
Subtracts: 30 - 40 = -10
Checks if result is negative. Yes, so it negates.
Final result = 10 (absolute difference).

3. Stored outp
The result 10 is stored in memory at label a.
#
**Known limitations**
1. The program always uses fixed numbers (30 and 40). It does not take input from the user or from memory.
2. The result is stored using sb (store byte). If the absolute difference is larger than 255, it will overflow.