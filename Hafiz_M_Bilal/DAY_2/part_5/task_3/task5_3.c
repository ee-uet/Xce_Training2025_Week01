#include <stdio.h>
#include <stdlib.h>

// Memory Leak Detector (simplified tracking)

// MAX_PTRS is the maximum number of allocations we track.
#define MAX_PTRS 100

// Stores allocated memory addresses
void* allocated_ptrs[MAX_PTRS];

// Number of allocations made
int allocated_count = 0;


void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    void* ptr = malloc(size);
    if(ptr != NULL && allocated_count < MAX_PTRS){
        // Save the pointer in our tracking list
        allocated_ptrs[allocated_count++] = ptr;
    }
    printf("Memory allocated to %dth pointer \n",allocated_count);
    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking

    // Found the pointer in our tracking list
    for(int i = 0;i < allocated_count;i++){
        if(allocated_ptrs[i] == ptr){
            printf("Allocated pointer's memory successfully free at %p\n",ptr);
            free(ptr);
            allocated_ptrs[i] = NULL;
            return;
        }
    }
    // If we didn’t find it in our list → invalid free
    printf("Warning: Tried to free untracked pointer!\n");
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    int leak = 0;
    for(int i = 0;i < allocated_count;i++){
        if(allocated_ptrs[i] != NULL){
            leak++;
            printf("Memory leak detected at pointer %p \n",allocated_ptrs[i]);
        }
    }
    if(leak == 0){
        printf("No memory leaks detected \n");
    }
    
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int*) my_malloc(5 * sizeof(int));   
    int *arr2 = (int*) my_malloc(3 * sizeof(int));

    my_free(arr2);   // Freed properly

    report_leaks();  // Should detect arr1 as leaked
}

// ======================= Main =======================
int main() {
    
    task5_3_leak_detector();

    return 0;
}