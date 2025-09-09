# C Programming Tasks Collection

A comprehensive collection of C programming tasks covering fundamental concepts and advanced topics. Each task is well-documented and demonstrates core programming principles.

## Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Compilation and Execution](#compilation-and-execution)
- [Tasks Overview](#tasks-overview)
- [File Outputs](#file-outputs)
- [Usage Examples](#usage-examples)
- [Features](#features)

## Overview

This project contains 10 programming tasks that cover essential C programming concepts including:
- Data types and type casting
- Control structures and algorithms
- File I/O operations
- Memory management
- Bitwise operations
- Data structures (structs, enums)
- Command line arguments

## Prerequisites

- GCC compiler or any C compiler
- Basic understanding of C programming
- Terminal/Command prompt access

## Compilation and Execution

### Basic Compilation
```bash
gcc -o program main.c -lm
```

### Run the Program
```bash
./program
```

### For Command Line Arguments (Task 10)
```bash
./program 15 25
```

## Tasks Overview

### Task 0.1 - Data Types
- **Function**: `task01_datatypes()`
- **Purpose**: Demonstrates different data types and type casting
- **Features**: 
  - Shows memory size of each data type
  - Demonstrates explicit type casting between int, float, double, char

### Task 0.2 - Calculator
- **Function**: `task02_calculator()`
- **Purpose**: Interactive calculator with switch-case implementation
- **Features**:
  - Basic arithmetic operations (+, -, *, /, %)
  - Interactive operator selection
  - Input validation

### Task 0.3 - Fibonacci & Guessing Game
- **Functions**: `task03_fibonacci()`, `task03_guessing_game()`
- **Purpose**: Recursive algorithms and interactive games
- **Features**:
  - Recursive Fibonacci sequence generation
  - Number guessing game with feedback
  - Attempt counter

### Task 0.4 - Prime Numbers
- **Function**: `task04_prime_numbers()`
- **Purpose**: Prime number detection and file operations
- **Features**:
  - Efficient prime checking algorithm (√n optimization)
  - Outputs primes 1-100 to console and file
  - Creates `prime_numbers.txt`

### Task 0.5 - String & Array Operations
- **Functions**: `task05_reverse_string()`, `task05_second_largest()`
- **Purpose**: String manipulation and array algorithms
- **Features**:
  - String reversal without library functions
  - Second largest element detection with duplicate handling
  - Manual string length calculation

### Task 0.6 - File I/O
- **Function**: `task06_file_io()`
- **Purpose**: File read/write operations
- **Features**:
  - Write integers to file
  - Read data back from file
  - Error handling for file operations

### Task 0.7 - Bitwise Operations
- **Function**: `task07_bitwise_ops()`
- **Purpose**: Demonstrate bitwise operators and applications
- **Features**:
  - AND, OR, XOR, NOT operations
  - Left and right bit shifts
  - Power of 2 detection using bitwise trick

### Task 0.8 - Enumerations
- **Function**: `task08_enum_weekday()`
- **Purpose**: Enum usage for mapping numbers to weekdays
- **Features**:
  - Custom enum definition
  - Number to weekday conversion
  - Switch-case with enum constants

### Task 0.9 - Structures
- **Functions**: `task09_struct_distance()`, `task09_check_power_of_two()`
- **Purpose**: Structure usage and geometric calculations
- **Features**:
  - 2D point structure
  - Euclidean distance calculation
  - Additional power of 2 checking

### Task 0.10 - Command Line Arguments
- **Function**: `task10_cmd_args()`
- **Purpose**: Command line argument processing
- **Features**:
  - Takes two integers as arguments
  - String to integer conversion
  - Usage instruction display

## File Outputs

The program creates the following files:
- `prime_numbers.txt` - Contains prime numbers from 1 to 100 (Task 4)
- `numbers.txt` - Used for file I/O demonstration (Task 6)

## Usage Examples

### Running Individual Tasks
Uncomment the desired task in the `main()` function:

```c
int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    task01_datatypes();     // Run data types demo
    // task02_calculator();    // Run calculator
    // ... other tasks
    
    return 0;
}
```

### Sample Inputs and Outputs

**Task 1 Output:**
```
Size of car_no is:  4 bytes
Size of car_torque: 4 bytes
Size of engine_V:   8 bytes
Size of car_name:   1 bytes
Converting int(12) ---> float:      12.000000
Converting float(54.7) ---> int:    54
```

**Task 3 Fibonacci (n=7):**
```
Fibonacci Series: 0 1 1 2 3 5 8
```

**Task 10 Command Line:**
```bash
$ ./program 15 25
Sum = 40
```

## Features

- **Well-Commented Code**: Every function and algorithm is thoroughly documented
- **Error Handling**: Proper file operation error checking
- **Efficient Algorithms**: Optimized implementations (e.g., prime checking with √n)
- **Interactive Programs**: User-friendly input/output interfaces
- **File Operations**: Demonstrates both reading and writing to files
- **Memory Efficient**: Uses appropriate data types and structures
- **Modular Design**: Each task is a separate, reusable function

## Learning Outcomes

After working with these tasks, you will understand:
- C data types and memory management
- Control structures and algorithms
- File I/O operations
- Bitwise operations and their applications
- Structure and enum usage
- Command line argument handling
- Recursive programming techniques
- String manipulation without library functions

## Getting Started

1. Clone or download the source code
2. Compile using the provided command
3. Uncomment desired tasks in `main()`
4. Run and experiment with different inputs
5. Check generated files for file I/O tasks
