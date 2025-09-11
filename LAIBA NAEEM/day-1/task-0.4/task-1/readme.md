# Problem
Write a function isPrime(int n) that returns 1 if n is prime, otherwise 0. Use it to print all prime numbers between 1–100.
##
**Approach**
1. First I made a helper function isPrime that checks if a number is prime or not.
2. In this function: if the number is 1 or less then it is not prime. Otherwise, I check by dividing the number from 2 up to its square root.
3. If any division has no remainder, the number is not prime
4. if no such division is found, the number is prime
5. Then in the task04_prime_numbers, I run a loop from 2 to 100
6. For each number, I call isPrime. if the function says true, I print that number as a prime.
##
**How to run**
- Save the code in a file, for example: code.c
  
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code

- Run the program:
    ./code
##
**Example**  
We are checking from 2 to 10 (just for the example)  
n = 2
Divisors checked: none  
Prime  print 2

n = 3
Divisors checked: 2 (no divisor)  
Prime  print 3

n = 4
Divisors checked: 2 (divisor found)  
Not prime  skip

n = 5
Divisors checked: 2, 3 (no divisor)  
Prime  print 5

n = 6
Divisors checked: 2 (divisor found)  
Not prime  skip

n = 7
Divisors checked: 2, 3 (no divisor)    
Prime  print 7

n = 8
Divisors checked: 2 (divisor found)  
Not prime  skip

n = 9
Divisors checked: 2, 3 (divisor found)  
Not prime  skip

n = 10
Divisors checked: 2 (divisor found)  
Not prime  skip

Final output from 2 to 10: 2, 3, 5, 7.  
So, this is how the complete code will execute from 1-100.
##
**Knowm Limitations**  
The program only finds primes between 1 and 100 (not for bigger ranges).