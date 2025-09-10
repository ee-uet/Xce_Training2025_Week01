#include <stdio.h>

void task1_1() {
    int a = 10;
    int *ptr = &a;
    
    // Printing value of a directly
    printf("Direct value is %d\n", a);
    // Printing valu of a through pointer
    printf("Value by using pointer is %d\n", *ptr);

    // Changing the value through pointer and printing it
    *ptr = 20;
    printf("New value is %d\n", a);
}

void swap(int *a, int *b) {
    // Swapping the values of a and b
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a = %d\nb = %d\n", *a, *b);
}

void task1_3() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements of array

    for (int i = 0; i < n; i++) {
        printf("%d\n", *p);
        p++;
    }

    int sum = 0;
    p = arr;
    for (int i = 0; i < n; i++) {
        sum += *p;
        p++;
    }
    printf("Sum is %d\n", sum);

    // Reverse in place
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Reversed array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main(){
    task1_1();
    int a = 5, b = 10;
    swap(&a, &b);
    task1_3();
    return 0;
}
