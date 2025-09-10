# Day 2 – C Programming Tasks

## Task 1: Pointers

### 1.1 Pointer Basics
- Declares an integer variable and a pointer to it.  
- Prints the value directly and through the pointer.  
- Modifies the variable’s value using the pointer.  

### 1.2 Swap Two Integers Using Pointers
- Swaps two integers using pointer dereferencing.  
- Demonstrates changing values without returning from the function.

---

## Task 2: Arrays and Strings

### 2.1 Array Operations
- Creates an integer array.  
- Prints all elements using pointers.  
- Calculates the sum of array elements.  
- Reverses the array in-place and prints it.

### 2.2 String Functions
- `my_strlen`: Computes the length of a string using pointers.  
- `my_strcpy`: Copies a string from source to destination using pointers.  
- `my_strcmp`: Compares two strings and checks if they are equal.  
- `is_palindrome`: Checks if a given string is a palindrome.

---

## Task 3: Macros and File I/O

### 3.1 Macros
- `SQUARE(x)`: Computes the square of a number.  
- `MAX2(a,b)`: Returns the maximum of two numbers.  
- `MAX3(a,b,c)`: Returns the maximum of three numbers.  
- `MAX4(a,b,c,d)`: Returns the maximum of four numbers.  
- `TO_UPPER(c)`: Converts a lowercase character to uppercase.

### 3.2 File I/O with Structs
- Defines `struct Student` to store name, roll, and GPA.  
- Finds and prints the student with the highest GPA.  
- Saves all students to `student.txt` and reads back to display.

---

## Task 4: Linked Lists

### 4.1 Insert at Beginning
- Creates a new node and inserts it at the start of the list.

### 4.2 Delete by Value
- Deletes a node by its value if it exists.  
- Handles deletion of the head node and nodes in the middle.

### 4.3 Print Linked List
- Prints all elements of the linked list in order.

---

## Task 5: Dynamic Memory Allocation

### 5.1 Dynamic Arrays
- Allocates memory dynamically using `malloc`.  
- Inputs array elements from the user.  
- Computes the sum and average.  
- Frees the memory after use.

### 5.2 Extend Array Using Realloc
- Demonstrates extending a previously allocated array using `realloc`.

### 5.3 Memory Leak Detector
- Tracks memory allocations using a custom `my_malloc`.  
- Frees memory using `my_free`.  
- Reports unfreed memory to detect leaks.

---

## Task 6: Booth’s Multiplication

### 6.1 Booth Algorithm
- Implements Booth’s multiplication for signed integers.  
- Uses bitwise addition and subtraction.  
- Handles positive, negative, and zero values.  
- Includes test cases for demonstration.

---

## How to Run

1. Compile the program:
```bash
gcc day2_tasks.c -o day2_tasks

