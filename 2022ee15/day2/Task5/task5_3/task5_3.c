#include <stdio.h>
#include <stdlib.h>

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // allocate memory and keep track of it
    if(allocated_count >= MAX_PTRS) {
        printf("Memory tracking limit reached\n");
        return NULL;
    }
    void *ptr = malloc(size);
    allocated_ptrs[allocated_count] = ptr; // store allocated pointer
    allocated_count++;
    return ptr;
}

void my_free(void *ptr) {
    // free memory and remove it from tracking
    for(int i = 0; i < allocated_count; i++) {
        if(allocated_ptrs[i] == ptr) {
            free(ptr);
            // shift the remaining pointers back
            for (int j = i; j < allocated_count-1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j+1];
            }
            allocated_count--;
            return;
        }
    }
}

void report_leaks() {
    // check if any allocated memory was not freed
    if(allocated_count == 0) {
        printf("No memory leaks\n");
        return;
    }
    printf("Memory leak detected\n");
    for(int i = 0; i < allocated_count; i++) {
        printf("Memory leak at address %p\n", allocated_ptrs[i]);
    }
}

void task5_3_leak_detector() {
    // allocate some memory
    int *arr_1 = (int*)my_malloc(5*sizeof(int));
    double *arr_2 = (double*)my_malloc(5*sizeof(double));

    // free allocated memory (try commenting one to simulate leak)
    my_free(arr_1);
    my_free(arr_2);

    // report memory leaks at the end
    report_leaks();
}

int main() {
    task5_3_leak_detector();
    return 0;
}

