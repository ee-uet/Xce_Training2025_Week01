#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    int a = 10;
    int *p = &a;
    printf("%d\n", a);
    printf("%d\n", *p);
    *p = 20;
    printf("%d\n", *p);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
     printf("%d\n", *a);
      printf("%d\n", *b);
}

// Task 1.3: Pointer arithmetic on array
void task1_3() {
    int a[] = {1,2,3,4,5};
    int len = sizeof(a)/sizeof(a[0]);
    int *p = a;
    int i, b = 0;

    for (i = 0; i < len; i++) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");

    p = a; 
    for (i = 0; i < len; i++) {
        b += *p;
        p++;
    }
    printf("Sum: %d\n", b);

    p = &a[len-1];  
    for (i = 0; i < len; i++) {
        printf("%d ", *p);
        p--;
    }
    printf("\n");
}

// ======================= Part 2: Pointers and Arrays/Strings =======================

int my_strlen(const char *s) {
    const char *p = s;
    int count = 0;
    while (*p != '\0') {
        count++;
        p++;
    }
    return count;
}

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    int diff = (*s1 - *s2);
    if (diff < 0) printf("1st string is smaller\n");
    else if (diff > 0) printf("2nd string is smaller\n");
    return diff;
}

int is_palindrome(const char *s) {
    const char *p = s + strlen(s) - 1;
    while (s < p) {
        if (tolower(*s) != tolower(*p)) return 0;
        s++;
        p--;
    }
    return 1;
}

// ======================= Part 3: Preprocessor & File I/O =======================
void task3_1_macros(){
#define SQUARE(x) ((x)*(x))
#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define MAX4(a,b,c,d) ((a) > (b) ? ((a) > (c) ? ((a) > (d) ? (a) : (d)) : ((c) > (d) ? (c) : (d))) : ((b) > (c) ? ((b) > (d) ? (b) : (d)) : ((c) > (d) ? (c) : (d)))))
#define TO_UPPER(c) (toupper(c))
};
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float gpa;
};

void task3_2_fileio() {
    struct Student a[5] = {
        {"zahra", 51, 3.6},
        {"alishba", 6, 3.33},
        {"mariam", 10, 3.4},
        {"laiba", 7, 3.4},
        {"areeba", 56, 3.2}
    };

    // Find student with highest GPA
    float h_gpa = a[0].gpa;
    int idx = 0;
    int i;
    for (i = 1; i < 5; i++) {
        if (h_gpa < a[i].gpa) {
            h_gpa = a[i].gpa;
            idx = i;
        }
    }
    printf("Student with highest GPA: %s, GPA: %.2f\n", a[idx].name, h_gpa);

    // Write one student to file
    FILE *p = fopen("a.txt", "w");
    if (p != NULL) {
        fprintf(p, "Name: %s GPA: %.2f\n", "Hamna", 3.85);
        fclose(p);
    }

    // Read a student from file
    char name[50];
    float gpa;
    FILE *fp = fopen("a.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "Name: %s GPA: %f", name, &gpa);
        printf("Read from file -> Name: %s, GPA: %.2f\n", name, gpa);
        fclose(fp);
    }
}


// ======================= Part 4: Linked List =======================
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    struct Node* a = malloc(sizeof(struct Node));
    a->data = value;
    a->next = head;
    return a;
}

struct Node* delete_value(struct Node *head, int value) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr) {
        if (curr->data == value) {
            if (prev == NULL) head = curr->next;
            else prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void print_list(struct Node *head) {
    while (head) {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

void task4_1_linkedlist() {
    struct Node* head = NULL;

    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);

    print_list(head);

    head = delete_value(head, 20);
    printf("After deletion:\n");
    print_list(head);

    // free remaining nodes
   
}

// ======================= Part 5: Dynamic Memory =======================

void* my_malloc(size_t size);
void my_free(void *ptr);
void report_leaks(void);

#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count < MAX_PTRS) {
        void *p = malloc(size);
        allocated_ptrs[allocated_count++] = p;
        return p;
    }
    return NULL;
}

void my_free(void *ptr) {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            allocated_ptrs[i] = NULL;
            break;
        }
    }
    free(ptr);
}

void report_leaks() {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i]) printf("%p not free\n", allocated_ptrs[i]);
    }
}

void task5_1_dynamic_array() {
    int num;
    scanf("%d", &num);
    int *a = my_malloc(num * sizeof(int));
    int i, sum = 0, integer;
    for (i = 0; i < num; i++) {
        scanf("%d", &integer);
        a[i] = integer;
        sum += a[i];
    }
    printf("%d %.2f\n", sum, (float)sum / num);
    free(a);
}

void task5_2_realloc_array() {
    int num = 3;
    int *a = my_malloc(num * sizeof(int));
    a[0] = 1; a[1] = 2; a[2] = 3;
    a = realloc(a, (num + 1) * sizeof(int));
    a[3] = 4;
    for (int i = 0; i < num + 1; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
}

void task5_3_leak_detector() {
    int *p1 = my_malloc(5 * sizeof(int));
    double *p2 = my_malloc(3 * sizeof(double));
    char *p3 = my_malloc(10 * sizeof(char));
    my_free(p2);
    report_leaks();
}

// ======================= Part 6: Booth's Multiplication =======================



// Bitwise addition 
int16_t sum(int16_t a, int16_t b) {
    while (b != 0) {
        uint16_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Booth's multiplication
int32_t booth_multiply(int16_t M, int16_t Q) {
    int16_t A = 0;
    int Q_1 = 0;
    int n = 16;

    for (int i = 0; i < n; i++) {
        int Q0 = Q & 1;

        if (Q0 == 1 && Q_1 == 0)
            A = sum(A, -M);
        else if (Q0 == 0 && Q_1 == 1)
            A = sum(A, M);

        int new_Q1 = Q & 1;

        // Combine A and Q into 32-bit
        int32_t combined = ((int32_t)A << 16) | ((uint16_t)Q);
        combined >>= 1;  // arithmetic shift
        A = combined >> 16;
        Q = combined & 0xFFFF;

        Q_1 = new_Q1;
    }

    return ((int32_t)A << 16) | ((uint16_t)Q);
}

 
void test_booth() {
    printf(" 7 * 6 = %d\n", booth_multiply(7, 6));
    printf(" 7 * -4 = %d\n", booth_multiply(7, -4));
    printf("-9 * 5 = %d\n", booth_multiply(-9, 5));
    printf("-8 * -3 = %d\n", booth_multiply(-8, -3));
    printf(" 0 * 10 = %d\n", booth_multiply(0, 10));
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
     //task5_1_dynamic_array();
     //task5_2_realloc_array();
     //task5_3_leak_detector();

    // --- Final Task ---
    // test_booth();

    return 0;
}
