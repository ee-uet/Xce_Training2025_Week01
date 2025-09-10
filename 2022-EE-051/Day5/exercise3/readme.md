# RISC-V Assembly: Factorial Program  

## Overview  
This program computes the **factorial of a number `n`** using RISC-V assembly.  
- Input: `n = 5` (hardcoded in register `a0`).  
- Output: The factorial result (`5! = 120`) is stored in memory at label `result`.  
- The program signals **termination** for the Spike simulator using the `tohost` mechanism.  

---

## Code Structure  
1. **Initialization**  
   - Load `n = 5` into `a0`.  
   - Set factorial accumulator (`t0 = 1`).  
   - Copy counter (`t1 = n`).  

2. **Loop (factorial_loop)**  
   - If counter = 0 → exit loop.  
   - Multiply accumulator by counter.  
   - Decrement counter.  
   - Repeat until counter = 0.  

3. **Store Result**  
   - Save final factorial result into memory (`result`).  

4. **Exit Handling**  
   - Write `1` into `tohost` to signal completion.  
   - Enter infinite loop if Spike does not exit automatically.  

---

## How the Code Works  

1. The program begins by loading the number `n = 5` into a register and setting the factorial result to 1.  
2. It copies the value of `n` into another register which will act as a countdown counter.  
3. A loop is then started that multiplies the current result by the counter.  
4. After each multiplication, the counter is decreased by 1.  
5. This loop continues until the counter becomes zero.  
6. When the loop ends, the final factorial value is saved in memory at the label `result`.  
7. At the end, the program signals the Spike simulator that it has finished execution, and then it enters an infinite loop in case Spike does not exit automatically.  


## Verification

* Manual calculation:

  ```
  5! = 5 × 4 × 3 × 2 × 1 = 120
  ```

* After running in Spike, memory at `result` contained:

  ```
  0x0000000000000078
  ```

  which is decimal **120**, matching the expected factorial.

---

## How to Compile and Run  

1. Save the code as **exercise1.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o exercise3.o exercise3.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o exercise1.elf exercise3.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits exercise3.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits exercise3.elf
   ```

---

## Expected Result in Memory

```
0x0000000000000078
```