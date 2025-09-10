

# Print Hello, World

### Introduction
A basic script that prints `"Hello, World"` to the terminal.

### Problem
Write a bash script to display `"Hello, World"`.

### Approach
- Use `echo` to print text.



#  Read and Print Name

## Introduction
This script asks the user for their name and then greets them.  
It demonstrates basic input/output in bash using `read` and `echo`.

---

## Problem
- Prompt the user to enter their name.  
- Print back the name and a friendly greeting.  

---

## Approach
- Use `read -p` to capture input from the user.  
- Store the value in a variable (`name`).  
- Use `echo` to print the responses.  

##  Example
Input:
enter your name Hamna

Output:
your name is Hamna
hey! there Hamna


---
## AI usage:
- used Ai to learn about different options in read.

# Sum of Two Numbers

## Introduction
This script demonstrates the use of **command-line arguments** in bash by adding two numbers provided by the user.  

---

## Problem
- Accept two numbers as input arguments.  
- Compute their sum.  
- Print the result.  

---

## Approach
- `$1` stores the first argument, `$2` stores the second argument.  
- Arithmetic expansion `$(( ))` is used to add them.  
- Print the sum using `echo`.  

---
## Example
 ./sum.sh 5 7

SUM=12

--

## AI usage:
nope.




