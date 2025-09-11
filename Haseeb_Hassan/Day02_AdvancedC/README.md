# Advanced C Programming Lab 2

## Overview
This advanced C programming lab focuses on pointers, dynamic memory allocation, file I/O, preprocessor macros, linked lists, and advanced algorithms. The lab contains 15+ programming tasks organized into 5 main parts, demonstrating intermediate to advanced C programming concepts.

## Lab Structure

### Part 1: Pointer Basics and Arithmetic
**Core Concepts**: Pointer fundamentals, memory addresses, pointer arithmetic, array manipulation

### Part 2: Pointers with Arrays and Strings
**Core Concepts**: String manipulation using pointers, custom string functions, palindrome detection

### Part 3: Preprocessor Macros and File I/O
**Core Concepts**: Macro definitions, conditional compilation, file operations with structures

### Part 4: Advanced Data Structures
**Core Concepts**: Linked list implementation, dynamic node management

### Part 5: Dynamic Memory Allocation
**Core Concepts**: malloc/realloc/free, memory leak detection, custom memory management

## Detailed Task Breakdown

### Part 1: Pointer Basics and Arithmetic

#### Task 1.1 - Basic Pointer Usage
**Problem**: Demonstrate pointer declaration, dereferencing, and value modification.
**Implementation**: 
- Declares integer variable and pointer to it
- Shows value access through direct variable and pointer dereferencing
- Modifies value via pointer and displays changes

#### Task 1.2 - Swap Function Using Pointers
**Problem**: Implement integer swapping using pointer parameters.
**Implementation**: 
- Uses pass-by-reference with pointers
- Employs temporary variable for safe swapping
- Displays values before and after swap

#### Task 1.3 - Pointer Arithmetic on Arrays
**Problem**: Array manipulation using pointer arithmetic and in-place reversal.
**Implementation**: 
- Traverses array using pointer arithmetic (`*(array_ptr + i)`)
- Calculates sum using pointer-based iteration
- Implements in-place array reversal using two-pointer technique

### Part 2: Pointers and Arrays/Strings

#### Custom String Functions
**my_strlen()**: Calculates string length by iterating until null terminator
**my_strcpy()**: Copies string characters using pointer arithmetic
**my_strcmp()**: Compares strings character by character, returns 1 for equal, 0 for different
**reverse_string()**: In-place string reversal using two-pointer approach

#### Task 2.2 - Palindrome Checker
**Problem**: Case-sensitive palindrome detection using custom string functions.
**Implementation**: 
- Creates reversed copy using `my_strcpy()` and `reverse_string()`
- Compares original with reversed using `my_strcmp()`
- Returns boolean result for palindrome status

### Part 3: Preprocessor Macros and File I/O

#### Macro Definitions
- `SQUARE(x)`: Calculates square of a number
- `MAX2(a,b)`: Finds maximum of two numbers using ternary operator
- `MAX3(a,b,c)`: Nested macro using MAX2 for three numbers
- `MAX4(a,b,c,d)`: Further nested macro for four numbers
- `TO_UPPER(c)`: Converts lowercase to uppercase using ASCII arithmetic

#### Task 3.2 - Student File I/O
**Problem**: Manage student records with file operations.
**Implementation**: 
- Defines `struct Student` with name, roll number, and GPA
- Creates 5 student records programmatically
- Finds highest GPA using nested MAX macros
- Saves all student data to "student.txt"
- Reads back and displays first student's information

### Part 4: Advanced Data Structures

#### Linked List Implementation
**Node Structure**: Contains integer data and next pointer
**insert_begin()**: Inserts new node at list beginning using malloc
**delete_value()**: Removes node by value with proper memory deallocation
**print_list()**: Displays entire list in "data -> data -> NULL" format

#### Task 4.1 - Linked List Operations
**Problem**: Demonstrate complete linked list functionality.
**Implementation**: 
- Creates empty list and inserts multiple values
- Shows list after insertions
- Deletes existing and non-existing values
- Handles edge cases with appropriate error messages

### Part 5: Dynamic Memory Allocation

