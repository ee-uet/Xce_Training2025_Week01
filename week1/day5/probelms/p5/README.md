# Problem 5: Insertion Sort 

## Problem Statement
Implement an insertion sort algorithm in RISC-V assembly to sort an array of integers in ascending order.  


## Approach
- Start the outer loop at index `i = 1` (since the first element is already sorted).  
- Store the value at `arr[i]` in a temporary register (`key`).  
- Use an inner loop to shift all elements greater than `key` one position to the right.  
- Once the correct position is found (or when the start of the array is reached), insert the `key`.  
- Repeat until all elements are sorted.  

## How to Run
1. Assemble the program:
   ```bash
   make run
   make debug
   
## Known Limitations
1. Array length is fixed in the code (li t2, 5) and must be updated manually.
2. Works only for word-sized (.word) integers.

## Sources & AI
1. Checked the algorithm and C code online for insertion sort.

