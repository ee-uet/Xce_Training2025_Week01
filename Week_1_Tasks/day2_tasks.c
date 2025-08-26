#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>  
#include <ctype.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a =10;
    int *ptra = &a;
    // Print value using direct and pointer
    printf("print value of a using direct method %d\n", a);
    printf("print value of a using pointer method %d\n", *ptra);
    // Modify via pointer and print new value
    *ptra = 15;
    printf("Updated value using pointer %d\n", *ptra);
    
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    int temp = *b;
    *b = *a;
    *a = temp;
    printf("a = %d, b = %d\n", *a, *b);

}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int arr[] = {1,2,3,4,5};
    int *ptrarr = arr;
    int size = (sizeof(arr)/4);
    // Print all elements using pointers
    printf("Array: ");
    for (int i =0; i<size; i++)
    {
        printf("%d\t", *(ptrarr+i));
        
    }
    printf("\n");
    // Calculate sum
    ptrarr = arr;
    int sum=0;
    for (int i =0; i<size; i++)
    {
        sum += *(ptrarr+i);
        
    }
    printf("sum of arr is: %d\n", sum);
    // Reverse in place
    
    int *end = ptrarr + (size-1);
    
    for(int i =0; i<(size/2); i++)
    {  
        int temp = *ptrarr;
        *ptrarr = *end;
        ptrarr++;
        *end = temp;
        end--;
        
    }
    ptrarr = arr;
    printf("Updated Reverse Array: ");
    for (int i =0; i<size; i++)
    {
        printf("%d\t", *(ptrarr+i));
        
    }
    printf("\n");
    
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int size = 0;
    while (*s != '\0')
    {
        size++;
        s++;
    }
    
    return size;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while(*src!='\0')
    {
        *dest = *src;
        dest++;
        src++;

    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}


// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char *start = s;
    const char *end = s;
    
    while(*end != '\0')
    {
        end++;
    }
    while(tolower(*start) < tolower(*end))
    {
        if(*s != *end)
        {
            return 0;
        }
        *start++;
        *end--;
    }
    return 1;
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) ((x)*(x))       
#define MAX2(a,b) (((a)>(b))?(a):(b))       
#define MAX3(a,b,c) (MAX2(MAX2((a),(b)),(c))) 
#define MAX4(a,b,c,d) (MAX2(MAX2((a),(b)),MAX2((c),(d))))  
#define TO_UPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 'a' + 'A') : (c))    

