#include <stdio.h>
#include "functions.h"

int main() {
    // Test the square function
    int num = 5;
    int result = square(num);
    printf("Square of %d is %d\n", num, result);
    return 0;
}

/* File: shell-lab/lab-5/advanced_makefile/functions.c */
#include "functions.h"

// Compute the square of a number
int square(int num) {
    return num * num;
}