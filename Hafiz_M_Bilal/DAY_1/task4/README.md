# Task 0.4 – Prime Numbers and Factorial

## Problem
This task contains two parts:
1. **Prime Numbers**  
   - Print all prime numbers between 1 and 100.  

2. **Factorial**  
   - Implement a recursive function to compute the factorial of a number.  
   - Demonstrate by calculating the factorial of 10.  

## Approach
### Prime Numbers
1. Implement a helper function `isPrime(int n)` that:  
   - Returns 0 if `n <= 1`.  
   - Checks divisibility from 2 to `n-1`.  
   - Returns 1 if no divisors are found.  
2. Use a loop from 1 to 100, call `isPrime()`, and print numbers that return 1.  

### Factorial
1. Implement a recursive function `factorial(int n)`:  
   - Base case: `factorial(1) = 1`.  
   - Recursive case: `factorial(n) = n * factorial(n-1)`.  
2. Call the function with `n = 10` and print the result.  

## How to Run
Compile and run using GCC:
```bash
gcc factorial.c -o factorial
./factorial

gcc prime_number.c -o prime_number
./prime_number

## Example Output
Prime numbers between 1 and 100 are:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
Factorial of 5 = 3628800

## Known Limitations

isPrime() is not efficient (checks divisibility up to n-1). It can be optimized to check up to √n.

Factorial function does not handle n = 0 (should return 1).

Factorial results may overflow for large n (beyond 12–15 depending on system).
