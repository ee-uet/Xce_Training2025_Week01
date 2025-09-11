#include <stdio.h>
#include <stdlib.h>

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n;
    int sum = 0;
    printf("Enter size of the array:");
    scanf("%d",&n);

    int* array = (int*)malloc(n*sizeof(int));
    
    for (int i=0;i<n;i++)
    {
        printf("Enter element%d: ",i);
        scanf("%d",(array+i));
    }
    for (int j=0;j<n;j++)
    {
        sum += *(array+j);
    }
    printf("Sum = %d\nAverage = %f\n",sum,(float)sum/n);
    free(array);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int initial_size, extended_size;
    int *array = NULL;
    
    printf("Enter initial size of the array: ");
    scanf("%d", &initial_size);
    
    array = (int*)malloc(initial_size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter %d elements:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    
    printf("Initial array: ");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("Enter extended size: ");
    scanf("%d", &extended_size);
    
    int *temp = (int*)realloc(array, extended_size * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(array);
        return;
    }
    array = temp;     
    
    printf("Enter %d additional elements:\n", extended_size - initial_size);
    for (int i = initial_size; i < extended_size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    
    printf("Extended array: ");
    for (int i = 0; i < extended_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    int sum = 0;
    for (int i = 0; i < extended_size; i++) {
        sum += array[i];
    }
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum / extended_size);
    
    free(array);
    
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    void* ptr = (void*)malloc(size);
    if (ptr != NULL && allocated_count < MAX_PTRS)
    {
        allocated_ptrs[allocated_count] = ptr;
        allocated_count += 1;
    }
    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    for (int i=0;i<allocated_count;i++)
    {
        if (allocated_ptrs[i] == ptr)
        {
            free(ptr);
            allocated_count -= 1;
            for (int j=i;j<allocated_count;j++)
            {
                allocated_ptrs[j] = allocated_ptrs[j+1];
            }
            break;
        }
    }
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count > 0)
    {
        printf("Memory leaks detected!\n");
        for (int i=0;i<allocated_count;i++)
        {
            printf("Leak at address: %p\n",allocated_ptrs[i]);
        }
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int* ptr1 = (int*)my_malloc(sizeof(int));
    int* ptr2 = (int*)my_malloc(50*sizeof(int));
    char* ptr3 = (char*)my_malloc(10*sizeof(char));
    my_free(ptr2);
    atexit(report_leaks);
}


int main()
{
    task5_1_dynamic_array();
    task5_2_realloc_array();
    task5_3_leak_detector();
    return 0;
}