# RISC-V Assembly Exercise: Insertion Sort

## Problem
Write a RISC-V assembly program that sorts an array of integers in **ascending order** using the **Insertion Sort** algorithm.  
The sorting should be done in-place (i.e., modifying the same array in memory).

Example:  
Input:  `[5, 3, 4, 1, 2]`  
Output: `[1, 2, 3, 4, 5]`

---

## Approach
1. **Data Section**
   - Define the array and its size:
   ```asm
   .data
   array: .word 5, 3, 4, 1, 2
   size:  .word 5
Initialization

a0 → base address of array.

a1 → size of array.

t1 → pointer to current element (starts from 2nd element).

t2 → counter for remaining elements.

Outer Loop

Take the current element (t3) from t1.

Shift all larger elements one step to the right until the correct position is found.

Inner Loop

Compare t3 with previous elements.

If previous element (t6) is greater, shift it forward.

Stop when the right position is found.

Insert

Store t3 at the correct position.

Move to next element and continue until all elements are sorted.

Exit

Write to .tohost so Spike exits cleanly.

## How to Run

Assemble and link:

make


Run in Spike:

make run


Debug step-by-step:

make debug


Clean build:

make clean

## Example Output

Initial array in memory:

5 3 4 1 2


After program execution:

1 2 3 4 5

(Check memory in Spike -d mode with mem 0 40 to see array before and after execution.)

## Known Limitations

Array size and contents are hardcoded in the .data section.

No direct console output (only memory update).

Works only with word-sized integers (4 bytes).

Sorting order is fixed to ascending (no descending mode).

## ources & AI Usage

This RISC-V assembly code was AI-assisted (ChatGPT). I used AI to understand:

How to implement insertion sort using RISC-V assembly instructions.

How to handle outer and inner loops with branch instructions (beq, ble, j).

How to properly use registers for array elements (t1, t2, t3, etc.) and shifting elements in memory.

How to signal program completion using the .tohost section.

The structure was guided by AI, but I typed, assembled, and debugged the code myself.

## What I Verified

I verified correctness by:

Running the program on a RISC-V simulator (e.g., Spike or QEMU).

Checking that the array [5, 3, 4, 1, 2] is sorted into [1, 2, 3, 4, 5].

Testing edge cases:

Array already sorted → algorithm makes no unnecessary changes.

Array of size 1 → remains unchanged.

Array with duplicates → maintains stable sorted order.

Confirming that the program terminates correctly at the finish label with .tohost.