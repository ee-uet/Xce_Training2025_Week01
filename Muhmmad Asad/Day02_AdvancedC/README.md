# Advanced C Programming

## Overview

This C programming lab contains advanced C programming concepts including pointer operations, dynamic memory allocation, preprocessor macros, file I/O, linked lists, and Booth algorithm implementation.

## Tasks

### Part 1: Pointer Basics and Arithmetic

#### Task 1.1 - Basic Pointer Usage
**Problem**: Demonstrate basic pointer operations including declaration, dereferencing, and modification.
**Approach**: Declare an integer variable and a pointer to it, print values using direct access and pointer dereferencing, then modify the value through the pointer.

#### Task 1.2 - Swap Two Integers Using Pointers
**Problem**: Swap two integers using pointer parameters.
**Approach**: Pass addresses of variables to a function and use pointer dereferencing to swap values.

#### Task 1.3 - Pointer Arithmetic on Array
**Problem**: Use pointer arithmetic to traverse arrays, calculate sum, and reverse array in place.
**Approach**: Use pointer arithmetic with array base address, increment pointers for traversal, and use two-pointer technique for reversal.

### Part 2: Pointers and Arrays/Strings

#### Custom String Functions
**Problem**: Implement strlen, strcpy, and strcmp using pointers without library functions.
**Approach**: Use pointer traversal and dereferencing to manipulate strings character by character.

#### Task 2.2 - Palindrome Checker
**Problem**: Check if a string is a palindrome (case-insensitive).
**Approach**: Copy string to buffer, reverse it using custom functions, then compare with original.

### Part 3: Preprocessor & File I/O

#### Task 3.1 - Macros
**Problem**: Create and demonstrate macros for SQUARE, MAX2, MAX3, MAX4, MAX5, and TO_UPPER.
**Approach**: Use preprocessor directives to define function-like macros with conditional operators.

#### Task 3.2 - File I/O with Student Records
**Problem**: Handle student data with file operations to find and store highest GPA student.
**Approach**: Create student structures, find maximum GPA using macros, write to file, then read back and display.

### Part 4: Advanced Challenge

#### Task 4.1 - Linked List Operations
**Problem**: Implement linked list with insert at beginning, delete by value, and print operations.
**Approach**: Use dynamic memory allocation for nodes, maintain head pointer, and traverse for operations.

### Part 5: Dynamic Memory Allocation

#### Task 5.1 - Dynamic Array Operations
**Problem**: Create dynamic array, input elements, and calculate sum and average.
**Approach**: Use malloc for memory allocation, pointer arithmetic for access, and free for cleanup.

#### Task 5.2 - Array Extension with Realloc
**Problem**: Extend existing array using realloc.
**Approach**: Use realloc to resize memory block and add new elements to extended portion.

#### Task 5.3 - Memory Leak Detector
**Problem**: Track memory allocations and detect leaks.
**Approach**: Maintain array of allocated pointers, track allocations/deallocations, and report unfreed memory.

### Final Task: Booth's Multiplication Algorithm

#### Booth's Multiplication
**Problem**: Implement Booth's multiplication algorithm for binary multiplication.
**Approach**: Use bitwise operations, arithmetic shifts, and addition/subtraction without using multiplication operator.

## How to Run

### Compilation
```bash
gcc -o lab2 lab2.c
```

### Running
```bash
./lab2
```

## Examples

### Task 1.2 - Swap Function
```
Output:
Before: 
a = 5 and b = 10
After: 
a = 10 and b = 5
```

### Task 2.2 - Palindrome Checker
```
Input: "Madam"
Output:
Palindrome? Yes
```

### Task 3.1 - Macros
```
Output:
square = 4
Max2 = 2
Max3 = 3
Max4 = 4
Max5 = 5
upper = B
```

### Final Task - Booth's Multiplication
```
Output:
5 x 3 = 15
5 x -3 = -15
5 x 0 = 0
```
