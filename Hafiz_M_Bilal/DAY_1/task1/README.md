# Task 0.1 – Data Types and Type Casting

## Problem
The task is to:
- Declare variables of basic C data types (`int`, `float`, `double`, `char`).
- Print their values and sizes.
- Demonstrate type casting between these types.

## Approach
1. Declare and initialize variables:  
   - `int i = 42;`  
   - `float f = 3.14;`  
   - `double d = 1.23456;`  
   - `char c = 'A';`
2. Use `printf` to display their values.
3. Use `sizeof` operator to display the memory size of each type.
4. Perform explicit type casting:
   - `i` cast to `float`
   - `f`, `d`, and `c` cast to `int`
5. Print the casted results.

## How to Run
Compile and run using GCC:
```bash
gcc task_1.c -o task_1
./task_1


## Example Output

Integer i = 42
Float f = 3.140000
Double d = 1.234560
Char c = A

Size of Integer i = 4 bytes
Size of Float f = 4 bytes
Size of Double d = 8 bytes
Size of Char c = 1 bytes

i = 42.000000
f = 3
d = 1
c = 65

## Known Limitations

Output format may vary slightly depending on the system and compiler.

Sizes of data types are system-dependent (e.g., int can be 2, 4, or 8 bytes on different architectures).

Type casting from float/double to int truncates the decimal part, it does not round.