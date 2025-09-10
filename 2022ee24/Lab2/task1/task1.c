#include <stdio.h>

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int n = 10;
    int* ptr = &n;
    printf("n = %d\n",n);
    printf("n = %d\n",*ptr);
    *ptr = 20;
    printf("n = %d\n",*ptr);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place
    int array[9];
    int* ptr = array;
    int sum = 0;
    int size = (sizeof(array)/sizeof(int));
    for (int i=0;i<(sizeof(array)/sizeof(int));i++)
    {
        printf("Enter element%d: ",i);
        scanf("%d",&array[i]);
    }

    for(int j=0;j<(sizeof(array)/sizeof(int));j++)
    {
        printf("%d ",*(ptr+j));
        sum += *(ptr+j);
    }
    printf("\n");
    printf("Sum = %d\n",sum);
    for(int k=0;k<size/2;k++)
    {
        int temp = *(ptr+k); 
        *(ptr+k) = *(ptr + size-1-k);
        *(ptr + size-1-k) = temp;
    }
    for(int x=0;x<(sizeof(array)/sizeof(int));x++)
    {
        printf("%d ",*(ptr+x));
    }
    printf("\n");
}

int main()
{
    task1_1();
    int a=5, b=10;
    printf("a = %d , b = %d\n",a,b);
    swap(&a,&b);
    printf("a = %d , b = %d\n",a,b);
    task1_3();
    return 0;
}