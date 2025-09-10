#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting
    int integer;
    float float_number;
    char character;
    double double_number;
    printf("Task 1:\n");

    printf("Enter character:");
    scanf("%c",&character);

    printf("Enter integer:");
    scanf("%d",&integer);

    printf("Enter float number:");
    scanf("%f",&float_number);

    printf("Enter double value:");
    scanf("%lf",&double_number);

    printf(" integer = %d\n",integer);
    printf(" float = %f\n",float_number);
    printf(" character = %c\n",character);
    printf(" double = %1f\n",double_number);
    printf("size of integer = %zu bytes\n",sizeof(integer));
    printf("size of float = %zu bytes\n",sizeof(float_number));
    printf("size of character = %zu bytes\n",sizeof(character));
    printf("size of double = %zu bytes\n",sizeof(double_number));
    printf("float to double = %1f\n",(double)float_number);
    printf("character to int = %d\n",(int)character);
    printf("integer to character = %c\n",(char)integer);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {


    task01_datatypes();

    return 0;
}