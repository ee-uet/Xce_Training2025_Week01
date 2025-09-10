# Task 0.1 — Basic Syntax and Data Types

## Problem
- Declare variables of type `int`, `float`, `double`, and `char`.  
- Print their values and sizes using the `sizeof` operator.  
- Demonstrate type casting between types (e.g., int → float, float → int).  

## Approach
- Declared one variable of each type (`int`, `float`, `double`, `char`).  
- Printed sizes using `sizeof(variable)`.  
- Showed type casting:
  - Float → Int  
  - Int → Float (with division example)  
- Printed the results of casting to confirm behavior.  

## How to Run
1. Save the code in `t1.c`.  
2. Compile:
   ```bash
   gcc t1.c -o out
   ./out
   
## Test Cases
    Expected output:
    size of int is: 4
    size of float is: 4
    size of double is: 8
    size of char is: 1
    Typecasting From Float to Int 3
    Typecasting From Int to Float 1.000000
    Typecasting From Int to Float 10.000000

## Known Limitations
1. Sizes of data types depend on system/architecture (may differ on 32-bit vs 64-bit).
2. Division of integers (num_1/num_2) truncates before casting to float.

