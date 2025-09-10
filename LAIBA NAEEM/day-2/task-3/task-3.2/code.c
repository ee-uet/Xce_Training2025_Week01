#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    struct Student s1[5] = {{"A",7,3.4},
                         {"B",2,3.5},
                         {"C",4,3.1},
                         {"D",6,3.7},
                         {"E",9,1.9}}; 
    // Print student with highest GPA
    int i,j=0;
    for ( i = 1; i < 5; i++) {
       if (s1[i].gpa > s1[j].gpa ) {
            j = i;
      }
   }
   printf("student wit highest gpa is %s\n",s1[j].name);
    // Save to "students.txt"
    FILE *fp = fopen("students.txt","w");
    if (fp == NULL) {
     printf("File is empty\n");
    }
    for (int k = 0; k<5; k++) {
       fprintf(fp,"%s %d %.2f\n",s1[k].name,s1[k].roll,s1[k].gpa); 
}
    fclose(fp);
    printf("done\n");

    // Read back and print
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char name[50];
    int roll;
    float gpa;

    printf("Reading back from file\n");
    while (fscanf(fp, "%s %d %f", name, &roll, &gpa) == 3) {
        printf("%s %d %f\n", name, roll, gpa);
    }

    fclose(fp);
}

// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement


    task3_2_fileio();

   

    return 0;
}
