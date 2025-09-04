
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int num = 45;
    int *num_ptr = &num;
    printf("num = %d ,through pointer num = %d \n",num,*num_ptr);
    // Print value using direct and pointer
    // Modify via pointer and print new value
    *num_ptr = 54;
    printf("num = %d ,through pointer num = %d",num,*num_ptr);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
     printf("num a = %d , num b = %d \n",*a,*b);
     int temp;
    temp = *a;
    *a = *b;
    *b = temp;
     printf("after swaping num a = %d , num b = %d",*a,*b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int array [5]={11,12,13,14,15};
    int *array_ptr = array;
    printf("elements of array are");
    for (int i=0;i<=4;i++){
        printf(" %d ",*(array_ptr+i));
    }
    int sum = 0;
    for (int i=0;i<=4;i++){
        sum = sum + *(array_ptr+i) ;
    }
    printf(" \n sum = %d",sum);
    // Print all elements using pointers
    // Calculate sum
    
    int *end_ptr = NULL;
    
    end_ptr = (array + 4);
    while(array_ptr < end_ptr){
        int temp = *array_ptr;
        *array_ptr++ = *end_ptr;
        *end_ptr-- = temp;
    }
    int *point = array;
     printf(" \n elements of array are");
    for (int i=0;i<=4;i++){
        printf(" %d ",*(point+i));
    }
    
    // Reverse in place
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int length =0;
    while(*s != '\0'){
        
      length = length + 1 ;
      s++;
    }
    return length;
}

void reverse_string(char *ptr_arr){
    int len = my_strlen(ptr_arr);
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
    for (int i=0;i<5;i++){
       * (dest + i) = *(src + i);
    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int length_s1 = my_strlen(s1);
    int length_s2 = my_strlen(s2);
    int length = 0;
    if (length_s1==length_s2){
        
        while(*s1 == *s2 & *s1 != '\0'){
             length++;
             s1++;
             s2++;
        }
        if (length == length_s1){
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
          return 0;
    }
    
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    char rev_str[100];
    my_strcpy(rev_str, s);
    reverse_string(rev_str);
    return my_strcmp(s, rev_str);
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) (x*x)    // TODO: Define macro, delete this comment after defining
#define MAX2(a,b)   (a > b ? a : b)    // TODO: Define macro, delete this comment after defining
#define MAX3(a,b,c)   (MAX2(a,b) > c ? MAX2(a,b) :c)  // TODO: Define macro, delete this comment after defining
#define MAX4(a,b,c,d)   (MAX3(a,b,c) > d ? MAX3(a,b,c) : d)// TODO: Define macro, delete this comment after defining
#define TO_UPPER(c)    (c > 'a' && c < 'z' ? c - 'a' +'A' : c) // TODO: Define macro, delete this comment after defining

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("square of  %d = %d",2,SQUARE(2));
    printf("\nMaxamum between %d and %d is = %d",45,7,MAX2(45,7));
    printf("\nMaximum %d and %d and %d is = %d",6,45,7,MAX3(45,6,7));
   printf("\nMaxamum between %dand %d and %d and %d is = %d",45,68,90,7,MAX4(45,90,68,7));
   printf("\n lets convert %C into %c",'d',TO_UPPER('d'));
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
    struct Student no_1 = {"A",100,3.22};
    struct Student no_2 = {"B",101,3.32};
    struct Student no_3 = {"C",102,3.42};
    struct Student no_4 = {"D",103,3.52};
    struct Student no_5 = {"E",104,3.62};

    // Print student with highest GPA
    float temp = MAX4(no_1.gpa,no_2.gpa,no_3.gpa,no_4.gpa);
    float max = MAX2(temp,no_5.gpa);
    printf("%.2f\n", max);
    // Save to "students.txt"
    FILE *ptr;
    ptr = fopen("student.txt","w");
    
    fprintf(ptr, "%s\n",no_1.name);
    fprintf(ptr, "%d\n",no_1.roll);
    fprintf(ptr, "%f\n",no_1.gpa);

    fprintf(ptr, "%s\n",no_2.name);
    fprintf(ptr, "%d\n",no_2.roll);
    fprintf(ptr, "%f\n",no_2.gpa);

    fprintf(ptr, "%s\n",no_3.name);
    fprintf(ptr, "%d\n",no_3.roll);
    fprintf(ptr, "%f\n",no_3.gpa);

    fprintf(ptr, "%s\n",no_4.name);
    fprintf(ptr, "%d\n",no_4.roll);
    fprintf(ptr, "%f\n",no_4.gpa);

    fprintf(ptr, "%s\n",no_5.name);
    fprintf(ptr, "%d\n",no_5.roll);
    fprintf(ptr, "%f\n",no_5.gpa);
    fclose(ptr);


    
    // Read back and print
    
    char name_of_student[100];
    int roll_of_stdnt;
    float gpa_of_stdnt;
    ptr = fopen("student.txt", "r");
    fscanf(ptr, "%s", name_of_student);
    fscanf(ptr, "%d", &roll_of_stdnt);
    fscanf(ptr, "%f", &gpa_of_stdnt);
    fclose(ptr);

    printf("Reading a file\n");
    printf("Name =\t%s\n",name_of_student);
    printf("roll =\t%d\n", roll_of_stdnt);
    printf("gpa =\t%.2f\n", gpa_of_stdnt);
    
}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = value;
    new_node -> next = head;

    return new_node;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && head->data == value){
        head = temp->next;
        free(temp);
        return head;
    }
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;

    }
    if(temp==NULL){
        printf("%d not found in linked list",value);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;

}

