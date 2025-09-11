#  Factorial Program

## Introduction  
This  program computes the factorial of a number stored in memory.  
It multiplies the number by decremented values in a loop until reaching 1.  

---

## Problem  
Write a RISC-V program that:  
- Loads a number from memory.  
- Computes its factorial (`n! = n × (n-1) × (n-2) ... × 1`).  
- Stores the result in a register.  

---

## Approach  
- Place the number (`my_number = 4`) in memory.  
- Load the value into `x1`.  
- Use `x4` as a decrementing counter (`n-1`).  
- Multiply repeatedly (`mul x1, x1, x4`) until `x4` reaches 0.  
- At the end, `x1` contains the factorial of `my_number`.  


---





## Registers used  
- **x1**: Holds the current result (factorial value).  
- **x4**: Decrementing counter (n−1, n−2, …).  
- **x5**: Holds address of `my_number`.  
  

---

## Instruction Flow  
1. Load number from memory into `x1`.  
2. Initialize `x4 = x1 − 1`.  
3. Loop:  
   - Multiply: `x1 = x1 × x4`.  
   - Decrement: `x4 = x4 − 1`.  
   - Repeat while `x4 > 0`.  
4. Result (n!) is stored in `x1`.  


---

## Examples  

### Example 1: my_number = 4  
- 4! = 4 × 3 × 2 × 1 = 24  
- Result: `x1 = 24`.  

### Example 2: my_number = 5  
- 5! = 5 × 4 × 3 × 2 × 1 = 120  
- Result: `x1 = 120`.  

### Example 3: my_number = 1  
- 1! = 1  
- Result: `x1 = 1`.  

---



## AI Usage  
- Used AI to reformat word file into Markdown.  

---

