#  Even or Odd Checker

## Introduction
This script checks whether a given number (age) is **even** or **odd** using bash arithmetic expressions.  

---

## Problem
- Accept a number as a command-line argument.  
- Determine if it is even or odd.  
- Print the result.  

---

## Approach
- `$1` stores the first argument passed to the script.  
- Arithmetic expansion with `(( ))` allows modulo (`%`) operation.  
- If `age % 2 == 0`, the number is even; otherwise, it is odd.  

---
## Example
 ./evenodd.sh 10
even

 ./evenodd.sh 7
odd

## AI usage
nope

---

#  Multiplication Table Generator

## Introduction
This script generates the multiplication table of a number provided as a command-line argument.  

---

## Problem
- Accept a number as input.  
- Print its multiplication table from 1 to 10.  

---

## Approach
- `$1` stores the first argument passed to the script.  
- A `for` loop runs from 1 to 10.  
- Inside the loop, arithmetic expansion `$(( ))` computes the product.  
- The result is printed in the format `num * i = product`.  

---
## Example

$ ./table.sh 5

5 * 1 = 5

5 * 2 = 10

5 * 3 = 15

5 * 4 = 20

5 * 5 = 25


5 * 6 = 30

5 * 7 = 35

5 * 8 = 40

5 * 9 = 45

5 * 10 = 50

---
 ## AI usage
 nope.

 #  Number Guessing Game

## Introduction
This script implements a simple number guessing game.  
The program generates a random number between 1 and 10, and the user keeps guessing until the correct number is entered.  

---

## Problem
- Generate a random number between 1 and 10.  
- Prompt the user repeatedly to guess the number.  
- Print whether the guess is too low, too high, or correct.  
- Stop the game once the correct guess is entered.  

---

## Approach
- `$RANDOM` is a built-in bash variable that generates a random integer.  
- `% 10 + 1` ensures the value is between 1 and 10.  
- `while true` creates an infinite loop until the correct guess is made.  
- `read -p` takes user input.  
- `if-elif-else` checks:  
  - If guess < random → print `low`.  
  - If guess > random → print `high`.  
  - If equal → print `equal` and break loop.  

---
## Example
enter a num: 3
low
enter a num: 8
high
enter a num: 5
equal

---
## AI usage
nope.

---



