## Bit Manipulation  

This program demonstrates how to **set or clear a specific bit** of a given number **.

---

### Code Overview

| Register | Purpose |
|----------|----------|
| `t0`     | Number (`num`) whose bit will be modified |
| `t1`     | Bit position (`pos`) |
| `t2`     | Choice (1 = set bit, 2 = clear bit) |
| `t3`     | Mask (`1 << pos`) |
| `t4`     | Temporary register for branch comparison |
| `t5`     | Address to store result |
| `t6`     | Address for `tohost` (used for Spike simulator) |

---

## Algorithm  

1. **Initialization**
   ```assembly
   li t0, 22       # num = 22 (0b10110)
   li t1, 2        # pos = 2
   li t2, 2        # choice = 1=set, 2=clear
Other steps,
**Mask Creation**
li t3, 1
sll t3, t3, t1   # mask = 1 << pos

**Branching Based on Choice**
If choice == 1 : **Set bit**
or t0, t0, t3    # num = num | mask

If choice == 2 : **Clear bit**
not t3, t3       # ~mask
and t0, t0, t3   # num = num & ~mask

**Store Result**

la t5, result
sw t0, 0(t5)

---

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.