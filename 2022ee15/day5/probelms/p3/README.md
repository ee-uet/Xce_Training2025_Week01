# Problem 3: Factorial in RISC-V Assembly  

## Problem  
Write a RISC-V assembly program to calculate the factorial of a given number.  

## Approach  
- Load the number `n` into a register (`t0`).  
- Initialize an accumulator (`t1 = 1`).  
- Loop:  
  - Multiply accumulator by `t0`.  
  - Decrement `t0` until it reaches zero.  
- Store the result in `t1`.  

## Code Flow  
1. Initialize:  
   - `t0` ← 5 (input number).  
   - `t1` ← 1 (result).  
2. Loop:  
   - If `t0 == 0`, stop.  
   - Multiply result by `t0`.  
   - Decrement `t0`.  
3. Done:  
   - Factorial result is stored in `t1`.  
   - Signal exit using `tohost`.  

## How to Run  
    ```bash
    make run
    make debug
    
## Known Limitations
1. Input value is hardcoded (5).
2. Factorial grows quickly and can overflow 32-bit registers.
