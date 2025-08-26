#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdint.h>


// ======================= Part 1: Pointer Basics and Arithmetic =======================

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


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int i = 0;
    while( *(s+i) != '\0')
    {
        i += 1;
    }
    return i;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest+i) = *(src+i);
        i += 1;
    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int i = 0;
    while ( (*(s1+i)!='\0') && (*(s2+i)!='\0') )
    {
        int temp = (int)(*(s1+i) - *(s2+i));
        if (temp && temp!=32 && temp!=-32)
        {
            return temp;       
        }
        i += 1;
    }
    return 0;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    int len = my_strlen(s);
    int check;
    char* rs = (char*)malloc(len);
    my_strcpy(rs,s);
    for (int i=0;i<len;i++)
    {
        *(rs+i) = *(s+len-1-i);
    }
    check = my_strcmp(s,rs);
    free(rs);
    if (check)
    {
        return 0;
    }
    else {
        return 1;
    }
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) x*x       
#define MAX2(a,b) a>b? a:b
#define MAX3(a,b,c) MAX2(a,b)>c? MAX2(a,b):c
#define MAX4(a,b,c,d) MAX3(a,b,c)>d? MAX3(a,b,c):d
#define TO_UPPER(c) (c>96 && c<123)? c-32:c

void task3_1_macros() {
    int a = 5;
    int b = 6;
    int c = 17;
    int d = 8;
    char x = 'z';
    printf("Square of %d = %d\n",a,SQUARE(a));
    printf("Max2(%d,%d) = %d\n",a,b,MAX2(a,b));
    printf("Max3(%d,%d,%d) = %d\n",a,b,c,MAX3(a,b,c));
    printf("Max4(%d,%d,%d.%d) = %d\n",a,b,c,d,MAX4(a,b,c,d));
    printf("To_UPPER(%c) = %c\n",x,TO_UPPER(x));
}

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    // TODO: Input 5 students
    // Print student with highest GPA
    // Save to "students.txt"
    // Read back and print
    FILE *file = NULL;
    struct Student array[5] = {{"x",1,3.0},{"y",2,3.8},{"z",3,3.2},{"a",4,3.1},{"b",5,3.6}};
    float max = array[0].gpa;
    int count = 5;
    file = fopen("students.txt","w");
    for (int i=0;i<count;i++)
    {
        if (array[i].gpa > max)
        {
            max = array[i].gpa;
        }
        fprintf(file,"Name: %s\nRoll: %d\nGPA: %f\n\n",array[i].name,array[i].roll,array[i].gpa);
    }
    printf("highest GPA = %.1f\n",max);
    fclose(file);

}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    if (head != NULL)
    {
        new->next = head;
    }
    return new;
}

void delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr2 = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    ptr2 = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            ptr2->next = ptr->next;
            ptr->next = NULL;
            break;
        }
        ptr2 = ptr;
        ptr = ptr->next;
    }
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    free(ptr);
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;
    head = insert_begin(head,10);
    head = insert_begin(head,12);
    head = insert_begin(head,13);
    //delete_value(head,12);
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

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


// ======================= Final Task: Booth's Multiplication =======================
#include <stdint.h>

int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;   // Calculate carry bits
        a = a ^ b;          // Calculate sum without carry
        b = carry << 1;     // Shift carry to next position
    }
    return a;
}

int shift(int* ptrA, int* ptrQ, int Q_lsb) {
    int Qm1 = Q_lsb;     // Store current Q_lsb as Qm1 for next iteration
    int A_lsb = *ptrA & 1; // Get LSB of A
    *ptrA = *ptrA >> 1;  // Arithmetic right shift A (preserves sign)
    *ptrQ = (uint32_t)*ptrQ >> 1; // Logical right shift Q
    if (A_lsb) {
        *ptrQ |= (1U << 31); // Set MSB of Q if A_lsb is 1
    }
    return Qm1;
}

long int booth_multiply(int multiplicand, int multiplier) {
    int A = 0;           // Accumulator
    int Q = multiplier;  // Multiplier
    int M = multiplicand;// Multiplicand
    int n = 32;          // Number of bits
    int Qm1 = 0;         // Previous LSB of Q

    for (int i = 0; i < n; i++) {
        int Q_lsb = Q & 1; // Get LSB of Q
        if (Q_lsb == 0 && Qm1 == 1) {
            A = add(A, M); // Add M to A
        } else if (Q_lsb == 1 && Qm1 == 0) {
            // Subtract M by adding two's complement of M
            A = add(A, add(~M, 1)); // A - M = A + (-M) = A + (~M + 1)
        }
        Qm1 = shift(&A, &Q, Q_lsb); // Shift A and Q, update Qm1
    }

    // Combine A and Q into 64-bit result with proper sign extension
    int64_t result = ((int64_t)A << 32) | ((uint32_t)Q & 0xFFFFFFFF);
    return result;
}

void test()
{
    int a;
    int b;
    while(1)
    {
        printf("Enter integer1: ");
        scanf("%d",&a);
        printf("Enter integer2: ");
        scanf("%d",&b);
        printf("%d x %d = %ld\n",a,b,booth_multiply(a,b));
    }
}

