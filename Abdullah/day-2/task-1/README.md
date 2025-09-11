# Task 1: Pointer Basics and Arithmetic

## Problem
1. **Basic Pointer Usage (Task 1.1)**: Declare an integer variable and a pointer to it, print the value using both direct access and the pointer, modify the value using the pointer
2. **Swap Function (Task 1.2)**: Implement a function that swaps two integers using pointers
3. **Pointer Arithmetic (Task 1.3)**: Create an array and use pointer arithmetic to print elements, calculate sum, and reverse in-place

## Approach

### Basic Pointers
1. Declare integer variable and pointer
2. Use pointer dereferencing to modify and access values
3. Demonstrate pointer assignment and dereferencing

### Swap Function
1. Pass addresses of variables to function
2. Use pointer dereferencing to swap values
3. Display values before and after swapping

### Pointer Arithmetic
1. Use pointer arithmetic to traverse array
2. Calculate sum using pointer operations
3. Implement in-place reversal using pointer manipulation

## How to Run

### Basic Pointers
```bash
gcc -o basic_pointers basic_pointers.c
./basic_pointers
```

### Swap Pointers
```bash
gcc -o swap_pointers swap_pointers.c
./swap_pointers
```

### Pointer Arithmetic
```bash
gcc -o pointer_arithmetic pointer_arithmetic.c
./pointer_arithmetic
```

## Example Output

### Basic Pointers
```
Modified Value: 20
```

### Swap Pointers
```
Current Values: a = 5, b = 10
After Swapping: a = 10, b = 5
```

### Pointer Arithmetic
```
Array Elements: 1 2 3 4 5 
Sum: 15
Reversed Array: 5 4 3 2 1 
```

## Design Notes
- Uses pointer dereferencing (*) to access values
- Demonstrates address-of operator (&) for getting addresses
- Pointer arithmetic uses (ptr + i) for array element access
- In-place reversal swaps elements from both ends

## Key Concepts Demonstrated
- **Pointer Declaration**: `int *ptr = &variable`
- **Dereferencing**: `*ptr` to access value
- **Pointer Arithmetic**: `*(ptr + i)` equivalent to `ptr[i]`
- **Pass by Reference**: Using pointers to modify original variables

## Assumptions & Edge Cases
- Arrays have fixed size (ARR_SIZE = 5)
- Assumes valid pointer operations
- No bounds checking in pointer arithmetic

## Known Limitations
- Basic pointer demonstration lacks comprehensive value printing
- No input validation for array operations
- Fixed array size in pointer arithmetic example

## Sources & AI Usage
- Original template code from lab manual
- Standard pointer manipulation techniques from slides shared in class
- No AI assistance for core pointer logic