# Lab 3: Functions and Arrays  

# Exercise 3.1: Functions  
This Bash script defines a **function** that calculates the **factorial** of a given number and prints the result.  

---

## Approach
- Define a function `factorial()` that takes a number as input.  
- Initialize factorial result as `1`.  
- Use a `for` loop from 2 up to the input number to multiply sequentially.  
- Print the factorial result.  
- Call the function with different numbers (e.g., 1, 4, 5).  

---

## How to Run
1. Save the script as `exer3.1.sh`.  
2. Give it execute permission and run:  
   ```bash
   chmod +x exer3.1.sh
   ./exer3.1.sh
   ```
## Commands Used

- `function_name()` : defines a function.
- `for (( ... ))` : C-style for loop in Bash.
- `$((expression))` : arithmetic expansion in Bash.

## Sources and AI usage

- AI explained how to implement factorial using loops in Bash.
- Learnt function definition and calling in Bash.

---
# Exercise 3.2: Arrays

This Bash script demonstrates array operations: creating, printing, and updating arrays.

## Approach

- Define an array of fruits.
- Use array length ${#arr[@]} to determine size.
- Loop through indices and print each element.
- Append new fruits to the array using +=.
- Print the updated array.

## How to Run

- Save the script as exer3.2.sh.
- Give it execute permission and run:
```bash
chmod +x exer3.2.sh
./exer3.2.sh
```
## Commands Used

- `arr=("a" "b" "c")` : initializes an array.
- `${arr[i]}` : access element at index i.
- `${#arr[@]}` : get size of array.
- `arr+=("new")` : append element to array.

---
# Exercise 3.3: Associative Arrays
This Bash script uses an associative array of country-capital pairs and implements a lookup function.

## Approach

- Declare an associative array with `declare -A`.
- Store countries as keys and capitals as values.
- Write a function `capital()` that:
- Prompts the user for a country name.
- Looks up the capital in the associative array.
- If found, prints the capital; otherwise, shows an error message.

## How to Run

- Save the script as exer3.3.sh.
- Give it execute permission and run:
```bash
chmod +x exer3.3.sh
./exer3.3.sh
```

## Commands Used

- `array[key]=value` : assign value to a key.
- `${array[$key]}` : retrieve value by key.
- `[[ -n ${array[$key]} ]]` : check if key exists (non-empty).

## Sources and AI usage

- AI explained associative arrays in Bash.
- Learnt how to prompt users and handle missing keys.
- Learnt appending and iterating arrays.
- AI explained how to implement factorial using loops in Bash.
- Learnt function definition and calling in Bash.