// file: t2.c
#include <stdio.h>

void task02_calculator() {
    // take two integers as input
    int a, b;
    printf("Enter 1st Int: ");
    scanf("%d", &a);
    printf("Enter 2nd Int: ");
    scanf("%d", &b);

    // basic arithmetic operations
    printf("Add: %d\n", a + b);
    printf("Subtract: %d\n", a - b);
    printf("Multiply: %d\n", a * b);
    printf("Divide: %d\n", a / b);
    printf("Remainder: %d\n", a % b);

    // simple calculator using switch
    char operator;
    printf("Enter Operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+': printf("Add: %d\n", a + b); break;
        case '-': printf("Subtract: %d\n", a - b); break;
        case '*': printf("Multiply: %d\n", a * b); break;
        case '/': printf("Divide: %d\n", a / b); break;
        case '%': printf("Remainder: %d\n", a % b); break;
        default: printf("Invalid operator\n");
    }
}

int main(void) {
    task02_calculator();   
    return 0;
}

