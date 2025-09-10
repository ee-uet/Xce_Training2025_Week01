#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) 
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0; //not a prime number
    }
    return 1;
}

void task04_prime_numbers() {
    printf("Prime numbers between 1-100 are :\n");
    for (int i = 1; i <= 100; i++) {    
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main()
{
    task04_prime_numbers();
    return 0;
}