#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    struct Student students[5];

    //Writing to File
    FILE *file = fopen("students.txt", "w");
    for (int i = 0; i < 5; i++) {
        printf("Enter name, roll num and GPA for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].roll, &students[i].gpa);
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(file); // Close file after writing
   
    struct Student top_student = students[0];  // Finding  student with highest GPA
    for (int i = 1; i < 5; i++) {       
        if (students[i].gpa > top_student.gpa) {
            top_student = students[i];
        }
    }
    printf("Student with highest Gpa: %s (Roll: %d, Gpa: %.2f)\n",top_student.name, top_student.roll,top_student.gpa);
   
    // Read back from file
    file = fopen("students.txt", "r");    
    printf("Students read from file are :\n");
    int i=0;
    while (fscanf(file, "%s %d %f", students[i].name, &students[i].roll, &students[i].gpa) != EOF) {
        printf("Name: %s, RollNum: %d, Gpa: %.2f\n", students[i].name, students[i].roll, students[i].gpa);
        i++;
    }
    fclose(file); // Close file after reading
}
int main(){
    task3_2_fileio();
    return 0;
}