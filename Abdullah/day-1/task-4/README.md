# Task 4: Functions

## Problem
1. Write a function `isPrime(int n)` that returns 1 if n is prime, otherwise 0. Use it to print all prime numbers between 1–100.
2. Write a recursive function `factorial(int n)` that calculates factorial.

## Approach

### Prime Numbers
1. Implement `isPrime()` function with trial division method
2. Check divisibility from 2 to n-1
3. Use function to filter and print primes from 1 to 100

### Factorial
1. Implement recursive factorial function
2. Base case: factorial(0) = factorial(1) = 1
3. Recursive case: factorial(n) = n * factorial(n-1)

## How to Run

### Prime Numbers
```bash
gcc -o prime_numbers prime_numbers.c
./prime_numbers
```

### Factorial
```bash
gcc -o factorial factorial.c
./factorial
```

## Example Output

### Prime Numbers
```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
```

### Factorial
```
Factorial of 5 = 120
```

## Design Notes
- Prime checking uses simple trial division algorithm
- Factorial uses recursion with proper base case handling
- Both functions return integer values for easy testing

## Assumptions & Edge Cases
- Prime function correctly handles 0, 1 (not prime) and 2 (prime)
- Factorial handles edge cases: factorial(0) = 1, factorial(1) = 1
- Large factorial values may cause integer overflow

## Known Limitations
- Prime algorithm is not optimized (could check only up to sqrt(n))
- Factorial input is hardcoded; no user input handling

## Sources & AI Usage
- Original template code from lab manual
- Standard mathematical algorithms used
- No AI assistance for core logic implementation