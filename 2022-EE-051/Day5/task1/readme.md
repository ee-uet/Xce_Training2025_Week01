# Restoring Division Algorithm – RISC-V Implementation  

## Overview  
This project demonstrates the **Restoring Division Algorithm** implemented in **RISC-V assembly language**, alongside its equivalent **C program**. The algorithm divides a dividend by a divisor using bit-shifting and repeated subtraction, while maintaining both **quotient** and **remainder**.  

The work involves:  
- Writing the algorithm in **C**  
- Translating it to **RISC-V assembly** manually  
- Building the assembly file automatically from the C source using the **RISC-V GCC toolchain**  
- Comparing the **hand-written assembly** with the **compiler-generated assembly**  
- Running and testing both programs on the **Spike RISC-V simulator**  

---

## Algorithm Explanation  
The restoring division algorithm works as follows:  

1. Initialize **quotient = 0** and **remainder = 0**.  
2. Loop through each bit of the dividend starting from **MSB → LSB**:  
   - Left-shift the remainder.  
   - Bring down the current dividend bit into remainder.  
   - Perform a trial subtraction: `remainder = remainder – divisor`.  
   - If the result is negative, **restore** by adding back the divisor (quotient bit = 0).  
   - Otherwise, keep the result and set quotient bit = 1.  
3. At the end of the loop:  
   - `quotient` holds the final quotient.  
   - `remainder` holds the final remainder.  

---

## Step-by-Step Working of the C Program  

1. The program starts by setting:  
   - **Dividend = 77**  
   - **Divisor = 7**  
   - **Quotient = 0**  
   - **Remainder = 0**  

2. A **for-loop** is used that runs from **bit 31 (most significant bit)** down to **bit 0 (least significant bit)**.  

---

### Inside the Loop  

3. The remainder is **shifted left by 1 bit** to make space for the next dividend bit.  
4. The **current bit of the dividend** is extracted by shifting the dividend to the right and masking with `1`.  
5. If this bit is equal to `1`, it is added into the remainder (lowest bit becomes `1`).  
6. Now the program checks:  
   - If the remainder is **greater than or equal to the divisor**:  
     - Subtract the divisor from the remainder.  
     - Set the corresponding quotient bit to `1`.  
   - If the remainder is **less than the divisor**:  
     - Do nothing (the quotient bit remains `0`).  

---

### Loop Control  

7. The loop continues until all **32 bits** of the dividend have been processed.  
8. At each step, the quotient is being **built bit by bit**, starting from the most significant bit.  

---

### Program Completion  

9. When the loop finishes:  
   - **Quotient** holds the final division result.  
   - **Remainder** holds the leftover value after division.  
10. These results can then be displayed using `printf`.
 

## Step-by-Step Working of the Assembly Code  

1. The program begins by loading the **dividend (43)** into register `x1`.  
2. The **quotient (0)** is stored in register `x2`.  
3. The **remainder (0)** is stored in register `x3`.  
4. The **divisor (4)** is loaded into register `x4`.  
5. The **loop counter (31)** is placed in register `x5`, starting from the most significant bit.  

---

### Main Loop Execution  

6. The remainder is **shifted left by 1 bit** to make space for the next dividend bit.  
7. The **current bit** of the dividend is extracted by shifting right by `x5` and masking it with `1`.  
8. This extracted bit is added into the remainder.  
9. The quotient is also **shifted left by 1 bit** to prepare for the next quotient bit.  
10. A **trial subtraction** is performed: remainder – divisor.  
11. The trial result is temporarily stored in the remainder register.  
12. If the trial result is **negative**, the subtraction is **undone (restored)** by adding back the divisor.  
13. If the trial result is **non-negative**, the quotient bit is set to `1`.  

---

### Loop Control  

14. The loop counter is **decremented by 1**.  
15. If the counter is still greater than or equal to zero, the loop repeats for the next bit.  
16. This continues until all 32 bits of the dividend are processed.  

---

### Program Completion  

17. When the loop ends, the **quotient** remains stored in register `x2`.  
18. The **remainder** remains stored in register `x3`.  
19. Both values are then written to the special memory location `tohost`, which is used by the Spike simulator to display program results.  
20. Finally, the program jumps into an infinite loop to signal completion.  

---

## C Program Verification  

1. The program was compiled and executed on a normal system.  
2. The division example chosen was **77 ÷ 7**.  
3. Expected result:  
   - Quotient = 11  
   - Remainder = 0  
4. Program output matched the expected values, confirming correctness.  
5. Additional tests with other dividend and divisor values also gave correct results.  

---

## RISC-V Assembly Verification  

- **Given inputs:**  
```

Dividend = 43
Divisor  = 4

```

- **Manual calculation:**  
```

43 ÷ 4 = 10 remainder 3

```

- **Expected output:**  
```

Quotient = 10
Remainder = 3

```

- **Program output (Spike simulation):**  
- First value written to `tohost` = 10  
- Second value written to `tohost` = 3  

Both results match the manual calculation, confirming the assembly implementation is correct.

## How to Compile and Run Assembly Code

1. Save the code as **task1.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o task1.o task1.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o task1.elf task1.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits task1.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits task1.elf
   ```

---
## How to Compile and Run C  code

1. Save the code as **task1.s**  

2.  
 ```bash
gcc task1.c -o task1
````
3.
```sh
./task1
```
4. Generate assembly of C file
```sh
riscv64-unknown-elf-gcc -S task1.c -o task1_c.s
```
