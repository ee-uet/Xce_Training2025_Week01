#include <stdio.h>
#include <stdlib.h>

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int x = 10;
    printf("Initial Value: %d\n", x);
    int *ptr = &x;                          // Pointer to x
    *ptr = 20;                              // modify x via pointer
    printf("Modified Value: %d\n", *ptr);
}

int main() {
    task1_1();
    return 0;
}