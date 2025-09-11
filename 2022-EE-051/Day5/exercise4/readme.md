# RISC-V Assembly: Reverse Array Program

## Overview

This program reverses the contents of an array in **RISC-V assembly**.

* Input: An array of 4 elements → `[10, 20, 30, 40]`.
* Output: The array is reversed in memory → `[40, 30, 20, 10]`.
* The program signals **termination** for the Spike simulator using the `tohost` mechanism.

---

## Code Structure

1. **Initialization**

   * Load the base address of the array into `t0`.
   * Set `t1` as the starting index (`0`).
   * Set `t2` as the ending index (`3`).

2. **Loop (swap elements)**

   * If `t1 >= t2`, exit loop.
   * Compute address of `array[t1]` and load its value into `t4`.
   * Compute address of `array[t2]` and load its value into `t6`.
   * Swap the two values by storing them back at their respective addresses.
   * Increment `t1` and decrement `t2`.
   * Repeat until the array is fully reversed.

3. **Exit Handling**

   * Write `1` into `tohost` to signal completion.
   * End program execution.

---

## How the Code Works

1. The program loads the **base address of the array** into register `t0`.
2. Two registers act as **pointers**:

   * `t1` → left index (starts at 0).
   * `t2` → right index (starts at last element).
3. Inside the loop:

   * It loads `array[t1]` and `array[t2]`.
   * Swaps them using temporary registers.
   * Moves `t1` forward and `t2` backward.
4. The loop runs until all elements are swapped.
5. Finally, the program signals Spike to exit by writing to the `tohost` variable.

---

## Verification

* Manual reversal of the array:

```
Original: [10, 20, 30, 40]
Reversed: [40, 30, 20, 10]
```

* After running in **Spike**, inspecting memory at label `array` showed:

```
0x28 0x1E 0x14 0x0A
```

which corresponds to decimal values:

```
40, 30, 20, 10
```

matching the expected reversed array.

---

## How to Compile and Run

1. Save the code as **exercise2.s**

2. Assemble:

```bash
riscv64-unknown-elf-as -o exercise4.o exercise4.s
```

3. Link with a linker script:

```bash
riscv64-unknown-elf-ld -T linker.ld -o exercise4.elf exercise4.o
```

4. Run on Spike and log commits:

```bash
spike -d --log-commits exercise4.elf
```

5. Run using a Makefile:

```bash
make -f makefile.mak
spike -d --log-commits exercise4.elf
```

---

## Expected Result in Memory

```
array = [40, 30, 20, 10]
```
## Reference
ChatGpt
