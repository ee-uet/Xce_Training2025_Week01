# C Programming Lab Tasks

This repository contains implementations of various C programming tasks covering **pointers, arrays, strings, file I/O, macros, linked lists, dynamic memory allocation, and Booth's multiplication**.

---

## Part 1: Pointer Basics and Arithmetic

### Task 1.1: Basic Pointer Usage

**Problem Statement:**  
Demonstrate basic pointer operations including declaration, dereferencing, and modifying variable values through pointers.

**Working Explanation:**  
- Declare an integer `a` and a pointer `ptra` pointing to `a`.  
- Print the value of `a` directly and through the pointer.  
- Modify the value using the pointer to show that pointers can directly manipulate variables.  

---

### Task 1.2: Swap Two Integers Using Pointers

**Problem Statement:**  
Swap the values of two integers using pointers.

**Working Explanation:**  
- The function `swap(int *a, int *b)` takes addresses of two integers.  
- A temporary variable is used to swap values.  
- Pointer dereferencing ensures the actual variables are updated.

---

### Task 1.3: Pointer Arithmetic on Arrays

**Problem Statement:**  
Perform arithmetic operations on arrays using pointers: traverse, sum, and reverse.

**Working Explanation:**  
- Declare an integer array and use pointers to traverse and print its elements.  
- Calculate the sum of array elements using pointer arithmetic.  
- Reverse the array in place by swapping elements via pointers.  

---

## Part 2: Pointers and Arrays/Strings

### Custom `strlen`, `strcpy`, `strcmp`

**Problem Statement:**  
Implement standard string functions using pointers instead of array indexing.

**Working Explanation:**  
- `my_strlen`: Counts characters until the null terminator.  
- `my_strcpy`: Copies string including null terminator.  
- `my_strcmp`: Compares strings character by character and returns their difference.  

---

### Task 2.2: Palindrome Checker (Case-Insensitive)

**Problem Statement:**  
Check whether a string is a palindrome ignoring case sensitivity.

**Working Explanation:**  
- Use two pointers at the start and end of the string.  
- Compare characters after converting them to lowercase.  
- Move pointers toward the middle; if all pairs match, the string is a palindrome.  

---

## Part 3: Preprocessor & File I/O

### Task 3.1: Macros

**Problem Statement:**  
Demonstrate the use of preprocessor macros in C.

**Working Explanation:**  
- Defined macros: `SQUARE`, `MAX2`, `MAX3`, `MAX4`, `TO_UPPER`.  
- Used macros to perform compile-time operations on integers and characters.  
- Demonstrates efficiency and convenience of macros.

---

### Task 3.2: File Handling

**Problem Statement:**  
Store and retrieve structured data (students) using files.

**Working Explanation:**  
- Array of `struct Student` stores student information.  
- Maximum GPA is found using macros.  
- Write all student records to `students.txt` using `fprintf`.  
- Read selected student records using `fscanf`.  
- Demonstrates structured data handling and file I/O in C.  

---

## Part 4: Linked List Operations

**Problem Statement:**  
Implement a simple linked list with insertion and deletion operations.

**Working Explanation:**  
- `struct Node` represents each node of the list.  
- `insert_begin` inserts nodes at the start of the list.  
- `delete_value` deletes a node containing a specified value.  
- `print_list` traverses and prints the list.  
- Dynamic memory allocation ensures runtime flexibility.  

---

## Part 5: Dynamic Memory Allocation

### Task 5.1: Dynamic Array Sum and Average

**Problem Statement:**  
Allocate an array dynamically, input elements, and compute sum and average.

**Working Explanation:**  
- Memory allocated using `malloc`.  
- User inputs values which are summed and averaged.  
- Memory is freed using `free`.  

---

### Task 5.2: Extend Array Using `realloc`

**Problem Statement:**  
Extend a dynamically allocated array and append new elements.

**Working Explanation:**  
- Initial allocation done using `malloc`.  
- `realloc` used to extend array size.  
- New elements added to extended portion and full array printed.  
- Memory is freed after use.  

---

### Task 5.3: Memory Leak Detector

**Problem Statement:**  
Detect unfreed memory allocations to prevent memory leaks.

**Working Explanation:**  
- Custom `my_malloc` tracks allocated pointers.  
- `my_free` frees memory and updates tracking.  
- `report_leaks` identifies unfreed pointers.  
- Demonstrates proper dynamic memory management in C.  

---

## Final Task: Booth's Multiplication

**Problem Statement:**  
Implement Booth’s algorithm for signed integer multiplication.

**Working Explanation:**  
- Handles negative numbers by converting to positive and adjusting sign.  
- Performs arithmetic right shifts and conditional addition/subtraction based on Booth’s rules.  
- Returns the signed multiplication result.  
- Tested with multiple positive and negative integer combinations.  

---

## **Main Function**
- Execute all tasks in sequence.
- Calls each task function one by one.

## How to Run
To compile and run this code, following commands were used:
```
gcc code.c -o code 
./code
```

## Sources and AI Usage
- Recalled some Linked list concepts from [here](https://www.geeksforgeeks.org/c/linked-list-in-c/)
- Understood the working of `strlen`, `strcmp` and `strcpy`.
- Took AI assistance in writing code of Dynamic Memory part `ChatGPT`
- Understood the Booth Multiplication algorithm - `ChatGPT`
- Some final refining and optimization with help of AI - `ChatGPT`
