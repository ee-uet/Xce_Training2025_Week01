# C Program: Prime Numbers

## Overview
1. **Prime Numbers (1–100):**  
   - Finds prime numbers between 1 and 100.  
   - Prints them on the console.  
   - Saves them to a file named `primes.txt`.  
---

## How the Code Works

### Prime Numbers
- **`isPrime(int n)`**  
  - Checks if a number is prime.  
  - If `n <= 1`, it immediately returns `0` (not prime).  
  - Otherwise, it tries dividing `n` by every number from `2` to `n/2`.  
  - If any division is exact, `n` is not prime → return `0`.  
  - If no divisors are found, return `1` (prime).  

- **`task04_prime_numbers()`**  
  - Opens a file `primes.txt` in write mode.  
  - Loops through numbers from `1` to `100`.  
  - For each number, calls `isPrime(i)`.  
    - If the function returns `1`, the number is prime → print it on the console **and** write it into the file.  
  - After the loop, the file is closed.  

**Example:**  
For `i = 7` → `isPrime(7)` checks divisibility → no divisor found → prints `7` and saves it to `primes.txt`.

---

### `main()` Function
- First calls `task04_prime_numbers()` → prints and saves prime numbers.  

---

## How to Compile and Run

### Using GCC
```sh
gcc task4A.c -o task4A
./task4A
