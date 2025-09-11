#include <stdio.h>

// Check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int k = 2; k < n; k++) {
        if (n % k == 0) {
            return 0;
        }
    }
    return 1;
}

// Print all prime numbers between 1 and 100
void task04_prime_numbers() {
    for (int i = 1; i < 100; i++) {
        if (isPrime(i)) {
            printf("%d\t", i);
        }
    }
    printf("\n");
}

// Recursive factorial function
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    printf("Prime numbers between 1 and 100:\n");
    task04_prime_numbers();

    int num = 5;
    printf("Factorial of %d = %d\n", num, factorial(num));

    return 0;
}

