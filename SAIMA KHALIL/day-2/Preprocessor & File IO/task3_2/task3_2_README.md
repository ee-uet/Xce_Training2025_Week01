## Student File I/O  
This program demonstrates **file operations** using structs.

---

### Code Explanation

#### Struct
- `struct Student` has:
  - `char name[50]` : student name  
  - `int roll` : roll number  
  - `float gpa` : GPA  

#### Writing to File
1. Open file `students.txt` in write mode (`"w"`).  
2. Take input for 5 students: `name`, `roll`, `GPA`.  
3. Write student data to the file using `fprintf`.  
4. Close the file after writing.

#### Finding Top Student
- Iterate through the `students` array.  
- Then keep track of the student with the **highest GPA**.

#### Reading from File
1. Open file `students.txt` in read mode (`"r"`).  
2. Read all student data using `fscanf`.  
3. Print each student's information.  
4. Close the file after reading.

---

### Example Run
Enter name, roll num and GPA for student 1: Saima 1 3.5
Enter name, roll num and GPA for student 2: Ali 10 3.8
Enter name, roll num and GPA for student 3: Laiba 13 3.2
Enter name, roll num and GPA for student 4: Muntaha 14 3.9
Enter name, roll num and GPA for student 5: Abdullah 15 3.6
Student with highest Gpa: Muntaha (Roll: 104, Gpa: 3.90)
Students read from file:
Name: Saima, RollNum: 1, Gpa: 3.50
Name: Ali, RollNum: 10, Gpa: 3.80
Name: Laiba, RollNum: 13, Gpa: 3.20
Name: Muntaha, RollNum: 14, Gpa: 3.90
Name: Abdullah, RollNum: 15, Gpa: 3.60

---

### Run

```bash
gcc task3_2.c -o task3_2
./task3_2
```