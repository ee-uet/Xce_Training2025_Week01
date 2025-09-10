# RISC-V Assembly: Absolute Difference Program  

## Overview  
This program computes the **absolute difference** between two integers `x` and `y` using RISC-V assembly.  
- The result is stored at a **fixed memory location (0x80001000)**.  
- The program signals **termination** for the Spike simulator using the `tohost` mechanism.  

---

## Code Structure  
1. **Initialization** – load input values (`x = 7`, `y = 12`).  
2. **Branching** – decide whether `x ≥ y` using `bge`.  
3. **Computation** – subtract the smaller value from the larger to compute `|x - y|`.  
4. **Store Result** – write result into memory address `0x80001000`.  
5. **Exit Handling** – signal Spike using `tohost`.  
6. **Infinite Loop** – fallback if Spike does not exit automatically.  

---

## How the Code Works  

1. **Load Values**  
   - Put `x = 7` into register `a0`.  
   - Put `y = 12` into register `a1`.  

2. **Branch & Compute**  
   - If `x ≥ y`, jump to label `x_ge_y`.  
   - Otherwise, subtract `x` from `y` and store result in `t0`.  
   - At `x_ge_y`, subtract `y` from `x` and store result in `t0`.  

3. **Store Result**  
   - Load the memory address `0x80001000` into register `t1`.  
   - Store the result from `t0` into that memory location.  

4. **Exit for Spike**  
   - Load value `1` into register `t2`.  
   - Load the address of `tohost` into register `t3`.  
   - Store `1` into `tohost` so that Spike simulator knows the program has finished.  

5. **Fallback Loop**  
   - If Spike does not exit, the program jumps back to itself and runs forever.  

---

## How I Verified It is Correct  

- **Given inputs:**  
```

x = 7
y = 12

```

- **Manual calculation:**  
```

|7 - 12| = 5

```

- After running the program in **Spike**, memory at `0x80001000` contained the value:  
```

5

````

- The program terminated correctly using the **tohost** mechanism.

---

## How to Compile and Run  

1. Save the code as **exercise1.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o exercise1.o exercise1.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o exercise1.elf exercise1.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits exercise1.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits exercise1.elf
   ```

---

## Expected Result in Memory

```
0x0000000000000005
```