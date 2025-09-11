# RISC-V Assembly: Bit Count Program  

## Overview  
This program counts the number of **1 bits** (set bits) in a 32-bit integer using **Brian Kernighan’s algorithm** in RISC-V assembly.  
- The input number is stored in register `a0`.  
- A counter in `a1` keeps track of the set bits.  
- The final result is stored in the `result` variable in memory.  
- The program signals **termination** to the Spike simulator using `tohost`.  

---

##  Code Structure  
1. **Initialization** – load a 32-bit number into `a0`, set counter `a1 = 0`.  
2. **Loop** – repeatedly clear the lowest set bit and increment counter.  
3. **Store Result** – write the total count of set bits into `result`.  
4. **Exit Handling** – signal Spike using `tohost`.  
5. **Infinite Loop** – fallback if Spike does not exit automatically.  

---

## How the Code Works  

1. **Load Number**  
   - Register `a0` contains the input binary number.  
   - Register `a1` is initialized to 0 (bit counter).  

2. **Loop (Brian Kernighan’s Algorithm)**  
   - Check if `a0` is zero → if yes, exit loop.  
   - Increment `a1` by 1 (found one set bit).  
   - Compute `a0 - 1` and store in `t0`.  
   - Update `a0 = a0 & (a0 - 1)` → clears the lowest set bit.  
   - Repeat until `a0 = 0`.  

3. **Store Result**  
   - Save the value of `a1` into memory at label `result`.  

4. **Exit for Spike**  
   - Write `1` to `tohost` to notify Spike that the program has finished.  

5. **Fallback Loop**  
   - If Spike does not exit automatically, the program jumps back to itself forever.  

---

## How I Verified It is Correct  

- Input number: 
```sh 
  0b11001010101100101010101010101010
```
- Manual calculation: count the number of `1` bits → **16**.  
- After running in Spike, memory at `result` contained **16**, confirming correctness.  

---

## How to Compile and Run  

1. Save the code as **exercise2.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o exercise2.o exercise2.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o exercise2.elf exercise2.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits exercise2.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits exercise2.elf
   ```

---

## Expected Result in Memory

```
0x0000000000000010
```
