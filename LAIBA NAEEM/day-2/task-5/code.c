#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// ======================= Part 5: Dynamic Memory Allocation =======================

void task5_1_dynamic_array() {
    int n, i;
    int sum = 0;
    float average;

    printf("Enter total numbers: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", (arr+i));
    }

 
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }


    average = (float)sum / n;
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f\n", average);
    free(arr);
}
void task5_2_realloc_array() {
    int entries = 5;
    int *arr = (int*) malloc(entries * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    for(int i=0; i<entries; i++)
        arr[i] = i+1;   // 1,2,3,4,5

    int n = 7;
    arr = (int*) realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return;
    }

    
    arr[5] = 3;
    arr[6] = 5;

    for (int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    printf("done\n");
    free(arr);
}
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Cannot track more pointers!\n");
        return NULL;
    }
    
    void* ptr = malloc(size);         
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr;   
    }
    return ptr;
}

void my_free(void* ptr) {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
           
            for (int j = i; j < allocated_count - 1; j++)
                allocated_ptrs[j] = allocated_ptrs[j+1];
            allocated_count--;
            free(ptr);   
            return;
        }
    }
    printf("Pointer not found!\n");
}


void check_leaks() {
    if (allocated_count == 0) {
        printf("No memory leaks detected.\n");
    } else {
        printf("Memory leaks detected for %d pointer(s):\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  Leak at address: %p\n", allocated_ptrs[i]);
        }
    }
}

// ======================= Main =======================
int main() {
  
    // --- Part 5 ---
     task5_1_dynamic_array();
     task5_2_realloc_array();
     int *a = (int*) my_malloc(sizeof(int));
    int *b = (int*) my_malloc(sizeof(int));

    *a = 10;
    *b = 20;

    my_free(a);       

    check_leaks(); 
    return 0;
}
