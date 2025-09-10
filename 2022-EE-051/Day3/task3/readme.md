# Lab 3: Functions and Arrays in Bash

##  Overview
- How to define and use **functions**  
- How to work with **arrays** and update them dynamically  
- How to use **associative arrays (key-value pairs)** for mapping and lookups  

---
# Code Structure

- **Exercise 3.1: Functions** → Script defines a function `factorial()` that calculates the factorial of a number using a for loop, calls it with different inputs (5 and 7), and prints the results.  
- **Exercise 3.2: Arrays** → Script creates an array of fruits, defines a function `fruits()` to print all items, adds a new fruit (`Strawberry`), and prints the updated list.  
- **Exercise 3.3: Associative Arrays** → Script defines an associative array of country-capital pairs, asks the user to enter a country, prints the corresponding capital if found, otherwise displays an error message.  


## How the Code Works

### Exercise 3.1 – Functions

* Defines a function `factorial()` that computes factorial of a given number.
* Uses a **for loop** from 1 to `n` multiplying values.
* Called with different arguments (`5` and `7`).
* Outputs the result.

---

### Exercise 3.2 – Arrays

* Declares a **fruits array** with initial values.
* Defines a function `fruits()` to print each element of the array.
* Prints the array, adds **"Strawberry"** to it, and prints again.

---

### Exercise 3.3 – Associative Arrays

* Declares an **associative array** `capitals` with country-capital pairs.
* Prompts the user to enter a country name.
* If the country exists in the array → prints its capital.
* Otherwise → shows an error message (`"$country not found!"`).

---

## How to Compile and Run

Bash scripts don’t require compilation. Just make the script executable.

1. Save the file as **`task3.sh`**
2. Open terminal in the script’s directory
3. Run the following commands:

```bash
# Give execute permission
chmod +x task3.sh

# Run the script
./task3.sh
```

---

## Example Runs

```bash
$ ./task3.sh
Factorial of 5 is 120
Factorial of 7 is 5040
Apple
Banana
Orange
Mango
After adding fruit:
Apple
Banana
Orange
Mango
Strawberry
Enter a country: Pakistan
Capital of Pakistan is Islamabad
```
## Summary

* Functions in Bash make code reusable.
* Arrays allow you to store and update lists of items.
* Associative arrays enable storing **key-value pairs** and performing lookups.

## Reference
I am taking an online course on cybersecurity, I learnt bash scripting from there.