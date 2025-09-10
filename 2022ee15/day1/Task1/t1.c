// file: t1.c
#include <stdio.h>

void task01_datatypes() {
    // declare variables
    int num = 10;
    float a = 3.1f;
    double b = 10.0;
    char c = 'a';

    /* print sizes */
    printf("size of int is: %zu\n", sizeof(num));
    printf("size of float is: %zu\n", sizeof(a));
    printf("size of double is: %zu\n", sizeof(b));
    printf("size of char is: %zu\n", sizeof(c));

    /* type casting examples */
    printf("Typecasting From Float to Int %d\n", (int)a);

    int num_1 = 5, num_2 = 3;
    int result = num_1 / num_2;               // integer division (truncates)
    printf("Typecasting From Int to Float %f\n", (float)result);

    float z = (float)num;
    printf("Typecasting From Int to Float %f\n", z);
}

int main(void) {
    task01_datatypes();   // run the task
    return 0;
}

