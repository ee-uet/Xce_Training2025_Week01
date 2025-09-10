#include <stdio.h>
#include <stdlib.h>

void task03_fibonacci()
{ 
    int n;
    printf("Enter the number of terms for fibonacci sequence:\n");
    scanf("%d",&n);
    int t1=0,t2=1,nextterm;
    printf("The terms are: \n");
    for (int i=0; i<n ;i++)
    {
        printf("%d \n",t1);
        nextterm=t1+t2;
        t1=t2;
        t2=nextterm;
    }
}

int main()
{
    task03_fibonacci();
    return 0;
}