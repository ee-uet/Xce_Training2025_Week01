
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a = 10;
    int *ptr_a = &a;
    // Print value using direct and pointer
    printf("a = %d\n", a);
    printf("ptr_a = %d\n", *ptr_a);
    // Modify via pointer and print new value
    *ptr_a = 20;
    printf("a = %d\n", a);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    printf("Before: \n");
    printf("a = %d and b = %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After: \n");
    printf("a = %d and b = %d\n", *a, *b);

}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    //int len = 5
    int arr[5] = {1,2,3,4,5};
    // Print all elements using pointrs
    int *ptr_arr = arr;
    int sum = 0;
    
    printf("All elements in array\n");
    for(int i=0; i<5; i++){
        sum = sum + *(ptr_arr+i);
        printf("%d\n", *(ptr_arr+i));
    }
    // Calculate sum
    printf("sum = %d\n", sum);


    // Reverse in place
    
    int *end = ptr_arr + (5 - 1);
    while(ptr_arr < end){
        int temp = *ptr_arr;
        *ptr_arr++ = *end;
        *end-- = temp;

    }
    printf("reversed elements in array\n");
    for(int i=0; i<5; i++){
        
        printf("%d\n", arr[i]);
    }

}


// ======================= Part 2: Pointers and Arrays/Strings =======================



// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int len = 0;
    while(*s != '\0'){
        s++;
        len++;
    }
    return len;
}

void reverse_string(char *ptr_arr){
    int len = my_strlen(ptr_arr);
    //printf("%d\n", len);
    char *end = ptr_arr + (len - 1);
    while(ptr_arr < end){
        char temp = *ptr_arr;
        *ptr_arr++ = *end;
        *end-- = temp;
    }
}
// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while(*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int len1, len2;
    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    if (len1 == len2){
        for(int i=0; i<len1; i++){
            if(*(s1+i) != *(s2+i)){
                return 0;
            }
            else{
                continue;
            }

        }  
        return 1;
    }
    else{
        return 0;
    }

    
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    
    char buf[100];
    my_strcpy(buf, s);
    reverse_string(buf);
    return my_strcmp(s, buf);
    
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) (x*x)       
#define MAX2(a,b) (a > b ? a : b)
#define MAX3(a,b,c) (MAX2(a, b) > c ? MAX2(a, b) : c)
#define MAX4(a,b,c,d) (MAX2(a, b) > MAX2(c, d) ? MAX2(a, b) : MAX2(c, d))
#define MAX5(a,b,c,d,e) (MAX3(a, b, c) > MAX2(d, e) ? MAX3(a, b, c) : MAX2(d, e))
#define TO_UPPER(c) (c > 'a' && c < 'z'? c - 'a' + 'A': c)

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("square = %d\n", SQUARE(2));
    printf("Max2 = %d\n", MAX2(1, 2));
    printf("Max3 = %d\n", MAX3(1,2,3));
    printf("Max4 = %d\n", MAX4(1,2,3,4));
    printf("Max5 = %d\n", MAX5(1,2,3,4,5));
    printf("upper = %c\n", TO_UPPER('b'));

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
    struct Student s1 = {"hamza",165,3.8};
    struct Student s2 = {"naqi",164,3.5};
    struct Student s3 = {"haseeb",166,3.3};
    struct Student s4 = {"asad",169,3.4};
    struct Student s5 = {"hassan",162,3.2};
    // Print student with highest GPA
    float h_gpa = MAX5(s1.gpa, s2.gpa, s3.gpa, s4.gpa, s5.gpa);
    printf("%.2f\n", h_gpa);
    FILE *fp;
    fp = fopen("students.txt", "w");
    struct Student *top = NULL;
    if(s1.gpa == h_gpa) top = &s1;
    else if(s2.gpa == h_gpa) top = &s2;
    else if(s3.gpa == h_gpa) top = &s3;
    else if(s4.gpa == h_gpa) top = &s4;
    else if(s5.gpa == h_gpa) top = &s5;
    printf("Name =\t%s\n", top->name);
    printf("Roll =\t%d\n", top->roll);
    printf("GPA  =\t%.2f\n", top->gpa);

    fprintf(fp, "%s\n",top->name);
    fprintf(fp, "%d\n", top->roll);
    fprintf(fp, "%.2f", top->gpa);
    fclose(fp);

    char std_name[100];
    int std_roll;
    float std_gpa;
    fp = fopen("students.txt", "r");
    fscanf(fp, "%s", std_name);
    fscanf(fp, "%d", &std_roll);
    fscanf(fp, "%f", &std_gpa);
    fclose(fp);
    
    printf("Reading a file\n");
    printf("Name =\t%s\n", std_name);
    printf("Name =\t%d\n", std_roll);
    printf("Name =\t%.2f\n", std_gpa);

}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode; 
}
    


struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) 
    return head;

    if (head->data == value) {
        temp = head->next;
        head->next = NULL;
        return temp;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;  
    }
    else{
        prev->next = temp->next;
        temp = NULL;
        return head;
    }

}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;

    head = insert_begin(head, 1);
    head = insert_begin(head, 2);
    head = insert_begin(head, 3);

    head = delete_value(head, 2);
    print_list(head);


}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int len;
    int element;
    printf("enter the size of array: \n");
    scanf("%d", &len);
    int *ptr = (int *)malloc(len*sizeof(int));
    printf("enter array elements step by step: \n");
    for(int i=0; i<len; i++){
        scanf("%d", &element);
        *(ptr+i) = element;
    }
    int sum = 0;
    float avg;
    for(int i=0; i<len; i++){
        sum = sum + *(ptr+i);
    }
    avg = (float)sum/len;
    printf("Sum =\t%d\n", sum);
    printf("Avg =\t%.2f\n", avg);
    free(ptr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int n = 5,x=1;
    int *ptr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n;i++){
        *(ptr+i) = x;
        x++;
    }
    printf("Array before: \n");
    for(int i=0; i<n;i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");
    n = 10;
    ptr = (int *)realloc(ptr, n*sizeof(int));
    for(int i=5; i<n;i++){
        *(ptr+i) = x;
        x++;
    }
    printf("Array After: \n");
    for(int i=0; i<n;i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");


}

// Memory Leak Detector 
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count >= MAX_PTRS) {
        printf("Too many allocations!\n");
        return NULL;
    }

    void *ptr = malloc(size);
    allocated_ptrs[allocated_count++] = ptr;  
        
    return ptr;
}

    
 
void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (ptr == NULL) 
        return;

    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);

            for (int j = i; j < allocated_count - 1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            }
            allocated_count--;
            
        }
        printf("Warning: Tried to free untracked pointer %p\n", ptr);
    }
    
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count == 0) {
        printf("No memory leaks detected \n");
    } else {
        printf("Memory leaks detected: %d allocated ptrs are not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  Leak: pointer at %p\n", allocated_ptrs[i]);
        }
    }

}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int*) my_malloc(5 * sizeof(int));
    int *arr2 = (int*) my_malloc(10 * sizeof(int));

    my_free(arr1);   
    report_leaks(); 
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    int carry;
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int sub(int a, int b) {
    return add(a, add(~b, 1));
}

void arithmetic_shift(int *A, int *Q, int *Q_1, int *Q_0) {
    int msb_A = ((*A) >> 31) & 0x80000000;   
    int lsb_Q = *Q & 1;

    *Q = ((unsigned int)(*Q) >> 1) | ((*A & 1) << 31);
    *A = (*A >> 1) | msb_A;

    *Q_1 = *Q_0;
    *Q_0 = *Q & 1;
}

long booth_multiply(int M, int Q) {
    int n = 32;
    int A = 0, Q_1 = 0;
    int Q_0 = Q & 1;
    for (int i = 0; i < n; i++) {
        
        if (Q_0 == 1 && Q_1 == 0) {
            A = sub(A, M);
        } else if (Q_0 == 0 && Q_1 == 1) {
            A = add(A, M);
        }

        arithmetic_shift(&A, &Q, &Q_1, &Q_0);
    }

    long result = ((long)A << 32) | Q;
    return result;
}

void test_booth() {
    int a = 5, b = 3;
    long result = booth_multiply(a, b);
    //long expected = (long) a * (long) b;

    printf("%d x %d = %ld\n", a, b, result);
    a = 5;
    b = -3;
    result = booth_multiply(a, b);
    //expected = (long) a * (long) b;
    printf("%d x %d = %ld\n",a ,b, result);
    a = 5;
    b = 0;
    result = booth_multiply(a, b);
    //expected = (long) a * (long) b;
    printf("%d x %d = %ld\n",a ,b, result);
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
    //int i = my_strcmp("hello", "hello"); printf("%d\n", i);
    
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
    test_booth();

    return 0;
}