#include <stdio.h>
#include <stdlib.h>

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    printf("Current Values: a = %d, b = %d\n", *a, *b);
    int temp;                                           // 
    temp = *a;                                          // store the value at a in temp
    *a = *b;                                            // assign the value at b to a
    *b = temp;                                          // assign the temp value to b
    printf("After Swapping: a = %d, b = %d\n", *a, *b);
}

int main() {
    // initialize two integers hardcoded
    int a = 5, b = 10;
    swap(&a, &b);
    return 0;
}