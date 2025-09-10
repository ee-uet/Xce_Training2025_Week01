# Problem
Implement a program to reverse an array in-place.
#
**Approach**

1. Setup addresses and indices

    - Load the starting address of the original array into x5.

    - Load the starting address of the reversed array into x6.

    - Set x7 = 3 (index of the last element of the original array).

    - Set x8 = 0 (index for filling the reversed array).

2. Loop through elements

    - Check if x7 < 0. If yes, stop the loop.
    Otherwise: Use x9 = &array[x7] to point to the current element in the original array. Load that element into x10. Use x11 = &rev_array[x8] to point to the current position in the reversed array. Store the element (x10) there. Decrease x7 by 1 (move backward in original array). Increase x8 by 1 (move forward in reversed array).
    - Repeat until done.

1. Finish

    - After the loop ends, rev_array contains the reversed version of array.

#
**How to run**

1.	Assemble and link your code: Use these commands to assemble and link your code with the new linker script:
riscv64-unknown-elf-as -o example.o example.s, 
riscv64-unknown-elf-ld -T link.ld -o example example.o
2.	Run your code with Spike:  
spike example
3.	For debugging  
spike -d example
4.	Or you may use the following command to see the result too:  
spike -d –log-commits example
#
**Example**  
Iteration 1:

x7 = 3  array[3] = 4

Place 4 in rev_array[0]    
array becomes   [4, _, _, _]

Iteration 2:

x7 = 2  array[2] = 3

Place 3 in rev_array[1]   
array becomes  [4, 3, _, _]

Iteration 3:

x7 = 1  array[1] = 2

Place 2 in rev_array[2]   
array becomes  [4, 3, 2, _]

Iteration 4:

x7 = 0  array[0] = 1

Place 1 in rev_array[3]   
array becomes [4, 3, 2, 1]

Loop ends when x7 < 0.

#
**Known limitations**  
 The program assumes the array size is known in advance (x7 is hardcoded as 3 for 4 elements). It won’t work for arrays of other lengths without modifying the code.