#  Array Reversal Program

## Introduction  
This program reverses an array .
It swaps the first and last elements, then moves inward until all elements are reversed.  
 

---

## Problem  
Write a RISC-V program that:  
- Loads an array from memory.  
- Reverses the array in place (first element ↔ last element, second ↔ second-last, etc.).  
- Signals completion to Spike when done.  

---

## Approach  
- The array and its size (`n`) are stored in `.data`.  
- Registers are used for pointers and indices:  
  - `t1` = start index.  
  - `t2` = end index (`n − 1`).  
- Loop until start index > end index.  
- For each iteration:  
  1. Load array[start] and array[end].  
  2. Swap the two values.  
  3. Increment start, decrement end.  


---



## Registers used  
- **t0**: Base address of array.  
- **t1**: Start index (increasing).  
- **t2**: End index (decreasing).  
- **t3**: Address of `array[start]`.  
- **t4**: Value at `array[start]`.  
- **t5**: Address of `array[end]`.  
- **t6**: Value at `array[end]`.  
- **x2**: Address of `n`.  
- **x1**: Length of array (`n`).  

---

## Instruction Flow  
1. Load array base address into `t0`.  
2. Load array length (`n`) into `x1`, set `t2 = n − 1`.  
3. Loop:  
   - If `t2 < t1`, exit.  
   - Load array[start] into `t4`.  
   - Load array[end] into `t6`.  
   - Swap values using `sb`.  
   - Increment start (`t1++`), decrement end (`t2--`).  

---

## Examples  

### Example 1: Input array = {10, 20, 30, 40}  
- Start = 0, End = 3  
- Step 1: Swap 10 ↔ 40 → {40, 20, 30, 10}  
- Step 2: Swap 20 ↔ 30 → {40, 30, 20, 10}  
- Final result = {40, 30, 20, 10}  

### Example 2: Input array = {1, 2, 3}  
- Result = {3, 2, 1}  


---



## AI Usage  
- Used AI to reformat word file into structured Markdown.  

---

