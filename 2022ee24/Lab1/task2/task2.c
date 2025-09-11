#include<stdio.h>

void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    
    int num1,num2;
    char op;

    printf("Enter num1 = ");
    scanf("%d",&num1);
    printf("Enter num2 = ");
    scanf("%d",&num2);
    printf("Enter op = ");
    scanf(" %c",&op);

    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n",num1,num2,num1+num2);
        break;
    case '-':
        printf("%d - %d = %d\n",num1,num2,num1-num2);
        break;
    case '*':
        printf("%d * %d = %d\n",num1,num2,num1*num2);
        break;
    case '/':
        printf("%d / %d = %d\n",num1,num2,num1/num2);
        break;
    default:
        printf("invalid op!\n");
        break;
    }

}

int main()
{
    task02_calculator();
    return 0;
}