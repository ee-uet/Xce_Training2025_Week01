# Task 3.2 — File I/O with Structs

## Problem
Write a program that:
- Defines a struct `Student { char name[50]; int roll; float gpa; }`.
- Stores details of 5 students in an array.
- Prints the student with the highest GPA.
- Saves all students to a text file (`students_record.txt`).
- Reads them back from the file and prints.

## Approach
- Use a struct to hold student information.
- Store 5 students in a static array.
- Iterate to find the student with the highest GPA.
- Write all student details to a text file using `fprintf()`.
- Reopen the file in read mode, read each student using `fscanf()`, and print details.

## How to Run
1. **Compile the program:**
   ```bash
   gcc task3_2.c -o out
2. **Run the executable:**
    ./out

## Test Cases
1. Highest GPA student
Input: Predefined student list.
Expected: Student with roll 12 (Abdullah) having GPA 3.90 printed as the highest.
2. File save + read
Expected: All 5 students written to students_record.txt.
Expected: Reading the file prints all students in the same format.

## Example Output
Student with highest GPA:
Name: Abdullah, Roll: 12, GPA: 3.90

Reading students from file:
Name: Ali, Roll no: 15, GPA: 3.39
Name: Abdullah, Roll no: 12, GPA: 3.90
Name: Bilal, Roll no: 21, GPA: 3.75
Name: Abdullah, Roll no: 7, GPA: 3.85
Name: Hamza, Roll no: 10, GPA: 3.60

## Known Limitations
1. Student data is hardcoded, no user input support.
2. No validation for duplicate names/roll numbers.



