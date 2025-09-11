# C Program: Macros & File I/O with Structures

## 📌 Overview
This program demonstrates two major concepts in C:

1. **Macros** – for inline code expansion (mathematical operations and character manipulation).  
2. **File I/O with Structures** – storing, retrieving, and displaying student records.  

---

## ⚙️ Code Structure

### 🔹 Part 1: Macros (`task3_1_macros`)

- **`SQUARE(x)`** → Computes the square of a number.  
- **`MAX2(a, b)`** → Finds the maximum of two numbers.  
- **`MAX3(a, b, c)`** → Finds the maximum of three numbers (using `MAX2`).  
- **`MAX4(a, b, c, d)`** → Finds the maximum of four numbers (using `MAX2`).  
- **`TO_UPPER(c)`** → Converts a character to uppercase (if lowercase).  

### 🔹 Part 2: File I/O with Structures (`task3_2_fileio`)

- Defines a `struct Student` with:
  - `name` (string)
  - `roll` (integer)
  - `gpa` (float)  

- Creates an array of 5 students.  
- Finds the student with the **highest GPA**.  
- Writes student records to a file `students.txt`.  
- Reads back the data from the file.  
- Displays the retrieved student information.  

---

##  Example Output

```sh
Square of 5 is 25
Max of 6 and 3 is 6
Max of 10, 7 and 3 is 10
Max of 1, 2, 3 and 4 is 4
Uppercase of 'b' is B
Uppercase of 'Z' is Z
Student with maximum GPA is X

Reading data back from file:
U 1 3.10
V 2 3.20
X 3 3.50
Y 4 3.40
Z 5 3.30
```

---

## How the Code Works

### Macros
- Replaced at **compile time** (text substitution).
- Example: `SQUARE(5)` expands to `(5 * 5)`.

### File I/O with Structures
1. Writes student data into `students.txt` using `fprintf()`.  
2. Reads it back into the array using `fscanf()`.  
3. Displays it again to verify correctness.  

---

## Generated File

After running the program, the file `students.txt` will contain:

```
U 1 3.10
V 2 3.20
X 3 3.50
Y 4 3.40
Z 5 3.30
```

## How to Compile and Run

### Using GCC
```sh
gcc task3.c -o task3
./task3
```