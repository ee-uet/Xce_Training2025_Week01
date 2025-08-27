#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // Declaring int variable & pointer to it
    int x = 75;
    int *ptr = &x;

    // Printing value using direct and pointer
    printf("The value using direct access is: %d\n", x);
    printf("The value using pointer access is: %d\n", *ptr);

    // Modifying via pointer and printing new value
    *ptr = 52;
    printf("The new value is: %d\n", x);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    
    // before swaping
    printf("Before swaping: a = %d, b = %d\n", *a, *b);
    
    int temp = *a;
    *a = *b;
    *b = temp;

    // after swaping
    printf("After swaping: a = %d, b = %d\n", *a, *b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {

    // array creation
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    int sum = 0, len = 0;
    int i;

    // Printing all elements using pointers
    printf("The elements of array are: \n");
    for (i = 0; i < 5; i++){
        printf("%d\n", *(ptr + i));
        sum += *(ptr + i);
        len++;
    }
    
    // printing sum
    printf("The sum is: %d\n", sum);

    // Reverse in place
    int *start = arr;
    int *end = arr + len - 1;

    printf("The reversed array is: \n");
    while (start < end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    for (i = 0; i < len; i++){
            printf("%d\n", arr[i]);
    }
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    
    int len = 0;

    while (*s != '\0'){
        len++;
        s++;
    }
    return len;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    
    while (*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    
    while (*s1 != '\0' && *s2 != '\0'){
        if (*s1 != *s2){
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    
    const char *start = s;
    const char *end = s + strlen(s) - 1;

    while (start < end){
        if (!(*start == *end || *start + 32 == *end || *start - 32 == *end)){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x)  ((x) * (x))     
#define MAX2(a,b)  ((a) > (b) ? (a) : (b))    
#define MAX3(a,b,c)  (MAX2(MAX2((a),(b)), (c)))   
#define MAX4(a,b,c,d)   (MAX2(MAX2((a),(b)), MAX2((c),(d))))
#define TO_UPPER(c)  (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))   

void task3_1_macros() {
    // macros with test cases
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("SQUARE(8) = %d\n", SQUARE(8)); 

    printf("MAX2(10, 20) = %d\n", MAX2(10, 20));
    printf("MAX2(-5, -2) = %d\n", MAX2(-5, -2));

    printf("MAX3(1, 5, 3) = %d\n", MAX3(1, 5, 3));  
    printf("MAX3(7, 7, 7) = %d\n", MAX3(7, 7, 7));

    printf("MAX4(1, 9, 3, 6) = %d\n", MAX4(1, 9, 3, 6)); 
    printf("MAX4(-1, -2, -3, -4) = %d\n", MAX4(-1, -2, -3, -4));

    printf("TO_UPPER('i') = %c\n", TO_UPPER('i')); 
    printf("TO_UPPER('E') = %c\n", TO_UPPER('E')); 
}

// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {

    struct Student students[5];
    int i;

    // Input students
    printf("Enter details of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // student with highest GPA
    int HighGPA = 0;
    for (i = 1; i < 5; i++) {
        if (students[i].gpa > students[HighGPA].gpa) {
            HighGPA = i;
        }
    }

    // print highest gpa student name, roll number, gpa
    printf("\nStudent with highest GPA:\n");
    printf("Name: %s | Roll: %d | GPA: %.2f\n",
           students[HighGPA].name, students[HighGPA].roll, students[HighGPA].gpa);

    // open file in write mode
    FILE *fp = fopen("students.txt", "w");

    // write to file
    for (i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }

    // close file
    fclose(fp);
    printf("\nStudent data saved to students.txt\n");

    // open file in read mode
    struct Student readStudents[5];
    fp = fopen("students.txt", "r");

    // read from file
    printf("\nReading students back from file:\n");
    for (i = 0; i < 5; i++) {
        fscanf(fp, "%s %d %f", readStudents[i].name, &readStudents[i].roll, &readStudents[i].gpa);
        printf("Name: %s | Roll: %d | GPA: %.2f\n",
               readStudents[i].name, readStudents[i].roll, readStudents[i].gpa);
    }

    // close file
    fclose(fp);
}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

// new node at the begining
struct Node* insert_begin(struct Node *head, int value) {

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;   
    return newNode;

}

// delete a node
struct Node* delete_value(struct Node *head, int value) {

    struct Node *temp = head, *prev = NULL;

    // check if head itself has value to be deleted
    if (temp != NULL && temp->data == value) {
        head = temp->next;  
        free(temp);         
        return head;
    }

    // check for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // value not found then return head
    if (temp == NULL) {
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void print_list(struct Node *head) {

    struct Node *current = head;

    // traverse the list until NULL 
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    struct Node *head = NULL;

    // Inserting nodes
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);

    printf("Linked List after inserts: ");
    print_list(head);

    // Deleting node
    head = delete_value(head, 20);
    printf("Linked List after deleting 20: ");
    print_list(head);

    // Deleting head
    head = delete_value(head, 30);
    printf("Linked List after deleting 30: ");
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    
    // declaration
    int n, i, sum = 0;
    float avg;
    int *arr;

    // size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input elements from user & calculate sum
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Compute average
    avg = (float) sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    // free memory
    free(arr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    
    // declaration
    int n, new_n, i;
    int *arr;

    // array size from user
    printf("Enter initial size of array: ");
    scanf("%d", &n);

    // allocate memory dynamically
    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // input elements from user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print original array
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Extend array using realloc
    printf("Enter new size (greater than %d): ", n);
    scanf("%d", &new_n);

    // realloc array
    arr = (int*) realloc(arr, new_n * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return;
    }

    // enter new elements
    printf("Enter %d new elements:\n", new_n - n);
    for (i = n; i < new_n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print extended array
    printf("Extended array: ");
    for (i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free memory
    free(arr);
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

// allocate memory
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr != NULL && allocated_count < MAX_PTRS) {
        allocated_ptrs[allocated_count++] = ptr;
    }
    return ptr;
}

// free that updates tracking
void my_free(void* ptr) {

    if (ptr == NULL) {
        return;
    }

    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);

            // Shift remaining pointers left
            for (int j = i; j < allocated_count - 1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            }
            allocated_count--;
            return;
        }
    }
    printf("Warning: Attempted to free untracked pointer %p\n", ptr);
}

// Report leaks at the end
void report_leaks() {

    if (allocated_count == 0) {
        printf("No memory leaks detected\n");
    } 
    else {
        printf("Memory Leak Detected! %d not freed.\n", allocated_count);
    }
}

void task5_3_leak_detector() {

    int *a = (int*) my_malloc(sizeof(int));
    int *b = (int*) my_malloc(5 * sizeof(int));

    *a = 42;
    b[0] = 10;

    printf("a = %d, b[0] = %d\n", *a, b[0]);

    my_free(a);

    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

// Bitwise addition
int32_t add(int32_t a, int32_t b) {

    while (b != 0) {
        int32_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Two's complement
int32_t negate(int32_t x) {
    return add(~x, 1);
}

// Booth's multiplication 
int32_t booth_multiply(int32_t M, int32_t Q) {

    int64_t A = 0;                 
    int32_t Q_1 = 0;               
    int32_t negM = negate(M);      

    // Combining A (upper 32) and Q (lower 32) into 64-bit
    int64_t combined = ((int64_t) A << 32) | ((int32_t) Q);

    for (int i = 0; i < 32; i++) {
        int32_t Q0 = combined & 1;   

        if (Q0 == 1 && Q_1 == 0) {
            A = add((int32_t)(A & 0xFFFFFFFF), negM); // A = A - M
        } 
        else if (Q0 == 0 && Q_1 == 1) {
            A = add((int32_t)(A & 0xFFFFFFFF), M);    // A = A + M
        }

        // Update combined {A,Q}
        combined = ((A & 0xFFFFFFFFLL) << 32) | (combined & 0xFFFFFFFF);
        Q_1 = Q0;

        // Arithmetic right shift {A,Q,Q-1}
        combined >>= 1;
        A = (combined >> 32);
    }

    return (int32_t)(combined & 0xFFFFFFFF);
}

// Test function
void test_booth() {

    int32_t A, B, result;

    // Test cases
    A = 5; B = 3;
    printf("%d * %d = %d \n", A, B, booth_multiply(A, B));

    A = -1; B = -2147483648;
    printf("%d * %d = %d (Overflow Case)\n", A, B, booth_multiply(A, B));

    A = -75; B = 52;
    printf("%d * %d = %d \n", A, B, booth_multiply(A, B));

    A = -7; B = -8;
    printf("%d * %d = %d \n", A, B, booth_multiply(A, B));

    A = 0; B = 15;
    printf("%d * %d = %d \n", A, B, booth_multiply(A, B));
}

// ======================= Main =======================
int main() {

    // --- Part 1 ---
    task1_1();
    int a = 5, b = 10; swap(&a,&b);
    task1_3();

    // --- Part 2 ---
    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100]; my_strcpy(buf,"World");
    printf("Copied: %s\n", buf);
    printf("%d\n", my_strcmp("Hello", "Hello"));  
    printf("%d\n", my_strcmp("Apple", "Banana")); 
    printf("%d\n", my_strcmp("Zoo", "Ant"));      
    printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    task3_1_macros();
    task3_2_fileio();

    // --- Part 4 ---
    task4_1_linkedlist();

    // --- Part 5 ---
    task5_1_dynamic_array();
    task5_2_realloc_array();
    task5_3_leak_detector();

    // --- Final Task ---
    test_booth();

    return 0;
}
