#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================
// Task 1.1: Basic pointer usage
void task1_1() {
    int a = 5;
    int *ptr_a = &a;  // pointer stores address of 'a'
    
    // Print value directly and through pointer
    printf("%d\n", a);
    printf("%d\n", *ptr_a);  // dereference pointer
    
    // Modify via pointer and print result
    *ptr_a = *ptr_a + 1;
    printf("%d\n", *ptr_a);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // Store original value of *a in temporary variable
    int swp = *a;
    
    // Copy value of *b to *a
    *a = *b;
    
    // Copy original *a value (stored in swp) to *b
    *b = swp;
    
    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    int x = 0;  // sum accumulator
    int arr[] = {1, 2, 3, 4, 5};
    
    // Print all elements using pointer arithmetic and calculate sum
    int *ptr_array = arr;  // point to first element
    for(int i = 0; i < 5; i++){
        printf("%d ", *ptr_array);
        x = *ptr_array + x;  // add to sum
        ptr_array++;  // move pointer to next element
    }
    printf("\n");
    printf("sum is %d\n", x);
    
    // Reverse array in place using two pointers
    int temp;
    int *ptr_one = arr;          // pointer to start
    int *ptr_two = arr + 5 - 1;  // pointer to end
    
    while(ptr_one < ptr_two){
        temp = *ptr_one;
        *ptr_one++ = *ptr_two;   // swap and increment ptr_one
        *ptr_two-- = temp;       // assign and decrement ptr_two
    }
    
    // Print reversed array
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    int a = 0;  // length counter
    
    // Traverse string until null terminator
    while(*s != '\0'){
        s++;    // move pointer to next character
        a++;    // increment length counter
    }
    
    return a;   // return string length
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // Copy each character from src to dest
    while(*src != '\0'){
        *dest = *src;  // copy character
        dest++;        // move dest pointer forward
        src++;         // move src pointer forward
    }
    
    // Add null terminator to complete the string
    *dest = '\0';
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    int x = my_strlen(s1);  // get length of first string
    int y = my_strlen(s2);  // get length of second string
    int len_check = 0;      // counter for matching characters
    
    // Quick check: if lengths differ, strings are not equal
    if (x != y){
        return 0;
    }
    else{
        // Compare characters while they match and haven't reached end
        while((*s1 == *s2) && (*s1 != '\0')){
            len_check++;
            s1++;  // move to next character in s1
            s2++;  // move to next character in s2
        }
        
        // Check if we matched all characters
        if(len_check == x){
            return 1;  // strings are equal
        }
        else{
            return 0;  // strings are different
        }
    }
}

void reverse_string(char *s) {
    // Set end pointer to last character (skip null terminator)
    char *end = s + strlen(s) - 1;
    
    // Swap characters from both ends moving toward center
    while (s < end) {
        char temp = *s;    // store start character
        *s++ = *end;       // copy end to start, advance start pointer
        *end-- = temp;     // copy temp to end, move end pointer back
    }
}


// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    char buf[100];  // buffer to store copy of string
    
    // Copy original string to buffer for manipulation
    my_strcpy(buf, s);
    
    // Reverse the copied string
    reverse_string(buf);
    
    // Debug print: show reversed vs original
    printf("%s   %s\n", buf, s);
    
    // Compare reversed string with original
    return my_strcmp(buf, s);  // returns 1 if equal, 0 if different
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macro definitions - replaced by preprocessor before compilation
#define SQUARE(x) (x*x)                                    // Square a number
#define MAX2(a,b) (a>b?a:b)                               // Max of 2 numbers
#define MAX3(a,b,c) ((a>b?a:b)>c?(a>b?a:b):c)            // Max of 3 numbers
#define MAX4(a,b,c,d) ((a>b?a:b)>(c>d?c:d)?(a>b?a:b):(c>d?c:d))  // Max of 4 numbers
#define TO_UPPER(c) (((c)>='a'&&(c)<='z')?((c)-32):(c))  // Convert to uppercase

void task3_1_macros() {
    // Test variables
    int x = 2, a = 21, b = 3, c = 19, d = 31;
    char h = 'c';
    
    // Demonstrate each macro with test cases
    printf("SQUARE %d\n", SQUARE(x));        // 2*2 = 4
    printf("MAX2   %d\n", MAX2(a,b));        // max(21,3) = 21
    printf("MAX3   %d\n", MAX3(a,b,c));      // max(21,3,19) = 21
    printf("MAX4   %d\n", MAX4(a,b,c,d));    // max(21,3,19,31) = 31
    printf("TO_UPPER %c\n", TO_UPPER(h));    // 'c' -> 'C'
}

