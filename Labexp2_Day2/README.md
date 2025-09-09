## Overview

This project demonstrates comprehensive C programming concepts through practical implementations. Each part focuses on specific programming fundamentals with well-commented code for educational purposes.

## Features

- **Pointer Operations**: Basic pointer usage, arithmetic, and array manipulation
- **String Functions**: Custom implementations of `strlen`, `strcpy`, `strcmp`
- **Preprocessor Macros**: Mathematical operations and character manipulation
- **File I/O**: Reading from and writing to files with error handling
- **Data Structures**: Linked list implementation with insertion and deletion
- **Dynamic Memory**: `malloc`, `realloc`, and custom memory leak detection
- **Advanced Algorithms**: Booth's multiplication algorithm implementation

## Part Breakdown

### Part 1: Pointer Basics and Arithmetic
- Basic pointer usage and dereferencing
- Swapping integers using pointers
- Array manipulation with pointer arithmetic

### Part 2: Pointers and Arrays/Strings
- Custom string functions (`my_strlen`, `my_strcpy`, `my_strcmp`)
- String reversal and palindrome checking
- Pointer-based string manipulation

### Part 3: Preprocessor & File I/O
- Mathematical macros (`SQUARE`, `MAX2/3/4`, `TO_UPPER`)
- Student record management with file operations

### Part 4: Advanced Challenge
- Linked list implementation with node operations
- Dynamic data structure management

### Part 5: Dynamic Memory Allocation
- Runtime memory allocation and reallocation
- Custom memory leak detection system

### Final Task: Booth's Multiplication
- Hardware-level multiplication algorithm
- 64-bit signed integer operations

## Getting Started

### Compilation
```bash
gcc -o program main.c -std=c99 -Wall
```

### Running the Program
```bash
./program
```

### Testing Specific Parts
Edit the `main()` function to uncomment the parts you want to test:
- Part 1: `task1_1()`, `swap()`, `task1_3()`
- Part 2: String function tests
- Part 3: `task3_1_macros()`, `task3_2_fileio()`
- Part 4: `task4_1_linkedlist()`
- Part 5: Dynamic memory functions
- Final: `test_booth()`

## Learning Objectives

Upon completion, you will understand:

- **Memory Management**: Dynamic allocation and deallocation
- **Pointer Arithmetic**: Direct memory access and manipulation
- **String Processing**: Low-level string operations
- **File Operations**: Reading from and writing to files
- **Data Structures**: Linked list implementation
- **Algorithm Implementation**: Complex multiplication algorithms
- **Debugging**: Memory leak detection and prevention

## Key Concepts Covered

- Address-of and dereference operators
- Function parameters by reference
- Dynamic memory allocation (`malloc`, `realloc`, `free`)
- Null-terminated string handling
- File I/O operations with error handling
- Preprocessor macros and definitions
- Linked list operations
- Memory leak tracking

## Requirements

- C99 compliant compiler (gcc recommended)
- Standard C library
- Basic understanding of C programming concepts

## Output Files

The program may create:
- `students.txt` - Student records with GPA information

## Notes

- All code includes educational comments
- Memory operations include proper error checking
- Custom memory tracker helps identify leaks
- Each part can be tested independently

---
