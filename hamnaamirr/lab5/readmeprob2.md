#  Bit Count Program

## Introduction  
This program counts the number of set bits (1s) in a word.  
It loads a number from memory, shifts through all its bits, and increments a counter each time a bit is 1.  


---

## Problem  
Write a RISC-V program that:  
- Loads a 32-bit word from memory.  
- Iterates through its bits, checking each one.  
- Counts how many bits are set to 1.  
- Stores the result in a register and signals pass to Spike.  

---

## Approach  
- Place the number to test (`my_number = 12345`) in the `.text` section.  
- Load the word into a register (`x1`).  
- Use a loop to:  
  1. Mask the least significant bit (`andi x2, x1, 1`).  
  2. If it is 1, increment the counter (`a0`).  
  3. Shift the number right by 1 (`srli`).  
  4. Repeat until all bits are shifted out.  
  
---



## Registers used  
- **x1**: Holds shifting number.  
- **x2**: Temporary register for LSB test.  
- **a0**: Counter for number of set bits.  
- **a1**: Constant `1` for comparison.   
- **x4**: Holds address of `my_number`.  

---

## Instruction Flow  
1. Load `my_number` (12345) into `x1`.  
2. Initialize `a0=0` (count) and `a1=1` (mask).  
3. Loop:  
   - `andi x2, x1, 1` → check least significant bit.  
   - If equal to 1, increment `a0`.  
   - Shift right: `srli x1, x1, 1`.  
   - Repeat until `x1=0`.  
4. Write `1` to `tohost` to signal pass.  
5. Infinite loop to stop execution.  

---

## Examples  

### Example 1: my_number = 12345  
Binary representation: `00000000000000000011000000111001`  
Number of set bits = 6  
Result stored in `a0 = 6`.  

### Example 2: my_number = 255  
Binary representation: `00000000000000000000000011111111`  
Number of set bits = 8  
Result stored in `a0 = 8`.  

### Example 3: my_number = 0  
Binary representation: `000...0`  
Number of set bits = 0  
Result stored in `a0 = 0`.  




---

## AI Usage  
- Used AI to reformat word file into Markdown.  

---

