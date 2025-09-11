# Booth Multiplication in C

## Overview

This project demonstrates two key concepts in **C programming** and **computer architecture**:

1. **Bitwise Addition** → Performing integer addition without using the `+` operator.
2. **Booth’s Multiplication Algorithm** → An efficient algorithm for signed integer multiplication using **shifts and add/subtract operations**.

---

## Code Structure

### 1. `int add(int a, int b)`

* Adds two integers using **bitwise operators only**.
* Algorithm:

  * `XOR (^)` → sum of bits without carry.
  * `AND (&)` + `SHIFT (<<)` → compute carry bits.
  * Repeat until carry becomes `0`.

---

### 2. `long long booth_multiply(int multiplicand, int multiplier)`

* Implements **Booth’s Multiplication Algorithm (32-bit version)**.
* Registers:

  * `A` → Accumulator (high 32 bits, starts at 0).
  * `M` → Multiplicand (sign-extended).
  * `Q` → Multiplier (low 32 bits).
  * `Q_1` → Extra bit (starts at 0).
* Steps (32 iterations):

  1. Look at `(Q0, Q_1)` pair:

     * `(1,0)` → `A = A - M`.
     * `(0,1)` → `A = A + M`.
     * `(0,0)` or `(1,1)` → No operation.
  2. Perform **arithmetic right shift** on `(A, Q, Q_1)`.
* Final result = `(A << 32) | Q`.

---

### 3. `void test_booth()`

* Runs multiple test cases for Booth multiplication.
* Demonstrates handling of positive numbers, negatives, and zero.

---

### 4. `int main()`

* Entry point of the program.
* Calls `test_booth()` to display results.

---

## How the Algorithm Works

### Example: `7 * 5`

* Multiplicand = 7
* Multiplier = 5
* Initial: `A = 0`, `Q = 5`, `Q_1 = 0`
* After 32 iterations, result = **35**.

### Handling Negatives

* Works correctly for signed integers using **two’s complement representation**.
* Examples:

  * `-7 * 5 = -35`
  * `-7 * 0 = 0`
  * `-5 * -6 = 30`

---

## Example Run

### Code Snippet

```c
int main() {
    test_booth();
    return 0;
}
```

### Compile & Run
```bash
gcc task6.c -o task6
./task6
```

### Output

```
7 * 5 = 35
-7 * 5 = -35
-7 * 0 = 0
5 * 0 = 0
-5 * -6 = 30
123456 * -654321 = -80779853376
```

