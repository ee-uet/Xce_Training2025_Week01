#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a = 5;
    int *ptr_a = &a;
    
    // Print value using direct and pointer
    printf("%d\n",a);
    printf("%d\n",*ptr_a);

    // Modify via pointer and print new value
    *ptr_a = *ptr_a + 1;
    printf("%d\n",*ptr_a);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    int swp = *a;
    *a = *b;
    *b = swp;

    printf("a = %d\n",*a);
    printf("b = %d\n",*b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int x = 0;
    int arr[] = {1,2,3,4,5};
    // Print all elements using pointers
    // Calculate sum
    int *ptr_array = arr;
    for(int i = 0; i<5; i++){
        printf("%d ",*ptr_array);
        x = *ptr_array + x;
        ptr_array++;
    }
    printf("\n");
    printf("sum is %d\n",x);
    // Reverse in place
    int temp;
    int *ptr_one = arr;
    int *ptr_two = arr + 5 - 1;

    while(ptr_one<ptr_two){
        temp = *ptr_one;
        *ptr_one++ = *ptr_two;
        *ptr_two-- = temp;
    }
    for(int i = 0; i<5; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int a = 0;
    while(*s != '\0'){
        s++;
        a++;
    }
    return a;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    char temp; ;
    while(*src != '\0'){
        temp = *src;
        *dest = temp;
        dest++;
        src++; 
    }
    *dest = '\0';
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int x = my_strlen(s1);
    int y = my_strlen(s2);
    int len_check = 0;

    if (x != y){
        return 0;
    }
    else{
        while((*s1 == *s2) & (*s1 != '\0')){
            len_check++;
            s1++;
            s2++;
        }
        if(len_check == x){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void reverse_string(char *s) {
    char *end = s + strlen(s) - 1;
    while (s < end) {
        char temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}


// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    char buf[100];
    my_strcpy(buf,s);
    reverse_string(buf);
    printf("%s   %s\n",buf,s);
    return my_strcmp(buf,s);
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x)(x*x)  
#define MAX2(a,b)(a>b?a:b) 
#define MAX3(a,b,c)((a>b?a:b)>c?(a>b?a:b):c)
#define MAX4(a,b,c,d)((a>b?a:b)>(c>d?c:d)?(a>b?a:b):(c>d?c:d))
#define TO_UPPER(c)(((c)>='a'&&(c)<='z')?((c)-32):(c))

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    int x = 2, a = 21, b = 3, c = 19, d = 31;
    char h = 'c';

    printf("SQUARE %d\n",SQUARE(x));
    printf("MAX2   %d\n",MAX2(a,b));
    printf("MAX3   %d\n",MAX3(a,b,c));
    printf("MAX4   %d\n",MAX4(a,b,c,d));
    printf("MAX2   %c\n",TO_UPPER(h));
}

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    float i,x;
    int a;
    char m[100];
    char n[100];
    char buffer[100];

    // TODO: Input 5 students
    struct Student ONE = {"ASAD",169,3.34};
    struct Student TWO = {"HASEEB",166,3.31};
    struct Student THREE = {"HASSAN",162,3.21};
    struct Student FOUR = {"NAQI",164,3.50};
    struct Student FIVE = {"ALI",161,3.99};
    // Print student with highest GPA

    i = (MAX4(MAX2(ONE.gpa,TWO.gpa),THREE.gpa,FOUR.gpa,FIVE.gpa));

    // Save to "students.txt"
    FILE *f1;
    f1 = fopen("students.txt", "w");
    if (!f1) {
        printf("Error opening file for writing.\n");
        return;
    }
    else{
        if(ONE.gpa == i){
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",ONE.name,ONE.roll,ONE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", ONE.name,ONE.roll,ONE.gpa);
        }
        else if(TWO.gpa == i){
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",TWO.name,TWO.roll,TWO.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", TWO.name,TWO.roll,TWO.gpa);
        }
        else if(THREE.gpa == i){
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",THREE.name,THREE.roll,THREE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", THREE.name,THREE.roll,THREE.gpa);
        }
        else if(FOUR.gpa == i){
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",FOUR.name,FOUR.roll,FOUR.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FOUR.name,FOUR.roll,FOUR.gpa);
        }
        else{
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",FIVE.name,FIVE.roll,FIVE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FIVE.name,FIVE.roll,FIVE.gpa);
        }
        
    }
    fclose(f1);
    
    // Read back and print
    f1 = fopen("students.txt", "r");
    if (!f1) {
        printf("Error opening file for reading.\n");
        return;
    } else {
        fgets(buffer, sizeof(buffer), f1); // skip line
        fscanf(f1, "NAME: %s   ROLL NO: %d   GPA: %f", m, &a, &x);
    }
    fclose(f1);

    printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n",
        m, a, x);


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
    if (head == NULL) 
        return NULL;

    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next != NULL) { 
        struct Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *curr = head;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;

    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);

    printf("List after insertions: ");
    print_list(head);

    head = delete_value(head, 20);
    printf("List after deleting 20: ");
    print_list(head);

    head = delete_value(head, 30);
    printf("List after deleting 30: ");
    print_list(head);

    head = delete_value(head, 10);
    printf("List after deleting 10: ");
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    double avg = (n > 0) ? (double)sum / n : 0;

    printf("Sum = %d, Average = %.2f\n", sum, avg);

    free(arr);
}

