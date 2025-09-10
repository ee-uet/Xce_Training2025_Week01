#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int arr[] = {1,2,3,4,5,6,7};
    int sum = 0;
    // Print all elements using pointers
    int *ptr = arr;
    int enteries = sizeof(arr)/sizeof(int);
    for (int i = 0; i < enteries; i++) {
       printf("enteries of array = %d\n",*(ptr));
       sum += *ptr;
       ptr++;
       
}
    // Calculate sum
    printf("sum of all enteries = %d\n",sum);

    // Reverse in place
    ptr = arr;
    int temp;
    int *start = arr;
    int *end = arr + enteries - 1;
    while ( start < end ) {
        temp = *start;
        *start = *end;
        *end = temp;
       start++;
       end--;
      
}
    printf("Reverse array is\n");
    for (int i = 0; i < enteries; i++) {
       printf("enteries of array = %d\n",*(ptr));
       ptr++;
}

// ======================= Main =======================
int main() {
    
     task1_3();
    return 0;
}
