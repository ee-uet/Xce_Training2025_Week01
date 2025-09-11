# C Programming Tasks

This project contains multiple small programs written in **C language**, each demonstrating a different concept. Every task is explained with its **problem statement** and **working**.

---

## **Task 0.1 – Data Types and Type Casting**
### Problem Statement
- Print sizes of different C data types (`int`, `float`, `double`, `char`).
- Show type casting between `int` and `char`, and demonstrate integer vs floating-point division.

### Working
- `sizeof()` operator is used to print size of each data type.
- An integer `123` is type-casted to `char` (ASCII = `{`) and concatenated with a string.
- Division `20/3` is shown once without casting (integer division) and once after casting to `float`.

---

## **Task 0.2 – Calculator**
### Problem Statement
- Take two numbers.
- Perform addition, subtraction, multiplication, division, or modulus depending on user’s choice.

### Working
- Two integers are passed as arguments.
- Arithmetic results are pre-calculated.
- A `switch-case` executes the operation chosen by user (`+`, `-`, `*`, `/`, `%`).

---

## **Task 0.3 – Fibonacci Series & Guessing Game**
### Fibonacci Series
#### Problem Statement
- Print Fibonacci numbers up to `n`.

#### Working
- Initialize `f1 = 0` and `f2 = 1`.
- Use a loop to calculate next numbers (`next = f1 + f2`).
- Print series until `n` terms are reached.

### Guessing Game
#### Problem Statement
- Computer picks a random number between 1–100.
- User keeps guessing until correct.

#### Working
- `rand()` generates the random number.
- User guesses repeatedly inside a `while` loop.
- Hints are shown if guess is **too high** or **too low**.
- Loop ends when correct number is guessed.

---

## **Task 0.4 – Prime Numbers & Factorial**
### Prime Numbers
#### Problem Statement
- Check if a number is prime.
- Print all prime numbers between 1–100.

#### Working
- A number is prime if it has no divisors except 1 and itself.
- Loops check divisibility.
- Prints prime numbers between 2 and 100.

### Factorial
#### Problem Statement
- Calculate factorial of a number using recursion.

#### Working
- Base cases: `0! = 1` and `1! = 1`.
- Recursive call: `n * factorial(n-1)`.

---

## **Task 0.5 – String Reversal & Second Largest**
### Reverse String
#### Problem Statement
- Input a string and print it in reverse.

#### Working
- Find string length manually.
- Swap characters from start and end using a temporary variable until middle is reached.

### Second Largest Element
#### Problem Statement
- Find second largest number in an array.

#### Working
- Traverse array and track largest and second largest values.
- Handle special cases like:
  - All numbers equal → no second largest.
  - Array with less than 2 elements.

---

## **Task 0.6 – File I/O**
### Problem Statement
- Input 5 integers.
- Save them in a file.
- Read them back and print.

### Working
- File opened in **write mode** to store integers using `fprintf()`.
- Then file opened in **read mode** to fetch integers using `fscanf()`.
- Handles errors if file cannot be opened.

---

## **Task 0.7 – Bitwise Operations**
### Problem Statement
- Demonstrate bitwise operators: `AND`, `OR`, `XOR`, `NOT`, left shift, right shift.
- Check if a number is a power of 2.

### Working
- Bitwise expressions applied on integers `x=5` and `y=9`.
- Formula `(n > 0) && ((n & (n-1)) == 0)` is used to check power of 2.

---

## **Task 0.8 – Enum Weekday**
### Problem Statement
- Map a number (1–7) to a day of the week using `enum`.

### Working
- Enum values `MON=1` to `SUN=7` are defined.
- User inputs a number.
- Program prints corresponding day or error if input is invalid.

---

## **Task 0.9 – Struct and Distance**
### Problem Statement
- Define a structure for points `(x, y)`.
- Calculate distance between two points.

### Working
- Struct `Point` holds `x` and `y`.
- User inputs two points.
- Euclidean distance is calculated using formula:  
  \[
  d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
  \]

---

## **Task 0.10 – Command-Line Arguments**
### Problem Statement
- Read two integers from command-line arguments.
- Print their sum.

### Working
- `argc` counts arguments, `argv` stores them as strings.
- `atoi()` converts arguments to integers.
- Sum is calculated and printed.

---

## **Main Function**
- Execute all tasks in sequence.
- Calls each task function one by one.

## How to Run
To compile and run this code, following commands were used:
```
gcc code.c -o code -lm
./code
```

## Sources and AI Usage
- Recalled some concepts of `command-line arguments` with the help of `ChatGPT`
- Understood working of `enum` from [here](https://www.geeksforgeeks.org/c/enumeration-enum-c/)
- Had a look over C structures from [here](https://www.w3schools.com/c/c_structs.php)
- Concepts/Syntax of File Handling from [here](https://www.geeksforgeeks.org/c/basics-file-handling-c/)
- Took some help in building logic (for finding second largest element in array) - `ChatGPT`
- Asked AI about the respective libraries/headers of different functions - `ChatGPT`
- Some final refining and optimization with help of AI - `ChatGPT`