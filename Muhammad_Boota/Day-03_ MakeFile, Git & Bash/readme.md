# Day-03: Makefile, Git & Bash – Lab Guide

This directory contains multiple labs for Bash scripting, Makefile usage, and C programming. Each lab is organized in its own folder. Follow the instructions below to run and test each task.

---

## Folder Structure

- `lab1/` – Basic Bash scripts (arguments, hello, username)
- `lab2/` – Bash control flow (for loop, if-else, while loop)
- `lab3/` – Bash arrays and functions
- `lab4/` – Bash scripts for backup, counting, logging
- `lab5/` – C projects with Makefiles (multiple sub-labs)

---

## How to Run Bash Scripts

1. **Navigate to the desired lab folder**
	- Example: `cd lab1`
2. **Give execute permission to the script**
	- Run:
	  ```sh
	  chmod +x scriptname.sh
	  ```
	  Replace `scriptname.sh` with the actual file name (e.g., `hello.sh`).
3. **Run the script**
	- Run:
	  ```sh
	  ./scriptname.sh
	  ```
	- Some scripts may require arguments. Example:
	  ```sh
	  ./arguments.sh arg1 arg2
	  ```

---

## Bash Labs Overview

### lab1
- `arguments.sh` – Demonstrates passing arguments to a script.
- `hello.sh` – Prints a hello message.
- `username.sh` – Prints the current username.

### lab2
- `for_loop.sh` – Example of a for loop in Bash.
- `if_else.sh` – Demonstrates if-else logic.
- `while_loop.sh` – Example of a while loop.

### lab3
- `array.sh`, `arrays.sh` – Demonstrates array usage in Bash.
- `functions.sh` – Shows how to define and use functions.

### lab4
- `backup.sh` – Script for backing up files.
- `count.sh` – Counts lines, words, etc.
- `log.sh` – Writes logs to `log.txt`.

---

## How to Run C Projects (lab5)

1. **Navigate to the desired subfolder**
	- Example: `cd lab5/lab1`
2. **Build the project using Makefile**
	- Run:
	  ```sh
	  make
	  ```
	- This will compile the C code and create an executable (usually named `main.exe` on Windows).
3. **Run the executable**
	- Run:
	  ```sh
	  ./main
	  ```


---

## Notes

- Always use `chmod +x` to give execute permission to Bash scripts before running them.
- For scripts that require arguments, check the script for usage instructions or run with sample arguments.
- For C projects, ensure you are in the correct subfolder before running `make`.
- Output and any generated files (e.g., logs, backups) will be created in the respective lab folders.

---

**Tip:** Explore each script and C project to understand its functionality. You can modify and rerun them to experiment further.