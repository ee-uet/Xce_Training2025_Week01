#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    // negative numbers, 0 and 1 are not prime numbers
    if (n < 2) {    // 0 and 1 are not prime numbers
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // n is divisible by i, hence not prime
        }
    }
    return 1; // n is prime
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    task04_prime_numbers();
    return 0;
}