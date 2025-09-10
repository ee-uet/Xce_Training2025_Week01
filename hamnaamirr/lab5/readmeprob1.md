# Absolute difference

## Introduction  
This is a  program that performs a signed subtraction, conditionally negates the result to make it non-negative(if its negative).In other words it finds the absolute of subtraction.

---

## Problem  
Write a tiny RISC-V assembly program that:  
- Computes x2 = x1 − x3 and ensures x2 is non-negative.  
- Runs in a bare-metal environment.

---

## Approach  
- Load operands into registers (`li x1, 10`, `li x3, 25`).  
- Perform subtraction (`sub x2, x1, x3`).  
- If the result is negative, negate it (`sub x2, x0, x2`).  
  

---





## Registers used  
- **x1**: first operand (10)  
- **x3**: second operand (25)  
- **x2**: result register (|x1 − x3|)  
- **t0**: pass code (1)  
- **t1**: pointer to `tohost`  

---

## Instruction Flow  
1. `li x1, 10` → load operand 1.  
2. `li x3, 25` → load operand 2.  
3. `sub x2, x1, x3` → compute difference.  
4. `bge x2, x0, done` → skip negate if result ≥ 0.  
5. `sub x2, x0, x2` → negate if result < 0.  
6.  

---

## Examples  

### Example 1: As written  
- x1 = 10, x3 = 25  
- x2 = 10 − 25 = −15 → negated to 15  
- Writes `tohost = 1` → Spike interprets as test pass.  

### Example 2: Positive result  
- Change `li x1, 40`, keep `li x3, 25`  
- x2 = 40 − 25 = 15 (non-negative, no negate).  
- Writes `tohost = 1`.  

### Example 3: Equal operands  
- x1 = 25, x3 = 25  
- x2 = 0 → result ≥ 0, no negate.  
- Writes `tohost = 1`.  

---



## AI Usage  
- Used AI to reformat word file into structured Markdown.  

---


