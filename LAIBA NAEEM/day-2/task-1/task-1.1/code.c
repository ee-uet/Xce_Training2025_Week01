#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    int x = 5;
    int *ptr = &x;
    printf("value of x = %d\n",x);
    printf("value of x using pointer = %d\n",*ptr);
    // Modify via pointer and print new value
    *ptr = 100;
    printf("Modified value of x = %d\n",x);
    printf("Modified value of x  with pointer = %d\n",*ptr);
    
}


// ======================= Main =======================
int main() {
    
    task1_1();
    return 0;
}