// Task 3.2: File I/O
void task3_2_fileio() {
    float i, x;  // i = highest GPA, x = GPA read from file
    int a;       // roll number read from file
    char m[100]; // name read from file
    char buffer[100]; // buffer for file reading
    
    // Create 5 student records
    struct Student ONE = {"ASAD", 169, 3.34};
    struct Student TWO = {"HASEEB", 166, 3.31};
    struct Student THREE = {"HASSAN", 162, 3.21};
    struct Student FOUR = {"NAQI", 164, 3.50};
    struct Student FIVE = {"ALI", 161, 3.99};
    
    // Find highest GPA using nested MAX macros
    i = (MAX4(MAX2(ONE.gpa, TWO.gpa), THREE.gpa, FOUR.gpa, FIVE.gpa));
    
    // Write highest GPA student to file
    FILE *f1;
    f1 = fopen("students.txt", "w");
    if (!f1) {
        printf("Error opening file for writing.\n");
        return;
    }
    else {
        // Check which student has highest GPA and write to file
        if(ONE.gpa == i) {
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", ONE.name, ONE.roll, ONE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", ONE.name, ONE.roll, ONE.gpa);
        }
        else if(TWO.gpa == i) {
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", TWO.name, TWO.roll, TWO.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", TWO.name, TWO.roll, TWO.gpa);
        }
        else if(THREE.gpa == i) {
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", THREE.name, THREE.roll, THREE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", THREE.name, THREE.roll, THREE.gpa);
        }
        else if(FOUR.gpa == i) {
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FOUR.name, FOUR.roll, FOUR.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FOUR.name, FOUR.roll, FOUR.gpa);
        }
        else {
            printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FIVE.name, FIVE.roll, FIVE.gpa);
            fprintf(f1, "Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", FIVE.name, FIVE.roll, FIVE.gpa);
        }
    }
    fclose(f1);
    
    // Read data back from file
    f1 = fopen("students.txt", "r");
    if (!f1) {
        printf("Error opening file for reading.\n");
        return;
    } else {
        fgets(buffer, sizeof(buffer), f1); // read first line (header)
        fscanf(f1, "NAME: %s   ROLL NO: %d   GPA: %f", m, &a, &x); // parse data
    }
    fclose(f1);
    
    // Print data read from file
    printf("Highest GPA among students:\nNAME: %s   ROLL NO: %d   GPA: %.2f\n", m, a, x);
}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node structure
struct Node {
    int data;           // data stored in node
    struct Node *next;  // pointer to next node
};

// Insert new node at beginning of list
struct Node* insert_begin(struct Node *head, int value) {
    // Allocate memory for new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;  // set data
    newNode->next = head;   // point to current head
    return newNode;         // return new head
}

// Delete node with specified value
struct Node* delete_value(struct Node *head, int value) {
    // Handle empty list
    if (head == NULL) 
        return NULL;
    
    // Handle deletion of first node
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;    // move head to next node
        free(temp);           // free old head
        return head;
    }
    
    // Search for node to delete
    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }
    
    // Delete node if found
    if (curr->next != NULL) { 
        struct Node *temp = curr->next;
        curr->next = temp->next;  // bypass node to delete
        free(temp);               // free memory
    }
    return head;
}

// Print entire linked list
void print_list(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;  // move to next node
    }
    printf("NULL\n");  // indicate end of list
}

// Test function for linked list operations
void task4_1_linkedlist() {
    struct Node *head = NULL;  // start with empty list
    
    // Insert nodes at beginning
    head = insert_begin(head, 10);  // List: 10 -> NULL
    head = insert_begin(head, 20);  // List: 20 -> 10 -> NULL
    head = insert_begin(head, 30);  // List: 30 -> 20 -> 10 -> NULL
    printf("List after insertions: ");
    print_list(head);
    
    // Delete nodes by value
    head = delete_value(head, 20);  // List: 30 -> 10 -> NULL
    printf("List after deleting 20: ");
    print_list(head);
    
    head = delete_value(head, 30);  // List: 10 -> NULL
    printf("List after deleting 30: ");
    print_list(head);
    
    head = delete_value(head, 10);  // List: NULL
    printf("List after deleting 10: ");
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================
void task5_1_dynamic_array() {
    int n;
    
    // Get array size from user
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory dynamically for n integers
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Input elements from user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Calculate sum by iterating through array
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    
    // Calculate average with division by zero protection
    double avg = (n > 0) ? (double)sum / n : 0;
    
    // Display results
    printf("Sum = %d, Average = %.2f\n", sum, avg);
    
    // Free allocated memory to prevent memory leak
    free(arr);
}

void task5_2_realloc_array() {
    int n;
    
    // Get initial array size
    printf("Enter initial number of elements: ");
    scanf("%d", &n);
    
    // Allocate initial memory block
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Fill initial array with user input
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    // Get new larger size from user
    printf("Enter new size (greater than %d): ", n);
    int new_n;
    scanf("%d", &new_n);
    
    // Resize array using realloc (preserves existing data)
    arr = (int*)realloc(arr, new_n * sizeof(int));
    if (!arr) {
        printf("Reallocation failed!\n");
        return;
    }
    
    // Fill additional elements in extended array
    printf("Enter %d more integers:\n", new_n - n);
    for (int i = n; i < new_n; i++) scanf("%d", &arr[i]);
    
    // Display complete final array
    printf("Final array: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // Clean up allocated memory
    free(arr);
}

#define MAX_PTRS 100  // Maximum number of tracked pointers

// Global arrays to track allocated memory
void* allocated_ptrs[MAX_PTRS];  // stores pointers to allocated memory blocks
int allocated_count = 0;         // current number of tracked allocations

// Custom malloc wrapper that tracks allocations
void* my_malloc(size_t size) {
    // Allocate memory using standard malloc
    void *ptr = malloc(size);
    
    // Track the pointer if allocation succeeded and we have space
    if (ptr && allocated_count < MAX_PTRS) {
        allocated_ptrs[allocated_count++] = ptr;
    }
    
    return ptr;
}

// Custom free wrapper that removes from tracking
void my_free(void *ptr) {
    if (!ptr) return;  // handle NULL pointer gracefully
    
    // Find the pointer in tracking array
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);  // free the actual memory
            
            // Remove from tracking: replace with last element (efficient removal)
            allocated_ptrs[i] = allocated_ptrs[allocated_count - 1];
            allocated_count--;
            return;
        }
    }
    // If pointer not found in tracking, it wasn't allocated by my_malloc
}

