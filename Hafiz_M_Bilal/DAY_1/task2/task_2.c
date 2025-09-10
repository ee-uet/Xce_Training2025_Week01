#include <stdio.h>

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator

    int a;
	int b;
    char operator;

	printf("Enter First number  ");
	scanf("%d", &a);
	printf("Enter Second number ");
	scanf("%d", &b);

    printf("Enter Operator +, -, *, /, %%,\n");
	scanf(" %c", &operator);

    switch (operator){
        case '+':
            printf("Result of %d + %d = %d\n",a,b,a+b);
            break;
        case '-':
            printf("Result of %d - %d = %d\n",a,b,a-b);
            break;
        case '*':
            printf("Result of %d * %d = %d\n",a,b,a*b);
            break;
        case '/':
            if(b != 0){
                printf("Result of %d / %d = %d\n",a,b,a/b);
            }
            else{
                printf("Division by zero is not allowed\n");
            }
            break;
        case '%':
            if(b != 0){
                printf("Result of %d %% %d = %d\n",a,b,a%b);
            }
            else{
                printf("Modulo by zero is not allowed\n");
            }
            break;
        default:
            printf("Invalid Operator!\n");

    }
}

// ======================= Main =======================
int main() {
    
    
    task02_calculator();
    

    return 0;
}