void print_list(struct Node *head) {
    // TODO: Print linked list
     struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node* head = NULL;

    head = insert_begin(head,1);
    head = insert_begin(head, 2);
    head = insert_begin(head, 3);

    printf("List after insertions: ");
    print_list(head);  

    head = delete_value(head, 2);
    printf("List after deleting 2: ");
    print_list(head);  

    head = delete_value(head, 50); 
    printf("List after trying to delete 50: ");
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int *arr;
    int n;
    int sum=0;
    float average;
    int i;
    printf("Enter size of your array ");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
    }
    printf("enter %d integers",n);
    for(i=0;i<n;i++){
        scanf("%d ",&arr[i]);
        sum += arr[i];
    }
    average = (float) sum/n;
    printf("sum = %d and average = %f",sum,average);

}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int *arr;
    int n, newSize, i;

    printf("Enter size of your array: ");
    
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Your original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int extra;
    printf("How many extra elements do you want to add? ");
    scanf("%d", &extra);

    newSize = n+extra;
    arr = (int*)realloc(arr,newSize*sizeof(int));
    printf("Enter %d more integers: ", extra);
    
    for (i = n; i < newSize; i++) {
        scanf("%d", &arr[i]);
    }

    // Print final array
    printf("Final array: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    void *ptr = malloc(size);
    if(ptr != NULL && allocated_count<MAX_PTRS){
         allocated_ptrs[allocated_count++] = ptr;
    }
    return NULL;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if(ptr == NULL){
        return ;
    }
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);  

            
            for (int j = i; j < allocated_count - 1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j+1];
            }

            allocated_count--;  
            return;
        }
    }
    printf("Warning: Attempted to free untracked memory!\n");
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count == 0) {
        printf("No memory leaks detected.\n");
    }
    else {
        printf(" Memory leak detected! %d block(s) not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  Leak at address: %p\n", allocated_ptrs[i]);
        }
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int*)my_malloc(5*sizeof(int));
    int *arr2 = (int*)my_malloc(10*sizeof(int));
    my_free(arr1);
    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    return 0;
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    return 0;
}

long test_booth(int multiplicand, int multiplier) {
    // TODO: Write test cases for booth_multiply
    int64_t A = 0;
    int32_t Q = multiplier;
    int32_t M = multiplicand;
    int Q_1 = 0;
    int count = 32;

    while (count > 0) {
        if ((Q & 1) == 1 && Q_1 == 0) {
            A -= M;
        } else if ((Q & 1) == 0 && Q_1 == 1) {
            A += M;
        }

        // Save LSB before shift
        Q_1 = Q & 1;

        
        int64_t combined = (A << 32) | (uint32_t)Q;
        combined >>= 1;   
        A = combined >> 32;
        Q = (int32_t)(combined & 0xFFFFFFFF);

        count--;
    }

    return (A << 32) | (uint32_t)Q;
    // Include positive, negative, zero, overflow cases
}


// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    // task1_1();
     //int a=5, b=10; swap(&a,&b);
    // task1_3();

    // --- Part 2 ---
     //printf("Len = %d\n", my_strlen("Hello"));
     //char buf[100]; my_strcpy(buf,"World");
    // printf("Copied: %s\n", buf);
   // int g = my_strcmp("buffalo","buffalo");
   // printf("if answere is 1 means string is same ...Ans = %d",g);
    // printf("Palindrome? %s\n", is_palindrome("madam") ? "Yes":"No");

    // --- Part 3 ---
    // task3_1_macros();
    //task3_2_fileio();

    // --- Part 4 ---
    //task4_1_linkedlist();

    // --- Part 5 ---
     //task5_1_dynamic_array();
   // task5_2_realloc_array();
   // task5_3_leak_detector();

    // --- Final Task ---
    
    int a = 5, b = 3;
    long result = test_booth(a, b);
    printf("%d x %d = %ld \n", a, b, result);

    a = 5; b = -3;
    result = test_booth(a, b);
    printf("%d x %d = %ld \n", a, b, result);

    

    return 0;
}

