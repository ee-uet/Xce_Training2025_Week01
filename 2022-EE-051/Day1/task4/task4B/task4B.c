#include <stdio.h>

int factorial(int n) {
    // Implement recursive factorial function
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    printf("Factorial of 5 = %d\n", factorial(5));
    return 0;
}
