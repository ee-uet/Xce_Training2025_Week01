# Task 1: Basic Syntax and Data Types

## Problem
Declare variables of type int, float, double, char. Print their values and sizes using the sizeof operator. Demonstrate type casting (e.g., int → float, float → int).

## Approach
1. Declare variables of each basic data type with sample values
2. Use `sizeof` operator to determine memory usage of each type
3. Demonstrate explicit type casting between different types
4. Print results showing original values, sizes, and casted values

## How to Run

### Compilation
```bash
gcc -o task01_datatypes task01_datatypes.c
```

### Execution
```bash
./task01_datatypes
```

## Example Output
```
Size of int: 4 bytes
Size of float: 4 bytes
Size of double: 8 bytes
Size of char: 1 byte
Casted int to double: 10.000000
Casted double to float: 3.141590
Casted float to int: 5
```

## Design Notes
- Uses `%zu` format specifier for `sizeof` results (returns `size_t`)
- Demonstrates truncation in float-to-int casting
- Shows precision differences between float and double

## Known Limitations
- Data type sizes are platform-dependent
- There's an issue in original code: `printf("Casted double to float: %f\n", casted);` should use `casted_float` instead of `casted`

## Sources & AI Usage
- Original template code from lab manual
- No AI assistance used for core logic
- Documentation enhanced for clarity