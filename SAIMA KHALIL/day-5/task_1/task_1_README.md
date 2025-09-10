## Non-Restoring Division  

This assembly program implements a **non-restoring division algorithm** and does non-restoring divison and produces   quotient and remainder.

---

###  Code Overview


| Register | Purpose |
|----------|---------|
| `t0`     | Q (Dividend or quotient) |
| `t1`     | M (Divisor) |
| `t3`     | A (Accumulator or remainder) |
| `t4`     | Loop counter (number of bits) |
| `t5`     |  MSB extraction |
| `t6`     | Address for tohost |

---

### Algorithm  

1. **Initialization**
   ```assembly
   li t0, 22      # Q = 10110 (dividend)
   li t1, 3       # M = 00011 (divisor)
   li t3, 0       # A = 00000 (accumulator)
   li t4, 5       # n = 5 iterations
   ```
2. **Loop**
At first,perform a combined left shift of A and Q.
At second,extract the MSB of Q and place it in the LSB of A.
Then,subtract the divisor i-e A = A - M.
Then check,if A is negative, restore A .
i-e A = A + M.
Set LSB of Q according to result.
At last,decrement loop counter and repeat until n = 0

**Finalize**
Mask quotient and remainder to n bits.

---

#### Example 
![j](example.jpg)

###   Built and Run the Program

1. Assembled the `.s` file and linked it using the Makefile to create the executable.  
2. Ran the program using the Spike simulator .through the Makefile.
```bash
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
 
PROG ?= task01

all: $(PROG)

$(PROG): $(PROG).s
	$(AS) -o $(PROG).o $<
	$(LD) -T linker.ld -o $@ $(PROG).o

run: $(PROG)
	$(SPIKE) $(PROG)

debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG)

clean:
	rm -f *.o $(PROG)

.PHONY: all run debug clean

```
---