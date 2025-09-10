#include <stdio.h>

// function to demonstrate pointer arithmetic on arrays
void task1_3() {
    int arr[] = {1, 2, 3, 4, 5};        
    int *ptrarr = arr;                  
    int size = sizeof(arr) / sizeof(arr[0]);  // number of elements

    // print all elements using pointer arithmetic
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", *(ptrarr + i));
    }
    printf("\n");

    // calculate sum using pointer
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(ptrarr + i);
    }
    printf("Sum of array elements: %d\n", sum);

    // reverse array in-place using two pointers
    int *start = arr;
    int *end = arr + (size - 1);

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;   // move forward
        end--;     // move backward
    }

    // print reversed array
    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

int main() {
    task1_3();
    return 0;
}

