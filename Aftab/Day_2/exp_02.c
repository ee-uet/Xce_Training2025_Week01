#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>


// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    int a = 2;
    int *ptr = &a;
    // Print value using direct and pointer
    printf("direct print: %d\npointer print: %d\n", a, *ptr);
    // Modify via pointer and print new value
    *ptr = 3;
    printf("modified value using pointer: %d\n", *ptr);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    int swap = *a;
    *a = *b;
    *b = swap;
    printf("*a = %d & *b = %d\n", *a, *b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    int sum = 0;
    int arr[] = {3,7,5,4,2,6};
    char string[] = "AFTAB";
    // Print all elements using pointers

    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr; 
    for (int i=0; i<size; i++) {
        printf("%d ", *ptr);
        *ptr++;  // pointer moving to next memory address
    }
    printf("\n");
    
    int *ptr2 = arr;

    // Calculate sum
    for (int n=0; n<size; n++) {
        sum += *ptr2;
        *ptr2++;  // pointer moving to next memory address
    }
    printf("Sum is %d\n", sum);

    // Reverse in place

    char *start = string; // pointer to first element
    char *end = start + strlen(start) - 1; // pointer to last element
    while (start < end) {
        char temp = *start;  // temporary storage for first element
        *start = *end;       // last element stored at first index
        *end = temp;         // first element at the last index
        *start++;            // start pointer increment
        *end--;              // end pointer decrement
    }
    printf("%s\n", string);
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int size=0;
    while (*s != 0) {   // while s is not equal to NULL "/0"
        size += 1;      // counter increment
        *s++;           // pointer moving to next mem address
    }
    return size;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while (*src != 0) {  // while src is not equal to NULL "/0"
        *dest = *src;    // current value of src stored in dest
        *src++;          // src pointer moving to next mem address
        *dest++;         // dest pointer moving to next mem address
    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return 0; // Mismatch found
        }
        s1++;
        s2++;
    }
    // Check if both strings ended (same length)
    if (*s1 == '\0' && *s2 == '\0') {
        return 1; // Strings are equal
    }
    return 0; // One string is longer than the other
}

//Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char *e = s + strlen(s) - 1;  
    while (s < e) {                        // case-insensitive checking  
        if (tolower(*s) != tolower(*e)) {  // whether character is equal or not. 
            return 0;
        }
        *s++;
        *e--;
    }
    
    return 1;
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) ((x)*(x))
#define MAX2(a,b) (a>b ? a:b)   // If True then a will get selected
#define MAX3(a,b,c) (MAX2(a,b)>c ? MAX2(a,b):c)       
#define MAX4(a,b,c,d) (MAX3(a,b,c)>d ? MAX3(a,b,c):d)
#define TO_UPPER(c) ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))   
// A=65; a=97; if c in between small letters 
//  then minus that value from 32 and we have capital letter.

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("between 5 & 10: %d\n", MAX2(5,10));
    printf("between 8, 5 and 10: %d\n", MAX3(8,5,10));
    printf("between 12,8,5 and 10: %d\n", MAX4(12,8,5,10));
    printf("Square of %d: %d\n",4, SQUARE(4));
    printf("%c\n", TO_UPPER('a'));
}

// Student struct
struct student {
    char name[50];
    int roll;
    float gpa;
};

// Task 3.2: File I/O
void task3_2_fileio() {
    // TODO: Input 5 students
    struct student students[5] = {   // array of 5 structs 
        {"hamza", 16, 3.1},
        {"ali", 15, 3.5},
        {"ahsan", 17, 3.4},
        {"bilal", 14, 3.3},
        {"ahmad", 24, 3.2}
    };

    int topper = 0;           // index of topper student in struct array
    for (int i=1; i<5; i++) { // if topper gpa is less than the current student
        if(students[topper].gpa < students[i].gpa) { 
            topper = i;       // topper is current student
        }
    } 
    
    // Print student with highest GPA
    printf("Name: %s\nRoll no: %d\nGPA: %.1f\n", students[topper].name, students[topper].roll, students[topper].gpa);
    
    // Save to "students.txt"
    FILE *fp=fopen("students.txt", "w");  // opening file with write permission
    if (!fp) {                            // if not available, then it will create. 
        printf("File could not be opened for writing.\n");
        return;
    }
    int n=0;
    while (n < 5) {
        fprintf(fp, "Name: %s\nRoll no: %d\nGPA: %.1f\n",
            students[n].name,
            students[n].roll,
            students[n].gpa);
        n++;
    }
    fclose(fp);

    // Read back and print
    fp = fopen("students.txt", "r");
    if (!fp) {
        printf("File could not be opened for reading.\n");
        return;
    }
    struct student students_reading[5];
    int j = 0;  // variable for array to store corresponding student info

    while (j < 5 &&
       fscanf(fp, "Name: %s\nRoll no: %d\nGPA: %f\n",
              students_reading[j].name,
              &students_reading[j].roll,
              &students_reading[j].gpa) == 3) {
    j++;
    }
    fclose(fp);
}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node *insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    // current head = *head
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    // new_node created 
    new_node->data=value;
    new_node->next=head;  // current head is stored at the next of new_node
    return new_node;      // returning the new_head to the function call. 
}

