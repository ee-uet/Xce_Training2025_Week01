## Absolute Difference in RISC-V Assembly

This program calculates the **absolute difference** between two numbers.  
Then the result is stored in a register.

---

### Code Overview

| Register | Purpose |
|----------|---------|
| `t0`     | First number (input A) |
| `t1`     | Second number (input B) |
| `t2`     | Result : Absolute difference |
| `t1`     | Also used for `tohost` address later i-e at the end|

---

### Algorithm

1. **Initialization**
   ```assembly
   li t0, 15     # First number
   li t1, 25     # Second number
    ```
Other steps are : 
**Check Condition**
If t0 < t1 : jump to do_subtr
Else : t2 = t0 - t1
blt t0, t1, do_subtr
sub t2, t0, t1
**Subtraction (when t1 > t0)**
do_subtr:
    sub t2, t1, t0
**End**
Signal done to Spike via tohost
done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
---

#### Example Run
for Input
t0 = 15
t1 = 25

Output would be
Absolute Difference = |15 - 25| = 10 in t2

---

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.