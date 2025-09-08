# Problem 1: Absolute Difference  

## Problem  
Write a RISC-V assembly program to calculate the **absolute difference** between two numbers.  

## Approach  
- Load the two numbers into registers (`a0`, `a1`).  
- Subtract `a1` from `a0` and store the result in `a2`.  
- If the result is already positive, keep it.  
- If the result is negative, negate it to get the absolute value.  
- Use the `tohost` mechanism to signal program termination.  

## How to Run  
1. **Build the program**  
   ```bash
   make
2. **Run with Spike**
    make run
3. **Debug with Spike**
    make debug

## Example Output 
Input values: a0 = 10, a1 = 20
Calculation: 10 - 20 = -10 → absolute value = 10

## Known Limitations
1. Numbers are hardcoded; no user input is supported.
2. Output is not directly printed, only observable via Spike logs or register inspection.

