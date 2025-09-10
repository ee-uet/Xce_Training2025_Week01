# Bit Manipulation – Set and Clear Bit  

## Overview  
This project demonstrates how to **set** or **clear** a specific bit in a number using both **C language** and its equivalent **RISC-V assembly implementation**.  

The work involves:  
- Writing the algorithm in **C**  
- Translating it to **RISC-V assembly** manually  
- Building the assembly file automatically from the C source using the **RISC-V GCC toolchain**  
- Comparing the **hand-written assembly** with the **compiler-generated assembly**  
- Running and testing both programs on the **Spike RISC-V simulator**  

---

## Algorithm Explanation  

1. Start with an integer `num`.  
2. Choose a bit **position (pos)** that needs to be modified.  
3. Choose a **value (1 = set, 0 = clear)**.  
4. Create a **mask** with `1 << pos`.  
5. If value = 1 → Use **bitwise OR** to set the bit.  
6. If value = 0 → Use **bitwise AND with inverted mask** to clear the bit.  
7. Store the updated result.  

---

## Step-by-Step Working of the C Program  

1. Initialize:  
   - `num = 0x55` (binary = `01010101`)  
   - `pos = 3`  
   - `value = 1` (means set the bit)  

2. Create a mask by shifting `1` left by `pos`.  
   - `mask = 1 << pos` → `00001000`  

3. If `value == 1`:  
   - Perform `num | mask` to set the bit.  

4. If `value == 0`:  
   - Perform `num & ~mask` to clear the bit.  

5. Final result is stored in `num`.  

---

## Step-by-Step Working of the Assembly Code  

1. Load variables from memory:  
   - `num` → register `t1`  
   - `pos` → register `t2`  
   - `value` → register `t3`  

2. Compute `mask = 1 << pos` using shift-left instruction.  

3. If `value == 0`:  
   - Invert the mask.  
   - Perform `num & mask` to clear the bit.  

4. If `value == 1`:  
   - Perform `num | mask` to set the bit.  

5. Store the result into memory at `result`.  

6. Write a signal to `tohost` so Spike simulator detects program completion.  

---

## Verification of C Program  

- **Inputs:**  
```

num = 0x55   (binary = 0101 0101)
pos = 3
value = 1

```

- **Manual Calculation:**  
- Bit at position 3 is currently `0`.  
- Setting this bit makes the number `0101 1101` (0x5D).  

- **Expected Result:**  
```

Updated num = 0x5D

```

- **Program Output:**  
- Matches expected result  

---

## Verification of Assembly Program  

- **Inputs loaded from .data section:**  
```

num   = 0x55
pos   = 3
value = 1

```

- **Manual Calculation:**  
- Mask = `00001000` (0x08).  
- Setting bit 3 in `0101 0101` → `0101 1101` (0x5D).  

- **Expected Result:**  
```

result = 0x5D

````

- **Program Output on Spike (written to memory):**  
- Value stored at `result` = 0x5D  

Both results match, confirming correctness of the assembly implementation.  

---

## How to Compile and Run C Program  

1. Save the C code as `task2.c`.  
2. Compile:  
 ```bash
 gcc task2.c -o task2
````

3. Run:

   ```bash
   ./task2
   ```
4. To generate assembly from C:

   ```bash
   riscv64-unknown-elf-gcc -S task2.c -o task2_c.s
   ```

---
## How to Compile and Run Assembly Code

1. Save the code as **task2.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o task2.o task2.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o task2.elf task2.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits task2.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits task2.elf
   ```

---