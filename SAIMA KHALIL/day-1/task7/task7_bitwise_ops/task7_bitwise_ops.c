#include <stdio.h>
#include <stdlib.h>

void task07_bitwise_ops() {
    int a,b;
    printf("Enter two numbers :\n");
    scanf("%d %d",&a,&b);
    printf("AND:  %d\n", a & b);
    printf("OR:   %d\n", a | b);
    printf("XOR: %d\n", a ^ b);
    printf("NOT: %d\n", ~a);
    printf("Left Shift:  %d\n",a << 1);
    printf("Right Shift: %d\n", a  >> 1);
}

int main(){
    task07_bitwise_ops();
    return 0;
}

