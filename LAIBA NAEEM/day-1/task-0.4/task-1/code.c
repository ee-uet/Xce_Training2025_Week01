#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int isPrime(int n) {

    if (n <= 1) 
      return 0;      

    for (int i = 2; i*i<= n; i++) {
        if (n % i == 0) return 0;  
    }

    return 1;  
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    printf("\n");
    printf("Task 4: Prime numbers from 1 to 100\n");
    for (int n = 2; n <= 100; n++) {
        if (isPrime(n)) {
            printf("%d\n ", n);
        }
    }
}
// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    
     task04_prime_numbers();
    
    return 0;
}
