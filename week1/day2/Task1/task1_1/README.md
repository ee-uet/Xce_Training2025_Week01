# Task 1_1: Basic Pointer Usage

## Problem
Create a program that demonstrates basic pointer usage:
- Declare an integer variable and a pointer to it.
- Print the value of the variable using both direct access and the pointer.
- Modify the value using the pointer and print the new value.

## Approach
The core logic uses the `&` (address-of) and `*` (dereference) operators. A pointer is assigned the memory address of a variable. The variable's value is then accessed and modified indirectly through this pointer, demonstrating that the pointer "points to" the original variable's memory location.

## How to Run
1. **Compile the code:** Use a C compiler like gcc.
   ```bash
   gcc task1_1.c -o out
2. **Run the executable:**
    ./out
    
## Test Case
    **The program tests the following core pointer operations:**
1. Initialization and Assignment: The pointer ptra is assigned the address of variable a.
2. Value Access: The value of a is printed using both the variable name and by dereferencing the pointer. This verifies both methods access the same data.
3. Value Modification: The value of a is changed by assigning a new value to *ptra. Printing a again confirms the change was made to the original variable.

## Example Output
    Print value of a using direct method: 10
    Print value of a using pointer method: 10
    Updated value of a: 15
    
## Known Limitations
1. This is a simple demonstration program. It uses hardcoded values and does not accept user input.
2. The program only demonstrates pointers to a single integer. It does not cover pointers to other data types, arrays, or structures.

