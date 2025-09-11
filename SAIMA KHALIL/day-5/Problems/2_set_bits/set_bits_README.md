## Count Set Bits in a 32-bit Number 
This program counts the number of **set bits (1s)** in a 32-bit integer.
It loops through all 32 bits, extracts each bit, and increments a counter when the bit is `1`.

---

### Code Overview

| Register | Purpose |
|----------|---------|
| `t0`     | Input number (shifts right each iteration) |
| `t1`     | Count of set bits (final result) |
| `t2`     | Bit counter (number of iterations = 32) |
| `t3`     | Temporary : stores extracted LSB |

---

### Algorithm

1. **Initialize**
   ```assembly
   li t0, 0b11010101100101010010101010101010   # Example 32-bit number
   li t1, 0        # count = 0
   li t2, 32       # 32 bits to check
   ```
other steps are:
Loop through all bits
If all bits checked (t2 == 0) : exit loop
Extract least significant bit (LSB) using andi
Add extracted bit to t1 (bit counter)
Shift right by 1 (srli)
Decrement loop counter (addi)
**Finish**
Signal completion to Spike i-e via tohost
done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

---

---

### Built and Run the Program 
1. Assembled the .s file and linked it using the Makefile to create the executable. 
2. Ran the program using the Spike simulator .through the Makefile.