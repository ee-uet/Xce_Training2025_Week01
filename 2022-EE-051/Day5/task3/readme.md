# Non-Restoring Division Algorithm – RISC-V Implementation

## Overview

This project demonstrates the **Non-Restoring Division Algorithm** implemented in both **C** and **RISC-V Assembly**.

Unlike the restoring method (where the remainder is “restored” if subtraction goes negative), the **non-restoring algorithm skips restoring** and directly decides the quotient bit in the next step.

The project covers:

- Writing the algorithm in **C**
- Translating it into **RISC-V Assembly** manually
- Generating assembly from C using **RISC-V GCC toolchain**
- Comparing **manual assembly** vs **compiler-generated** code
- Running and testing both versions using the **Spike RISC-V simulator**

---

## Algorithm Explanation (Non-Restoring)

1. Initialize `quotient = 0`, `remainder = 0`.
2. Loop over **32 bits** of the dividend (**MSB → LSB**):
   - Shift `remainder` left by 1.
   - Bring down the current dividend bit into `remainder`.
   - If `remainder ≥ divisor`: subtract divisor, set quotient bit = 1.
   - Else: leave remainder unchanged, quotient bit = 0.
3. After all iterations:
   - `quotient` contains the division result.
   - `remainder` contains the leftover.

---

## Step-by-Step Working of the C Code

1. **Initialization**
   - Dividend = 77  
   - Divisor = 7  
   - Quotient = 0  
   - Remainder = 0  

2. **For-loop (i = 31 → 0)**
   - Shift `rem` left by 1 and insert the current dividend bit.  
   - If `rem ≥ divisor`: subtract divisor, set the quotient bit = 1.  
   - Otherwise: leave remainder unchanged, quotient bit = 0.  

3. **End Result**
   - Quotient = 11  
   - Remainder = 0  

---

## Step-by-Step Working of the Assembly Code

1. **Register Setup**
   - `x1` = dividend (43)  
   - `x2` = quotient (0)  
   - `x3` = remainder (0)  
   - `x4` = divisor (4)  
   - `x5` = bit index (31 → 0)  

2. **Loop Execution**
   - Shift remainder left by 1.  
   - Extract dividend bit, insert into remainder.  
   - If remainder < divisor → quotient bit = 0.  
   - Else → remainder = remainder – divisor, quotient bit = 1.  

3. **Completion**
   - After all bits, quotient remains in `x2`.  
   - Remainder remains in `x3`.  
   - Both are stored in memory and signaled to Spike using `tohost`.  

---

## Verification

### C Program

- **Inputs:**
```

Dividend = 77
Divisor  = 7

```

- **Manual Calculation:**
```

77 ÷ 7 = 11 remainder 0

```

- **Output:**
```

Quotient = 11
Remainder = 0

```
 Matches expected. So, Correct.

---

### RISC-V Assembly

- **Inputs:**
```

Dividend = 43
Divisor  = 4

```

- **Manual Calculation:**
```

43 ÷ 4 = 10 remainder 3

```

- **Expected Output:**
```

Quotient = 10
Remainder = 3

````

- **Spike Output:**
- Quotient written = 10  
- Remainder written = 3  

Matches manual calculation. Hence, Correct.

---

## How to Compile & Run

### C Code

```bash
gcc task3.c -o task3
./task3
````

Generate assembly from C:

```bash
riscv64-unknown-elf-gcc -S task3.c -o task3_c.s
```

---

### Assembly Code

1. Save the code as **task3.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o task3.o task3.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o task3.elf task3.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits task3.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits task3.elf
   ```

---

## Key Difference (Restoring vs Non-Restoring)

| Feature                    | Restoring Algorithm | Non-Restoring Algorithm |
| -------------------------- | ------------------- | ----------------------- |
| Negative trial subtraction | Restores remainder  | Skips restoring         |
| Steps per iteration        | Slightly more       | Slightly fewer          |
| Hardware complexity        | Higher              | Lower                   |
| Speed                      | Slower              | Faster                  |

## Reference
- https://youtu.be/je7RSR6w37c?si=TgUa-lQIIv8LQtD0
- AI