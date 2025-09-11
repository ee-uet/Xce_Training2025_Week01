#include <stdio.h>
#include <stdlib.h>

void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int n1 = 5, n2 = 10, i;
    int *arr;

    // Initial allocation
    arr = (int *)malloc(n1 * sizeof(int));
    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return;
    }

    printf("Initially allocated for %d elements.\n", n1);
    for (i = 0; i < n1; i++) {
        arr[i] = i + 1; // Fill with some data
    }

    // Extend the array using realloc
    printf("Reallocating to hold %d elements.\n", n2);
    int *temp = (int *)realloc(arr, n2 * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        free(arr); // Free the original block
        return;
    }
    arr = temp; // Point to the new, possibly moved, block

    // Fill the new part of the array
    for (i = n1; i < n2; i++) {
        arr[i] = i + 1;
    }

    // Print the final array
    printf("Final array contents: ");
    for (i = 0; i < n2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main() {
    task5_2_realloc_array();
    return 0;
}