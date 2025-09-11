## Reverse an Array 

This program reverses an array **in-place**.  
eg, the array `[9, 2, 3, 4, 5]` becomes `[5, 4, 3, 2, 9]`.

---

###     Code Overview

| Register | Purpose |
|----------|---------|
| `t0`     | Base address of array |
| `t1`     | Right index offset (decreasing) |
| `t2`     | Left index offset (increasing) |
| `t3`     | Address of left element |
| `t4`     | Value of left element |
| `t5`     | Address of right element |
| `t6`     | Value of right element |

---

### Algorithm

1. **Initialization**
   ```assembly
   la t0, array      # Base address of array
   li t1, 16         # Right index offset (last element = 4*4 = 16 bytes)
   li t2, 0          # Left index offset (first element = 0 bytes)
   ```
Array has 5 elements :last element offset = 4 × (5-1) = 16)
other steps:
Swap elements Loop
If t2 >= t1 :stop (array reversed).
else:
Load left element (lw t4, 0(t3))
Load right element (lw t6, 0(t5))
Swap them (sw t6, 0(t3) and sw t4, 0(t5))
Move left index forward (t2 += 4)
Move right index backward (t1 -= 4)
```assembly
reverse_loop:
    bge t2, t1, done
 
    add t3, t0, t2   # Left element address
    lw t4, 0(t3)     # Load left

    add t5, t0, t1   # Right element address
    lw t6, 0(t5)     # Load right

    sw t6, 0(t3)     # Store right into left
    sw t4, 0(t5)     # Store left into right
    
    addi t2, t2, 4   # Left++
    addi t1, t1, -4  # Right--
    j reverse_loop
```


**Finish**
Signal Spike simulator using tohost.

---

---

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.