struct Node *delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    // For deleting a node, I should have the address of the node 
    // before the node to be deleted. 
    int counter = 1;
    struct Node *current_node = head;
    struct Node *prev; // initialized the prev node pointer
    
    if (value == 1) {
        head = head->next;
    }
    else {
        while (current_node != NULL ) {
            prev = current_node;                // current node will be prev
            current_node = current_node->next;  // current node will be current.next_node
            counter += 1;
            if ( value == counter ) {
                prev->next = current_node->next;
            } 
        }
    }
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node* current_node = head;
    while (current_node != NULL ) {
        printf("%d\n", current_node->data);
        current_node = current_node->next; 
    }
}

struct Node* task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node* head = NULL;
    head = insert_begin(head, 2); // 4th node
    head = insert_begin(head, 3); // 3rd node
    head = insert_begin(head, 5); // 2nd node
    head = insert_begin(head, 7); // first node
    head = delete_value(head, 2);
    return head;
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int *arr = (int *)malloc(5 * sizeof(int));

    int sum = 0;
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    float avg = sum / 5.0f;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    free(arr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int *arr = malloc(5 * sizeof(int));
    arr = realloc(arr, 8 * sizeof(int));
    free(arr);
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void *allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void *my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count >= MAX_PTRS) {
    return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL) {
        allocated_ptrs[allocated_count] = ptr;
        allocated_count++;
    }

    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (ptr == NULL) {
        return;
    }
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            for (int j = i; j < allocated_count - 1; j++) {
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            }
            allocated_count--;
            return;
        }
    }
    printf("Pointer not found.\n");

}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count == 0) {
        printf("No leaks.\n");
    } else {
        printf("Leaked pointers:\n");
        for (int i = 0; i < allocated_count; i++) {
            printf("%p\n", allocated_ptrs[i]);
        }
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    char *a = my_malloc(10);
    int *b = my_malloc(20);

    my_free(b);
    report_leaks();
}

// ======================= Final Task: Booth's Multiplication =======================

int32_t add(int32_t a, int32_t b) {
    // TODO: Implement bitwise addition helper
    int32_t carry;
    while (b) {
        carry = a & b; // for carry
        a = a ^ b; // for sum bit
        b = carry << 1; // if carry remains, loop will remain functional
    }
    return a;
}

int64_t booth_multiply(int32_t multiplicand, int32_t multiplier) {
    // Initialize registers for Booth's algorithm
    int32_t A = 0;                      // Use int64_t to avoid overflow in intermediate steps
    uint32_t Q = (uint32_t)multiplier;  // Multiplier as unsigned for bit operations
    int32_t M = multiplicand;           // Multiplicand
    int32_t Q_1 = 0;                    // Extra bit for Booth’s algorithm
    int32_t new_Q_1;

    // Perform 32 iterations for 32-bit multiplication
    for (int i = 0; i < 32; ++i) {
        int32_t Q0 = Q & 1;             // Least significant bit of Q

        // Booth’s algorithm: check Q0 and Q_1 to decide add/subtract
        if (Q0 == 1 && Q_1 == 0) {
            A = add(A, -M);             // A = A - M
        } else if (Q0 == 0 && Q_1 == 1) {
            A = add(A, M);              // A = A + M
        }

        // Update Q_1 with the current LSB of Q
        Q_1 = Q & 1;
        // Arithmetic right shift: Q gets LSB of A, A is shifted
        Q = (Q >> 1) | ((A & 1) << 31);
        A = (A >> 1);                   // Arithmetic right shift (sign-extending)
    }

    // Combine A (upper 32 bits) and Q (lower 32 bits) into 64-bit result
    return ((int64_t)A << 32) | (uint32_t)Q;
}


void test_booth() {
    // TODO: Write test cases for booth_multiply
    // Include positive, negative, zero, overflow cases
    assert(booth_multiply(3, 4) == 12);
    assert(booth_multiply(-3, 4) == -12);
    assert(booth_multiply(3, -4) == -12);
    assert(booth_multiply(-3, -4) == 12);
    assert(booth_multiply(0, 1000000) == 0);
    assert(booth_multiply(123456, 0) == 0);
    assert(booth_multiply(INT_MAX, 2) == (int64_t)INT_MAX * 2);
    assert(booth_multiply(1, INT_MIN) == (int64_t)INT_MIN);
    assert(booth_multiply(INT_MAX, INT_MAX) == (int64_t)INT_MAX * INT_MAX);

    printf("All tests passed.\n");
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
    // printf("%d\n", my_strcmp("Afta","Aftab"));

    // --- Part 3 ---
    // task3_1_macros();
    // task3_2_fileio();

    // --- Part 4 ---
    // struct Node* head = task4_1_linkedlist();
    // print_list(head);

    // --- Part 5 ---
    // task5_1_dynamic_array();
    // task5_2_realloc_array();
    // task5_3_leak_detector();

    // --- Final Task ---
    test_booth();

    return 0;
}