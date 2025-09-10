#include <stdio.h>

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    // Initialize array of 5 students
    struct Student students[5] = {
        {"AliKhan", 14, 3.20},
        {"SaraAhmed", 15, 3.90},
        {"BilalRaza", 16, 3.50},
        {"AhsanMalik", 17, 3.99},
        {"HinaNoor", 18, 3.70}
    };

    // Find highest GPA

    // Assume first student has highest GPA
    float highest = students[0].gpa;

    // Index of highest GPA student
    int h = 0;

    for (int i = 1; i < 5; i++) {
        // Compare with current highest
        if (students[i].gpa > highest) {
            // Update highest GPA
            highest = students[i].gpa;
            // Store index
            h = i;
        }
    }

    printf("Student with highest gpa:\n");
    printf("Name = %s ,Roll = %d ,gpa = %.2f\n",
           students[h].name, students[h].roll, students[h].gpa);

    // ---------- Write all student records to file ----------
    FILE *file = fopen("Students.txt","w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    // Write each student's data to file
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s %d %.2f\n",
                students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(file);
    printf("Data saved to Students.txt\n");

    // ---------- Read student records back from file ----------
    file = fopen("Students.txt","r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    printf("\nReading back from file:\n");

    // Temporary struct to store data while reading
    struct Student temp;

    // Read line by line until EOF (fscanf returns 3 if all 3 fields read correctly)
    while (fscanf(file, "%s %d %f",
                  temp.name, &temp.roll, &temp.gpa) == 3) {
        printf("Name = %s, Roll = %d, GPA = %.2f\n",
               temp.name, temp.roll, temp.gpa);
    }
    fclose(file);
}

// ======================= Main =======================
int main() {
    
    task3_2_fileio();

    return 0;
}
