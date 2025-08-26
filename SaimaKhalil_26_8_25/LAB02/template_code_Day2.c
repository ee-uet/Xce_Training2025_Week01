#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // for 'tolower'


// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int a = 10;
    int *ptr = &a;
    printf("Address of a is : %zu\n",&a);
    printf("Value of a is : %d\n", a);
    printf("Value of a using pointer is : %d\n", *ptr);
    
    *ptr = 100;  //modifying value using pointer
    printf("New value of a after modification via pointer is : %d\n", a);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array_in_place(int *arr, int size) {
    int *left_ptr = arr;
    int *right_ptr = arr + size - 1;

    while (left_ptr < right_ptr) {
        // Swap elements
        swap(left_ptr, right_ptr);
        // Move pointers
        left_ptr++;
        right_ptr--;
    }
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place
    int arr[]={1,2,3,4,5};
    int *ptr = arr;
    int sum = 0;
    printf("Array elements are: ");
    for(int i=0; i<5; i++) {
        printf("%d ", *(ptr + i));
        sum += *(ptr + i);
    }
    printf("\nSum of elements: %d\n", sum); //sum of elements

    printf("Reversed array in place is : "); //reverse array in plac
    reverse_array_in_place(ptr, 5);
    for(int i=0; i<5 ;i++){
        printf("%d ", *(ptr+i));
    }
}

// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    const char *ptr = s;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - s; // Return length by pointer difference
}
 
// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    while (*src != '\0') {
        *dest = *src; // Copy character (also can do by taking dest as arr dest[i]==src(ptr+i) etc or src[i])
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate destination string
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2; // Return difference
}

// Task 2.2: Palindrome checker (case-insensitive)ok
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    const char *start = s;
    const char *end = s + my_strlen(s) - 1;
    while (start < end) {
        if (tolower(*start) != tolower(*end)){//coz case-insensitive ha
            return 0; // Not a palindrome
        }
        start++;
        end--;
    } 
    return 1; // Is a palindrome
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) ((x)*(x))  
#define MAX2(a,b)  ((a>b)?a:b) 
#define MAX3(a,b,c)  MAX2(MAX2(a,b),c) 
#define MAX4(a,b,c,d) MAX2(MAX3(a,b,c),d)
#define TO_UPPER(c)   (toupper(c))

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    int x = 5, y = 10, z = 15, w = 20;
    printf("Square of %d: %d\n", x, SQUARE(x));
    printf("Max of %d and %d: %d\n", x, y, MAX2(x, y));
    printf("Max of %d, %d and %d: %d\n", x, y, z, MAX3(x, y, z));
    printf("Max of %d, %d, %d and %d: %d\n", x, y, z, w, MAX4(x, y, z, w));
    char c = 'a';
    printf("Uppercase of '%c': '%c'\n", c, TO_UPPER(c));
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

    struct Student students[5];
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return; 
    }

    for (int i = 0; i < 5; i++) {
        printf("Enter name, roll num and GPA for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].roll, &students[i].gpa);
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(file); // Close file after writing
   
    struct Student top_student = students[0];  // Finding  student with highest GPA
    for (int i = 1; i < 5; i++) {       
        if (students[i].gpa > top_student.gpa) {
            top_student = students[i];
        }
    }
    printf("Student with highest Gpa: %s (Roll: %d, Gpa: %.2f)\n",top_student.name, top_student.roll,top_student.gpa);
   
    file = fopen("students.txt", "r");    // Read back from file
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    printf("Students read from file:\n");
    int i=0;
    while (fscanf(file, "%s %d %f", students[i].name, &students[i].roll, &students[i].gpa) != EOF) {
        printf("Name: %s, RollNum: %d, Gpa: %.2f\n", students[i].name, students[i].roll, students[i].gpa);
        i++;
    }
    fclose(file); // Close file after reading
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
    new_node->data = value;
    new_node->next = head; // Point new node to current head
    return new_node; // New node becomes the new head
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node *current = head;
    struct Node *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) { // Deleting head(i-e its the first node or head node)
                struct Node *temp = head;
                head = head->next; // Move head to next node
                free(temp); // Free old head
            } else {
                prev->next = current->next; // Bypass current node
                free(current); // Free current node
            }
            return head; // Return new head
        }
        prev = current;
        current = current->next;
    } 
    printf("Value %d not found in list.\n", value);
    return head; // Return unchanged head if value not found
} 
 
