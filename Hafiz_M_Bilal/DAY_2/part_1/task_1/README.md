# Task 1.1 – Basic Pointer Usage

## Problem
- Declare an integer variable.  
- Create a pointer to the integer.  
- Print the value using both direct access and pointer dereferencing.  
- Modify the value through the pointer and print the updated value.  

---

## Approach
1. Declare an integer variable `a` and initialize it with `10`.  
2. Declare a pointer `b` that stores the address of `a`.  
3. Print the value of `a` directly.  
4. Print the value of `a` using the pointer (`*b`).  
5. Modify the value of `a` via the pointer (`*b = 20`).  
6. Print the updated value of `a`.  

---

## How to Run
1. Save the code in a file,`task1_1.c`.  
2. Compile the program:  
   ```bash
    gcc task1_1.c -o task1_1
    ./task1_1

## Example Output
Direct: 10
Using pointer: 10
Modified value using pointer: 20

## Known Limitations

Only demonstrates pointers with a single integer.

No input is taken from the user.

For larger programs, pointer handling should include null checks to avoid errors.