#include <stdio.h>
#include <stdlib.h>

void task1_1() {
    
    int a = 10;
    int *ptr = &a;
    printf("Address of a is : %zu\n",&a);
    printf("Value of a is : %d\n", a);
    printf("Value of a using pointer is : %d\n", *ptr);
    
    *ptr = 100;  //modifying value using pointer
    printf("New value of a after modification via pointer is : %d\n", a);
}

int main(){
    task1_1();
    return 0;
}
