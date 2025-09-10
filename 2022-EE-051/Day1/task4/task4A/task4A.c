#include <stdio.h>

int isPrime(int n) {
    // Return 1 if n is prime, else 0
    if(n <= 1) return 0;
    for(int i = 2; i <= n/2; i++)
        if(n % i == 0) return 0;
    return 1;
}

void task04_prime_numbers() {
    // Print prime numbers between 1 and 100
    // Opening a text file in write mode
    FILE *fp = fopen("primes.txt", "w");
    if(!fp) {
        printf("File not found!\n");
        //return;
    }
    // Printing the prime numbers in the file
    printf("Prime numbers between 1 and 100:\n");
    for(int i = 1; i <= 100; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            fprintf(fp, "%d\n", i);
        }
    }
    fclose(fp);
}

int main() {
    task04_prime_numbers();
    return 0;
}
