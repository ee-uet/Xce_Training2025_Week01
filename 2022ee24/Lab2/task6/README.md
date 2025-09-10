
---

# Booth's Multiplication in C

## Problem

This program implements **Booth's Multiplication Algorithm** in C to multiply two signed 32-bit integers.

The program supports:

* Binary addition using bitwise operations.
* Arithmetic and logical right shifts for intermediate steps.
* Full Booth’s algorithm to handle positive and negative operands.
* Test cases covering edge cases such as multiplication by 0, ±1, and large integers.

---

## Approach

### 1. Addition (`add`)

* Implements bitwise addition without using `+` or `-`.
* Uses XOR (`^`) for sum and AND/shift for carry.

### 2. Shifting (`shift`)

* Performs an arithmetic right shift on the accumulator (`A`).
* Performs a logical right shift on the multiplier (`Q`).
* Updates `Q-1` for Booth’s decision step.

### 3. Booth’s Algorithm (`booth_multiply`)

* Initializes registers:

  * `A = 0` (accumulator)
  * `Q = multiplicand`
  * `M = multiplier`
  * `Qm1 = 0`
* Repeats **n times** (n = 32 bits):

  * If `Q[0]Qm1 == 01`: Add `M` to `A`.
  * If `Q[0]Qm1 == 10`: Subtract `M` from `A`.
  * Perform right shift on `(A, Q, Qm1)`.
* Combines `A` and `Q` into the final 64-bit signed result.

### 4. Testing

* `test_booth()` includes 12 test cases:

  * Positive × Positive, Positive × Negative, Negative × Negative.
  * Multiplication by 0, 1, and –1.
  * Large inputs near `INT32_MAX` and `INT32_MIN`.

---

## How to Run

1. Save the program in a file named `task6.c`.
2. Compile with GCC:

   ```bash
   gcc -o task6 task6.c
   ```
3. Run:

   ```bash
   ./task6
   ```

---

## Examples

### Example Run

```
Test 1: 5 * 3
Passed: 5 * 3 = 15
Test 2: -5 * 3
Passed: -5 * 3 = -15
Test 3: 5 * -3
Passed: 5 * -3 = -15
Test 4: -5 * -3
Passed: -5 * -3 = 15
Test 5: 42 * 0
Passed: 42 * 0 = 0
...
Test 12: INT32_MIN * 1
Passed: INT32_MIN * 1 = -2147483648
All test cases completed!
```


---

## Known Limitations

* Only works for **32-bit signed integers**. Multiplying very large numbers can cause overflow beyond the 64-bit result.
---

## What I Verified

* Correctness for:

  * Positive and negative operands.
  * Zero and ±1 multipliers.
  * Edge cases with `INT32_MAX` and `INT32_MIN`.
* Complexity: Runs in **O(n)** where n = number of bits (32 iterations).
* Constraints: Assumes inputs fit within 32-bit signed integers.

---

## Sources & AI Usage

* Code was primarily written by me, with AI assistance.

---

