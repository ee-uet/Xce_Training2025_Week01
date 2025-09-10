# Lab 2: Control Structures in Bash

## Overview
This lab focuses on using **control structures** in Bash scripts:
- **If-Else statements** for decision making  
- **For loops** for iteration  
- **While loops** for repetition until a condition is met  

---
# Code Structure

- **Exercise 3.1: Functions** → Script defines a function `factorial()` that calculates the factorial of a number using a for loop, calls it with different inputs (5 and 7), and prints the results.  
- **Exercise 3.2: Arrays** → Script creates an array of fruits, defines a function `fruits()` to print all items, adds a new fruit (`Strawberry`), and prints the updated list.  
- **Exercise 3.3: Associative Arrays** → Script defines an associative array of country-capital pairs, asks the user to enter a country, prints the corresponding capital if found, otherwise displays an error message.  


## How the Code Works

### Exercise 2.1 – If-Else Statement

* Prompts the user for a number.
* Uses modulo (`%`) to check divisibility by 2.
* If remainder is 0 → prints **Even**. Otherwise → prints **Odd**.

---

### Exercise 2.2 – For Loop

* Prompts the user for a number.
* Loops from **1 to 10** using `{1..10}`.
* Multiplies the number by the loop counter.
* Prints the first **10 multiples** of the entered number.

---

### Exercise 2.3 – While Loop (Guessing Game)

* Generates a random number between **0 and 10** using `$RANDOM % 11`.
* Keeps asking the user to **guess the number**.
* Gives hints (**Higher / Lower**) until the correct number is guessed.
* Ends when the guess matches the random number.

---

## How to Compile and Run

Bash scripts don’t require compilation. Just make the script executable.

1. Save the file as **`task2.sh`**
2. Open terminal in the script’s directory
3. Run the following commands:

```bash
# Give execute permission
chmod +x task2.sh

# Run the script
./task2.sh
```

---

## Example Runs

```bash
$ ./task1.sh
Enter a number to check whether its odd or even: 8
8 is Even
Enter a number to find its 1st 10 multiples: 7
7
14
21
28
35
42
49
56
63
70
Guess a number between 1 and 10 : 3
Give a Higher Number
Guess a number between 1 and 10 : 9
Give a Lower Number
Guess a number between 1 and 10 : 7
Correct
```

---

## Summary

* **If-Else** is used for decision-making.
* **For Loop** generates a sequence of repeated actions.
* **While Loop** continues until the condition is satisfied.

## Reference
I am taking an online course on cybersecurity, I learnt bash scripting from there.