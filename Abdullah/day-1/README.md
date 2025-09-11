# C Programming Lab - Day 1

This repository contains solutions for Lab Experiment 01 - C Language fundamentals and revision exercises.

## Project Structure

```
/day-1/
├── README.md                    # This file
├── task-1/                      # Basic Syntax and Data Types
│   ├── datatypes.c
│   └── README.md
├── task-2/                      # Operators and Calculator
│   ├── calculator.c
│   └── README.md
├── task-3/                      # Control Structures
│   ├── fibonacci.c
│   ├── guessing_game.c
│   └── README.md
├── task-4/                      # Functions (Prime & Factorial)
│   ├── prime_numbers.c
│   ├── factorial.c
│   └── README.md
├── task-5/                      # Arrays and Strings
│   ├── reverse_string.c
│   ├── second_largest.c
│   └── README.md
├── task-6/                      # File I/O
│   ├── file_io.c
│   └── README.md
├── task-7/                      # Bitwise Operations
│   ├── bitwise_ops.c
│   └── README.md
├── task-8/                      # Enumerations
│   ├── enum_weekday.c
│   └── README.md
├── task-9/                      # Structures
│   ├── struct_distance.c
│   └── README.md
└── task-10/                     # Command Line Arguments
    ├── cmd_args.c
    └── README.md
```

## Lab Objective

To experience with C programming fundamentals including:
- Data types and type casting
- Operators and expressions
- Control structures
- Functions (recursive and iterative)
- Arrays and string manipulation
- File I/O operations
- Bitwise operations
- Enumerations and structures
- Command line argument handling

## How to Compile and Run

Each task folder contains its own compilation instructions. Generally:

```bash
gcc -o program_name source_file.c -lm
./program_name
```

Note: The `-lm` flag is required for tasks using math functions.

## Materials Needed

- Computer with GCC compiler
- Text editor or IDE
- Terminal/Command prompt

## Tasks Overview

1. **Task 1**: Basic data types, sizeof operator, type casting
2. **Task 2**: Arithmetic operations and switch-case calculator
3. **Task 3**: Loops (Fibonacci) and random number guessing game
4. **Task 4**: Function implementation (prime checking, factorial)
5. **Task 5**: String reversal and array processing
6. **Task 6**: File input/output operations
7. **Task 7**: Bitwise operations and power of 2 checking
8. **Task 8**: Enumeration usage for weekdays
9. **Task 9**: Structure definition and Euclidean distance calculation
10. **Task 10**: Command line argument processing

## Sources & AI Usage

This code was developed as part of a C programming lab exercise. Some implementation approaches were verified and refined using AI assistance for:
- Code organization and structure
- Documentation standards
- Edge case handling verification

## What I Verified

- All arithmetic operations handle integer division correctly
- File operations include proper error checking
- Memory safety in string operations
- Edge cases for mathematical functions (factorial of 0, prime checking for 1)
- Proper random number seeding
- Command line argument validation