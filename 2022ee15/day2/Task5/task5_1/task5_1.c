#include <stdio.h>
#include <stdlib.h>

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // take input from user for array size
    int n;
    printf("Enter the number of elements of arr: ");
    scanf("%d",&n);

    // allocate memory dynamically for n integers
    int *arr =(int*)malloc(n*sizeof(int));

    // input elements in the array
    printf("Enter the elements: ");
    for (int i = 0; i<n; i++)
    {
        scanf("%d",arr+i); // using pointer arithmetic to store values
    }

    // calculate sum of elements
    int sum =0;
    for (int i=0; i<n;i++)
    {
        sum+=*(arr+i);  // adding each element
    }

    // print sum and average
    printf("Sum is %d\n",sum);
    printf("Average is %.2f\n",(float)sum/n); // cast to float for correct average

    // free allocated memory
    free(arr);
}

int main() {
    task5_1_dynamic_array(); // run the task
    return 0;
}

