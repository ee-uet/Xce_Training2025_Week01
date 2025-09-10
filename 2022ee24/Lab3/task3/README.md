
---

# Shell Scripting Exercises – Part 3

This repository contains solutions for three shell scripting exercises that focus on **functions**, **arrays**, and **associative arrays** in Bash.

---

## Exercise 3.1: Functions (Factorial)

### Problem

* Create a function that calculates the factorial of a number.
* Call the function with different numbers.
* Print the results.

### Approach

* Implemented a **recursive function** `factorial()`.
* Used recursion: `n! = n * (n-1)!`, with base case `0! = 1` and `1! = 1`.
* User enters a number, and the factorial is computed.

### Example

```bash
$ ./t3_1.sh
Enter a number: 5
Factorial of 5: 120
```

### Known Limitations

* Very large numbers (e.g., >20) will overflow since Bash uses 64-bit integers.
* Negative numbers are not handled.

---

## Exercise 3.2: Arrays (Fruits List)

### Problem

* Create an array of fruits.
* Write a function that prints each fruit in the array.
* Add a new fruit and call the function again.

### Approach

* Initialized `FRUITS=("orange" "banana" "apple")`.
* Created a function `print()` to display fruits:

  * Method 1: Loop directly over array elements.
  * Method 2: Loop over array indices.
* Added `"grapes"` to the array dynamically and reprinted.

### Example

```bash
$ ./t3_2.sh
orange
banana
apple

Method2

orange
banana
apple

grapes added later:

orange
banana
apple
grapes
```

### Known Limitations

* Hardcoded fruits initially.
* No user input support for adding fruits dynamically.

---

## Exercise 3.3: Associative Arrays (Country-Capital Lookup)

### Problem

* Create an associative array of country–capital pairs.
* Ask the user for a country and return its capital.
* Implement error handling for unknown countries.

### Approach

* Declared associative array with:

  ```bash
  declare -A asso_array
  ```
* Stored pairs like `asso_array["Pakistan"]="Islamabad"`.
* Wrote function `foo()` to:

  * Prompt user for a country.
  * Check if key exists with `[[ -v asso_array["$name"] ]]`.
  * Print capital or error message with available options.

### Example

```bash
$ ./t3_3.sh
Capital of Pakistan: Islamabad
Capital of Japan: Tokyo
Enter Country name: France
Capital of France: Paris

Enter Country name: Germany
Error: 'Germany' not found in the database!
Available countries: Pakistan Japan France USA
```

### Known Limitations

* Country names are case-sensitive (`pakistan` vs `Pakistan`).
* Database is small and hardcoded.

---

## How to Run

1. Make scripts executable:

   ```bash
   chmod +x t3_1.sh
   chmod +x t3_2.sh
   chmod +x t3_3.sh
   ```
2. Run them:

   ```bash
   ./t3_1.sh
   ./t3_2.sh
   ./t3_3.sh
   ```

---

## What I Verified

* **Exercise 3.1:** Factorial recursion works for numbers up to \~20. Correct output for small numbers.
* **Exercise 3.2:** Arrays print correctly in both loop styles; dynamic append works.
* **Exercise 3.3:** Associative array lookups succeed; error handling triggers for unknown inputs.

---

## Sources & AI Usage

* AI was used assist in bash scripts and to prepare this README file (structure, formatting, and known limitations).
* Verified correctness with small test cases and edge inputs.

---