#### Task 5.1 - Dynamic Array Operations
**Problem**: Runtime array creation with statistical calculations.
**Implementation**: 
- Gets array size from user input
- Allocates memory using `malloc()` with error checking
- Calculates sum and average of user-entered elements
- Demonstrates proper memory management

#### Task 5.2 - Array Extension with realloc
**Problem**: Extend existing array using `realloc()`.
**Implementation**: 
- Creates initial array with user-specified size
- Displays original array contents
- Extends array using `realloc()` for additional elements
- Shows final extended array

#### Task 5.3 - Memory Leak Detector
**Problem**: Track memory allocation and detect leaks.
**Implementation**: 
- `my_malloc()`: Wrapper around malloc that tracks allocated pointers
- `my_free()`: Wrapper around free that updates tracking array
- `report_leaks()`: Identifies and reports unfreed memory blocks
- Maintains global array of allocated pointers for tracking

## Incomplete/Advanced Features

### Booth's Multiplication Algorithm
**Status**: Function stubs provided for implementation
**Purpose**: Implement Booth's algorithm for binary multiplication
**Functions**: `add()` for bitwise addition, `booth_multiply()` for main algorithm

## How to Run

### Compilation
```bash
gcc -o lab2 lab2.c -lm
```

### Execution
Uncomment desired task functions in `main()` and run:
```bash
./lab2
```

### Task Selection
Each part's tasks are commented out in `main()`. Uncomment specific tasks to test:
```c
// Part 1 Examples
task1_1();
int a=5, b=10; swap(&a,&b);
task1_3();

// Part 2 Examples  
printf("Len = %d\n", my_strlen("Hello"));
char buf[100]; my_strcpy(buf,"World");
printf("Palindrome? %s\n", is_palindrome("madam") ? "Yes":"No");
```

## Sample Outputs

### Task 1.1 - Basic Pointers
```
num = 45 ,through pointer num = 45 
num = 54 ,through pointer num = 54
```

### Task 1.2 - Swap Function
```
num a = 5 , num b = 10 
after swaping num a = 10 , num b = 5
```

### Task 1.3 - Array Operations
```
elements of array are 11  12  13  14  15  
sum = 65
elements of array are 15  14  13  12  11
```

### Task 2 - String Functions
```
Len = 5
Copied: World
if answere is 1 means string is same ...Ans = 1
Palindrome? Yes
```

### Task 3.1 - Macros
```
square of 2 = 4
Maxamum between 45 and 7 is = 45
Maximum 6 and 45 and 7 is = 45
Maxamum between 45and 68 and 90 and 7 is = 90
lets convert d into D
```

### Task 4.1 - Linked List
```
List after insertions: 3 -> 2 -> 1 -> NULL
List after deleting 2: 3 -> 1 -> NULL
50 not found in linked listList after trying to delete 50: 3 -> 1 -> NULL
```

### Task 5.3 - Memory Leak Detection
```
Memory leak detected! 1 block(s) not freed:
  Leak at address: 0x7f8b4b405760
```

## Key Programming Concepts Demonstrated

### Memory Management
- Dynamic allocation with `malloc()` and `realloc()`
- Proper deallocation with `free()`
- Memory leak detection and prevention
- Pointer arithmetic and array manipulation

### Data Structures
- Linked list implementation from scratch
- Node insertion and deletion algorithms
- Memory-efficient data organization

### String Processing
- Custom string function implementation
- Pointer-based string manipulation
- Character-level processing without library functions

### File I/O
- Structure serialization to files
- Reading structured data from files
- File pointer management

### Preprocessor Features
- Macro definition and usage
- Nested macro implementations
- Conditional compilation techniques

## Code Quality Features
- Comprehensive error handling for memory allocation
- Edge case management (empty lists, invalid inputs)
- Memory leak prevention with proper cleanup
- Modular function design for reusability
- Clear variable naming and code organization

## Files Generated
- `student.txt`: Contains student records in text format
- Any files created during testing of file I/O operations

## Notes
- Some advanced features (Booth's algorithm) are provided as stubs for further implementation
- Memory leak detector provides simplified tracking functionality
- All string operations are implemented without using standard library functions
- Code demonstrates both basic and advanced pointer manipulation techniques