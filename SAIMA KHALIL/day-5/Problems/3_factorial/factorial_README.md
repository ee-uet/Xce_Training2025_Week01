## Factorial  
This program computes the **factorial** of a number using an iterative loop  .  

---

### Code Overview

| Register | Purpose |
|----------|---------|
| `t0`     | Input number (n) |
| `t1`     | Result (factorial) |
| `t2`     | Counter (loop variable) |

---

### Algorithm

1. **Initialize**
   ```assembly
   li t0, 6      # Input number (n = 6)
   li t1, 1      # Result = 1
   li t2, 1      # Counter = 1
   ```

Othe rsteps are:
Loop until counter > n
Multiply result by counter (t1 = t1 * t2)
Increment counter (t2 = t2 + 1)
Repeat until t2 > t0
```assembly
factorial_loop:
    bgt t2, t0, done   # Exit if counter > n
    mul t1, t1, t2     # result *= counter
    addi t2, t2, 1     # counter++
    j factorial_loop
   ```
**End**
On completion, t1 holds the factorial result
Program signals Spike using tohost
done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

---

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.