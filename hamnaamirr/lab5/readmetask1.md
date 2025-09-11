# Restoring Division Algorithm

## Introduction  
This program implements **integer division** using the *restoring division algorithm*.
It calculates the **quotient** and **remainder** when dividing a dividend by a divisor using bitwise shifts and subtraction.

---

## Problem  
Write a RISC-V program that:  
- Divides a 32-bit integer dividend by a divisor.  
- Produces the **quotient** and **remainder**.  

---

## Approach  
- Initialize registers with dividend, divisor, quotient, and remainder.  
- Use a loop that iterates over all 32 bits of the dividend.  
- At each step:  
  - Left-shift the remainder and bring down the next dividend bit.  
  - Subtract the divisor.  
  - If subtraction is successful (non-negative), keep the result and set the current quotient bit = 1.  
  - If subtraction is negative, restore the remainder and set quotient bit = 0.  
- Continue until all bits have been processed.  

---

## Registers Used  
- **x1**: Dividend  
- **x2**: Quotient (result)  
- **x3**: Remainder  
- **x4**: Divisor  
- **x5**: Loop counter (bit size, 32)  
- **x6**: Temporary dividend bit  
- **x7**: Temporary subtraction result (`temp`)  
- **x8**: Temporary mask/bit for quotient update  

---

## Instruction Flow  
1. Initialize registers: dividend, divisor, remainder = 0, quotient = 0, loop size = 32.  
2. Loop (`loop`):  
   - Shift remainder left.  
   - Bring down next bit of dividend.  
   - Subtract divisor → store in `temp`.  
   - If `temp < 0`, restore remainder, quotient bit = 0.  
   - If `temp >= 0`, set remainder = temp, quotient bit = 1.  
3. Decrement loop counter and repeat until all 32 bits are processed.  
4. Store results in registers `x2` (quotient) and `x3` (remainder).  
 

---

## Example  

### Example 1: Dividend = 43, Divisor = 4  
- Initial: dividend = `101011₂ (43)`, divisor = `100₂ (4)`  
- initially: remainder is 0 shift it towards the left an bring down bits from the left of dividend
- remainder =1
- as 1<4 so no subtraction remainder stays 1 and quotient 0
- next iteration: left shift remainder it is now 10 bring down next bit of dividend it stays 10 which is 2 
- 2<4 no subtraction remainder becomes 2 quotient stays 0 and so on.
- After 32 iterations, final:  
  - Quotient = `1010₂ (10)`  
  - Remainder = `11₂ (3)`  

---

## AI Usage  
- Used AI to convert word into readme.
- Used AI to correct syntax error.
   
