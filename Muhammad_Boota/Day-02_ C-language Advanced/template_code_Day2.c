#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a=100;
    int *ptr=&a;
    // Print value using direct and pointer
    printf("a=%d\n",a);
    printf("*ptr=%d\n",*ptr);
    // Modify via pointer and print new value
    *ptr=200;
    printf("after modification a=%d\n",a);
    printf("after modification *ptr=%d\n",*ptr);

}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    printf("before swap a=%d\n",*a);
    printf("before swap b=%d\n",*b);
    int temp= *a;
    *a=*b;
    *b=temp;
    printf("after swap a=%d\n",*a);
    printf("after swap b=%d\n",*b);

}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int arr[]={1,2,3,4,5,6};
    int *ptr=arr;
    int sum=0;
    // Print all elements using pointers
    int len=0;
    while(len<(sizeof(arr)/sizeof(int))){
        printf("%d,",*ptr);
        sum=sum+*ptr;
        ptr++;
        len++;
    }
    // Calculate sum
    printf("\nsum is equal=%d\n",sum);
    // Reverse in place
    printf("reverse the order\n");
    ptr=arr;
    int* end=ptr+len-1;
    while (end>ptr)
    {
        int temp=*ptr;
        *ptr++=*end;
        *end--=temp;
    }
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        printf("%d,",arr[i]);
    }
    
    

}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    int count=0;
    while(*s != '\0'){
        count++;
        s++;
    }
    return count;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    char** dest_addr=&dest;
    while(*src != '\0'){
        *dest++=*src;
        src++;
    }
    *dest='\0';
    dest=*dest_addr;
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int c1=my_strlen(s1);
    int c2=my_strlen(s2);
    return c1-c2;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char* end=s+my_strlen(s)-1;
    while(s<end){
      if (*s != *end){
        printf("s->%c,end->%c\n",*s,*end);
        return 0;
        
      }
      s++;
      end--;
    }
    return 1;
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) (x*x)      // TODO: Define macro, delete this comment after defining
#define MAX2(a,b) (a>b ? a:b)      // TODO: Define macro, delete this comment after defining
#define MAX3(a,b,c) (MAX2(a,b)>c ? MAX2(a,b):c)    // TODO: Define macro, delete this comment after defining
#define MAX4(a,b,c,d) (MAX3(a,b,c)>d ? MAX3(a,b,c):d)  // TODO: Define macro, delete this comment after defining
#define TO_UPPER(c) (((c)>='a' && (c)<='z')? (c-'a'+'A'):c)    // TODO: Define macro, delete this comment after defining

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("SQUARE(5)=%d\n",SQUARE(5));
    printf("MAX2(5,40)=%d\n",MAX2(5,40));
    printf("MAX3(100,5,40)=%d\n",MAX3(100,5,40));
    printf("MAX4(30,100,500,40)=%d\n",MAX4(30,100,500,40));
    printf("TO_UPPER('g')=%c\n",TO_UPPER('g'));
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
    int n=5;
    struct Student student[n];
    strcpy(student[0].name, "Ali");
    student[0].roll=1;
    student[0].gpa=3.5;

    strcpy(student[1].name, "Ahmad");
    student[1].roll=2;
    student[1].gpa=3.4;

    strcpy(student[2].name, "Umer");
    student[2].roll=3;
    student[2].gpa=3.3;

    strcpy(student[3].name, "Abdullah");
    student[3].roll=4;
    student[3].gpa=3.8;

    strcpy(student[4].name, "Usman");
    student[4].roll=5;
    student[4].gpa=3.1;

    // Print student with highest GPA
    printf("highest gpa=%f\n",MAX2(student[0].gpa,MAX4(student[1].gpa,student[2].gpa,student[3].gpa,student[4].gpa)));
    // Save to "students.txt"
    FILE* file=fopen("student.txt","w");
    if (file==NULL){
        printf("error in opening file");
    }else{
        for (int i = 0; i < n; i++)
        {
            fprintf(file,"Student[%d].name=%s ,roll no.%d, GPA:%.2f\n",i,student[i].name,student[i].roll,student[i].gpa);
        }
        
    }
fclose(file);
    // Read back and print
