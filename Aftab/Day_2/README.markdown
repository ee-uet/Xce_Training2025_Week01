
## Part 1: Pointer Basics and Arithmetic

### Task 1.1: Basic Pointer Usage
TODO: Show basic pointer stuff with an int variable.

Working: 
Declare an int `a = 2` and pointer `ptr` to it. 
Print `a` directly and via `*ptr`. 
Change `a` to 3 using `*ptr` and print it.

Test Case: Call task1_1()
```
printf("direct print: %d\npointer print: %d\n", a, *ptr); 
printf("modified value using pointer: %d\n", *ptr);
```

Output:
```
direct print: 2
pointer print: 2
modified value using pointer: 3
```

### Task 1.2: Swap Two Integers Using Pointers
TODO: Swap two integers using their pointers.

Working: 
Takes pointers to two ints, 
uses a temp variable to swap their values, 
and prints the result.

Test Case:
```
int a = 5, b = 10;
swap(&a, &b);
```
Output:
```
*a = 10 & *b = 5
```

### Task 1.3: Pointer Arithmetic on Array
TODO: Use pointers to print array elements, sum them, and reverse a string.

Working: 
Uses an array `arr = {3, 7, 5, 4, 2, 6}` and string `AFTAB`. 
Prints array via pointer, sums it, and reverses string using start/end pointers.

Test Case: Call task1_3().

Output:
```
3 7 5 4 2 6
Sum is 27
BATFA
```

## Part 2: Pointers and Arrays/Strings

### Task 2.1: Custom String Functions
TODO: Implement `my_strlen`, `my_strcpy`, and `my_strcmp` with pointers.

Working: 
`my_strlen` counts chars until `\0`. 
`my_strcpy` copies chars from `src` to `dest` until `\0`.
`my_strcmp` compares two strings using pointers. 

Test Case:
``` 
printf("Len = %d\n", my_strlen("Hello")); 
char buf[100]; my_strcpy(buf, "World"); 
printf("Copied: %s\n", buf);
printf("%d\n", my_strcmp("Afta","Aftab"));
```
Output:
```
Len = 5
Copied: World
0
```

### Task 2.2: Palindrome Checker
TODO: Check if a string is a case-insensitive palindrome.

Working: 
Uses two pointers (start and end) to compare chars using `tolower`. 
Returns 1 if palindrome, 0 if not.

Test Case: 
```
printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes" : "No");
```
Output:
```
Palindrome? Yes
```

## Part 3: Preprocessor & File I/O

### Task 3.1: Macros
TODO: Define and test macros for squaring, max of 2/3/4 numbers, and uppercase conversion.

Working: `SQUARE` multiplies a number by itself. 
`MAX2`, `MAX3`, `MAX4` use ternaries to find the largest. 
`TO_UPPER` subtracts 32 from lowercase ASCII.

Test Case: task3_1_macros();
```
printf("between 5 & 10: %d\n", MAX2(5,10));
printf("between 8, 5 and 10: %d\n", MAX3(8,5,10));
printf("between 12,8,5 and 10: %d\n", MAX4(12,8,5,10));
printf("Square of %d: %d\n",4, SQUARE(4));  
printf("%c\n", TO_UPPER('a'));
```
Output:
```
between 5 & 10: 10
between 8, 5 and 10: 10
between 12, 8, 5 and 10: 12
Square of 4: 16
A
```

### Task 3.2: File I/O
TODO: Manage student data, find topper, save to file, and read back.

Working: 
Uses a `struct student` array with 5 students. 
Finds highest GPA, writes to `students.txt`, and reads back.

Test Case: Array of 5 students
```
struct student students[5] = {    
        {"hamza", 16, 3.1},
        {"ali", 15, 3.5},
        {"ahsan", 17, 3.4},
        {"bilal", 14, 3.3},
        {"ahmad", 24, 3.2}
    };
```    
Output:
```
File student.txt in directory
Name: ali
Roll no: 15
GPA: 3.5
```

## Part 4: Advanced Challenge (Linked List)

### Task 4.1: Linked List Operations
TODO: Implement insert, delete, and print for a linked list.

Working: `insert_begin` adds a node at the start. 
`delete_value` removes a node by position. 
`print_list` shows all nodes. 
Tests by inserting 7, 5, 3, 2 and deleting 2nd.

Test Case: struct Node* head = task4_1_linkedlist(); 
print_list(head);

Output:
```
7
3
2
```

## Part 5: Dynamic Memory Allocation

### Task 5.1: Dynamic Array
TODO: Allocate array, take input, compute sum and average.

Working: Uses `malloc` for a 5-int array, takes user input, calculates sum and average, then frees memory.

Test Case: Call task5_1_dynamic_array(); (input: 1, 2, 3, 4, 5)

Output:
```
Enter 5 integers:
Element 1: 1
Element 2: 2
Element 3: 3
Element 4: 4
Element 5: 5
Sum = 15
Average = 3.00
```

### Task 5.2: Realloc Array
TODO: Extend a dynamic array with `realloc`.

Working: Allocates 5-int array, extends to 8 with `realloc`, then frees it.

Test Case: Call task5_2_realloc_array();
```
char *a = my_malloc(10);
int *b = my_malloc(20);
my_free(b);
report_leaks();
```

Output: (No output, just memory ops)

### Task 5.3: Memory Leak Detector
TODO: Track memory allocations and detect leaks.

Working: `my_malloc` tracks pointers, `my_free` removes them, `report_leaks` shows unfreed pointers. Tests by allocating two pointers, freeing one.

Test Case: Call task5_3_leak_detector();

Output:
```
Leaked pointers:
<address of a>
```

## Final Task: Booth’s Multiplication

TODO: Implement Booth’s algorithm for multiplication.

Working: Uses bitwise `add` helper. Checks `Q` and `Q_1` bits to add/subtract `A`, shifts right each step. Handles 32-bit integers.

Test Case: Call test_booth();

    assert(booth_multiply(3, 4) == 12);
    assert(booth_multiply(-3, 4) == -12);
    assert(booth_multiply(3, -4) == -12);
    assert(booth_multiply(-3, -4) == 12);
    assert(booth_multiply(0, 1000000) == 0);
    assert(booth_multiply(123456, 0) == 0);
    assert(booth_multiply(INT_MAX, 2) == (int64_t)INT_MAX * 2);
    assert(booth_multiply(1, INT_MIN) == (int64_t)INT_MIN);
    assert(booth_multiply(INT_MAX, INT_MAX) == (int64_t)INT_MAX * INT_MAX);
    printf("All tests passed.\n");

Output: 
```
All tests passed.
```
## Notes
- Uses 32-bit integers.
- Task 3.2 creates `students.txt` in the working directory.
