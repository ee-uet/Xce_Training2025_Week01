#include <stdio.h>

// Student struct definition
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O demonstration
void task3_2_fileio() {
    // Initialize 5 students in an array
    struct Student students[5] = {
        {"Ali", 15, 3.39},
        {"Abdullah", 12, 3.90},
        {"Bilal", 21, 3.75},
        {"Abdullah", 7, 3.85},
        {"Hamza", 10, 3.60}
    };

    // Find the student with the highest GPA
    int highest = 0;
    for (int i = 1; i < 5; i++) {
        if (students[i].gpa > students[highest].gpa) {
            highest = i;
        }
    }

    printf("Student with highest GPA:\n");
    printf("Name: %s, Roll: %d, GPA: %.2f\n", students[highest].name, students[highest].roll, students[highest].gpa);

    // Save students to file
    FILE *file = fopen("students_record.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(file);

    // Read students back from file
    printf("\nReading students from file:\n");
    file = fopen("students_record.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return;
    }

    struct Student temp;
    while (fscanf(file, "%49s %d %f", temp.name, &temp.roll, &temp.gpa) == 3) {
        printf("Name: %s, Roll no: %d, GPA: %.2f\n",
               temp.name, temp.roll, temp.gpa);
    }
    fclose(file);
}

int main() {
    task3_2_fileio();
    return 0;
}

