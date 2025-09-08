# Task 1.3 – Pointer Arithmetic on Array

## Problem
- Create an integer array and perform pointer-based operations:
  1. Print all elements using pointers.
  2. Calculate the sum of array elements.
  3. Reverse the array in place using pointer arithmetic.

---

## Approach
1. Declare an array `arr[] = {1,2,3,4,5}`.  
2. Use a pointer (`ptr`) to iterate and print all elements.  
3. While iterating, accumulate the sum.  
4. To reverse the array:
   - Set `ptr` to start of array.
   - Set another pointer `a` to last element.
   - Swap values while moving `ptr` forward and `a` backward until they meet.  
5. Print the reversed array.  

---

## How to Run
1. Save the code in a file, e.g., `task1_3.c`.  
2. Compile the program:  
   ```bash
   gcc task1_3.c -o task1_3
    ./task1_3

## Example Output
Array elements are: 1 2 3 4 5 
The Sum is: 15
Reverse array elements are: 5 4 3 2 1 

## Known Limitations

Works only with statically defined arrays (no dynamic size handling).

Array contents are hardcoded in the function.

No user input functionality.