#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ======================= Part 1: Pointer Basics and Arithmetic =======================
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
// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    printf("Value of a is %d and of b is %d\n", *a,*b);
    int c = *a;
    *a = *b;
    *b = c;
    printf("Values of a and b after swapping are %d and %d respectively\n", *a,*b);
}
// Task 1.3: Pointer arithmetic on array
void task1_3() {
    int sum = 0;int length;
    // TODO: Create an array
    int arr[5] = {1,2,3,4,5};
    length = sizeof(arr) / sizeof(arr[0]);
    // Print all elements using pointers
    printf("array elements: ");
    for (int i=0;i<length;i++){
    printf("%d  ",*(arr+i));
    }
    printf("\n");
    // Calculate sum
    for (int i=0;i<length;i++){
        sum = sum + *(arr+i);
        }
    printf("Sum of array elements: %d\n",sum);
    // Reverse in place
 
    int *start = arr;
    int *end = arr + (length - 1);
    int loop = length/2;
    for (int j=0;j<=loop;j++){
    swap (start,end);
    
    start++;
    end--;
    }
    printf("swapped array elements: ");
    for (int i=0;i<length;i++){
    printf("%d  ",*(arr+i));
    }
    printf("\n");
}
// ======================= Part 2: Pointers and Arrays/Strings =======================
// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int length = 0;
    while(*s != '\0'){
        length++;
        s++;
    }
    return length;
}
// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    int src_len = my_strlen(src);
    for (int i=0;i<src_len;i++){
        dest[i] = *(src+i);
    }
}
// Custom strcmp using pointers
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
// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    int str_len = my_strlen(s);  int loop = str_len/2;
    const char *start = s;
    const char *end = (s + str_len)-1;
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
// ======================= Part 3: Preprocessor & File I/O =======================
// Macros
#define SQUARE(x)   ((x)*(x))
#define MAX2(a,b)    (((a)>(b)) ? (a):(b))
#define MAX3(a,b,c)  ((a) > (b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c))
//#define MAX4(a,b,c,d)  ((a)>(b)) ? (((a)>(c)) ? (((a)>(d) ? (a) : (d)) : ((c)>(d) ? (c):(d))) : (((b)>(c)) ? ((b)>(d) ? (b) : (d)) : ((c)>(d) ? (c):(d))))
#define MAX4(a,b,c,d) (MAX2(MAX2(a,b),MAX2(c,d)))
#define TO_UPPER(c)  (((c) >= 'a' && (c) <= 'z') ? ((c) - 'a' + 'A') : (c))
void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    int x = 2+3;
    int a,b,c,d;
    a=3;b=6;c=5;d=2;
    //SQUARE
    printf("SQUARE macro demo : (2+3)^2 = %d\n",SQUARE(x));
    //MAX2
    printf("MAX2 macro demo: which is greater, %d or %d. ans = %d\n",a,b,MAX2(a,b));
    //MAX3
    printf("MAX3 macro demo: which is greater, %d or %d or %d. ans = %d\n",a,c,d,MAX3(a,d,c));
    //MAX4
    printf("MAX4 macro demo: which is greater, %d or %d or %d or %d. ans = %d\n",a,b,c,d,MAX4(a,b,c,d));
    //TO_UPPER
    printf("TO_UPPER macro demo: f, D, g -> %c, %c, %c\n",TO_UPPER('f'),TO_UPPER('D'),TO_UPPER('g'));
}
// Student struct
struct Student {
    char name[50];
    int roll;
    float gpa;
};
// Task 3.2: File I/O
void task3_2_fileio() {
    struct Student students[5] = {
        {"Hiba",   1, 3.5},
        {"Sara",   2, 3.8},
        {"Usman",  3, 3.2},
        {"Ayesha", 4, 3.9},
        {"Bilal",  5, 3.6}
    };

    // Print student with highest GPA
    int topIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (students[i].gpa > students[topIndex].gpa) {
            topIndex = i;
        }
    }

    printf("Top student:\n");
    printf("Roll: %d\n", students[topIndex].roll);
    printf("Name: %s\n", students[topIndex].name);
    printf("GPA: %.2f\n\n", students[topIndex].gpa);

    // Save all students to file
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].roll, students[i].name, students[i].gpa);
    }
    fclose(fp);
    printf("All students saved to students.txt\n");
    // Now read back only 2 students and find highest
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char name[50], top_name[50];
    int roll, top_roll;
    float gpa, top_gpa = -1.0;

    for (int i = 0; i < 2; i++) {
        if (fscanf(fp, "%d %s %f", &roll, name, &gpa) == 3) {
            if (gpa > top_gpa) {
                top_gpa = gpa;
                top_roll = roll;
                // copy name
                int j = 0;
                while ((top_name[j] = name[j]) != '\0') j++;
            }
        }
    }

    fclose(fp);

    printf("\nHighest GPA among first 2 read from file:\n");
    printf("Name: %s\nRoll: %d\nGPA: %.2f\n", top_name, top_roll, top_gpa);
}
// ======================= Part 4: Advanced Challenge =======================
// Linked List Node
struct Node {
    int data;
    struct Node *next;
};
struct Node* insert_begin(struct Node *head, int value) {
    // Allocate new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head; // point to old head
    return newNode;       // new node becomes head
}
struct Node* delete_value(struct Node *head, int value) {
    if (head == NULL) return head;

    struct Node *temp = head;
    struct Node *prev = NULL;

    // If head itself holds the value
    if (temp != NULL && temp->data == value) {
        head = temp->next; // move head
        free(temp);        // free old head
        return head;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) return head;

    // Unlink node
    prev->next = temp->next;
    free(temp);

    return head;
}
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
// ======================= Part 5: Dynamic Memory Allocation =======================
// Task 5.1: Dynamic array, sum, average
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
// Task 5.2: Extend array with realloc
void task5_2_realloc_array() {
    int *arr = NULL;
    int n, new_n, i;

    // Step 1: Ask user for initial size
    printf("Enter initial size of array: ");
    scanf("%d", &n);

    // Step 2: Allocate memory for 'n' integers
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Step 3: Input initial elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Ask for new size (must be greater than old size)
    printf("Enter new size of array (greater than %d): ", n);
    scanf("%d", &new_n);

    // Step 5: Reallocate memory
    int *temp = realloc(arr, new_n * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        free(arr); // Free old memory
        return;
    }
    arr = temp; // Point arr to new memory

    // Step 6: Input new elements for extended part
    printf("Enter %d new elements:\n", new_n - n);
    for (i = n; i < new_n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 7: Print full array
    printf("Final array elements:\n");
    for (i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 8: Free memory
    free(arr);

}
// Memory Leak Detector (simplified tracking)
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

// Free memory and remove from tracking
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

// ======================= Final Task: Booth's Multiplication =======================

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



// ======================= Main =======================
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
