
---

# Shell Scripting Exercises – task 2

This repository contains solutions for three shell scripting exercises that practice control flow constructs (`if-else`, `for`, and `while` loops).

---

## Exercise 2.1: If-Else Statement

### Problem

Write a script that checks if a number (provided as an argument) is even or odd.

### Approach

* Use `$1` to read the argument.
* Apply modulo operation (`num % 2`).
* Use an `if-else` statement to print `even` or `odd`.

### Example

```bash
$ ./t2_1.sh 8
8 is even

$ ./t2_1.sh 7
7 is odd
```

### Known Limitations

* Only supports integer input.
* If no argument is passed, script will fail with an error.

---

## Exercise 2.2: For Loop

### Problem

Create a script that prints the first **10 multiples** of a number (provided as an argument).

### Approach

* Read `$1` as input.
* Use a `for` loop (`for ((i=1; i<=10; i++))`).
* Multiply and print results.

### Example

```bash
$ ./t2_2.sh 3
3
6
9
12
15
18
21
24
27
30
```

### Known Limitations

* No error handling if the user forgets to provide a number.

---

## Exercise 2.3: While Loop (Guessing Game)

### Problem

Write a guessing game where the program generates a random number and the user keeps guessing until correct.

### Approach

* Generate a random number with:

  ```bash
  NUM=$((RANDOM % 100 + 1))
  ```
* Use a `while` loop to continue until the guess matches.
* Provide **higher/lower hints** after each attempt.
* Count number of attempts.

### Example

```bash
$ ./t2_3.sh
(Re)Enter guess: 50
higher!
(Re)Enter guess: 75
lower
(Re)Enter guess: 63
You took 3 attempts to guess
```

### Known Limitations

* Number is between **1 and 100** (not 1–10 as originally specified).
* No input validation — entering non-numeric values may break the script.

---

## How to Run

1. Make scripts executable:

   ```bash
   chmod +x t2_1.sh
   chmod +x t2_2.sh
   chmod +x t2_3.sh
   ```
2. Run them:

   ```bash
   ./t2_1.sh 7
   ./t2_2.sh 4
   ./t2_3.sh
   ```

---

## What I Verified

* Exercise 2.1 correctly identifies even and odd numbers.
* Exercise 2.2 prints exactly 10 multiples.
* Exercise 2.3:

  * Random number generation works.
  * Loop terminates when guessed correctly.
  * Attempt count is displayed.
---

## Sources & AI Usage

* AI (ChatGPT) was used to create `README.md` structure and formatting, and to highlight known limitations.

---
