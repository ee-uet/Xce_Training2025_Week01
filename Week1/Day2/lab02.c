#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
// ======================= Part 1: Pointer Basics and Arithmetic =======================
// Task 1.1: Basic pointer usage
void task1_1() {
    int a = 10;
    int *ptr = &a;

    printf("Direct value is %d\n", a);
    printf("Value by using pointer is %d\n", *ptr);

    *ptr = 20;
    printf("New value is %d\n", a);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a = %d\nb = %d\n", *a, *b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        printf("%d\n", *p);
        p++;
    }

    int sum = 0;
    p = arr;
    for (int i = 0; i < n; i++) {
        sum += *p;
        p++;
    }
    printf("Sum is %d\n", sum);

    // Reverse in place
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Reversed array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

// ======================= Part 2: Pointers and Arrays/Strings =======================

int my_strlen(const char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int is_palindrome(const char *s) {
    const char *start = s;
    const char *end = s + strlen(s) - 1;
    while (start < end) {
        if (tolower(*start) != tolower(*end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// ======================= Part 3: Preprocessor & File I/O =======================

#define SQUARE(x)       ((x) * (x))
#define MAX2(a,b)       ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c)     (MAX2(MAX2((a),(b)),(c)))
#define MAX4(a,b,c,d)   (MAX2(MAX2((a),(b)), MAX2((c),(d))))
#define TO_UPPER(c)     (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))

void task3_1_macros() {
    printf("Square of 5 is %d\n", SQUARE(5));
    printf("Max of 6 and 3 is %d\n", MAX2(6, 3));
    printf("Max of 10, 7 and 3 is %d\n", MAX3(10, 7, 3));
    printf("Max of 1, 2, 3 and 4 is %d\n", MAX4(1, 2, 3, 4));
    printf("Uppercase of 'b' is %c\n", TO_UPPER('b'));
    printf("Uppercase of 'Z' is %c\n", TO_UPPER('Z'));
}

struct Student {
    char name[50];
    int roll;
    float gpa;
};

void task3_2_fileio() {
    struct Student students[5] = {
        {"U", 1, 3.1},
        {"V", 2, 3.2},
        {"X", 3, 3.5},
        {"Y", 4, 3.4},
        {"Z", 5, 3.3}
    };
    int maxgpa = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].gpa > students[maxgpa].gpa) {
            maxgpa = i;
        }
    }
    printf("Student with maximum GPA is %s\n", students[maxgpa].name);

    FILE *fp = fopen("students.txt", "w");
    if (!fp) {
        printf("Error!\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (!fp) {
        printf("Error!\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].roll, &students[i].gpa);
    }
    fclose(fp);

    printf("\nReading data back from file:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
}

// ======================= Part 4: Linked List =======================

struct Node {
    int data;
    struct Node *next;
};

struct Node *insert_begin(struct Node *head, int value) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}

struct Node *delete_value(struct Node *head, int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return head;
    if (!prev) head = head->next;
    else prev->next = temp->next;
    free(temp);
    return head;
}

void print_list(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List is ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    struct Node *head = NULL;
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    print_list(head);
    head = delete_value(head, 10);
    print_list(head);
}

// ======================= Part 5: Dynamic Memory =======================

void task5_1_dynamic_array() {
    int n, sum = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum is %d and average is %f\n", sum, (float)sum / n);
    free(arr);
}

void task5_2_realloc_array() {
    int n, newsize;
    printf("Enter size: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter new size: ");
    scanf("%d", &newsize);
    arr = (int *)realloc(arr, newsize * sizeof(int));
    printf("Enter %d elements for extended array:\n", newsize);
    for (int i = 0; i < newsize; i++) scanf("%d", &arr[i]);

    printf("Final array: ");
    for (int i = 0; i < newsize; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

// Simple memory leak detector
#define MAX_PTRS 100
void *allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void *my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Error!\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr) allocated_ptrs[allocated_count++] = ptr;
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) return;
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            for (int j = i; j < allocated_count - 1; j++)
                allocated_ptrs[j] = allocated_ptrs[j + 1];
            allocated_count--;
            return;
        }
    }
    printf("Trying to free untracked pointer %p\n", ptr);
}

void report_leaks() {
    if (allocated_count == 0) printf("No memory leaks!\n");
    else {
        printf("Memory leaks detected: %d\n", allocated_count);
        for (int i = 0; i < allocated_count; i++)
            printf("Leak at pointer: %p\n", allocated_ptrs[i]);
    }
}

void task5_3_leak_detector() {
    int *arr1 = (int *)my_malloc(5 * sizeof(int));
    int *arr2 = (int *)my_malloc(3 * sizeof(int));
    my_free(arr1);
    // my_free(arr2);
    report_leaks();
}

// ======================= Part 6: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
	while (b != 0) {
        int carry = a & b;   
        a = a ^ b;           
        b = carry << 1;     
    }
    return a;
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
	int n = 8; 
    int A = 0;
	int Q = multiplier;
	int Q_1 = 0;
	
    for(int i=0; i<n; i++) {
        int Q0 = Q & 1;

        if(Q0 == 1 && Q_1 == 0) {
            A = A - multiplicand;
         
        } else if(Q0 == 0 && Q_1 == 1) {
            A = A + multiplicand;
        }
        int msbA = A >> 7;
        Q_1 = Q & 1;
        Q = (Q >> 1) | ((A & 1) << 7);
        A = (A >> 1) | (msbA << 7);
    }

    return (A << 8) | (Q & 0xFF);
}

void test_booth() {
    printf("7 + 5 = %d\n", add(7, 5));
    printf("7 * 5 = %d\n", booth_multiply(7, 5));
    printf("-7 * 5 = %d\n", booth_multiply(-7, 5));
    printf("-7 * 0 = %d\n", booth_multiply(-7, 0));
    printf("5 * 0 = %d\n", booth_multiply(5, 0));


}

// ======================= Main =======================

int main() {
    task1_1();
    int a = 5, b = 10;
    swap(&a, &b);
    task1_3();

    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100];
    my_strcpy(buf, "World");
    printf("Copied: %s\n", buf);
    printf("%d\n", my_strcmp("Whatever", "What"));
    printf("Palindrome? %s\n", is_palindrome("Whatever") ? "Yes" : "No");

    task3_1_macros();
    task3_2_fileio();

    task4_1_linkedlist();

    task5_1_dynamic_array();
    task5_2_realloc_array();
    task5_3_leak_detector();

    test_booth();

    return 0;
}
