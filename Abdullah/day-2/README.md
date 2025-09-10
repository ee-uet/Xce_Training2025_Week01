# C Programming Lab - Day 2

This repository contains solutions for Lab Experiment 02 - Advanced C Language concepts including pointers, dynamic memory allocation, and advanced algorithms.

## Project Structure

```
/day-2/
├── README.md                    # This file
├── task-1/                      # Pointer Basics and Arithmetic
│   ├── basic_pointers.c
│   ├── swap_pointers.c
│   ├── pointer_arithmetic.c
│   └── README.md
├── task-2/                      # Pointers and Arrays/Strings
│   ├── custom_string_functions.c
│   ├── palindrome_checker.c
│   └── README.md
├── task-3/                      # Preprocessor & File I/O
│   ├── macros.c
│   ├── file_io.c
│   └── README.md
├── task-4/                      # Advanced Challenge - Linked List
│   ├── linked_list.c
│   └── README.md
├── task-5/                      # Dynamic Memory Allocation
│   ├── dynamic_array.c
│   ├── realloc_array.c
│   ├── memory_leak_detector.c
│   └── README.md
└── task-6/                      # Final Task - Booth's Multiplication
    ├── booth_multiplication.c
    └── README.md
```

## Lab Objective

To gain practical experience with advanced pointer concepts in C, including:
- Pointer basics and arithmetic operations
- Pointers with arrays and strings
- Custom string function implementation
- Preprocessor macros and file I/O
- Dynamic memory allocation and management
- Advanced algorithms (Booth's multiplication)
- Memory leak detection
- Linked list implementation

## How to Compile and Run

Each task folder contains its own compilation instructions. Generally:

```bash
gcc -o program_name source_file.c
./program_name
```

For programs using math functions:
```bash
gcc -o program_name source_file.c -lm
./program_name
```

## Materials Needed

- Computer with GCC compiler
- Debugger (GDB)
- Text editor or IDE
- Terminal/Command prompt

## Tasks Overview

1. **Task 1**: Pointer basics, swapping, and arithmetic operations
2. **Task 2**: Custom string functions and palindrome checking
3. **Task 3**: Preprocessor macros and file I/O with structures
4. **Task 4**: Linked list implementation with insert/delete operations
5. **Task 5**: Dynamic memory allocation, realloc, and leak detection
6. **Task 6**: Booth's multiplication algorithm implementation

## Key Concepts Covered

- **Pointer Fundamentals**: Declaration, dereferencing, address operations
- **Pointer Arithmetic**: Array traversal, element access via pointers
- **String Manipulation**: Custom implementations without library functions
- **Dynamic Memory**: malloc, realloc, free, memory leak prevention
- **Data Structures**: Linked list operations and management
- **Advanced Algorithms**: Booth's multiplication with bit manipulation
- **File Operations**: Reading/writing structured data to files
- **Preprocessor**: Macro definitions and conditional compilation

## Sources & AI Usage

This code was developed as part of a C programming lab exercise. Some implementation approaches were verified and refined using AI assistance for:
- Algorithm understanding
- Documentation standards and formatting
- Edge case handling verification
- Memory management best practices

## What I Verified

- All pointer operations are memory-safe
- Dynamic memory allocation includes proper error checking
- File operations include appropriate error handling
- Booth's algorithm implementation follows standard specifications
- Memory leak detector correctly tracks allocations
- All string functions handle edge cases appropriately
