#include <stdio.h>


// ======================= Task 0.4 =======================

// Recursive function to calculate factorial of a number
int factorial(int n) {
    // TODO: Implement recursive factorial function
    // Base case: factorial of 1 is 1
    if(n == 1){
        return 1;
    }
    else{
        // Recursive step:
        n = n * (factorial(n-1));
    }
    return n;
}

// ======================= Main =======================
int main() {
    
    printf("Factorial of 5 = %d\n", factorial(5));
   
    return 0;
}