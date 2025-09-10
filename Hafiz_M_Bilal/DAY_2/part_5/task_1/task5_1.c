#include <stdio.h>
#include <stdlib.h>

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n;
    printf("Enter number of elements of an array: ");
    scanf("%d",&n);

    // Allocate memory dynamically for n integers
    int *arr = (int*) malloc(n*sizeof(int));

    // Check if memory allocation succeeded
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int sum = 0;
    // Input elements from user
    for(int i = 0;i < n;i++){
        printf("Enter %dth number: ",i+1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    // Compute average (typecast to float for decimal division)
    float avegr = (float)sum/(float)n;

    printf("Sum: %d\n",sum);
    printf("Average: %0.2f\n",avegr); 

    free(arr);

}

// ======================= Main =======================
int main() {

    task5_1_dynamic_array();
    
    return 0;
}
