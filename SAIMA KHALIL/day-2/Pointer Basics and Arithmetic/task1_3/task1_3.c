#include <stdio.h>
#include <string.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array_in_place(int *arr, int size) {
    int *left_ptr = arr;
    int *right_ptr = arr + size - 1;

    while (left_ptr < right_ptr) {
        // Swap elements
        swap(left_ptr, right_ptr);
        // Move pointers
        left_ptr++;
        right_ptr--;
    }
}
 
void task1_3() {

    int arr[]={1,2,3,4,5};
    int *ptr = arr;
    int sum = 0;
    printf("Array elements are: ");
    for(int i=0; i<5; i++) {
        printf("%d ", *(ptr + i));
        sum += *(ptr + i);
    }
    printf("\nSum of elements: %d\n", sum); //sum of elements

    printf("Reversed array in place is : "); //reverse array in plac
    reverse_array_in_place(ptr, 5);
    for(int i=0; i<5 ;i++){
        printf("%d ", *(ptr+i));
    }
}

int main()
{
    task1_3();
    return 0;
}