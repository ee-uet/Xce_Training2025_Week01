# Task 3.2 – File I/O with Structures

## Problem
Write a C program that:
1. Stores details of 5 students (name, roll, GPA) in an array of structures.
2. Finds and prints the student with the **highest GPA**.
3. Saves all student records to a file (`Students.txt`).
4. Reads the records back from the file and prints them.

---

## Approach
- Defined a `struct Student` with fields:
  - `char name[50]`
  - `int roll`
  - `float gpa`
- Created an array of 5 students with sample data.
- Used a loop to find the student with the **highest GPA**.
- Used **file I/O**:
  - `fprintf` to write student data into `Students.txt`.
  - `fscanf` to read data back and display it.

---

## How to Run
1. Save the code in a file, `task3_2.c`.
2. Compile:
   ```bash
   gcc task3_2.c -o task3_2
    ./task3_2

## Example Output
Student with highest gpa:
Name = AhsanMalik ,Roll = 17 ,gpa = 3.99
Data saved to Students.txt

Reading back from file:
Name = AliKhan, Roll = 14, GPA = 3.20
Name = SaraAhmed, Roll = 15, GPA = 3.90
Name = BilalRaza, Roll = 16, GPA = 3.50
Name = AhsanMalik, Roll = 17, GPA = 3.99
Name = HinaNoor, Roll = 18, GPA = 3.70

## File Created

The program generates a file called Students.txt with the following content:

AliKhan 14 3.20
SaraAhmed 15 3.90
BilalRaza 16 3.50
AhsanMalik 17 3.99
HinaNoor 18 3.70

## Known Limitations
fscanf is used in a loop to read until end of file (EOF).

The file is overwritten each run (because "w" mode is used).
To append, use "a" instead of "w".