void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
     int n;
    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter new size (greater than %d): ", n);
    int new_n;
    scanf("%d", &new_n);

    arr = (int*)realloc(arr, new_n * sizeof(int));
    if (!arr) {
        printf("Reallocation failed!\n");
        return;
    }

    printf("Enter %d more integers:\n", new_n - n);
    for (int i = n; i < new_n; i++) scanf("%d", &arr[i]);

    printf("Final array: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}

#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    void *ptr = malloc(size);
    if (ptr && allocated_count < MAX_PTRS) {
        allocated_ptrs[allocated_count++] = ptr;
    }
    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (!ptr) return;
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            allocated_ptrs[i] = allocated_ptrs[allocated_count - 1]; // replace with last
            allocated_count--;
            return;
        }
    }
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count == 0) {
        printf("No memory leaks detected!\n");
    } else {
        printf("Memory leaks detected! %d block(s) not freed.\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf(" - Leak at pointer %p\n", allocated_ptrs[i]);
        }
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int*)my_malloc(5 * sizeof(int));
    int *arr2 = (int*)my_malloc(10 * sizeof(int));

    my_free(arr1);

    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

void add(int64_t *A, int32_t M) {
    *A += (int64_t)M << 32;
}


void arithmetic_right_shift(int64_t *AQ, int *Q_1) {
    int lsb = *AQ & 1;            
    *AQ >>= 1;    
    if (*AQ < 0) 
        *AQ |= (1LL << 63);
    *Q_1 = lsb;
}

int64_t booth_multiply(int32_t M, int32_t Q) {
    int64_t AQ = (int64_t)Q & 0xFFFFFFFF; 
    int Q_1 = 0;

    for (int i = 0; i < 32; i++) {
        int Q0 = AQ & 1;
        if (Q0 == 0 && Q_1 == 1) {
            add(&AQ, M);
        } else if (Q0 == 1 && Q_1 == 0) {
            add(&AQ, -M);
        }
        arithmetic_right_shift(&AQ, &Q_1);
    }
    return AQ;
}

void test_booth() {
    int32_t m1, m2;
    int64_t result;

    m1 = 3; m2 = 2;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);

    m1 = -3; m2 = 2;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);

    m1 = -4; m2 = -3;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);

    m1 = 123456; m2 = -789;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);

    m1 = INT32_MAX; m2 = INT32_MIN;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);
}

// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    // task1_1();
    // int a=5, b=10; swap(&a,&b);
    // task1_3();

    // --- Part 2 ---
    // printf("Len = %d\n", my_strlen("Hello"));
    // char buf[100]; my_strcpy(buf,"World");
    // printf("Copied: %s\n", buf);
    // int i = my_strcmp("WORLR","WORLD");
    // printf("%d\n",i);
    // printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    // task3_1_macros();
    // task3_2_fileio();

    // --- Part 4 ---
    // task4_1_linkedlist();

    // --- Part 5 ---
    // task5_1_dynamic_array();
    // task5_2_realloc_array();
    // task5_3_leak_detector();

    // --- Final Task ---
    test_booth();

    return 0;
}
