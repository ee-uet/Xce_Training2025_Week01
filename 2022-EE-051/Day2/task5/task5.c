#include <stdio.h>
#include <stdlib.h>

// dynamic array(using malloc)
void task5_1_dynamic_array() {
    int n, sum = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    // allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));

    // read elements and compute sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum is %d and average is %f\n", sum, (float)sum / n);
    free(arr);
}

// reallocating array
void task5_2_realloc_array() {
    int n, newsize;

    printf("Enter size: ");
    scanf("%d", &n);

    // allocate initial array
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // resize array using realloc
    printf("Enter new size: ");
    scanf("%d", &newsize);
    arr = (int *)realloc(arr, newsize * sizeof(int));

    // input new array contents
    printf("Enter %d elements for extended array:\n", newsize);
    for (int i = 0; i < newsize; i++) scanf("%d", &arr[i]);

    // print final array
    printf("Final array: ");
    for (int i = 0; i < newsize; i++) printf("%d ", arr[i]);
    printf("\n");

    // free memory
    free(arr);
}

// Simple memory leak detector
#define MAX_PTRS 100
void *allocated_ptrs[MAX_PTRS]; // track allocated pointers
int allocated_count = 0;

// custom malloc that records allocations
void *my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Error!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr) allocated_ptrs[allocated_count++] = ptr;
    return ptr;
}

// custom free  that removes pointer
void my_free(void *ptr) {
    if (ptr == NULL) return;
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);

            // shift remaining pointers
            for (int j = i; j < allocated_count - 1; j++)
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            allocated_count--;
            return;
        }
    }
    printf("Trying to free untracked pointer %p\n", ptr);
}

// report unfreed memory
void report_leaks() {
    if (allocated_count == 0) printf("No memory leaks!\n");
    else {
        printf("Memory leaks detected: %d\n", allocated_count);
        for (int i = 0; i < allocated_count; i++)
            printf("Leak at pointer: %p\n", allocated_ptrs[i]);
    }
}

void task5_3_leak_detector() {
    // memory allocate
    int *arr1 = (int *)my_malloc(5 * sizeof(int));
    int *arr2 = (int *)my_malloc(3 * sizeof(int));

    // free only arr1
    my_free(arr1);
    // my_free(arr2);

    // report any memory leaks
    report_leaks();
}

int main() {

    task5_1_dynamic_array();
    task5_2_realloc_array();
    task5_3_leak_detector();
    return 0;
}
