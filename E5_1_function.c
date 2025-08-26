#include <stdio.h>

void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int a = 10;
    int *b = &a;
    printf("Direct: %d\n",a);
    printf("Using pointer: %d\n",*b);
    *b = 20;
    printf("Modified value using pointer: %d\n",a);
}