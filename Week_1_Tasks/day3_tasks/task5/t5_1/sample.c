#include <stdio.h>

int add(int a, int b)
{
    return(a+b);
}
int mul(int a, int b)
{
    return(a*b);
}

int main(void)
{
    int res_add=add(3,5);
    int res_mul=mul(5,3);
    printf("result for add and multiplication is %d, %d\n", res_add, res_mul );
}