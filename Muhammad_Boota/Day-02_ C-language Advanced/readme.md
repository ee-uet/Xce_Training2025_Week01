## C Language Advanced Lab – How to Run Each Task

This directory contains `template_code_Day2.c` with multiple advanced C programming tasks. Each task is implemented as a separate function. Follow these steps to run and test each task:

### 1. Select the Task(s) to Run
- Open `template_code_Day2.c` in your editor.
- In the `main` function, **uncomment** the function call(s) for the task(s) you want to run. (Each task is named like `task1_1()`, `task3_2_fileio()`, etc.)
- Comment out or remove other function calls if you only want to run specific tasks.

### 2. Build the Code
- Open a terminal in this directory.
- Run:
	```sh
	make
	```

### 3. Run the Program
- In the terminal, run:
	```sh
	./main
	```
### 4. Task-Specific Instructions
- **User Input Required:**
	- Most tasks in this file use hardcoded values and do **not** require user input.
	- If you uncomment and run the following, you will be prompted for input:
		- None of the provided tasks require user input via `scanf` (all data is set in code).
	- For file I/O tasks, files like `student.txt` will be created or modified in this directory.

### 5. Output
- The output for each task will be printed in the terminal.
- For file I/O tasks, check the generated files for saved data.

---

## Task List (in `template_code_Day2.c`)
1. Pointer basics and arithmetic
2. Swap integers using pointers
3. Pointer arithmetic on arrays
4. Custom string functions (`strlen`, `strcpy`, `strcmp`)
5. Palindrome checker (case-insensitive)
6. Macros (SQUARE, MAX2, MAX3, MAX4, TO_UPPER)
7. Student struct and file I/O
8. Linked list operations (insert, delete, print)
9. Dynamic memory allocation (malloc, realloc)
10. Memory leak detector
11. Booth's multiplication algorithm
![Booth's_multiplication algoritm](/Muhammad_Boota/Day-02_%20C-language%20Advanced/docx/Booth-Multiplier-Algorithm.webp)

---

**Tip:** Only uncomment the function(s) you want to test to avoid running all tasks at once.