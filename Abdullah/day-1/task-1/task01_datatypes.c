#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting

    int a = 10;
    float b = 5.5f;
    double c = 3.14159;
    char d = 'A';

    // Print sizes of each data type
    printf("Size of int: %ld bytes\n", sizeof(a));
    printf("Size of float: %zu bytes\n", sizeof(b));
    printf("Size of double: %zu bytes\n", sizeof(c));
    printf("Size of char: %zu bytes\n", sizeof(d));

    // Type Casting
    double casted = (double)a; // int to double
    printf("Casted int to double: %f\n", casted);
    float casted_float = (float)c; // double to float
    printf("Casted double to float: %f\n", casted_float);
    int casted_int = (int)b; // float to int
    printf("Casted float to int: %d\n", casted_int);
}

int main() {
    task01_datatypes();
    return 0;
}