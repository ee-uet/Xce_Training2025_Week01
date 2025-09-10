


---

## Task 1 – Data Types and Type Casting

### Introduction
This task demonstrates how different data types (`int`, `float`, `double`, `char`) are declared, printed, typecasted, and measured in size.

### Problem
- Declare variables of different data types.  
- Print their values.  
- Show explicit typecasting.  
- Print memory size of each data type.  

### Approach
- Define variables: `int a`, `float b`, `char i`, `double d`.  
- Use `printf` with correct format specifiers.  
- Perform typecasting (e.g., `(int)i`, `(float)a`).  
- Use `sizeof()` operator to determine size in bytes.  

### Example Output
character b
integer 10
double 23.440000
float 7.660000
character to int 98
integer to float 10.000000
double to integer 23
float to char g
character size = 1 bytes
integer size = 4 bytes
double size = 8 bytes
float size = 4 bytes


### AI Usage
- nope.

---

## Task 2 – Simple Calculator

### Introduction
This task demonstrates arithmetic operations and the use of a `switch` statement to select an operation.

### Problem
- Perform addition, subtraction, multiplication, division, and modulo.  
- Implement a calculator that executes operations based on a character input.  

### Approach
- Declare `int a=10, b=20`.  
- Print direct arithmetic results.  
- Use a `switch` block with cases `'a'`, `'s'`, `'m'`, `'d'`, `'r'`.  

### Example Output
a = 10 ; b = 20
add 30
sub -10
mult 200
quotient 0
remainder 10
addition 30


### AI Usage
- nope.
---

## Task 3 – Fibonacci and Guessing Game

### Fibonacci Sequence

#### Problem
Generate the Fibonacci series up to `n` terms.  

#### Approach
- Input `num` using `scanf`.  
- Start with `a=0`, `b=1`.  
- Iterate `num` times and print sequence.  

#### Example Output
1 1 2 3 5 8


#### AI Usage
- nope.

---

### Guessing Game

#### Problem
Guess a random number between 1 and 100 until correct.  

#### Approach
- Generate `random_number = rand() % (100-1) + 1`.  
- Loop until user input equals random number.  
- Print hints ("too high"/"too low").  

#### Example Output
Input: 50
Output: too high
Input: 20
Output: too low
Input: 35
Output: correct number



#### AI Usage
- used AI to search how to generate random number in a certain range. 

---

## Task 0.4 – Prime Numbers and Factorial

### Prime Numbers

#### Problem
Print all prime numbers between 2 and 100.  

#### Approach
- For each `n` from 2 to 100, check divisibility.  
- If not divisible, print `n`.  

#### Example Output
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97


#### AI Usage
- nope.  

---

### Factorial (Recursive)

#### Problem
Compute factorial of `n`.  

#### Approach
- If `n==0` or `1`, return 1.  
- Else return `n * factorial(n-1)`.  

#### Example Output
if n =5
than result is 120.


#### AI Usage
- nope.
---

## Task 5 – String Reverse and Second Largest Element

### Reverse String

#### Problem
Reverse the string .  

#### Approach
- Calculate length of string.   
-calculate length than using for loop print bakwards while decrementing length.

#### Example Output
input apple
result elppa


#### AI Usage
- nope 

---

### Second Largest Element

#### Problem
Find the second largest element in an array.  

#### Approach
- Traverse array, track largest and second largest. 
- if a number larger than current element is found make current second large and that number largest.


#### Example Output
input {1,2,3,4,5}
output 4

#### AI Usage
- used Ai to verify logic.



 

---

## Task 0.6 – File I/O

### Introduction
This task demonstrates reading and writing integers from and to a text file using C file I/O functions.

### Problem
- Ask the user for 5 integers.  
- Write them to a file.  
- Read them back and print to the console.  

### Approach
- Use `scanf` to read 5 integers into an array.  
- Open a file in write mode (`fopen("numbers.txt","w")`) and store the integers using `fprintf`.  
- Close and reopen the file in read mode.  
- Use `fscanf` inside a loop to read the integers back and print them.  

### Example Input/Output
Input:
Enter 5 integers:
10 20 30 40 50

Output:
Numbers written to file successfully!
Numbers read from file:
10
20
30
40
50


### AI Usage
- Used AI for syntax.
---

## Task 0.7 – Bitwise Operations

### Introduction
This task demonstrates basic bitwise operations (`&`, `|`, `^`, `~`, `<<`, `>>`) and checks whether a number is a power of 2.

### Problem
- Perform bitwise operations on integers `x=4` and `y=9`.  
- Check if `n=4` is a power of 2.  

### Approach
- Use bitwise operators directly in `printf`.  
- For power of 2 check: `(n & (n-1)) == 0`.  

### Example Output
0
13
13
-10
4
8
it is a power of 2

### AI Usage
-nope.
---

## Task 0.8 – Enum Weekday

### Introduction
This task uses an `enum` to represent days of the week and prints the corresponding day name based on user input.

### Problem
- Input a number between 0 and 6.  
- Print the corresponding weekday using an enum and `switch`.  

### Approach
- Define `enum weekday {monday, tuesday, ..., sunday}`.  
- Read input with `scanf`.  
- Use `switch(day)` to print the correct weekday string.  

### Example Input/Output
Input:
2
Output:
Day is Wednesday


### AI Usage
- nope.  

---

## Task 0.9 – Structure and Distance Calculation

### Introduction
This task demonstrates using a `struct` to represent 2D points and calculating Euclidean distance.

### Problem
- Define a `struct Point` with members `x` and `y`.  
- Compute distance between `p1(0,0)` and `p2(3,4)`.  

### Approach
- Use formula `sqrt((x2-x1)^2 + (y2-y1)^2)`.  
- Print the result with `printf`.  

### Example Output
output = 5

### AI Usage
- nope.  

---

## Task 0.10 – Command-Line Arguments

### Introduction
This task shows how to pass arguments from the command line and process them inside `main`.

### Problem
- Accept two integers as command-line arguments.  
- Print their sum.  

### Approach
- Use `argv[1]` and `argv[2]`, convert them with `atoi`.  
- Add the numbers and print the result.  

### Example Run

./a.out 12 8

20

### AI Usage
- used Ai for syntax.  

---