// Report any remaining unfreed memory blocks
void report_leaks() {
    if (allocated_count == 0) {
        printf("No memory leaks detected!\n");
    } else {
        printf("Memory leaks detected! %d block(s) not freed.\n", allocated_count);
        // Display each leaked pointer address
        for (int i = 0; i < allocated_count; i++) {
            printf(" - Leak at pointer %p\n", allocated_ptrs[i]);
        }
    }
}

// Demonstrate memory leak detection functionality
void task5_3_leak_detector() {
    // Allocate two memory blocks (both tracked)
    int *arr1 = (int*)my_malloc(5 * sizeof(int));   // tracked allocation
    int *arr2 = (int*)my_malloc(10 * sizeof(int));  // tracked allocation
    
    // Free only one block (creates intentional memory leak)
    my_free(arr1);  // removes arr1 from tracking
    // arr2 remains allocated and tracked
    
    // Check for memory leaks - will detect arr2 as leaked
    report_leaks();
}


// ======================= Final Task: Booth's Multiplication =======================

// Add M to the upper 32 bits of AQ (A register)
void add(int64_t *AQ, int32_t M) {
    *AQ += (int64_t)M << 32;  // shift M to upper 32 bits and add
}

// Perform arithmetic right shift on AQ register pair
void arithmetic_right_shift(int64_t *AQ, int *Q_1) {
    int lsb = *AQ & 1;        // save least significant bit
    *AQ >>= 1;                // right shift by 1 position
    
    // Preserve sign bit for arithmetic shift
    if (*AQ < 0) 
        *AQ |= (1LL << 63);   // set MSB if negative
    
    *Q_1 = lsb;               // update Q_1 with old LSB
}

// Booth's multiplication algorithm implementation
int64_t booth_multiply(int32_t M, int32_t Q) {
    // Initialize AQ register: A=0, Q=multiplicand (lower 32 bits)
    int64_t AQ = (int64_t)Q & 0xFFFFFFFF; 
    int Q_1 = 0;              // extra bit for Booth's algorithm
    
    // Perform 32 iterations (one per bit)
    for (int i = 0; i < 32; i++) {
        int Q0 = AQ & 1;      // current least significant bit
        
        // Booth's algorithm decision logic
        if (Q0 == 0 && Q_1 == 1) {
            add(&AQ, M);      // add M to A register
        } else if (Q0 == 1 && Q_1 == 0) {
            add(&AQ, -M);     // subtract M from A register
        }
        // if Q0 == Q_1, do nothing (no add/subtract needed)
        
        // Arithmetic right shift AQ register pair
        arithmetic_right_shift(&AQ, &Q_1);
    }
    
    return AQ;  // return 64-bit result
}

// Test Booth's multiplication with various cases
void test_booth() {
    int32_t m1, m2;
    int64_t result;
    
    // Test case 1: positive × positive
    m1 = 3; m2 = 2;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);
    
    // Test case 2: negative × positive
    m1 = -3; m2 = 2;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);
    
    // Test case 3: negative × negative
    m1 = -4; m2 = -3;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);
    
    // Test case 4: large numbers
    m1 = 123456; m2 = -789;
    result = booth_multiply(m1, m2);
    printf("%d * %d = %ld\n", m1, m2, result);
    
    // Test case 5: extreme values
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
