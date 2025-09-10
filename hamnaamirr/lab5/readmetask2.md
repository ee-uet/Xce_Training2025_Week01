# Bit Set/Clear Program 

## Introduction  
This program **sets or clears a specific bit** in a 32-bit integer.  
The target bit position is given by an index, and the action (set vs clear) is selected via a flag.

---

## Problem  
Write a RISC-V program that:  
- Takes a 32-bit number and a **bit position** (0-based).  
- **Sets** that bit if `setbit != 0`, otherwise **clears** it if `setbit == 0`.  


---

## Approach  
1. Load inputs:  
   - `x1` = number (the value to modify)  
   - `x2` = bit index (0-based)  
   - `x3` = set/clear flag (`0` ⇒ clear, non-zero ⇒ set)  
2. Build a **single-bit mask** in `x4` by left-shifting `1` by `x2`.  
3. Branch on `x3`:  
   - If `x3 == 0` → **clear**: invert mask and AND with number.  
   - Else **set**: OR mask with number.  

---

## Registers Used  
- **x1**: Input number (modified in place to the bit-updated result)  
- **x2**: Bit position (0–31)  
- **x3**: Action flag (`0` → clear bit, non-zero → set bit)  
- **x4**: Working mask (`1 << x2`)  


---

## Instruction Flow  
1. `li x1, 32` → number = `0b…0010_0000` (only bit 5 set)  
2. `li x2, 5` → target **bit index = 5**  
3. `li x3, 0` → **clear** mode (set if non-zero)  
4. `li x4, 1` ; `sll x4, x4, x2` → `x4 = 1 << 5` (mask for bit 5)  
5. `beq x3, x0, clear_bit` → since `x3==0`, go clear path  
6. **Clear bit** path:  
   - `xori x4, x4, -1` → bitwise NOT of mask (all 1s except target bit)  
   - `and x1, x1, x4` → zero out target bit  
7. **Set bit** path (if taken):  
   - `or x1, x1, x4` → set target bit  
8. Signal pass: `sd 1, 0(tohost)`

---

## Example  
With the defaults in code:  
- `x1 = 32` (`0000000000000000000000000010_0000₂`), `x2 = 5`, `x3 = 0` (clear)  
- Target is **bit 5**; since it’s already 1 and we’re clearing, result becomes `0`.

If `x3` were non-zero (set):  
- `x1` would become `x1 | (1 << 5)` (ensures bit 5 is 1).

---

## AI usage:
- Used AI to help make readme file.
- Used AI to implement bitwise not using xori.
---

