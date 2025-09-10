# Shell Scripts and Makefile

## Overview

This lab contains shell scripting tasks covering basic commands, control structures, functions, arrays, file operations, and Makefile automation for build processes and testing.

## Folder Structure

```
Day03_Shell_Make_Git/
├── Task1/
│   ├── task1_.sh
│   ├── task1_2.sh
│   └── task1_3.sh
├── Task2/
│   ├── task2_1.sh
│   ├── task2_2.sh
│   └── task2_3.sh
├── Task3/
│   ├── task3_1.sh
│   ├── task3_2.sh
│   └── task3_3.sh
├── Task4/
│   ├── task4_1.sh
│   ├── task4_2.sh
│   ├── task4_3.sh
|   ├── log.txt
|   ├── data.txt
|   └── imp_file
|   
├── task5_12/
│   ├── function.c
|   ├── main.c
|   └── Makefile
└── task5_3/
    ├── task1_.sh
    ├── task1_3.sh
    ├── test_task1_1.sh
    └── test_task1_3.sh
    └── Makefile
    
```

## Tasks

### Task 1: Basic Shell Commands

#### Task 1.1 - Hello World
**Problem**: Print "hello_world!" message.
**Approach**: Use echo command to display output.

#### Task 1.2 - User Input
**Problem**: Read user name and greet them.
**Approach**: Use read command with prompt and echo for output.

#### Task 1.3 - Command Line Arguments
**Problem**: Add two numbers passed as command line arguments.
**Approach**: Use positional parameters $1 and $2 with arithmetic expansion.

### Task 2: Control Structures

#### Task 2.1 - Even/Odd Check
**Problem**: Check if a number is even or odd.
**Approach**: Use modulo operation with if-else conditional statement.

#### Task 2.2 - Multiplication Table
**Problem**: Generate multiplication table for a given number.
**Approach**: Use for loop with arithmetic operations.

#### Task 2.3 - Guessing Game
**Problem**: Generate random number and let user guess it.
**Approach**: Use RANDOM variable with while loop and conditional statements.

### Task 3: Functions and Data Structures

#### Task 3.1 - Recursive Factorial
**Problem**: Calculate factorial using recursive function.
**Approach**: Define function with base case and recursive call using command substitution.

#### Task 3.2 - Array Operations
**Problem**: Work with arrays to store and manipulate fruit names.
**Approach**: Use indexed arrays with function to iterate and add elements.

#### Task 3.3 - Associative Arrays
**Problem**: Create country-capital mapping using associative arrays.
**Approach**: Use declare -A for associative array and iterate through keys.

### Task 4: File Operations and Text Processing

#### Task 4.1 - File I/O
**Problem**: Create file, write content, and read line by line with numbering.
**Approach**: Use output redirection and while read loop with line counter.

#### Task 4.2 - Log Analysis
**Problem**: Analyze log file to count entries and extract user statistics.
**Approach**: Use awk for text processing, sort and uniq for data analysis.

#### Task 4.3 - Directory Backup
**Problem**: Create compressed backup of directory with timestamp.
**Approach**: Use tar command with date formatting and error handling.

### Task 5: Makefile Operations

#### Task 5.12 - C Program Makefile
**Problem**: Create Makefile for compiling C programs with dependencies.
**Approach**: Use wildcards, pattern rules, and automatic dependency generation.

#### Task 5.3 - Shell Script Testing Makefile
**Problem**: Create Makefile for shell script syntax checking and testing.
**Approach**: Use phony targets, loops for batch operations, and test automation.

## How to Run

### Shell Scripts
```bash
chmod +x script_name.sh
./script_name.sh
```

### With Arguments
```bash
./task1_3.sh 5 10
```

### Makefile Operations
```bash
make all
make clean
make install
```

## Examples

### Task 1.3 - Command Line Arguments
```bash
./task1_3.sh 5 10
Output:
Sum= 15
```

### Task 2.2 - Multiplication Table
```
Input: 5
Output:
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
```

### Task 3.1 - Recursive Factorial
```
Output:
factorial of 5
120
factorial of 3
6
```

### Makefile - Build Process
```bash
make all
Output:
Checking syntax...
task1_.sh passed syntax check...
task1_3.sh passed syntax check...
All scripts passed syntax check.
Running tests...
task1_1.sh test passed
task1_3.sh test passed
All tests passed.
```
