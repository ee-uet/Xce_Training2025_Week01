# RISC-V Assembly: Insertion Sort Program  

## Overview  
This program implements the **Insertion Sort algorithm** in RISC-V assembly.  
- It sorts an array of integers stored in memory.  
- The algorithm works in-place, shifting elements to insert each new item in its correct position.  
- The sorted array replaces the original array in memory.  
- Program signals termination for the Spike simulator using the `tohost` mechanism.  

---

## Code Structure  
1. **Initialization**  
   - Load base address of the array.  
   - Set `n = 5` (array length).  
   - Start with index `i = 1` (since the first element is already "sorted").  

2. **Outer Loop**  
   - Repeat for each element until `i = n`.  
   - Take the current element as the **key**.  
   - Set `j = i - 1` to compare with previous elements.  

3. **Inner Loop**  
   - While `j >= 0` and `array[j] > key`, shift elements one position to the right.  
   - Decrement `j` after each shift.  
   - Stop when `array[j] <= key` or `j < 0`.  

4. **Insert Key**  
   - Place the key in its correct sorted position (`array[j+1] = key`).  
   - Increment `i` and repeat until the entire array is sorted.  

5. **Exit Handling**  
   - Write `1` to `tohost` to signal completion.  
   - Fall back to an infinite loop if Spike does not exit automatically.  

---

## How the Code Works  

1. The program begins by loading the starting address of the array into a register.  
2. It sets the array length (`n = 5`) and starts with the second element (`i = 1`).  
3. For each element, it stores the value in a temporary register called the key.  
4. It then compares the key with previous elements of the array.  
5. If a previous element is larger, it shifts that element one step to the right.  
6. This continues until the correct place for the key is found.  
7. The key is then inserted at its correct position.  
8. This process repeats for all elements until the array is fully sorted.  
9. At the end, the sorted array is left in memory, replacing the original unsorted version.  
10. The program then signals Spike that execution is complete and enters an infinite loop.  

---

## Verification  

- **Initial array:**  
```

[5, 3, 4, 1, 2]

```

- **Step-by-step sorting:**  
- After 1st iteration: [3, 5, 4, 1, 2]  
- After 2nd iteration: [3, 4, 5, 1, 2]  
- After 3rd iteration: [1, 3, 4, 5, 2]  
- After 4th iteration: [1, 2, 3, 4, 5]  

- **Final sorted array in memory:**  
```

[1, 2, 3, 4, 5]

````

---

## How to Compile and Run  

1. Save the code as **exercise5.s**  

2. Assemble:  
 ```bash
 riscv64-unknown-elf-as -o exercise5.o exercise5.s
````

3. Link with a linker script:

   ```bash
   riscv64-unknown-elf-ld -T linker.ld -o exercise5.elf exercise5.o
   ```

4. Run on Spike and log commits:

   ```bash
   spike -d --log-commits exercise5.elf
   ```

5. Run using a Makefile:

   ```bash
   make -f makefile.mak
   spike -d --log-commits exercise5.elf
   ```

Check the memory where `array` is stored, and confirm it contains the sorted result:

   ```
   [1, 2, 3, 4, 5]
   ```

---

This confirms the program correctly sorts the array using Insertion Sort in RISC-V assembly.

## Reference
I wrote insertion sort in C then generated its assembly, from there I took the idea and wrote it.
