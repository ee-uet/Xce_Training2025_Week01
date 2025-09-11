#include <stdio.h>

void task02_calculator() {
    // Taking two integers as input
    int a = 3;
    int b = 4;
    char op;
    // Perforing arithmetic operations
    printf("%d + %d = %d\n",a , b, a + b);
    printf("%d + %d = %d\n",a , b, a + b);
    printf("%d * %d = %d\n",a , b, a * b);
    printf("%d / %d = %d\n",a , b, a / b);
    printf("%d %% %d = %d\n",a , b, a % b);

    // Implementing switch-case calculator
    printf("Enter Operation");
    scanf("%c", &op);
    switch(op){
        case '+': printf("%d + %d = %d\n", a, b, a + b); break;
        case '-': printf("%d - %d = %d\n", a, b, a - b); break;
        case '*': printf("%d * %d = %d\n", a, b, a * b); break;
        case '/': printf("%d / %d = %d\n", a, b, a / b); break;
        case '%': printf("%d %% %d = %d\n", a, b, a % b);break;
        default: printf("Invalid operation!\n"); break;
    }

}
int main() {
    task02_calculator();
    return 0;
    }