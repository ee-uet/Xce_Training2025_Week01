# Task 5.2: Extend Array with realloc()  

## Problem  
Implement a function that uses `realloc()` to extend an existing dynamically allocated array.  

## Approach  
- Start with a dynamically allocated array of size `5` using `malloc`.  
- Initialize the array with values `1..5`.  
- Print the array before reallocation.  
- Ask the user for a new array size `n`.  
- Use `realloc` to resize the memory block to `n` integers.  
- Fill the resized array with values `1..n`.  
- Print the array after reallocation.  
- Free the allocated memory using `free()`.  

## How to Run  
1. **Compile the code:**  
   ```bash
   gcc task5_2.c -o out
2. **Run the executable:**
    ./out

## Test Cases
Case 1 – Increase size
Input: new size = 8
Output: Array after reallocation = 1 2 3 4 5 6 7 8
Case 2 – Decrease size
Input: new size = 3
Output: Array after reallocation = 1 2 3
Case 3 – Same size
Input: new size = 5
Output: Array after reallocation = 1 2 3 4 5

## Example Output
Array size before reallocation: 1  2  3  4  5  
Enter size for reallocation: 8  
Array size after reallocation: 1  2  3  4  5  6  7  8  

## Known Limitations
1. The program overwrites all elements with 1..n, so the original values are not preserved after resizing.
2. Memory allocation failure (malloc/realloc returning NULL) is not checked.

