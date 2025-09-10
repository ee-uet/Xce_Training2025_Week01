#include <stdio.h>

// Macros
#define SQUARE(x) x*x       
#define MAX2(a,b) a>b? a:b
#define MAX3(a,b,c) MAX2(a,b)>c? MAX2(a,b):c
#define MAX4(a,b,c,d) MAX3(a,b,c)>d? MAX3(a,b,c):d
#define TO_UPPER(c) (c>96 && c<123)? c-32:c

void task3_1_macros() {
    int a = 5;
    int b = 6;
    int c = 17;
    int d = 8;
    char x = 'z';
    printf("Square of %d = %d\n",a,SQUARE(a));
    printf("Max2(%d,%d) = %d\n",a,b,MAX2(a,b));
    printf("Max3(%d,%d,%d) = %d\n",a,b,c,MAX3(a,b,c));
    printf("Max4(%d,%d,%d.%d) = %d\n",a,b,c,d,MAX4(a,b,c,d));
    printf("To_UPPER(%c) = %c\n",x,TO_UPPER(x));
}

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
    FILE *file = NULL;
    struct Student array[5] = {{"x",1,3.0},{"y",2,3.8},{"z",3,3.2},{"a",4,3.1},{"b",5,3.6}};
    float max = array[0].gpa;
    int count = 5;
    file = fopen("students.txt","w");
    for (int i=0;i<count;i++)
    {
        if (array[i].gpa > max)
        {
            max = array[i].gpa;
        }
        fprintf(file,"Name: %s\nRoll: %d\nGPA: %f\n\n",array[i].name,array[i].roll,array[i].gpa);
    }
    printf("highest GPA = %.1f\n",max);
    fclose(file);

}


int main()
{
    task3_1_macros();
    task3_2_fileio();
    return 0;
}