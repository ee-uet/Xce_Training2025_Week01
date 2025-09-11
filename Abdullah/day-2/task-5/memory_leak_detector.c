#include <stdio.h>
#include <stdlib.h>

// Note: These global variables are part of the template
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Leak detector can't track any more pointers.\n");
        return malloc(size); // Allocate without tracking
    }
    
    void *ptr = malloc(size);
    if (ptr != NULL) {
        // Track the allocated pointer
        allocated_ptrs[allocated_count] = ptr;
        allocated_count++;
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) return;

    int i, found = -1;
    // Find the pointer in our tracking array
    for (i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        // Shift remaining pointers to fill the gap
        for (i = found; i < allocated_count - 1; i++) {
            allocated_ptrs[i] = allocated_ptrs[i + 1];
        }
        allocated_count--;
    }
    
    free(ptr); // Free the actual memory
}

void report_leaks() {
    printf("--- Memory Leak Report ---\n");
    if (allocated_count == 0) {
        printf("No memory leaks detected. Well done!\n");
    } else {
        printf("Warning! %d block(s) of memory were not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  - Leaked block at address: %p\n", allocated_ptrs[i]);
        }
    }
    printf("--------------------------\n");
}

void task5_3_leak_detector() {
    printf("\nMemory leak detection...\n");
    
    // Allocate three blocks of memory
    int *p1 = (int*)my_malloc(sizeof(int));
    char *p2 = (char*)my_malloc(10 * sizeof(char));
    int *p3 = (int*)my_malloc(5 * sizeof(int));
    
    printf("Allocated 3 blocks.\n");
    
    // Free only two of them
    printf("Freeing 2 blocks.\n");
    my_free(p1);
    my_free(p3);
    
    // Generate the report
    report_leaks(); // This should report that p2 was leaked
        printf("Freeing remaining blocks.\n");
    // Cleanup the intentionally leaked block for a clean run
    my_free(p2);
}

int main() {
    task5_3_leak_detector();
    return 0;
}