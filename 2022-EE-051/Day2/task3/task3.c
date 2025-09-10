#include <stdio.h>

#define SQUARE(x)       ((x) * (x))
#define MAX2(a,b)       ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c)     (MAX2(MAX2((a),(b)),(c)))
#define MAX4(a,b,c,d)   (MAX2(MAX2((a),(b)), MAX2((c),(d))))
#define TO_UPPER(c)     (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))

void task3_1_macros() {
    printf("Square of 5 is %d\n", SQUARE(5));
    printf("Max of 6 and 3 is %d\n", MAX2(6, 3));
    printf("Max of 10, 7 and 3 is %d\n", MAX3(10, 7, 3));
    printf("Max of 1, 2, 3 and 4 is %d\n", MAX4(1, 2, 3, 4));
    printf("Uppercase of 'b' is %c\n", TO_UPPER('b'));
    printf("Uppercase of 'Z' is %c\n", TO_UPPER('Z'));
}

struct Student {
    char name[50];
    int roll;
    float gpa;
};

void task3_2_fileio() {
    struct Student students[5] = {
        {"U", 1, 3.1},
        {"V", 2, 3.2},
        {"X", 3, 3.5},
        {"Y", 4, 3.4},
        {"Z", 5, 3.3}
    };
    int maxgpa = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].gpa > students[maxgpa].gpa) {
            maxgpa = i;
        }
    }
    printf("Student with maximum GPA is %s\n", students[maxgpa].name);

    FILE *fp = fopen("students.txt", "w");
    if (!fp) {
        printf("Error!\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (!fp) {
        printf("Error!\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].roll, &students[i].gpa);
    }
    fclose(fp);

    printf("\nReading data back from file:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
}

int main(){
    task3_1_macros();
    task3_2_fileio();
    return 0;
}