void test_booth() {
    // Test case 1: Positive numbers
    printf("Test 1: 5 * 3\n");
    if (booth_multiply(5, 3) == 15) {
        printf("Passed: 5 * 3 = 15\n");
    } else {
        printf("Failed: 5 * 3, expected 15, got %ld\n", booth_multiply(5, 3));
    }

    // Test case 2: Negative multiplicand
    printf("Test 2: -5 * 3\n");
    if (booth_multiply(-5, 3) == -15) {
        printf("Passed: -5 * 3 = -15\n");
    } else {
        printf("Failed: -5 * 3, expected -15, got %ld\n", booth_multiply(-5, 3));
    }

    // Test case 3: Negative multiplier
    printf("Test 3: 5 * -3\n");
    if (booth_multiply(5, -3) == -15) {
        printf("Passed: 5 * -3 = -15\n");
    } else {
        printf("Failed: 5 * -3, expected -15, got %ld\n", booth_multiply(5, -3));
    }

    // Test case 4: Both negative
    printf("Test 4: -5 * -3\n");
    if (booth_multiply(-5, -3) == 15) {
        printf("Passed: -5 * -3 = 15\n");
    } else {
        printf("Failed: -5 * -3, expected 15, got %ld\n", booth_multiply(-5, -3));
    }

    // Test case 5: Multiplication by zero
    printf("Test 5: 42 * 0\n");
    if (booth_multiply(42, 0) == 0) {
        printf("Passed: 42 * 0 = 0\n");
    } else {
        printf("Failed: 42 * 0, expected 0, got %ld\n", booth_multiply(42, 0));
    }

    // Test case 6: Zero multiplicand
    printf("Test 6: 0 * 42\n");
    if (booth_multiply(0, 42) == 0) {
        printf("Passed: 0 * 42 = 0\n");
    } else {
        printf("Failed: 0 * 42, expected 0, got %ld\n", booth_multiply(0, 42));
    }

    // Test case 7: Multiplication by 1
    printf("Test 7: 123 * 1\n");
    if (booth_multiply(123, 1) == 123) {
        printf("Passed: 123 * 1 = 123\n");
    } else {
        printf("Failed: 123 * 1, expected 123, got %ld\n", booth_multiply(123, 1));
    }

    // Test case 8: Multiplication by -1
    printf("Test 8: 123 * -1\n");
    if (booth_multiply(123, -1) == -123) {
        printf("Passed: 123 * -1 = -123\n");
    } else {
        printf("Failed: 123 * -1, expected -123, got %ld\n", booth_multiply(123, -1));
    }

    // Test case 9: Edge case - Large positive numbers
    printf("Test 9: 46340 * 46340\n");
    if (booth_multiply(46340, 46340) == 2147395600LL) {
        printf("Passed: 46340 * 46340 = 2147395600\n");
    } else {
        printf("Failed: 46340 * 46340, expected 2147395600, got %ld\n", booth_multiply(46340, 46340));
    }

    // Test case 10: Edge case - Negative and positive
    printf("Test 10: -46340 * 46340\n");
    if (booth_multiply(-46340, 46340) == -2147395600LL) {
        printf("Passed: -46340 * 46340 = -2147395600\n");
    } else {
        printf("Failed: -46340 * 46340, expected -2147395600, got %ld\n", booth_multiply(-46340, 46340));
    }

    // Test case 11: Edge case - INT32_MAX * 1
    printf("Test 11: INT32_MAX * 1\n");
    if (booth_multiply(INT32_MAX, 1) == (long int)INT32_MAX) {
        printf("Passed: INT32_MAX * 1 = %ld\n", (long int)INT32_MAX);
    } else {
        printf("Failed: INT32_MAX * 1, expected %ld, got %ld\n", (long int)INT32_MAX, booth_multiply(INT32_MAX, 1));
    }

    // Test case 12: Edge case - INT32_MIN * 1
    printf("Test 12: INT32_MIN * 1\n");
    if (booth_multiply(INT32_MIN, 1) == (long int)INT32_MIN) {
        printf("Passed: INT32_MIN * 1 = %ld\n", (long int)INT32_MIN);
    } else {
        printf("Failed: INT32_MIN * 1, expected %ld, got %ld\n", (long int)INT32_MIN, booth_multiply(INT32_MIN, 1));
    }

    printf("All test cases completed!\n");
}


// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    // task1_1();
    //int a=5, b=10;
    //printf("a = %d , b = %d\n",a,b);
    //swap(&a,&b);
    //printf("a = %d , b = %d\n",a,b);
    //task1_3();

    // --- Part 2 ---
    // printf("Len = %d\n", my_strlen("Hello"));
    // char buf[100]; my_strcpy(buf,"World");
    // printf("Copied: %s\n", buf);
    //printf("%d\n",my_strcmp("aDc","adg"));
    //printf("Palindrome? %s\n", is_palindrome("Mam") ? "Yes":"No");

    // --- Part 3 ---
    //task3_1_macros();
     //task3_2_fileio();

    // --- Part 4 ---
    // task4_1_linkedlist();

    // --- Part 5 ---
    // task5_1_dynamic_array();
    // task5_2_realloc_array();
     task5_3_leak_detector();

    // --- Final Task ---
    //test_booth();

    //printf("%d\n",add(INT32_MIN,1));

    //test();

    return 0;
}
