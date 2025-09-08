#include <stdio.h>

void task1_1() {
    int a = 10;         // Declare an integer variable
    int *ptra = &a;     // Declare a pointer and assign the address of 'a' to it

    // Print the value using both methods
    printf("Print value of a using direct method: %d\n", a);
    printf("Print value of a using pointer method: %d\n", *ptra);

    *ptra = 15; // Modify the value of 'a' using the pointer
    printf("Updated value of a: %d\n", a); // Print the new value to confirm the change
}

int main() {
    task1_1();
    return 0;
}
