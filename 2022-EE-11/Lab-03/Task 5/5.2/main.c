#include <stdio.h>
#include "functions.h"
#include "math_ops.h"

int main() {
    printf("Hello from main!\n");
    
    int result = add_numbers(5, 3);
    printf("5 + 3 = %d\n", result);
    
    int product = multiply(4, 7);
    printf("4 * 7 = %d\n", product);
    
    double quotient = divide(10.0, 3.0);
    printf("10.0 / 3.0 = %.2f\n", quotient);
    
    greet("Advanced Makefile");
    
    return 0;
}