#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int a = 4;
    int *p = &a;

    printf("direct value: %d\n",a);
    printf("using pointer: %d\n",*p);

    *p = 6;
    printf("new value: %d\n",a);
}

void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("a = %d\n",*a);
    printf("b = %d\n",temp);
}

void task1_3() {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place

    int arr[] = {2,3,6};
    int *ptr = arr;
    int sum = 0;
    printf("elements are: ");
    while (*ptr!='\0'){
        printf("%d ",*ptr);
        sum = sum + (*ptr);
        ptr++;
        
    }
    printf("\nsum is %d",sum);
    
}

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int length = 0;
    while (*s!='\0'){
        length += 1;
        s++;
    }
    printf("length is: %d",length);
    return 0;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    char *p = dest;
    while(*src!='\0'){
        *dest = *src;
        src++;
        dest++;
    }
    
    printf("copied string is %s",p);
    // TODO: Implement strcpy
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            printf("%d ", (int)(*s1) - (int)(*s2));
        }
        s1++;
        s2++;
    }
    printf("%d ", (int)(*s1) - (int)(*s2));}

int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char *end = s + strlen(s)-1;
    while(s<end){
        if (*s==*end){
            s++;
            end--;
        }
        else{
            printf("not palindrome");
            break;
        }
    }

    return 0;
}
#define SQUARE(x)      x*x // TODO: Define macro, delete this comment after defining
#define MAX2(a,b)      (a>b)?a:b // TODO: Define macro, delete this comment after defining
#define MAX3(a,b,c)     ((a>b && a>c)?a:(b>c ? b:c))// TODO: Define macro, delete this comment after defining
#define MAX4(a,b,c,d)   ((a>b && a>c && a>d)?a:((b>c && b>d)?b:((c>d)?c:d)))// TODO: Define macro, delete this comment after defining
#define TO_UPPER(c)     ((int) (c)>=97 && (int)(c)<=122)?(char) (c-32):(char)(c)// TODO: Define macro, delete this comment after defining

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    int s=SQUARE(4);
    char n = TO_UPPER('D');
    printf("greater number is: %d\n",MAX2(4,5));
    printf("greater of three number is: %d\n",MAX3(7,6,9));
    printf("greatest of four number is: %d\n",MAX4(4,3,7,5));
    printf("upper case is: %c\n",n);
}

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};
void task3_2_fileio() {
    // TODO: Input 5 students
    // Print student with highest GPA
    // Save to "students.txt"
    // Read back and print
    struct Student s1={"asad",169,3.4};
    struct Student s2={"haseeb",166,3.3};
    struct Student s3={"hassan",162,3.62};
    struct Student s4={"ali",161,3.5};
    struct Student s5={"ahmad",163,3.6};

    if(s1.gpa>s2.gpa && s1.gpa>s3.gpa && s1.gpa>s4.gpa && s1.gpa>s5.gpa){
        printf("%s has highest gpa",s1.name);
    }
    else if(s2.gpa>s3.gpa && s2.gpa>s4.gpa && s2.gpa>s5.gpa){
        printf("%s has highest gpa",s2.name);
    }
    else if(s3.gpa>s4.gpa && s3.gpa>s5.gpa){
        printf("%s has highest gpa",s3.name);
    }
    else if(s4.gpa>s5.gpa){
        printf("%s has highest gpa",s4.name);
    }
    else{
        printf("%s has highest gpa",s5.name);
    }
    FILE *file;

    file = fopen("student.txt","w");
    if(file==NULL){
        printf("there is an error");
        return ;
    }
    fprintf(file,"%s %d %f",s1.name,s1.roll,s1.gpa);
    fprintf(file,"%s %d %f",s2.name,s2.roll,s2.gpa);
    fprintf(file,"%s %d %f",s3.name,s3.roll,s3.gpa);
    fprintf(file,"%s %d %f",s4.name,s4.roll,s4.gpa);
    fprintf(file,"%s %d %f",s5.name,s5.roll,s5.gpa);
    
    fclose(file);

    struct Student temp;
    file = fopen("student.txt","r");
    if(file==NULL){
        printf("Error opening file for reading\n");
        return;
    }

    printf("\nReading data back from file:\n");
    while(fscanf(file,"%s %d %f", temp.name, &temp.roll, &temp.gpa) == 3){
        printf("Name: %s, Roll: %d, GPA: %.2f\n", temp.name, temp.roll, temp.gpa);
    }

    fclose(file);
    
    
}

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* delete_value(struct Node *head, int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found\n", value);
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void print_list(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    struct Node* head = NULL;

    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    head = insert_begin(head, 40);

    printf("Linked List after insertion:\n");
    print_list(head); 

    head = delete_value(head, 30);
    printf("After deleting 30:\n");
    print_list(head); 

    head = delete_value(head, 20);
    printf("After trying to delete 20:\n");
    print_list(head); 

    head = delete_value(head, 40);
    printf("After deleting 40 (head):\n");
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int size;
    int *arr;
    int sum=0;
    float avg;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
         
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int j = 0;j<size;j++){
        sum = sum + arr[j];
        
    }
    avg = (float)sum/size;
    printf("sum is %d\n",sum);
    printf("avg is %f",avg);

    free(arr);

}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int *arr = (int*)malloc(2*sizeof(int));
    int newsize;
    printf("give new size: ");
    scanf("%d",&newsize);
    arr = (int *)realloc(arr,newsize*sizeof(int));
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count>=MAX_PTRS){
        printf("allocations are more than required");
        return NULL;
    }
    void* ptr = malloc(size);
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr;
    }

    return ptr;
    
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (ptr == NULL) return;
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            for (int j = i; j < allocated_count - 1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            }

            allocated_ptrs[--allocated_count] = NULL;
            return;
        }
    }

    printf("Warning: Attempted to free untracked pointer.\n");
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count == 0) {
        printf("No memory leaks detected.\n");
    } else {
        printf("Memory leaks detected! Unfreed pointers: %d\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf(" - Leak at pointer %p\n", allocated_ptrs[i]);
        }
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *a = (int *)my_malloc(sizeof(int));
    int *b = (int *)my_malloc(sizeof(int));
    int *c = (int *)my_malloc(sizeof(int));

    *a = 10;
    *b = 20;
    *c = 30;
    printf("a = %d, b = %d, c = %d\n", *a, *b, *c);
    my_free(b); 
    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    int carry = 0;
    while (b!=0){
        carry = a & b;
        a = a^b;
        b = carry<<1;
    }

    return a;
}
int complement(int x){
    return add(~x,1);
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    int A = 0;                       
    int Q = multiplier;              
    int M = multiplicand;            
    int Q_1 = 0;                     
    int n = sizeof(int) * 8;        

    for (int i = 0; i < n; i++) {
        int lastQ = Q & 1;

        if (lastQ == 1 && Q_1 == 0) {
            A = add(A, complement(M));  
        } else if (lastQ == 0 && Q_1 == 1) {
            A = add(A, M);           
        }
        int msb_A = A & (1 << 31);  
        Q_1 = lastQ;
        int lsb_A = A & 1;
        Q = ((lsb_A << 31) | ((unsigned)Q >> 1));
        A = ((msb_A) | ((unsigned)A >> 1));
    }

    return Q;

}

void test_booth() {
    // TODO: Write test cases for booth_multiply
    // Include positive, negative, zero, overflow cases
    printf(" 3 *  4 = %d\n", booth_multiply(3, 4));    
    printf("-3 *  4 = %d\n", booth_multiply(-3, 4));   
    printf(" 3 * -4 = %d\n", booth_multiply(3, -4));   
    printf("-3 * -4 = %d\n", booth_multiply(-3, -4));  
    printf(" 0 *  7 = %d\n", booth_multiply(0, 7));
}
int main(){
    int x = 4;
    int y = 6;
    const char str[] = "pointers";
    char darr[20]; 
    const char sarr[] = "copied string";
    const char a[] = "dog";
    const char b[] = "dog";
    const char d[] = "alla";
    //task1_1();
    //swap(&x,&y);
    //task1_3();
    //my_strlen(str);
    //my_strcpy(darr,sarr);
    //my_strcmp(a,b);
    //is_palindrome(d);
    //task3_1_macros();
    //task3_2_fileio();
    //task4_1_linkedlist();
    
   // task5_1_dynamic_array();
    //task5_2_realloc_array();
    //task5_3_leak_detector();
    test_booth();
    return 0;
}