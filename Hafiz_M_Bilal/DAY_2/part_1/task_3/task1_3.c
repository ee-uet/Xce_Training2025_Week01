#include <stdio.h>

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place

    int arr[] = {1,2,3,4,5};

    // Pointer to the first element of array
    int *ptr = arr;

    int sum = 0;
    // Number of elements in array
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("Array elements are: ");
    
    // Print elements and calculate sum
    for(int i = 0;i < length;i++){
        printf("%d ",ptr[i]);
        sum = sum + ptr[i];
    }
    printf("\nThe Sum is: %d\n",sum);

    // Reverse array in place using pointers

    // Points to last element
    int *a = arr + length-1;
    ptr = arr;

    while(ptr < a){
        int temp = *ptr;
        // Swap *ptr and *a
        *ptr = *a;
        *a = temp;

        // Move ptr forward
        ptr++;
        // Move a backward
        a--;
    }
    // Print reversed array
    ptr = arr;
    printf("Reverse array elements are: ");
    for(int i = 0;i < length;i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

// ======================= Main =======================
int main() {
    
   task1_3();
   
   return 0;
}
