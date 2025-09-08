#include <stdio.h>

// ======================= Task 0.6 optional =======================
// Function to check if a number is prime
int isPrime(int n) {
    // Prime numbers are greater than 1
    if (n <= 1) {
        return 0;
    } else {
        // Check divisibility from 2 to n-1
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return 0;  // Not prime
            }
        }
        return 1;  // Prime
    }
}


// Function: Write prime numbers between 1 and 100 into a file
void task06_file_io_prime() {
    // Declare a file pointer 
    // to handle file operations
    FILE *fp;

    // Open file for writing
    fp = fopen("primes.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Write primes between 1 and 100 into the file
    fprintf(fp, "Prime numbers between 1 and 100 are:\n");
    for (int n = 1; n <= 100; n++) {
        if (isPrime(n)) {
            fprintf(fp, "%d ", n);
        }
    }
    fprintf(fp, "\n");

    // Close file
    fclose(fp);  
    printf("Prime numbers written to primes.txt\n");
}

// ======================= Main =======================
int main() {
    
    task06_file_io_prime();   

    return 0;
}
