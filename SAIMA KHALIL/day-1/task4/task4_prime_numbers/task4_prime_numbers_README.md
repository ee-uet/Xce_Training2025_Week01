## Prime Numbers 
This program prints all the prime numbers between `1` and `100`.  

---

### Code Explanation  
#### Functions  
- `isPrime(int n)` :  
  - Returns `0` if the number is **not prime**.  
  - Returns `1` if the number is **prime**.  
  - Logic:  
    - If `n <= 1`, return `0` (not prime).  
    - Check divisibility from `2` to `sqrt(n)`.  
    - If divisible by any number, it’s not prime.  
    - Else , it’s a prime number.  

#### Main Logic  
- Loop from `1` to `100`.  
- Calling `isPrime(i)` for each number.  
- Printing the number if the function returns `1`.  

---

#### Example Run  

Prime numbers between 1-100 are :
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

---

#### Run:  
```bash
gcc task4_prime_numbers.c -o task4_prime_numbers -lm
./task4_prime_numbers
```
here,
-lm is required because sqrt() is used from the math library.

---