void task3_1_macros() {
    printf("SQUARE(5) = %d\n", SQUARE(5)); 
    printf("MAX2(10, 20) = %d\n", MAX2(10, 20));
    printf("MAX3(5, 15, 10) = %d\n", MAX3(5, 15, 10));
    printf("MAX4(10, 20, 30, 25) = %d\n", MAX4(10, 20, 30, 25));
    printf("TO_UPPER('a') = %c\n", TO_UPPER('a'));
    // TODO: Demonstrate macros with test cases
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
    struct Student students[5]={{"Ali",15,3.39},
                            {"Abdullah", 12, 3.90},
                            {"Bilal", 21, 3.75},
                            {"Abdullah", 7, 3.85},
                            {"Hamza", 10, 3.60}};

    // Print student with highest GPA
    int highest = 0;
    for (int i =0; i<5; i++)
    {
        if(students[i].gpa>students[highest].gpa)
        {
            highest = i;
        }
    }
    printf("Student with highest GPA: ");
    printf("Name: %s, Roll: %d, GPA: %.2f\n",students[highest].name, students[highest].roll, students[highest].gpa);

    // Save to "students.txt"
    FILE *file;
    file = fopen("students_record.txt","w");
    if(file == NULL)
    {
        printf("Failed to open file for writing\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(file);

    // Read back and print
    printf("Reading students from file:\n");
    file = fopen("students_record.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return;
    }

    struct Student temp;
    while (fscanf(file, "%49s %d %f", temp.name, &temp.roll, &temp.gpa) == 3) {
        printf("Name: %s, Roll no: %d, GPA: %.2f\n", temp.name, temp.roll, temp.gpa);
    }
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
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    if (head == NULL)
    {
        return head;
    }
    else if (head->data == value)
    {
        head = head->next;
    }
    
    struct Node *current = head;
        while(current->next != NULL && current->next->data != value)
        {
            current = current->next;
        }
        if (current->next != NULL)
        {
            
            current->next = current->next->next;
        }

    
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;

    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    head = insert_begin(head, 40);

    // Print the list
    printf("Linked list after insertion:\n");
    print_list(head);

    head = delete_value(head, 20);
    printf("Linked list after deleting 20:\n");
    print_list(head);


}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n;
    printf("Enter the number of elements of arr: ");
    scanf("%d",&n);
    int *arr =(int*)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i<n; i++)
    {
        scanf("%d",arr+i);
    }
    int sum =0;
    for (int i=0; i<n;i++)
    {
        sum+=*(arr+i);
    }
    printf("Sum is %d\n",sum);
    printf("Average is %.2f\n",(float)(sum/n));
    free(arr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int *arr = (int*)malloc(5*sizeof(int));
    for (int i=0;i<5;i++)
    {
        arr[i]= i+1;
    }
    printf("Array size before reallocation: ");
    for (int i=0;i<5;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

    int n;
    printf("Enter size for reallocation: ");
    scanf("%d",&n);
    arr = (int*)realloc(arr,n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        arr[i] = i+1;
    }
    printf("Array size after reallocation: ");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    free(arr);
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if(allocated_count>=MAX_PTRS)
    {
        printf("Memory tracking limit reached\n");
        return NULL;
    }
    void *ptr = malloc(size);
    allocated_ptrs[allocated_count] = ptr;
    allocated_count++;

    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    for(int i = 0;i<allocated_count;i++)
    {
        if(allocated_ptrs[i] == ptr)
        {
            free(ptr);
        
        for (int j = i;j<allocated_count-1;j++)
        {
            allocated_ptrs[j]=allocated_ptrs[j+1];
        }
        allocated_count--;
        return;
        
    }
}
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if(allocated_count == 0)
    {
        printf("No memory leaks\n");
        return;
    }
    printf("Memory leak detected\n");
    for(int i=0;i<allocated_count;i++)
    {
        printf("Memory leaks at adrress %p \n",allocated_ptrs[i]);
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr_1 = (int*)my_malloc(5*sizeof(int));
    double *arr_2 = (double*)my_malloc(5*sizeof(double));
    // If we remove the call of any my_free function then at output memory leak occurs 
    my_free(arr_1);
    my_free(arr_2);
    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    int carry; 
    while(b!=0)
    {
        carry = a&b;
        a = a^b;
        b = carry << 1;
    }

    return a;
}
void arithmetic_right_shift(int *AC, int *Q, int *Q1) {
    // Store LSB of Q in Q1
    *Q1 = *Q & 1;

    // Combine A and Q into 64-bit for shifting
    int64_t combined = ((int64_t)(*AC) << 32) | ((uint32_t)(*Q));
    combined >>= 1;

    // Extract back A and Q after the shift
    *AC = (int)(combined >> 32);
    *Q = (int)(combined & 0xFFFFFFFF);
}
int two_compliment(int M)
{
    int num = M;
    num = ~M;
    num = num + 0x1;
    return num;
}
long long booth_multiply(int multiplicand, int multiplier) {
    int M = multiplicand;
    int Q = multiplier;
    int AC = 0;
    int Q_1 = 0;
    int n = 32;

    for (int i = 0; i < n; i++) {
        int Q0 = Q & 1;
        
        if (Q0 == 1 && Q_1 == 0) {
            int comp_M = two_compliment(M);
            AC = AC + comp_M;
        } else if (Q0 == 0 && Q_1 == 1) {
            AC = AC + M;
        }

        arithmetic_right_shift(&AC, &Q, &Q_1);
       
    }

    
    return ((int64_t)AC << 32) | ((uint32_t)Q);
}

void test_booth() {
    long long res;
    res = booth_multiply(6, 3);
    printf("6 * 3 = %lld\n", res);

    res = booth_multiply(-6, 3);
    printf("-6 * 3 = %lld\n", res);

    res = booth_multiply(6, -3);
    printf("6 * -3 = %lld\n", res);

    res = booth_multiply(-6, -3);
    printf("-6 * -3 = %lld\n", res);

    res = booth_multiply(0, 12345);
    printf("0 * 12345 = %lld\n", res);

    res = booth_multiply(67890, 0);
    printf("67890 * 0 = %lld\n", res);

    res = booth_multiply(0, 0);
    printf("0 * 0 = %lld\n", res);

    res = booth_multiply(123, 1);
    printf("123 * 1 = %lld\n", res);

    res = booth_multiply(-123, 1);
    printf("-123 * 1 = %lld\n", res);

    res = booth_multiply(123, -1);
    printf("123 * -1 = %lld\n", res);

    res = booth_multiply(-123, -1);
    printf("-123 * -1 = %lld\n", res);

    res = booth_multiply(INT_MAX, 1);
    printf("INT_MAX * 1 = %lld\n", res);

    res = booth_multiply(INT_MIN, 1);
    printf("INT_MIN * 1 = %lld\n", res);

    res = booth_multiply(INT_MAX, INT_MAX);
    printf("INT_MAX * INT_MAX = %lld\n", res);
  
}

// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    //task1_1();
    //int a=5, b=10; swap(&a,&b);
    //task1_3();

    // --- Part 2 ---
    //printf("Len = %d\n", my_strlen("Hello"));
    //char buf[100]; my_strcpy(buf,"World");
    //printf("Copied: %s\n", buf);
    //const char *str1 = "hello"; const char *str2 = "hello"; const char *str3 = "world";
    //printf("Comparing %s and %s: %d\n", str1, str3, my_strcmp(str1, str3));
    //printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    //task3_1_macros();
    //task3_2_fileio();

    // --- Part 4 ---
    //task4_1_linkedlist();

    // --- Part 5 ---
    //task5_1_dynamic_array();
    //task5_2_realloc_array();
    //task5_3_leak_detector();

    // --- Final Task ---
    //test_booth();

    return 0;
}