FILE* f=fopen("student.txt","r");
char data[50];
while (fgets(data,sizeof(data),f)!=NULL)
{
    printf("%s",data);
}

}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=value;
    node->next=head;
    head=node;
    return head;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    if (head->data==value)
    {
        return head=head->next; //first node
    }
    struct Node* prev=head;
    struct Node* curr=head->next;
    while(curr !=NULL){
        if (curr->data==value)
        {
            prev->next=curr->next;
            return head;
        }
        prev=curr;
        curr=curr->next;
    }
    printf("value did not found\n");
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    printf("linklist print\n");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node* node=NULL;
    node=insert_begin(node,45);
    print_list(node);
    node=insert_begin(node,75);
    print_list(node);
    node=insert_begin(node,90);
    print_list(node);
    node=delete_value(node,45);
    print_list(node);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    int n=5,sum=0,avg;
    int* arr=(int*)malloc(n*sizeof(int));
    // TODO: malloc array, input elements, compute sum and avg
    for (int i = 0; i < n; i++)
    {
        *(arr+i)=i;
    }
    for (int j = 0; j < n; j++)
    {
        sum=sum+arr[j];
    }
    printf("sum=%d and average=%.2f\n",sum,(float)(sum/n));
    free(arr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    int n=5;
    int* arr=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(arr+i)=i;
    }
    // TODO: realloc to extend existing array
    n=n+5;
    arr=(int*)realloc(arr,n*sizeof(int));
    for (int i = 5; i < n; i++)
    {
        *(arr+i)=i;
    }
    printf("elements in arr\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",arr[i]);
    }
    free(arr);

}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count >= MAX_PTRS)
    {
        printf("Error: Cannot track more pointers, MAX_PTRS reached\n");
        return NULL;
    }else
    {
        void* ptr=malloc(size);
        allocated_ptrs[allocated_count++]=ptr;
        return ptr;
    }
    
    
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (ptr==NULL)
    {
        return;
    }else
    {
        for (int i = 0; i < allocated_count; i++)
        {
            if (allocated_ptrs[i]==ptr)
            {
                allocated_ptrs[i]=allocated_ptrs[allocated_count-1];
                ptr=NULL;
                allocated_count--;
            }
            
        }
        
    }
    
    
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count==0)
    {
        printf("\nNo memory leaks detected.\n");
    }else
    {
        printf("\nMemory leaks detected! %d unfreed allocations:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("Leak: Unfreed memory at %p\n", allocated_ptrs[i]);
        }
    }
    
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    void* ptr1 = my_malloc(100);
    void* ptr2 = my_malloc(200);
    void* ptr3 = my_malloc(300);

    report_leaks();
    my_free(ptr1); 
    report_leaks();
    my_free(ptr3); 
    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    if (b==0)
    {
        return a;
    }else
    {
        int carry=a&b;
        a=a^b;
        b=carry<<1;
        return add(a,b);
    }  
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    int A=0;
    int Q_1=0;
    int Q=multiplier;
    int Q_0=Q&1;
    int M=multiplicand;
    int n=32;
    for (int i = 0; i < n; i++)
    {
        
        if (Q_0==1 && Q_1==0)
        {
            A=add(A,-M);
        }
        else if (Q_0==0 && Q_1==1)
        {
            A=add(A,M);
        }
        Q_1=Q_0;
        Q = (A & 1) << 31 | ((Q >> 1)& 0x7fffffff); 
        A=(A>>1);
        Q_0=Q&1;
    }        
    return Q;

}

void test_booth() {
    // TODO: Write test cases for booth_multiply
    // Include positive, negative, zero, overflow cases
    for (int i = -10; i < 65536; i++)
    {
        for (int j = -100; j < 65535; j++)
        {
            printf("%d*%d=%d\n",i,j,booth_multiply(i,j));
        }
        
        
    }
    
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
    // printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    // task3_1_macros();
    // task3_2_fileio();

    // --- Part 4 ---
    // task4_1_linkedlist();

    // --- Part 5 ---
    // task5_1_dynamic_array();
    // task5_2_realloc_array();
     task5_3_leak_detector();

    // --- Final Task ---
    // test_booth();

    return 0;
}
