#include <stdio.h>
#include <stdlib.h>

void task02_calculator() 
{
    int a,b,operation;
    printf("Enter two numbers:\n");
    scanf("%d %d",&a,&b);
    printf("Enter the operation to be performed:\n");
    printf("1-Add 2-Sub 3-Mul 4-Div 5-Mod\n");
    scanf("%d",&operation);
    switch (operation)
    {
        case 1:
            printf("Add: a+b = %d \n",a+b);
            break;
        case 2:
            printf("Subtract: a-b = %d\n",a-b);
            break;
        case 3:
            printf("Multiply: a*b = %d\n",a*b);
            break;
        case 4:
            if(b!=0)
            {
                printf("Division: a/b = %.3f\n",(float)a/b);//typecasting int to float
            }
            else
            { 
                printf("Wrong operand 'b'");
            }
            break;
        case 5:
            printf("Modulus: a mod b = %d\n",a%b);
            break;
        default:
            printf("Something went wrong here!");
    }
}

int main()
{
   task02_calculator();
   return 0;
}