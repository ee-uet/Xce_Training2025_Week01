#include <stdio.h>
#include <stdlib.h>

void task05_second_largest() {
    int arr[100], n, largest, second_largest;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n < 2) {
        printf("You must enter 2 numbers!\n");
        return;
    }
    // largest = second_largest = arr[0]; // initially assuming this thing is wrong :)  
    // if the first number is actually the largest, then second_largest will never get updated.  

    if (arr[0] > arr[1]) {
    largest = arr[0];
    second_largest = arr[1];
    } else {
    largest = arr[1];
    second_largest = arr[0];
    }
 
    for (int i = 1; i < n; i++) {   
        if (arr[i] > largest) {
            second_largest = largest;//moving the old largest to second_largest
            largest = arr[i];  
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i]; //updating if greater than current second_largest and not equal to largest
        }
    }
    printf("Largest element: %d\n", largest); 
    printf("Second largest element: %d\n", second_largest);// assuming: if duplicate largest values exist (e.g., 5, 5, 3),then second_largest will also be the same as largest (i.e., 5).
    
}

int main()
{
    task05_second_largest();
    return 0;
} 