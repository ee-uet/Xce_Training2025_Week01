//Exercise 5.1: Basic Makefile
//1. Create a simple C program with a main.c and functions.c
//2. Write a Makefile to compile these into an executable
//3. Include targets for 'all', 'clean', and individual object files

#include <stdio.h>
#include "function.h"
#include "math.h"

int main() {
    printf("Sum: %d\n", add(5, 3));
    printf("Difference: %d\n", subtract(5, 3));
    printf("Multiply: %d\n", multiply(5, 3));
    printf("Divide: %d\n", divide(20, 3));
    return 0;
}