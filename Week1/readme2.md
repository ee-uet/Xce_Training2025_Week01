# Lab Experiment 02 – C Language
## Part 1: Pointer Basics and Arithmetic

### Task 1.1: Basic Pointer Usage
```
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a = 7;
    int *ptra = &a;
    // Print value using direct and pointer
    printf("Direct printed value: %d\n", a);
    printf("Value printed using pointer: %d\n", *ptra);
    // Modify via pointer and print new value
    *ptra = 10;
    printf("New value of variable: %d\n", *ptra);
}
```
### Task 1.2: Swap Two Integers Using Pointers
```
void swap(int *a, int *b) {
    printf("Value of a is %d and of b is %d\n", *a,*b);
    int c = *a;
    *a = *b;
    *b = c;
    printf("Values of a and b after swapping are %d and %d respectively\n", *a,*b);
}
```
### Task 1.3: Pointer Arithmetic on Arrays
```
void task1_3() {
    int sum = 0;
    int arr[5] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("array elements: ");
    for (int i=0;i<length;i++){
        printf("%d  ",*(arr+i));
    }
    printf("\n");

    for (int i=0;i<length;i++){
        sum += *(arr+i);
    }
    printf("Sum of array elements: %d\n",sum);

    int *start = arr;
    int *end = arr + (length - 1);
    int loop = length/2;
    for (int j=0;j<=loop;j++){
        swap(start,end);
        start++;
        end--;
    }
    printf("swapped array elements: ");
    for (int i=0;i<length;i++){
        printf("%d  ",*(arr+i));
    }
    printf("\n");
}
```
## Part 2: Pointers and Arrays/Strings
### Task 2.1: Custom String Functions
```
int my_strlen(const char *s) {
    int length = 0;
    while(*s != '\0'){
        length++;
        s++;
    }
    return length;
}

void my_strcpy(char *dest, const char *src) {
    int src_len = my_strlen(src);
    for (int i=0;i<src_len;i++){
        dest[i] = *(src+i);
    }
    dest[src_len] = '\0'; // null terminate
}

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
```
### Task 2.2: Palindrome Checker (Case-Insensitive)
```
int is_palindrome(const char *s) {
    int str_len = my_strlen(s);
    int loop = str_len/2;
    const char *start = s;
    const char *end = s + str_len - 1;
    while (loop != 0){
        if (tolower(*start) != tolower(*end)) {
            return 0; 
        }
        start++;
        end--;
        loop--;
    } 
    return 1;
}
```
## Part 3: Preprocessor & File I/O
### Task 3.1: Preprocessor Macros
```
#define SQUARE(x)   ((x)*(x))
#define MAX2(a,b)   (((a)>(b)) ? (a):(b))
#define MAX3(a,b,c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define MAX4(a,b,c,d) (MAX2(MAX2(a,b),MAX2(c,d)))
#define TO_UPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 'a' + 'A') : (c))

void task3_1_macros() {
    int x = 2+3;
    int a=3,b=6,c=5,d=2;
    printf("SQUARE macro demo : (2+3)^2 = %d\n",SQUARE(x));
    printf("MAX2 demo: %d or %d = %d\n",a,b,MAX2(a,b));
    printf("MAX3 demo: %d,%d,%d = %d\n",a,c,d,MAX3(a,d,c));
    printf("MAX4 demo: %d,%d,%d,%d = %d\n",a,b,c,d,MAX4(a,b,c,d));
    printf("TO_UPPER demo: f,D,g -> %c,%c,%c\n",TO_UPPER('f'),TO_UPPER('D'),TO_UPPER('g'));
}
```
### Task 3.2: File I/O with Struct Student
```
struct Student {
    char name[50];
    int roll;
    float gpa;
};

void task3_2_fileio() {
    struct Student students[5] = {
        {"Hiba",1,3.5},{"Sara",2,3.8},{"Usman",3,3.2},{"Ayesha",4,3.9},{"Bilal",5,3.6}
    };

    int topIndex = 0;
    for (int i = 1; i < 5; i++)
        if (students[i].gpa > students[topIndex].gpa)
            topIndex = i;

    printf("Top student:\nRoll:%d\nName:%s\nGPA:%.2f\n",students[topIndex].roll,students[topIndex].name,students[topIndex].gpa);

    FILE *fp = fopen("students.txt","w");
    for (int i=0;i<5;i++)
        fprintf(fp,"%d %s %.2f\n",students[i].roll,students[i].name,students[i].gpa);
    fclose(fp);

    char name[50], top_name[50];
    int roll, top_roll;
    float gpa, top_gpa = -1.0;
    fp = fopen("students.txt","r");
    for(int i=0;i<2;i++){
        if(fscanf(fp,"%d %s %f",&roll,name,&gpa)==3){
            if(gpa > top_gpa){
                top_gpa = gpa;
                top_roll = roll;
                int j=0; while((top_name[j]=name[j])!='\0') j++;
            }
        }
    }
    fclose(fp);
    printf("\nHighest GPA among first 2 read:\nName:%s\nRoll:%d\nGPA:%.2f\n",top_name,top_roll,top_gpa);
}
```
## Part 4: Advanced Challenge – Linked List
### Task 4.1: Simple Linked List Operations
```
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* delete_value(struct Node *head, int value) {
    if (!head) return head;
    struct Node *temp = head, *prev = NULL;
    if(temp->data == value){ head=temp->next; free(temp); return head;}
    while(temp && temp->data != value){ prev=temp; temp=temp->next;}
    if(!temp) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

void print_list(struct Node *head) {
    struct Node *current = head;
    while(current){ printf("%d -> ", current->data); current=current->next;}
    printf("NULL\n");
}
```
## Part 5: Dynamic Memory Allocation
### Task 5.1: Dynamic Array, Sum, Average
```
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n, i;
    int *arr;
    int sum = 0;
    float avg;
    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float)sum / n;
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    free(arr);
}
```
### Task 5.2: Extend Array Using Realloc
```
void task5_2_realloc_array() {
    int *arr=NULL,n,new_n;
    printf("Enter initial size of array: "); scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter new size (> %d): ",n); scanf("%d",&new_n);
    int *temp = realloc(arr,new_n*sizeof(int));
    if(!temp){ free(arr); return; }
    arr=temp;
    printf("Enter %d new elements:\n",new_n-n);
    for(int i=n;i<new_n;i++) scanf("%d",&arr[i]);
    printf("Final array: ");
    for(int i=0;i<new_n;i++) printf("%d ",arr[i]);
    printf("\n");
    free(arr);
}
```
### Task 5.3: Memory Leak Detector
```
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

// Allocate memory and track it
void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Cannot track more pointers!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr;  // track pointer
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) return;
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            // Shift remaining pointers down
            for (int j = i; j < allocated_count - 1; j++)
                allocated_ptrs[j] = allocated_ptrs[j+1];
            allocated_count--;
            return;
        }
    }
    printf("Warning: Pointer not found in tracking!\n");
}

// Report memory leaks
void report_leaks() {
    if (allocated_count == 0) {
        printf("No memory leaks detected.\n");
    } else {
        printf("Memory leak detected! %d pointer(s) not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++)
            printf("  Unfreed pointer: %p\n", allocated_ptrs[i]);
    }
}
// Demonstrate memory leak detection
void task5_3_leak_detector() {
    int *a = (int*)my_malloc(10 * sizeof(int));
    int *b = (int*)my_malloc(5 * sizeof(int));
    int *c = (int*)my_malloc(3 * sizeof(int));
    my_free(b);   // free only b, leave a and c intentionally
    report_leaks(); // should report a and c

}
```
### Main Function
```
int main() {
    // Uncomment and run tasks as you implement

    // --- P art 1 ---
    // task1_1();
    // int a=5, b=10; swap(&a,&b);
    //task1_3();

    // --- Part 2 ---
    // printf("Len = %d\n", my_strlen("Hello"));
    // char buf[100]; my_strcpy(buf,"World");
    // printf("Copied: %s\n", buf);
    // printf("%d \n", my_strcmp("aello","bello"));
    // printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    // task3_1_macros();
    // task3_2_fileio();

    // --- Part 4 ---
    /*void task4_1_linkedlist() {
        struct Node *head = NULL;
    
        head = insert_begin(head, 10);
        head = insert_begin(head, 20);
        head = insert_begin(head, 30);
    
        printf("List after insertions:\n");
        print_list(head);
    
        head = delete_value(head, 20);
        printf("List after deleting 20:\n");
        print_list(head);
    
        head = delete_value(head, 30);
        printf("List after deleting 30:\n");
        print_list(head);
    
        head = delete_value(head, 100);
        printf("List after trying to delete 100:\n");
        print_list(head);
    }*/

    // --- Part 5 ---
    // task5_1_dynamic_array();
    // task5_2_realloc_array();
    // task5_3_leak_detector();

    // --- Final Task ---
    // test_booth();

    return 0;
}
```
## Final Tasks of C-language:
### Task Y: Sequential Multiplier in C with Unit Tests
```

int add(int a, int b) {
    while (b != 0) {
        unsigned carry = a & b;  
        a = a ^ b;            
        b = carry << 1;       
    }
    return a;
}

int booth_multiply(int multiplicand, int multiplier) {
    int sign = 1;
if (multiplicand < 0) {
     multiplicand = -multiplicand; 
     sign = -sign; 
    }
if (multiplier < 0) {
    multiplier = -multiplier; 
    sign = -sign; 
}

    long int A = 0;
    int Q = multiplier;
    int M = multiplicand;
    int Q_1 = 0;
    int n = sizeof(int) * 8;  // 32 iterations

    for (int i = 0; i < n; i++) {
        int Q0 = Q & 1;

        // Decision step
        if (Q0 == 1 && Q_1 == 0) {
            A = add(A, -M);   // A = A - M
        } else if (Q0 == 0 && Q_1 == 1) {
            A = add(A, M);    // A = A + M
        }

        // Arithmetic right shift of (A, Q, Q-1)
        long int tempA = A;
        int msbA = (A >> 31) & 1;  // preserve sign

        Q_1 = Q & 1;
        Q = (A << 31) | ((unsigned)Q >> 1);
        A = (tempA >> 1) | (msbA << 31);
    }

    return sign*(add(A << 32 >> 32, Q));
}
void test_booth() {
    printf(" 5 *  3 = %d\n", booth_multiply(5, 3));   
    printf(" 5 * -3 = %d\n", booth_multiply(5, -3));  
    printf("-5 *  3 = %d\n", booth_multiply(-5, 3));  
    printf("-5 * -3 = %d\n", booth_multiply(-5, -3));
    printf(" 0 *  7 = %d\n", booth_multiply(0, 7));
}
```

