# Bash Script – Factorial Calculator

## Introduction
This script calculates the factorial of a given number using a loop inside a function.  

---

## Problem
- Accept a number as a command-line argument.  
- Compute its factorial.  
- Print the result.  

---

## Approach
- `$1` stores the number passed as an argument.  
- A variable `c` is initialized to `1` (factorial base value).  
- A function `factorial` loops from `0` to `num-1`.  
- In each iteration, it multiplies `c` by `(num - i)`.  
- After the loop, the factorial result is stored in `c` and printed.  

---
## Example
./factorial.sh 5

c = 120

$ ./factorial.sh 7

c = 5040


## AI usage 
nope



#  Print Array Elements

## Introduction
This script demonstrates how to use arrays in bash.  
It stores a list of fruits and prints each element using a loop inside a function.  

---

## Problem
- Store multiple string values in an array.  
- Print all array elements using a loop.  

---

## Approach
- Define an array `fruits` with four elements.  
- Use `${#fruits[@]}` to calculate the array length.  
- Define a function `print` that loops from `0` to `len-1`.  
- Inside the loop, print each element using `${fruits[$i]}`.  
- Call the function to display all fruits.  

---
## Example

apple
orange
banana
mango

## AI usage
nope

---

#  Country Capitals 

## Introduction
This script demonstrates the use of **associative arrays** in bash.  
It stores countries as keys and their capitals as values, then allows the user to query the capital by entering a country name.  

---

## Problem
- Store country–capital pairs in a bash associative array.  
- Prompt the user to enter a country.  
- Print the corresponding capital if it exists; otherwise, display an error message.  

---

## Approach
- `declare -A capitals` defines an associative array.  
- Keys: country names (e.g., `Pakistan`, `India`).  
- Values: capitals (e.g., `Islamabad`, `Delhi`).  
- `read -p` prompts the user for a country name.  
- `[[ -v capitals[$country] ]]` checks if the key exists in the array.  
- If it exists → print the capital.  
- If not → print "country does not exist in array".  

---
## Example
enter the country: Pakistan
the capital of Pakistan is islamabad
 
## AI usage
nope
