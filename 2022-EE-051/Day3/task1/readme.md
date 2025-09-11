# Lab 1: Basic Shell Scripting

## Overview
This lab introduces the basics of **shell scripting in Bash**.  
It covers:
1. Printing text to the terminal (`echo`).
2. Reading **user input** and storing it in variables.
3. Handling **command-line arguments** and performing arithmetic operations.

---

## Code Structure
The script `task1.sh` contains three main parts:

1. **Hello World (Exercise 1.1)**  
   Prints a simple "Hello, World!" message.

2. **User Input (Exercise 1.2)**  
   Prompts the user to enter their name, stores it in a variable, and displays a greeting.

3. **Command-line Arguments (Exercise 1.3)**  
   Accepts two numbers as arguments, checks if the inputs are valid, and prints their sum.

---

## How the Code Works

1. **Shebang Line (`#!/bin/bash`)**
   Tells the system to execute the script with the Bash shell.

2. **Exercise 1.1** – Prints `"Hello, World!"` using `echo`.

3. **Exercise 1.2** –

   * Prompts the user to enter their name.
   * Reads input using `read name`.
   * Displays a greeting message with the entered name.

4. **Exercise 1.3** –

   * Checks if exactly **2 arguments** are passed (`$# -ne 2`).
   * If not, shows usage instructions and exits.
   * If valid, calculates the sum with arithmetic expansion `$(())`.
   * Prints the result.

---

## How to Compile and Run

Bash scripts don’t need compilation. You just need to **make them executable**.

1. Save the file as **`task1.sh`**
2. Open terminal in the script’s directory
3. Run the following commands:

```bash
# Give execute permission
chmod +x task1.sh

# Run the script
./task1.sh
```

---

## Example Runs

### Example 1: Hello World & User Input

```bash
$ ./hello.sh
Hello, World!
Enter your name:
Zahra
Hello, Zahra! Welcome to Shell Scripting.
```

### Example 2: Passing Correct Arguments

```bash
$ ./hello.sh 7 5
Hello, World!
Enter your name:
Zahra
Hello, Zahra! Welcome to Shell Scripting.
Sum = 12
```

### Example 3: Missing Arguments

```bash
$ ./hello.sh 10
Hello, World!
Enter your name:
Zahra
Hello, Zahra! Welcome to Shell Scripting.
Usage: ./task1.sh num1 num2
```
## Reference
I am taking an online course on cybersecurity, I learnt bash scripting from there.