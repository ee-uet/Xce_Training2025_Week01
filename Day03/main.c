#include <stdio.h>
#include "functions.h"
int main()
{
    int num1,num2;
    printf("Enter num1: ");
    scanf("%d",&num1);
    printf("Enter num2: ");
    scanf("%d",&num2);
    printf("%d + %d = %d\n",num1,num2,add(num1,num2));
    return 0;
}
