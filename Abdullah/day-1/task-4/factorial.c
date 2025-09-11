#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    // TODO: Implement recursive factorial function
    // Bound to prevent Overflow
    if (n < 0 || n > 12) {
        printf("Input out of range. Please enter a number between 0 and 12.\n");
        return -1; // Indicate error
    }
    // Base case
    if (n == 0 || n == 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

int main() {
    printf("Factorial of 5 = %d\n", factorial(5));
    return 0;
}