#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int *iptr = NULL;
    int value = 42;
    iptr = &value;
    printf("Value: %d, Pointer: %p\n", value, (void*)iptr);
    printf("Value via pointer: %d\n", *iptr);
    *iptr = 100; // Modify value via pointer
    printf("New value: %d\n", value);
    printf("New value via pointer: %d\n", *iptr);
    
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    // printf("Swapping %d and %d\n", *a, *b);
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// Task 1.3: Pointer arithmetic on array
void task1_3(int arr[], int size) {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place
    const int* arr_start = arr;
    const int* arr_end = arr + size - 1;
    
    
    int sum = 0;
    int *end = arr_end;
    
    
    printf("Array elements: ");
    while ( arr <= end ) {
        sum += *arr;
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
    printf("Sum: %d\n", sum);

    arr = arr_start;
    while (arr < end) { 
        swap(arr, end);
        arr++;
        end--;
    }

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr_start + i));  
    }

}


// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int length = 0;
    char *ptr = (char *)s;
    while (*ptr) { ptr++; length++; }
    return length;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return *s1 - *s2; // Return difference if characters differ
        }
        s1++;
        s2++;
    }
    return *s1 - *s2; // If one string ends, return difference
    return 0;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char *start = s;
    const char *end = s + my_strlen(s) - 1;
    while (start < end) {
        // Convert to lowercase for case-insensitive comparison
        char c1 = (*start >= 'A' && *start <= 'Z') ? *start + 32 : *start;
        char c2 = (*end >= 'A' && *end <= 'Z') ? *end + 32 : *end;

        if (c1 != c2) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }

    return 1; // Is a palindrome
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) (x*x)      
#define MAX2(a,b) ((a > b) ? a:b)      
#define MAX3(a,b,c) (a>b ? (a>c ? a : c):(b>c ? b : c))    
#define MAX4(a,b,c,d) (a>b ? (a>c ? (a>d ? a:d):(c>d ? c:d)):(b>c ? (b>d ? b:d):(c>d ? c:d)))  
#define TO_UPPER(c) ((c >= 'a' && c <= 'z') ? (c-=32) : c)    

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("MAX2(3, 7) = %d\n", MAX2(3, 7));
    printf("MAX3(1, 2, 3) = %d\n", MAX3(1, 2, 3));
    printf("MAX4(1, 2, 3, 4) = %d\n", MAX4(1, 2, 3, 4));
    char c = 'a';
    printf("TO_UPPER('a') = %c\n", TO_UPPER(c));
    c = 'A';
    printf("TO_UPPER('A') = %c\n", TO_UPPER(c));
    c = 'z';
    printf("TO_UPPER('z') = %c\n", TO_UPPER(c));
    c = 'Z';        
    printf("TO_UPPER('Z') = %c\n", TO_UPPER(c));
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
    // Print student with highest GPA
    // Save to "students.txt"
    // Read back and print
    int length = 2;
    struct Student students[length];
    FILE *file = fopen("students.txt", "w+");
    if (!file) { 
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        printf("Enter name, roll, gpa for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].roll, &students[i].gpa);
    }

    struct Student top_student = students[0];
    for (int i = 0; i < length; i++) {
        if (students[i].gpa > top_student.gpa) {
            top_student = students[i];  
        }
    }

    fprintf(file, "%s %d %.2f\n", top_student.name, top_student.roll, top_student.gpa);

    fclose(file);

    file = fopen("students.txt", "r");
    if (!file) {
        printf("Error opening file for reading!\n");
        return;     
    }

    top_student = (struct Student){0}; // Reset top_student

    fscanf(file, "%s %d %f", top_student.name, &top_student.roll, &top_student.gpa);
    printf("Top student: %s, Roll: %d, GPA: %.2f\n", 
           top_student.name, top_student.roll, top_student.gpa);
}


// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
    }
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node *current = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return head; // Nothing to delete
    }

    while (current != NULL) {
        if (current->data == value)
        {
            if (current == head) {
                current = current->next; free(head);
                head = current;
                continue;
            }
            else {
                prev->next = current->next;
                free(current);
                current = prev->next;
                continue; 
            }
        }
        
        prev = current;
        current = current->next;
    }
    
    return head;
}

void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
}

