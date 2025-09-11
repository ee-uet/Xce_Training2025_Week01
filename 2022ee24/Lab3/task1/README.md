
---

# Shell Scripting Exercises

This repository contains solutions for three introductory shell scripting exercises:

* **Exercise 1.1** → Hello World
* **Exercise 1.2** → Variables and User Input
* **Exercise 1.3** → Command-line Arguments

---

## Exercise 1.1: Hello World

### Problem

Create a shell script that prints `"Hello, World!"`.

### Approach

* Add the shebang line (`#!/bin/bash`).
* Use the `echo` command to print the message.

### Example

```bash
Hello, World!
```


---

## Exercise 1.2: Variables and User Input

### Problem

Create a script that asks the user for their name, stores it in a variable, and prints a greeting.

### Approach

* Use `read -p` to prompt the user.
* Store the input in a variable (`NAME`).
* Print the greeting using `echo`.

### Example

```bash
Enter your name: Alice
HELLO Alice
```

### Known Limitations

* No input validation — empty input will print `HELLO ` with no name.
* Greeting format is fixed.

---

## Exercise 1.3: Command-line Arguments

### Problem

Create a script that accepts **two numbers** as command-line arguments and prints their sum.

### Approach

* Use `$#` to check number of arguments.
* If exactly 2 arguments are given, calculate sum using `$((...))`.
* Print error messages for:

  * **0 arguments** → "No input arguments".
  * **More than 2 arguments** → "Error! Only 2 arguments allowed".

### Examples

```bash
$ ./exercise1_3.sh 5 7
12

$ ./exercise1_3.sh
No input arguments

$ ./exercise1_3.sh 1 2 3
Error! Only 2 arguments allowed
```

### Known Limitations

* Only supports integer inputs.
* Non-numeric arguments may result in unexpected behavior.

---

## How to Run

1. Make a script executable:

   ```bash
   chmod +x hello.sh
   chmod +x inputname.sh
   chmod +x t1_3.sh
   ```
2. Run the scripts:

   ```bash
   ./hello.sh
   ./inputname.sh
   ./t1_3.sh 5 7
   ```

---

## What I Verified

* Correct output for valid and invalid cases.
* Negative numbers (`./t1_3.sh -5 10`) are handled correctly.
* Verified edge cases:

  * No arguments.
  * More than 2 arguments.
  * Empty input for Exercise 1.2.

---

## Sources & AI Usage

* AI assistance (ChatGPT) was used for:

  * Structuring and formatting the `README.md`.


---
