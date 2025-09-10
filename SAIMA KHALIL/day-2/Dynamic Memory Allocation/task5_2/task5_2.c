#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void task5_2_realloc_array() {
    int n;
    int new_size;
    
    printf("Enter initial number of elements in array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate initial memory
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }   
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }   
    printf("\n");
    
    printf("Enter new size for array: ");
    scanf("%d", &new_size);
    if (new_size <= n) {
        printf("New size must be greater than current size.\n");
        free(arr); // Free allocated memory
        return; 
    }
    int *new_arr = (int *)realloc(arr, new_size * sizeof(int)); // Reallocate memory
    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");    
    }
    else {
        arr = new_arr; // Update pointer to new memory
        printf("Array extended to size %d.\n", new_size);
        for (int i = n; i < new_size; i++) { // Initialize new elements
            arr[i] = i; // some value
        }
        printf("New array: ");
        for (int i = 0; i < new_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr); // Free allocated memory
    arr = NULL; // Avoid dangling pointer
}


int main(){
    task5_2_realloc_array();
    return 0;
}