#include <stdio.h>
#include <stdlib.h>

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    // TODO: Input 5 students
    // Print student with highest GPA
    // Save to "students.txt"
    // Read back and print
    
    struct Student student[5];
    struct Student *highest_gpa = &student[0];

    // Input student data
    for (int i = 0; i<5; i++) {
      printf("Enter the name of Student %d: ",i+1);
      scanf("%49s", student[i].name);
      printf("Enter the GPA of Student %d: ",i+1);
      scanf("%f", &student[i].gpa);
      printf("Enter the roll of Student %d: ", i+1);
      scanf("%d", &student[i].roll);
      
      // Check for highest GPA
      if (student[i].gpa > highest_gpa->gpa) {
        highest_gpa = &student[i];
      }
    }
    printf("The Student with highest GPA is: %s , %d, %f.\n", highest_gpa->name, highest_gpa->roll, highest_gpa->gpa);
    
    // Write student data to file
    FILE *studentsfile = fopen("students.txt", "w");
    if (studentsfile == NULL) {
      printf("Failed to open.");
    }
    // Write all 5 students to file
    for (int i = 0; i < 5; i++) {
      fprintf(studentsfile, "%s %d %f\n", student[i].name, student[i].roll, student[i].gpa);
    }
    fclose(studentsfile);
    
    // Read student data back from file using a temporary struct
    struct Student temp;
    FILE *students_file = fopen("students.txt", "r");
    if (students_file == NULL) {
      printf("Failed to open.");
    }
    // Read all 5 students from file
    for (int i = 0; i < 5; i++) {
      fscanf(students_file, "%s %d %f\n", temp.name, &temp.roll, &temp.gpa);
      printf("Read from students.txt : %s, %d, %f", temp.name, temp.roll, temp.gpa);
    }
    fclose(students_file);
}

int main() {
    task3_2_fileio();
    return 0;
}