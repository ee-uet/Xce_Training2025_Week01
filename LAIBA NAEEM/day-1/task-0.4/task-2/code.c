#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



int factorial(int n) {
    if (n == 0) {
        return 1;  
    }
    return n * factorial(n - 1);  
}

void task_factorial() {
    int n;
    printf("\n");
    printf("Task 4:Factorial\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = factorial(n);
    printf("factorial of %d = %d\n", n, result);
}



// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    
    
     task_factorial();
    return 0;
}
