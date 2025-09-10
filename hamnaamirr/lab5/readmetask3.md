# Non-Restoring Division Algorithm

## Introduction  
This program implements **integer division** using the *non-restoring division algorithm*.  
It computes the **quotient** and **remainder** by shifting in dividend bits and, at each step, **adding or subtracting** the divisor based on the **previous remainder’s sign** (no immediate “restore” after a negative result).

---

## Problem  
Write a RISC-V program that:  
- Divides a 32-bit **dividend** by a **divisor**.  
- Produces the **quotient** and the **remainder**.  

---

## Approach  
- Iterate from the **MSB to LSB** of the dividend 
- For each bit:  
  1) **Shift** the remainder left and **bring down** the next dividend bit: `R ← (R << 1) | next_bit`.  
  2) **If previous R ≥ 0**: do `R ← R − D`. **Else**: do `R ← R + D`.  
  3) **Set quotient bit** to **1** if the **updated** `R ≥ 0`, else **0**.  
- **After the loop**, if `R < 0`, do a **final correction**: `R ← R + D`.  

*(Key difference from restoring division: we don’t immediately restore on a negative result; we compensate on the **next** cycle by adding `D`, and possibly do one final correction at the end.)*

---

## Registers Used  
- **x1**: Dividend  
- **x2**: Quotient    
- **x3**: Remainder  
- **x4**: Divisor  
- **x5**: Bit index / loop counter  
- **x6**: Next dividend bit  
- **x7**: (optional temp) trial result if you keep both add/sub paths separate  
- **x8**: Bit mask used to set the current quotient bit  

---

## Instruction Flow  
1. Initialize: `R = 0`, `Q = 0`, set dividend, divisor, and loop counter.  
2. For each bit (from MSB→LSB):  
   - `R ← (R << 1) | next_bit` (shift in next dividend bit).  
   - If **previous R ≥ 0** then `R ← R − D`, else `R ← R + D`.  
   - If **R ≥ 0** then set the **current quotient bit = 1**, else **0**.  
3. After processing all bits:  
   - If **R < 0**, do **final correction** `R ← R + D`.  
4. `Q` and `R` are the final **quotient** and **remainder**.  

---

## Example  

## (43 ÷ 4)


- Dividend = **43** = `101011` (bits i = 5 → **1,0,1,0,1,1**)
- Divisor = **4** = `100`
- Start: **R = 0**, **Q = 0**

We process bits from **MSB → LSB** (i = 5 down to 0).  
At each step:
1) `R ← (R << 1) | bit_i`  
2) If **previous R ≥ 0** → `R ← R − D`, else `R ← R + D`  
3) If **R ≥ 0** → set `Q[i] = 1`, else `Q[i] = 0`

---

## Step i = 5 (bit = 1)
- Shift & bring: `R = (0 << 1) | 1 = 1`
- Previous R was ≥ 0 → **subtract**: `R = 1 − 4 = −3`
- Since `R < 0` → `Q[5] = 0`
- State: `R = −3`, `Q = 0b0`

## Step i = 4 (bit = 0)
- Shift & bring: `R = (−3 << 1) | 0 = −6`
- Previous R was < 0 → **add**: `R = −6 + 4 = −2`
- Since `R < 0` → `Q[4] = 0`
- State: `R = −2`, `Q = 0b00`

## Step i = 3 (bit = 1)
- Shift & bring: `R = (−2 << 1) | 1 = −3`
- Previous R was < 0 → **add**: `R = −3 + 4 = 1`
- Since `R ≥ 0` → `Q[3] = 1`
- State: `R = 1`, `Q = 0b001000` (bit 3 set)

---

## … (continue for i = 2, 1, 0) → Final
- After finishing all bits (i = 5):  
  - Quotient bits = `001010₂` = **10**
  - Remainder before correction = **−1**
- Final correction (non-restoring rule): `R = −1 + 4 = **3**`

### Result
- **Quotient = 10**  
- **Remainder = 3**  

**Therefore:** `43 ÷ 4 = 10` with remainder `3`.


---

## AI Usage  
- Reformatted your explanation into the requested Markdown structure.  
- Ran a complete non-restoring **hand trace** for 43 ÷ 4 with a clear step table.
