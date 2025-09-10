#include <stdio.h>
#include <stdlib.h>

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int n,m;
    printf("Enter number of elements of an array: ");
    scanf("%d",&n);
    // Allocate memory for n integers
    int *arr = (int*) malloc(n*sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input initial elements
    for(int i = 0;i < n;i++){
        printf("Enter %dth number: ",i+1);
        scanf("%d", &arr[i]);
    }
    // Print original array
    printf("Original array: ");
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    // Ask for extra elements
    printf("Enter number of Extra elements to append in an array: ");
    scanf("%d",&m);

    // Reallocate memory (extend array size to n+m)
    int *arr_1 = (int*) realloc(arr,(n+m)*sizeof(int));

    if (arr_1 == NULL) {
        printf("Reallocation failed!\n");
        return;
    }
    arr = arr_1;

    // Input new elements
    for(int i = 0;i < m;i++){
        printf("Enter %dth number: ", n + 1 + i);
        scanf("%d", &arr[n+i]);
    }

    // Print extended array
    printf("Extended array: ");
    for(int i = 0;i < (n+m);i++){
        printf("%d ",arr[i]);
    }
    
    free(arr);
    printf("\n");
}

// ======================= Main =======================
int main() {
    
    task5_2_realloc_array();

    return 0;
}