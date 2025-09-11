
---

# C Program: Prime Numbers & Factorial (Task 4)

## Problem

This program implements two tasks:

1. **Prime Numbers Generator**
   Prints all prime numbers between 1 and 100.

2. **Factorial Calculation**
   Computes the factorial of a given number using recursion.

## Approach

### Prime Numbers

1. Define a helper function `isPrime(int n)` that:

   * Returns `0` if the number is **not prime**.
   * Returns `1` if the number **is prime**.
2. Use trial division from `2` to `n-1` to check for factors.
3. Loop through numbers from 1 to 100 and print those that are prime.

### Factorial

1. Define a recursive function `factorial(int n)`:

   * Base case: if `n == 1`, return `1`.
   * Recursive case: return `n * factorial(n-1)`.
2. Demonstrate the function by calculating `factorial(5)`.

### Key Concepts Used

* **Functions**: Code reuse with `isPrime()` and `factorial()`.
* **Loops (`for`, `while`)**: To test numbers for primality and iterate through the range.
* **Recursion**: Used to implement the factorial function.

## How to Run

To run this program:

1. Copy the code into a file named `task4.c`.
2. Compile the C program using the following command:

   ```bash
   gcc -o task4 task4.c
   ```
3. Run the compiled executable:

   ```bash
   ./task4
   ```

## Examples

### Example 1: Prime Numbers

```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```

### Example 2: Factorial

```
Factorial of 5 = 120
```

## Known Limitations

* The `isPrime` function checks divisibility up to `n-1`, which is inefficient. It can be optimized to check only up to `sqrt(n)`.
* Recursive factorial may cause stack overflow for very large `n`.
* The range of prime numbers is hardcoded from `1` to `100`.

## What I Verified

* **Edge Cases**:

  * `n = 1` correctly identified as not prime.
  * Prime list correctly skips non-primes.
  * `factorial(1)` returns 1.

* **Constraints**:

  * Works for small `n` values.
  * Factorial limited by integer overflow for larger inputs (e.g., `factorial(13)` already exceeds 32-bit `int`).

## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to draft this `README.md` and document edge cases and limitations.

---

