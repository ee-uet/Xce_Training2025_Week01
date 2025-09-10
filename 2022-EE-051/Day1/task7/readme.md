# C Program: Bitwise Operations and Power of 2 Check

## Overview
This program demonstrates:
- Basic **bitwise operations** in C (`AND`, `OR`, `XOR`, `NOT`, `shift`)
- How numbers are manipulated at the **binary level**
- A practical example: **checking if a number is a power of 2**

---

## Code Structure
- `task07_bitwise_ops()`  
  - Declares two integers `x = 5` and `y = 9`  
  - Demonstrates:  
    - `x & y` → **Bitwise AND**  
    - `x | y` → **Bitwise OR**  
    - `x ^ y` → **Bitwise XOR**  
    - `~x` → **Bitwise NOT**  
    - `x << 1` → **Left shift**  
    - `y >> 2` → **Right shift**  
  - Asks user for a number and checks whether it is a **power of 2**.  
    - Repeatedly divides the number by 2 if even  
    - If result is `1` → power of 2  
    - Otherwise → not a power of 2  

- `main()`  
  - Calls `task07_bitwise_ops()`  

---

## How the Code Works

### Bitwise Examples
- `x = 5` → binary: `0101`  
- `y = 9` → binary: `1001`  

| Operation | Binary Result | Decimal Result |
|-----------|---------------|----------------|
| `x & y`   | `0001`        | `1`            |
| `x \| y`  | `1101`        | `13`           |
| `x ^ y`   | `1100`        | `12`           |
| `~x`      | `0110`        | `-6`  
| `x << 1`  | `1010`        | `10`           |
| `y >> 2`  | `0010`        | `2`            |

### Power of 2 Check
- Input: `8` → `8 → 4 → 2 → 1` → YES, power of 2  
- Input: `12` → `12 → 6 → 3` (not 1) → NO, not a power of 2  

---

## How to Compile and Run

### Using GCC
```sh
gcc task7.c -o task7
./task7
