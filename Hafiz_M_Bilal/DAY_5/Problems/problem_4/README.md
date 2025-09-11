# RISC-V Assembly Exercise: Reverse Array

## Problem
Write a RISC-V assembly program that reverses an array of integers in memory.  
The array should be reversed in place, without creating an extra array.

Example:  
Input:  `[1, 2, 3, 4, 5]`  
Output: `[5, 4, 3, 2, 1]`

## Approach
1. **Data Section**  
   - Define an array and its size:
   ```asm
   .data
   array: .word 1,2,3,4,5
   size:  .word 5
Load Pointers

a0 → points to the start of array.

a2 → points to the end of array ((size-1) * 4 + base).

Swap Loop

Load elements from a0 and a2.

Swap them using temporary registers.

Move a0 forward and a2 backward.

Stop when pointers cross.

Exit

Write to .tohost for Spike to exit.

## How to Run

Assemble and link:

make


Run with Spike:

make run


Debug execution:

make debug


Clean build:

make clean

## Example Output

Array in memory changes from:

1 2 3 4 5

to

5 4 3 2 1

## Known Limitations

Array size and elements are hardcoded in .data.

No direct console output; you need to inspect memory in Spike or debugger.

Works only with word-sized integers (4 bytes).