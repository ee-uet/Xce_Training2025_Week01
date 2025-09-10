#include <stdio.h>

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0

    // Prime numbers are greater than 1
    if (n<=1){
        return 0;
    }
    else{
        // Check divisibility from 2 to n-1
        for(int i = 2;i < n;i++){

            // If divisible, not prime
            if(n%i == 0){
                return 0;
            } 
        } 
        // If no divisor found, it is prime
        return 1;
    }   
    return 0;
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    printf("Prime numbers between 1 and 100 are:\n");
    for(int n = 1;n <= 100; n++){
        if(isPrime(n) == 1){
            printf("%d ",n);
        }
    }
    printf("\n");
}

// ======================= Main =======================
int main() {
    
    task04_prime_numbers();
    return 0;
}