#include <stdio.h>
#include <stdlib.h>

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int size = 0;
    printf("Enter the number size of arrray: ");
    scanf("%d",&size);
    int *ptr = (int *) malloc(size * sizeof(int));
    int sum = 0;
    if (ptr==NULL) {
      printf("Memory Allocation Failed!");
      }
    for (int i = 0; i < size ; i++) {
      printf("Enter number %d :", i+1);
      scanf("%d",(ptr+i));
      sum = sum + *(ptr+i);
    }printf ("Sum of the Elements: %d\nAverage of the Elements: %d\n", sum, sum/size);
    free(ptr);
}

int main() {
    task5_1_dynamic_array();
    return 0;
}