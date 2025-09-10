
## Task 1.1 – Basic Pointer Usage

### Introduction
Demonstrates how pointers reference memory and modify variable values.

### Problem
- Declare an integer `a`.  
- Use a pointer to print and modify its value.  

### Approach
- Assign `p = &a`.  
- Print `a` and `*p`.  
- Modify `*p` to change the value of `a`.  

### Example Output

10
10
20


### AI Usage
- nope.

---

## Task 1.2 – Swap Two Integers Using Pointers

### Introduction
Swaps two integers using pointers.

### Problem
Write a function `swap(int *a, int *b)` that exchanges the values.

### Approach
- Use a temporary variable.  
- Swap using dereferenced pointers.  

### Example Output
Input:
a = 10, b = 20

Output:
20
10


### AI Usage
- nope.

---

## Task 1.3 – Pointer Arithmetic on Array

### Introduction
Explores pointer arithmetic for traversing, summing, and reversing arrays.

### Problem
Perform three operations:  
1. Print array elements.  
2. Compute sum.  
3. Print array in reverse order.  

### Approach
- Use a pointer to traverse.  
- Increment pointer for forward traversal.  
- Decrement pointer for reverse traversal.  

### Example Output
Input:
Array = {1, 2, 3, 4, 5}

Output:
1 2 3 4 5
Sum: 15
5 4 3 2 1

### AI Usage
- nope.
---

## Task 2.1 – String Functions with Pointers

### Introduction
Reimplementation of standard string functions using pointers.

### Functions
- `my_strlen` → counts length.  
- `my_strcpy` → copies one string to another.  
- `my_strcmp` → compares two strings.  
- `is_palindrome` → checks palindrome ignoring case.  

### Example Output
Input:
s1 = "hello"
s2 = "hello"
s3 = "madam"

Output:
Length = 5
Copy result: hello
1st string is smaller (if comparing "abc" and "bcd")
Palindrome check on "madam": yes


### AI Usage
- Used AI to check the functionality and also to check if logic was correct, also used tolower based on suggestion.

---

## Task 3.1 – Macros

### Introduction
Demonstrates the use of preprocessor macros in C.

### Problem
Define macros for square, max of 2/3/4, and uppercase conversion.

### Approach
- Use `#define`.  
- Example: `#define SQUARE(x) ((x)*(x))`.  

### Example Output
Input:
SQUARE(5), MAX2(3,7), MAX3(1,4,2), MAX4(1,9,3,2), TO_UPPER('a')

Output:
Square(5) = 25
Max2(3,7) = 7
Max3(1,4,2) = 4
Max4(1,9,3,2) = 9
TO_UPPER('a') = A


### AI Usage
- to check syntax.

---

## Task 3.2 – File I/O with Structures

### Introduction
Demonstrates file I/O using a `struct Student`.

### Problem
- Find student with highest GPA.  
- Write a student record to a file.  
- Read it back.  

### Approach
- Iterate array to find max GPA.  
- Use `fprintf` to write and `fscanf` to read.  

### Example Output
Input:
Students = {{"zahra", 3.6}, {"alishba", 3.33}, {"mariam", 3.4}, {"laiba", 3.4}, {"areeba", 3.2}}

Output:
Student with highest GPA: zahra, GPA: 3.60
Read from file -> Name: Hamna, GPA: 3.4


### AI Usage
- syntax of fopen and fclose.

---

## Task 4.1 – Linked List Operations

### Introduction
Implements a singly linked list with insert, delete, and print operations.

### Problem
- Insert nodes at beginning.  
- Delete a node by value.  
- Print the list.  

### Approach
- Use dynamic allocation with `malloc`.  
- Update pointers on insert and delete.  

### Example Output
Input:
Insert 10, 20, 30
Delete 20

Output:
data: 30
data: 20
data: 10
After deletion:
data: 30
data: 10


### AI Usage
- nope.

---

## Task 5.1 – Dynamic Array with Custom malloc/free

### Introduction
Implements custom memory allocation tracker and dynamic array usage.

### Problem
- Allocate memory for `n` integers.  
- Input values, compute sum and average.  

### Approach
- Implement `my_malloc` and `my_free` to track allocations.  
- Use `scanf` to populate and process array.  

### Example Input/Output
Input:
5
1 2 3 4 5

Output:
15 3.00


### AI Usage
- nope.

---

## Task 5.2 – Realloc Array

### Introduction
Demonstrates `realloc` for resizing arrays.

### Problem
Start with array of 3 integers, resize to 4, and append new value.

### Example Output
Input:
Initial array = {1, 2, 3}
Append 4

Output:
1 2 3 4


### AI Usage
-nope.

---

## Task 5.3 – Leak Detector

### Introduction
Shows how to track allocated pointers and report leaks.

### Problem
- Allocate memory for several data types.  
- Free only one pointer.  
- Report leaks.  

### Example Output

Input:
Allocate int[5], double[3], char[10]
Free double[3]

Output:
0x55f2c3b5b2a0 not free
0x55f2c3b5b2c0 not free

### AI Usage
- used Ai to check every step and asked for guidance to next, also syntax error correcion.

---

## Task 6 – Booth’s Multiplication Algorithm

### Introduction
Implements Booth’s algorithm for signed integer multiplication.

### Problem
Multiply two signed integers using Booth’s algorithm.

### Approach
- Handle signs separately.  
- Use add/shift operations with accumulator and Q register.  
- Use helper `add_bits` for binary addition.  

### Example Output
Input:
booth_multiply(7, 6)
booth_multiply(7, -4)
booth_multiply(-9, 5)
booth_multiply(-8, -3)
booth_multiply(0, 10)

Output:
7 * 6 = 42
7 * -4 = -28
-9 * 5 = -45
-8 * -3 = 24
0 * 10 = 0


### AI Usage
- Used AI to solve the problem of not handling signs properly.
