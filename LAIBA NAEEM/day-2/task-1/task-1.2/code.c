#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>




// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
     printf("value of a before swapping = %d\n",*a);
     printf("value of b before swapping = %d\n",*b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("value of a after swapping = %d\n",*a);
    printf("value of b after swapping = %d\n",*b);
}


// ======================= Main =======================
int main() {

   
    int a=5, b=10; swap(&a,&b);

    return 0;
}
