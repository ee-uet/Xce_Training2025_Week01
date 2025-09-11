#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main()
{
    int n,fact;
    printf("Enter the number you want to find factorial of ! : \n");
    scanf("%d",&n);
    fact=factorial(n);
    printf("Factorial is : %d\n",factorial(n));
    return 0;
}