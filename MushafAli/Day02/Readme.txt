Lab #02 – Advanced C Programming Concepts

📌 Overview

This lab demonstrates various concepts of C programming through multiple tasks and a final project.
The topics include:

Pointers and array operations

String manipulation using pointers

Macros and file I/O with structures

Linked list operations

Dynamic memory allocation (malloc, realloc, free)

Booth multiplier algorithm

The program is menu-less (all tasks execute sequentially inside main()).

▶️ How to Compile & Run

Save the code in a file named lab02.c.

Open terminal/command prompt and compile:

gcc lab02.c -o lab02


Run the executable:

./lab02


You will be prompted for inputs in some tasks.

📊 Execution Flow & Example Outputs

The following shows the order in which tasks are executed and the kind of output produced.

##Task 1 – Pointers

###Task 1.1: Pointer demonstration
Direct : 10
Indirect : 10
Modified : 40

###Task 1.2: Swap using pointers
Swapped: x=20, y=10

###Task 1.3: Array operations

Program asks for size and elements of array:

Enter size of an array you want to print: 3
Please enter 3 elements in array:
1 2 3
You entered these integers in array:
1 2 3
Sum of all elements of array: 6
Array in reverse order:
3 2 1

##Task 2 – String Operations
String length
Length of string is: 5

String copy
Copied string: Hello

String compare
Matched part: Hel
Unmatched part: lo

Palindrome check
Forward: MONDAY
Reverse: YADNOM
Not palindrome

###Task 3 – Macros and File I/O
Macros
16
4
100
899
F

File I/O with struct student

Program asks for student details:

Enter number of students: 2

Enter data for student 1
Roll no: 1
Name: Ali
GPA: 3.1

Enter data for student 2
Roll no: 2
Name: Sara
GPA: 3.9


Output:

Highest GPA: 3.90 by Sara

Names read from file:
Ali
Sara

###Task 4 – Linked List

Deletes node with value 12:

Linked list after deletion: 15 23 14

###Task 5 – Dynamic Memory Allocation
malloc() usage
Enter number of slots: 3
Enter integers:
10 20 30
Array: 10 20 30
Sum: 60
Average: 20.00

realloc() usage
Enter old size: 2
Enter elements:
1 2
Enter new size: 3
Enter new elements:
4 5 6
Extended array: 4 5 6

Memory free detector
Memory allocated
0x55a7a3c0e260
0x55a7a3c0e264
0x55a7a3c0e268
0x55a7a3c0e26c
0x55a7a3c0e270
Memory freed successfully


(The hex addresses will vary.)


###Project

Project – Booth Multiplier

Performs signed binary multiplication:

Enter bit length: 4
Enter Multiplier (Q): 1 0 1 0
Enter Multiplicand (M): 0 1 1 0
Enter 2's complement of M (~M): 1 0 0 1
Result: 01011100








########### AI USAGE ###############
prefer google for syntax confirmation
use chatgpt for understanding the Booths Algorythm also see youtub vedios on Botths algorithm (working shifting etc )