#include <stdio.h>
#include <stdlib.h>

// Task 1.3: Pointer arithmetic on array
#define ARR_SIZE 5
void task1_3() {
    // TODO: Create an array
    
    // array declaration and initialization
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *ptr = arr; 
    // Sum & Print all elements using pointers through iteration
    printf("Array Elements: ");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", *(ptr + i)); 
        sum += *(ptr + i); // Summing elements
    }
    printf("\nSum: %d\n", sum);

    // Reverse the array in place
    for (int i = 0; i < ARR_SIZE / 2; i++) {        // divide by 2 to swap only half
        int temp = *(ptr + i);                      // store the value at current index in temp
        *(ptr + i) = *(ptr + (ARR_SIZE - 1 - i));   // assign the value from the opposite end
        *(ptr + (ARR_SIZE - 1 - i)) = temp;         // assign the temp value to the opposite end
    } 
    printf("Reversed Array: ");
    // Print reversed array
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", *(ptr + i)); 
    } 
    printf("\n");
}

int main() {
    task1_3();
    return 0;
}