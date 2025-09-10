#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

 
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Memory leak detected: too many allocations!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr; // Store pointer in tracking array  and then increment count
    } else {
        printf("Memory allocation failed.\n");
    }
    return ptr;
}

void my_free(void *ptr) {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            allocated_ptrs[i] = allocated_ptrs[--allocated_count]; // Remove pointer from tracking --allocated_count i-e first decrementing allocated_count then using it. 
            return;
        }
    }
    printf("Something went wrong here!\n");
}

void report_leaks() {
    if (allocated_count > 0) {
        printf("Memory leak detected! %d pointers not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("Pointer %d: %p\n", i + 1, allocated_ptrs[i]);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

void task5_3_leak_detector() {
    int *arr1 = (int *)my_malloc(10 * sizeof(int)); // Allocate memory
    if (arr1 == NULL) return; // Check allocation success
    int *arr2 = (int *)my_malloc(20 * sizeof(int)); // Allocate
    if (arr2 == NULL) {
        my_free(arr1); // Free first array if second allocation fails
        return;
    } 

    my_free(arr1); // Free first array
    // Intentionally leaking second array
    // my_free(arr2); // to avoid leak remove // this
    report_leaks(); // Report leaks
    my_free(arr2); // Free second array
    report_leaks(); // Report again after freeing
} 
int main(){
    task5_3_leak_detector();
    return 0;
}