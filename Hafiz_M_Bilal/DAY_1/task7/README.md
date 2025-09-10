# Task 0.7 – Bitwise Operations

## Problem
- Demonstrate usage of bitwise operators (`AND`, `OR`, `XOR`, `NOT`, left shift, right shift).  
- Implement a function to check whether a given number is a **power of 2** using bitwise operations.  

---

## Approach
1. Define two integers `x = 5` and `y = 9`.  
   - Apply bitwise operators:  
     - `x & y` → AND  
     - `x | y` → OR  
     - `x ^ y` → XOR  
     - `~x`, `~y` → NOT  
     - `x << 1`, `y << 1` → Left shift  
     - `x >> 1`, `y >> 1` → Right shift  
2. Define a helper function `is_power_of_two(int n)` using the property:  
A number n is a power of 2 if (n > 0) && ((n & (n-1)) == 0)
3. Ask the user for input and check whether the number is a power of 2.  

---

## How to Run
1. Save the code in a file, `task_7.c`.  
2. Compile the program:  
```bash
gcc task_7.c -o task_7
./task_7

## Example Output
x = 5, y = 9
x & y = 1
x | y = 13
x ^ y = 12
~x = -6
~y = -10
x << 1 = 10
y << 1 = 18
x >> 1 = 2
y >> 1 = 4

Enter a number to check if it is power of 2: 16
16 is a power of 2

## Known Limitations

Works only with integer inputs for bitwise operations.

Negative numbers in power-of-2 check are not considered valid.

User can only test one number at a time for the power-of-2 check.

## Sources 
I learned the implementation of the `is_power_of_two` function from the internet.  
Original source: [link](https://share.google/images/KYpB1OjG0f02jIJbx")

## What I Verified
- Verified the function works correctly for:
  - Powers of two (1, 2, 4, 8, 16, …).
  - Non-powers of two (3, 5, 6, 10, …).
  - Edge cases like `n = 0` and negative numbers.
- Confirmed it satisfies assignment constraints (no extra libraries, only bitwise operators and standard C).