void task4_1_linkedlist() {
    struct Node *head = NULL;
    int choice, value;
    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Delete value\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insert_begin(head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = delete_value(head, value);
                break;
            case 3:
                print_list(head);
                printf("NULL\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);   
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n = 0; float sum = 0;
    printf("Enter number of elements: "); scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Also enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        sum += *(arr+i);
    }
    printf("Sum:\t %f\n", sum);
    printf("Average:\t %f\n", sum/n);
    free(arr);
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int* arr = (int*)malloc(5 * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter 5 elements: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);   
    }
    printf("Reallocating to extend array...\n");
    int new_size = 10;
    int* new_arr = (int*)realloc(arr, new_size * sizeof(int));
    if (!new_arr) {
        printf("Memory reallocation failed!\n");    
    }
    else {
        arr = new_arr; // Update pointer to new array
        printf("Enter 5 more elements: ");
        for (int i = 5; i < new_size; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Extended array elements: ");
        for (int i = 0; i < new_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr); // Free the allocated memory
    arr = NULL; // Avoid dangling pointe
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count >= MAX_PTRS) {
        printf("Memory leak detector limit reached!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr) {
        allocated_ptrs[allocated_count++] = ptr; // Track this pointer
    } else {
        printf("Memory allocation failed!\n");
    }
    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    if (ptr == NULL) return; // Avoid freeing NULL
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            allocated_ptrs[i] = allocated_ptrs[--allocated_count]; // Remove from tracking
            free(allocated_ptrs[allocated_count]); // Free the last tracked pointer
            allocated_ptrs[allocated_count] = NULL; // Clear last pointer
            free(ptr);
            return;
        }
    }

    printf("Pointer not found in leak detector!\n");
    free(ptr); // Free anyway, but not tracked
}


void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count > 0) {
        printf("Memory leaks detected! Unfreed pointers:\n");
        for (int i = 0; i < allocated_count; i++) {
            printf("Pointer %d: %p\n", i + 1, allocated_ptrs[i]);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int*)my_malloc(10 * sizeof(int));
    int *arr2 = (int*)my_malloc(20 * sizeof(int));

    if (arr1) {
        for (int i = 0; i < 10; i++) {
            arr1[i] = i + 1; // Initialize array    
            arr2[i] = (i + 1) * 2; // Initialize array
        }
    }

    my_free(arr1); // Free first array
    // Intentionally not freeing arr2 to demonstrate leak detection
    report_leaks(); // Check for leaks
    my_free(arr2); // Free second array
    report_leaks(); // Check again after freeing
    // Reset tracking
    allocated_count = 0;
    for (int i = 0; i < MAX_PTRS; i++) {
        allocated_ptrs[i] = NULL; // Clear tracking array  
    }
    printf("Memory leak detection completed.\n");
    report_leaks(); // Final check after reset 
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    while (b != 0)
    {
        int temp = a ^ b; // Sum without carry
        b = (a & b) << 1; // Carry bits
        a = temp; // Update a to new sum
    }
    
    return a;
}

long booth_multiply(int multiplicand, int multiplier) {
    unsigned int QR = multiplier;
    int A = multiplicand;
    int S = ~multiplicand + 1; // Two's complement of multiplicand
    int count = 32;
    int Qn = 0; // The extra bit (Q_{-1})
    int AC = 0;
    
    while (count > 0) {
        int current_lsb = QR & 0x1; // Get current LSB of QR
        
        // Check the bit pair (current_lsb, Qn)
        if (current_lsb == 1 && Qn == 0) {
            // 10: subtract multiplicand (add S)
            AC = add(AC , S);
        } else if (current_lsb == 0 && Qn == 1) {
            // 01: add multiplicand (add A)
            AC = add(AC , A);
        }
        // 00 and 11: do nothing
        
        // Arithmetic right shift of AC:QR
        Qn = current_lsb; // Save current LSB for next iteration
        
        QR = (AC << 31) | (QR >> 1);
        AC = (AC >> 1);
        
        count--;
    }
    
    printf("AC: %d, QR: %d\n", AC, QR);
    return ((long)AC << 32) | QR;
}

void test_booth() {
    // TODO: Write test cases for booth_multiply
    // Include positive, negative, zero, overflow cases
    int a = 3, b = 4;
    int result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
    a = -3, b = -4;
    result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
    a = 0, b = 4;
    result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
    a = -1000000, b = 2000;
    result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
    a = 2, b = 0x7fffffff;
    result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
    a = 0x7fffffff, b = 0x7fffffff;
    result = booth_multiply(a, b);
    printf("Booth Multiply: %d * %d = %d\n", a, b, result);
}


// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement
    //int arr[5] = {1, 2, 3, 4, 5};
    // --- Part 1 ---
    //task1_1();
    //int a=5, b=10; swap(&a,&b);
    //printf("Swapped: a = %d, b = %d\n", a, b);
    //task1_3(arr, 5);

    // --- Part 2 ---
    //printf("Len = %d\n", my_strlen("Hello"));
    //char buf[100]; my_strcpy(buf,"World");
    //printf("Copied: %s\n", buf);
    //printf("%d\n",my_strcmp("abc","aBc"));
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
