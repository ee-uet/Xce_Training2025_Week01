# Insertion Sort Program

## Introduction  
This program implements the **insertion sort algorithm** to sort an array of integers in ascending order.  
It processes the array element by element, shifting larger values to the right, and then inserts the current element into its correct sorted position.  

---

## Problem  
Write a RISC-V program that:  
- Loads an array of integers from memory.  
- Sorts the array using the insertion sort algorithm.  
- Stores the sorted result back into the same memory location.  

---

## Approach  
- The array and its length `n` are defined in the `.data` section.  
- The algorithm uses **byte indexing** (`.byte` = 1 byte per element).  
- Outer loop (`loop1`) picks the next element (`key`) starting from the second position.  
- Inner loop (`loop2`) shifts all elements greater than `key` one position to the right.  
- Once the correct location is found, `key` is inserted.  
- The outer loop increments index `i` and repeats until all elements are processed.  

---

## Registers used  
- **x5**: Base address of the array.  
- **x6**: Array size (`n`).  
- **x7**: Current index `i` (starts at 1).  
- **x10**: Address of `arr[i]`.  
- **x11**: Key value (current element being inserted).  
- **x12**: Index `j` (used for shifting elements).  
- **x13**: Address of `arr[j]`.  
- **x14**: Value `arr[j]`.  
- **x15**: Comparison result (`arr[j] - key`).  

---

## Instruction Flow  
1. Load base address of `my_array` and size `n`.  
2. Initialize `i = 1`.  
3. Outer loop (`loop1`):  
   - Stop if `i >= n`.  
   - Load `key = arr[i]`.  
   - Set `j = i - 1`.  
4. Inner loop (`loop2`):  
   - While `j >= 0` and `arr[j] > key`:  
     - Shift `arr[j]` to `arr[j+1]`.  
     - Decrement `j`.  
5. Insert `key` at the correct position.  
6. Increment `i` and repeat.  

---

## Examples  

### Example 1: Input array = {12, 11, 13, 5, 6}  
- Step 1: Insert 11 → {11, 12, 13, 5, 6}  
- Step 2:  {11, 12, 13, 5, 6} (unchanged)  
- Step 3: Insert 5  → {5, 11, 12, 13, 6}  
- Step 4: Insert 6  → {5, 6, 11, 12, 13}  
- Final sorted array = {5, 6, 11, 12, 13}  

### Example 2: Input array = {3, 1, 2}  
-  Step 1: {1, 3, 2}  
-  Step 2: {1, 2, 3}



---



## AI Usage  
- Used AI to reformat word file into Markdown.  
- Used AI to correct syntax and logic related to outer loop.
---

