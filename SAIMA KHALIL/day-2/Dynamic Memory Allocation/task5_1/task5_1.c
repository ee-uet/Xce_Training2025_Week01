#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void task5_1_dynamic_array() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
     
    int *arr = (int *)malloc(n * sizeof(int)); // allocate memory for n integers
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter %d integers:\n", n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // calculate sum
    } 
    double average = (double)sum / n; //calculate average
    printf("Sum: %d, Average: %.2f\n", sum, average);
    free(arr); // free allocated memory
    arr = NULL; // avoiding dangling pointer
    
}

int main(){
    task5_1_dynamic_array();
    return 0;
}