void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }   
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
} 

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL; // Initialize empty list
    head = insert_begin(head, 10);  
    head = insert_begin(head, 20);
    head = insert_begin(head, 30); // Insert nodes at beginning
    print_list(head); // Print list
    head = delete_value(head, 20); // Delete node with value 20
    print_list(head); // Print list after deletion
    head = delete_value(head, 100); // Attempt to delete non-existent value
    print_list(head); // Print list after attempted deletion
  
} 

// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be positive.\n");
        return;
    }
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for n integers
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter %d integers:\n", n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Calculate sum
    } 
    double average = (double)sum / n; // Calculate average
    printf("Sum: %d, Average: %.2f\n", sum, average);
    free(arr); // Free allocated memory
    arr = NULL; // Avoid dangling pointer
    
}

// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int n;
    printf("Enter initial number of elements in array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be positive.\n");
        return; 
    }
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate initial memory
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }   
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }   
    printf("\n");
    int new_size;
    printf("Enter new size for array: ");
    scanf("%d", &new_size);
    if (new_size <= n) {
        printf("New size must be greater than current size.\n");
        free(arr); // Free allocated memory
        return; 
    }
    int *new_arr = (int *)realloc(arr, new_size * sizeof(int)); // Reallocate memory
    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");    
    }
    else {
        arr = new_arr; // Update pointer to new memory
        printf("Array extended to size %d.\n", new_size);
        for (int i = n; i < new_size; i++) { // Initialize new elements
            arr[i] = i; // some value
        }
        printf("New array: ");
        for (int i = 0; i < new_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr); // Free allocated memory
    arr = NULL; // Avoid dangling pointer
}

// Memory Leak Detector (simplified tracking)
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    // TODO: Track allocated pointers
    if (allocated_count >= MAX_PTRS) {
        printf("Memory leak detected: too many allocations!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL) {
        allocated_ptrs[allocated_count++] = ptr; // Store pointer in tracking array  and then increment count
    } else {
        printf("Memory allocation failed.\n");
    }
    return ptr;
}

void my_free(void *ptr) {
    // TODO: Free and update tracking
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            allocated_ptrs[i] = allocated_ptrs[--allocated_count]; // Remove pointer from tracking --allocated_count yni pehle allocated_count ko 1 kam kar diya, phir use kiya.
            return;
        }
    }
    printf("Pointer not found in allocated pointers.\n");
}

void report_leaks() {
    // TODO: Report if unfreed memory remains
    if (allocated_count > 0) {
        printf("Memory leak detected! %d pointers not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("Pointer %d: %p\n", i + 1, allocated_ptrs[i]);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

void task5_3_leak_detector() {
    // TODO: Demonstrate memory leak detection
    int *arr1 = (int *)my_malloc(10 * sizeof(int)); // Allocate memory
    if (arr1 == NULL) return; // Check allocation success
    int *arr2 = (int *)my_malloc(20 * sizeof(int)); // Allocate
    if (arr2 == NULL) {
        my_free(arr1); // Free first array if second allocation fails
        return;
    }
    // Use arrays...
    my_free(arr1); // Free first array
    // Intentionally leak second array
    // my_free(arr2); // Uncomment to avoid leak
    report_leaks(); // Report leaks
    my_free(arr2); // Free second array
    report_leaks(); // Report again after freeing
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    return 0;
}

 

// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    // task1_1();
    // int a=5, b=10; swap(&a,&b);
    // task1_3();

    // --- Part 2 ---
     //printf("\n Len = %d\n", my_strlen("Hello"));
     //char buf[100]; my_strcpy(buf,"World");
     //printf("Copied: %s\n", buf);
     //printf("Comparison: %d\n", my_strcmp("saima", "aaaa"));
    // printf("Palindrome? %s\n", is_palindrome("Madam") ? "Yes":"No");

    // --- Part 3 ---
    // task3_1_macros();
    // task3_2_fileio();

    // --- Part 4 ---
    //task4_1_linkedlist();

    // --- Part 5 ---
     task5_1_dynamic_array();
    // task5_2_realloc_array();
    // task5_3_leak_detector();
 

    return 0;
}
