## C Lab Tasks: How to Run Each Task

This directory contains a C file (`template_code_Part0.c`) with multiple lab tasks. Each task is implemented as a separate function. You can run and test each task by following these steps:

### 1. Select the Task(s) to Run
- Open `template_code_Part0.c` in your editor.
- In the `main` function, **uncomment** the function call(s) for the task(s) you want to run. (Each task is named like `task01_datatypes()`, `task02_calculator()`, etc.)
- Comment out or remove other function calls if you only want to run specific tasks.

### 2. Build the Code
- Open a terminal in this directory.
- Run:
	```
	make
	```
	This will compile the code and create an executable.

### 3. Run the Program
- In the terminal, run:
	```
	./main
	```

### 4. Task-Specific Instructions
- Some tasks require user input (e.g., calculator, guessing game, Fibonacci, etc.). Follow the prompts in the terminal.
- For the command-line arguments task (`task10_cmd_args`), run the program with two integer arguments:
	```
	./main.exe 5 7
	```
	This will print the sum of 5 and 7.

### 5. Output
- The output for each task will be printed in the terminal.
- For file I/O tasks, files like `integerfile.txt` will be created or modified in this directory.

---

## Task List (in `template_code_Part0.c`)
1. Data types and type casting
2. Simple calculator
3. Fibonacci sequence
4. Guessing game
5. Prime numbers
6. Factorial (recursion)
7. Reverse string
8. Second largest in array
9. File I/O
10. Bitwise operations
11. Enum weekday mapping
12. Struct distance calculation
13. Command-line arguments

---

**Tip:** Only uncomment the function(s) you want to test to avoid running all tasks at once.