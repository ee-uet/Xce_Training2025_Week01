#include <stdio.h>
#include <stdlib.h>

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // allocate an array of 5 integers
    int *arr = (int*)malloc(5*sizeof(int));
    for (int i=0;i<5;i++)
    {
        arr[i]= i+1;  // fill with numbers 1..5
    }

    // print the array before reallocation
    printf("Array size before reallocation: ");
    for (int i=0;i<5;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

    int n;
    // ask user for the new size
    printf("Enter size for reallocation: ");
    scanf("%d",&n);

    // resize the array to the new size
    arr = (int*)realloc(arr,n*sizeof(int));

    // fill (or refill) the array with numbers 1..n
    for (int i=0;i<n;i++)
    {
        arr[i] = i+1;
    }

    // print the array after reallocation
    printf("Array size after reallocation: ");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

    // free the memory
    free(arr);
}

int main() {
    task5_2_realloc_array(); // call the function
    return 0;
}

