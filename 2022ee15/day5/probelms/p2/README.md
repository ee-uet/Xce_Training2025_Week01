# Problem 2: Count Set Bits in a 32-bit Word  

## Problem  
Write a RISC-V assembly program to count the number of set bits (1s) in a 32-bit word.  

## Approach  
- Load the word into a register.  
- Use bitwise AND with `1` to extract the least significant bit (LSB).  
- If the LSB is 1, increment a counter.  
- Shift the word right by 1 and repeat until the word becomes 0.  
- Store the final count in a register (`t1`).  

## How to Run  
    ```bash
    make run
    make debug

## Known Limitations
1. Input value is hardcoded (0xAD230FC1). No user input support.
2. Only works for 32-bit words; for 64-bit, code changes are needed.

## Sources and AI Usage
1. Verified syntax for shifting (srli) and masking (andi) using AI.
