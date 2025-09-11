# Problem
Implement an insertion sort algorithm for sorting an array.
#
**Approach**

1. Initialize values

   - Load the base address of the array into x5.

   - Store the array size (n = 5) in x6.

2. Start the outer loop counter i in x7.

   - Outer Loop (i = 1 to n-1)

   - Repeatedly go through the array until all elements are sorted.

   - For each pass, set the inner loop counter j = i-1.

3. Inner Loop (compare and swap)

   - Compare array[j] with array[j+1].

   - If array[j] > array[j+1], swap them.

   - Decrement j and repeat until reaching the start of the array.

4. Repeat Passes

   - Increment i and run the next outer loop pass.

   - This pushes larger values toward the end of the array step by step.

5. Completion  
When all passes are done, the array is sorted.

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
Iteration 1:

Compare 3 and 2 , swap = [2, 3, 1, 4, 5]

Compare 3 and 1 , swap = [2, 1, 3, 4, 5]

Compare 3 and 4 , no swap

Compare 4 and 5 , no swap

Array iteration 1: [2, 1, 3, 4, 5]

Iteration 2:

Compare 2 and 1 , swap = [1, 2, 3, 4, 5]

Compare 2 and 3 , no swap

Compare 3 and 4 , no swap

Compare 4 and 5 , no swap

Array iteration 2: [1, 2, 3, 4, 5]

Iteration 3:

Already sorted, no swaps needed.

#
**Known limitations**  
 The program assumes the array size is known in advance. It won’t work for arrays of other lengths without modifying the code.