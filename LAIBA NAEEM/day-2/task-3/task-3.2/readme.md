# Problem
Write a program that:
- Define a struct Student { char name[50]; int roll; float gpa; };
-	Store details of 5 students in an array.
-	Print the student with the highest GPA.
-	Saves them to a text file (students.txt).
-	Reads them back and prints.

#
**Approach**

- Create a Student struct with name, roll, and GPA fields to store student information.

- Input data for 5 students.

- Find the student with the highest GPA by comparing each student’s GPA in a loop.

- Write student data to a file "students.txt" using fprintf().

- Read the file back using fscanf() to verify the content and print all student details.
#
**How to run**

- Save the code in a file, for example: code.c
- Open a terminal and compile the program using GCC:    
  gcc code.c -o code
- Run the program:
    ./code
#
**Example**    
struct Student s1[5] = {{"A",7,3.4},
                         {"B",2,3.5},
                         {"C",4,3.1},
                         {"D",6,3.7},
                         {"E",9,1.9}};   
student wit highest gpa is D  
done   
Reading back from file  
A 7 3.400000  
B 2 3.500000  
C 4 3.100000  
D 6 3.700000  
E 9 1.900000                   
#
**Resources and References**    
Used Google to understand basic struct syntax and how to store multiple student records in C.
