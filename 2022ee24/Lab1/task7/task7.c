#include <stdio.h>

void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int x,y;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d",&y);
    printf("x & y = %d\n",x & y);
    printf("x | y = %d\n",x | y);
    printf("~x = %d\n",~x);
    printf("x<<2 = %d\n",x<<2);

    printf("is a power of 2: ");
    scanf("%d",&x);
    if ((x>0) && ((x & (x-1))==0))
    {
        printf("is a power of 2\n");
    }
    else{
        printf("is not a power of 2\n");
    }

}

int main()
{
    task07_bitwise_ops();
    return 0;
}