## Insertion Sort  

This program implements **Insertion Sort** on an integer array .  
It sorts the array in **ascending order**.

---

### Code Overview

| Register | Purpose |
|----------|---------|
| `t0`     | Base address of array |
| `t1`     | Number of elements (n) |
| `t2`     | Loop index `i` |
| `a0`     | Offset for index calculation (i*4) |
| `a1`     | Address of key element |
| `a2`     | Key (current element being inserted) |
| `a3`     | Index `j` (for inner loop) |
| `a4`     | Offset for index `j` |
| `a5`     | Address of element at `j` |
| `a6`     | Value of element at `j` |

---

### Algorithm  

1. **Initialization**
   ```assembly
   la t0, array    # Base address of array
   li t1, 6        # Number of elements
   li t2, 1        # Start from i = 1
   ```
Other steps are:

**Outer Loop**
Runs while i < n
Picks the key = array[i]
Sets j = i-1
 ```assembly
outer_loop:
    bge t2, t1, done   # if i >= n, stop
    slli a0, t2, 2     # i * 4 (word offset)
    add a1, t0, a0
    lw a2, 0(a1)       # key = array[i]
    addi a3, t2, -1    # j = i-1
```

**Inner Loop (i-e forr Shifting Elements)**
While j >= 0 and array[j] > key, shift array[j] to the right.
 ```assembly
inner_loop:
    blt a3, x0, insert     # if j < 0 → break
    slli a4, a3, 2
    add a5, t0, a4
    lw a6, 0(a5)           # load array[j]

    bge a2, a6, insert     # if key >= array[j] → stop shifting

    sw a6, 4(a5)           # shift right
    addi a3, a3, -1        # j--
    j inner_loop
```
**Insert Key**
Place the key at the correct position i-e (j+1).
 ```assembly
insert:
    addi a3, a3, 1
    slli a4, a3, 2
    add a5, t0, a4
    sw a2, 0(a5)           # array[j+1] = key

    addi t2, t2, 1         # i++
    j outer_loop
```

**Done**
Signal Spike simulator with tohost

---

### Example
For clarity,its C implementation is:
![fd](example.jpg)

---

### Sources Used
Used some websites to see how it works .
Used AI to comprehend how can it be implemented using outer and inner loop.

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.