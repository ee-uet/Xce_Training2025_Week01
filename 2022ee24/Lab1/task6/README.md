
---

# C Program: File I/O with Integers (Task 6)

## Problem

This program demonstrates basic file input and output operations in C. It:

1. Prompts the user to enter 5 integers.
2. Writes these integers to a file named `numbers.txt`.
3. Reads the integers back from the file.
4. Prints the integers to the console.

## Approach

1. Open a file in **write mode** (`"w"`) using `fopen()`.
2. Take 5 integers from the user and write them to the file using `fprintf()`.
3. Close the file.
4. Reopen the file in **read mode** (`"r"`) using `fopen()`.
5. Read the integers from the file using `fscanf()` and print them.
6. Close the file.

### Key Concepts Used

* **File Handling**: Using `fopen()`, `fprintf()`, `fscanf()`, and `fclose()`.
* **Loops**: For reading and writing multiple integers.
* **Error Handling**: Checking if the file was opened successfully.

## How to Run

To run this program:

1. Copy the code into a file named `task6.c`.

2. Compile the C program using the following command:

   ```bash
   gcc -o task6 task6.c
   ```

3. Run the compiled executable:

   ```bash
   ./task6
   ```

4. The program will create a file named `numbers.txt` in the same directory.

## Examples

### Example Run

```
Enter number0: 12
Enter number1: 45
Enter number2: 78
Enter number3: 23
Enter number4: 56
12
45
78
23
56
```

### Example `numbers.txt` contents

```
12
45
78
23
56
```

## Known Limitations

* The number of integers is fixed at **5**.
* The filename is hardcoded as `numbers.txt`.
* If the program cannot open the file, it only prints an error message but continues execution.
* No validation for user input (non-integer values may cause undefined behavior).

## What I Verified


  * Verified correct handling when valid integers are provided.
  * Verified that numbers are written line by line to the file.

* **Constraints**:

  * Relies on a valid filesystem and write permissions in the current directory.

## Sources & AI Usage

The program was written from scratch for practice. AI assistance was used to structure this `README.md` and analyze possible edge cases and limitations.

---
