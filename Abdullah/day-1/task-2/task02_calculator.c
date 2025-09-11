#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator

    int int1, int2, result;
    printf("Enter 1st Integer: \n"); 
    scanf("%d",&int1);
    printf("Enter 2nd Integer: \n");
    scanf("%d",&int2);
    
    char operator;
    printf("Enter operator symbol (ADD, SUB, MUL, DIV, REM): \n");
    scanf(" %c", &operator);

    switch (operator) {
    case '+':
        printf("Performing Addition\n");
        result = int1 + int2;
        printf("The result is: %d", result);
        break;
    
    case '-':
        printf("Performing Subtratcion:\n");
        result = int1 - int2;
        printf("The result is: %d\n", result);
        break;
    
    case '*':
        printf("Performing Multiplication:\n");
        result = int1 * int2;
        printf("The result is: %d\n", result);
        break;

    case '/':
        printf("Performing Division:\n");
        result = int1 / int2;
        printf("The result is: %d\n", result);
        break;
    
    case '%':
        printf("Performing Modulo:\n");
        result = int1 % int2;
        printf("The result is: %d \n", result);
        break;
    
    default:
        printf("Invalid operator. Please use ADD, SUB, MUL, DIV, or REM.\n");
        break;
    }
}

int main() {
    task02_calculator();
    return 0;
}