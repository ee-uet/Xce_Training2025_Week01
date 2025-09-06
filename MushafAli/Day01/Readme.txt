Lab 01 – C Programming Fundamentals  

This project contains the solutions to **Lab 01** tasks for practicing the fundamentals of the C programming language.  
The lab covers essential concepts such as data types, arithmetic operations, loops, conditionals, recursion, file handling, bitwise operations, enumerations, and structures.  

---

##  Problem Statement  

The purpose of this lab is to strengthen understanding of **basic programming constructs in C**.  
The tasks gradually build from simple operations (data types, arithmetic) to more advanced concepts like recursion, file I/O, and structures.  

By completing these tasks, I practise practices:  

- Declaring and using variables of different data types  
- Performing arithmetic operations and handling user input  
- Implementing loops and conditionals  
- Generating sequences and games using random numbers  
- Understanding recursion with factorial  
- Manipulating strings and arrays  
- Writing to and reading from files  
- Applying bitwise operations  
- Using enumerations for better code readability  
- Working with structures to represent complex data  

---

##  Task List  

| Task | Description |
|------|-------------|
| **Task 01** | Data types and their memory sizes |
| **Task 02** | Arithmetic operations and calculator using `switch` |
| **Task 03.1** | Fibonacci sequence generation |
| **Task 03.2** | Number guessing game |
| **Task 04.1** | Prime number check |
| **Task 04.2** | Printing all prime numbers up to 100 |
| **Task 04.3** | Factorial calculation using recursion |
| **Task 05.1** | String reversal |
| **Task 05.2** | Find second highest element in an array |
| **Task 06** | File handling: write and read numbers |
| **Task 07.1** | Bitwise operations (AND, OR, XOR, shifts) |
| **Task 07.2** | Check if a number is a power of 2 |
| **Task 08** | Enumeration of weekdays |
| **Task 09.1** | Distance between two points using structures |
| **Task 09.2** | Power of 2 check using structures |

---

##  Approach  

- Each task is written as a separate function and calling each task in  `main.c`.  
- The `main()` function sequentially calls all task functions to demonstrate their outputs.  
- Important concepts covered:  
  - **Recursion** → Factorial calculation  
  - **Loops** → Fibonacci, prime numbers  
  - **Switch-case** → Arithmetic calculator, enumeration  
  - **File I/O** → Writing and reading integers  
  - **Bitwise operations** → Efficient mathematical checks  
  - **Structures** → Distance calculation, number check  
  - **Enumerations** → Mapping integers to days of the week  

---

##  How to Compile and Run  

1. Make sure you have **GCC** installed.  
2. Open a terminal in the project directory.  
3. Compile the program:  

   ```bash
   gcc main.c -o lab1 -lm





## Example Outputs



###Task 01: Data Types and Sizes

size of int is 4
size of float is 4
size of double is 8
size of char is 1


###Task 02 – Arithmetic Operations

Enter 1st positive number: 10
Enter 2nd positive number: 3
sum=13 sub=7 mul=30 div=3.33 mod=1

###Task 03.1 – Fibonacci Sequence

Enter a number: 7
0 1 1 2 3 5 8

###Task 03.2 – Guessing Game

Guess a number between 1 to 100: 42
YOU FAIL! Your guess is less than the random number (87)

###Task 04 – Prime and Factorial
Enter a number: 17
Yes, it's a prime number

Prime numbers up to 100:
2 3 5 7 11 ... 97

Factorial of 5 is: 120


###Task 05 – Strings and Arrays

Reverse of "Hello" is: olleH
Second highest is 4


###Task 06 – File Handling

1 2 3 4 5 6 7 8 9 10

###Task 07 – Bitwise Operations

Enter x: 5
Enter y: 2
AND = 0
OR = 7
XOR = 7
Shift Left = 20
Shift Right = 1

Enter a number: 16
Yes, 16 is the power of 2

###Task 08 – Enumeration (Days of Week)

Enter a number (1-7): 3
WEDNESDAY

###Task 09 – Structures

Enter values of x1 y1 x2 y2: 0 0 3 4
Distance = 5.00
Enter a number: 32
Yes, 32 is power of 2





## Key Learnings
- Learned how to use data types and memory sizes
- Practiced recursion and iterative methods
- Worked with file input/output in C
- Applied bitwise operations for efficient checks
- Improved understanding of structures and enums








########### AI USAGE ###############
prefer google for syntax confirmation
use chatgpt for checking which function used to generate the random numbers etc






















