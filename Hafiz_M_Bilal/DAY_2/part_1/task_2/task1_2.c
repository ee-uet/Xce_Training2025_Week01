#include <stdio.h>

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers

    printf("Before swap\n");
    printf("int_1: %d\n",*a);
    printf("int_2: %d\n",*b);
    
    // Perform swap using a temporary variable
    int temp = *b;
    *b = *a;
    *a = temp;
    
    printf("After swap\n");
    printf("int_1: %d\n",*a);
    printf("int_2: %d\n",*b);
}

// ======================= Main =======================
int main() {
    
    int a=5, b=10; swap(&a,&b);
      
    return 0;
}
