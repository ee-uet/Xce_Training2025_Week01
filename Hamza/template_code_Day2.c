#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void task1_1() {
    int n = 5;
    int *p;
    p = &n;

    printf("value directly: %d\n", n);
    printf("value via pointer: %d\n", *p);

    *p = 10;
    printf("new value directly: %d\n", n);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void task1_3() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    int sum = 0;
    int n = 5;
    
    printf("elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
        sum += *(p + i);
    }
    printf("\n");

    printf("sum: %d\n", sum);

    for (int i = 0; i < n / 2; i++) {
        swap(p + i, p + n - 1 - i);
    }

    printf("reversed: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int my_strlen(const char *s) {
    const char *p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

void my_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0');
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int is_palindrome(const char *s) {
    int len = my_strlen(s);
    char *lower = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) {
            lower[j++] = tolower(s[i]);
        }
    }
    lower[j] = '\0';

    int ispal = 1;
    for (int i = 0; i < j / 2; i++) {
        if (lower[i] != lower[j - 1 - i]) {
            ispal = 0;
            break;
        }
    }
    free(lower);
    return ispal;
}

#define SQUARE(x) ((x) * (x))
#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) (MAX2(MAX2(a,b),c))
#define MAX4(a,b,c,d) (MAX2(MAX2(a,b),MAX2(c,d)))
#define TO_UPPER(c) ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))

void task3_1_macros() {
    printf("5 squared is %d\n", SQUARE(5));
    printf("max of 10, 20 is %d\n", MAX2(10, 20));
    printf("max of 10, 20, 5 is %d\n", MAX3(10, 20, 5));
    printf("max of 10, 20, 5, 40 is %d\n", MAX4(10, 20, 5, 40));
    printf("a in upper is %c\n", TO_UPPER('a'));
}

struct Student {
    char name[50];
    int roll;
    float gpa;
};

void task3_2_fileio() {
    struct Student students[5];
    printf("enter details for 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("student %d roll: ", i + 1);
        scanf("%d", &students[i].roll);
        printf("student %d gpa: ", i + 1);
        scanf("%f", &students[i].gpa);
    }
    
    struct Student highest_gpa_student = students[0];
    for (int i = 1; i < 5; i++) {
        if (students[i].gpa > highest_gpa_student.gpa) {
            highest_gpa_student = students[i];
        }
    }
    printf("student with highest gpa: %s\n", highest_gpa_student.name);

    FILE *fp = fopen("students.txt", "w");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].roll, students[i].gpa);
    }
    fclose(fp);

    printf("reading from file:\n");
    fp = fopen("students.txt", "r");
    while (fscanf(fp, "%s %d %f", students[0].name, &students[0].roll, &students[0].gpa) != EOF) {
        printf("name: %s, roll: %d, gpa: %.2f\n", students[0].name, students[0].roll, students[0].gpa);
    }
    fclose(fp);
}

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

struct Node* delete_value(struct Node *head, int value) {
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return head;

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return head;
}

void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void task4_1_linkedlist() {
    struct Node *head = NULL;
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    printf("list after inserts: ");
    print_list(head);

    head = delete_value(head, 20);
    printf("list after deleting 20: ");
    print_list(head);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void task5_1_dynamic_array() {
    int size;
    printf("enter array size: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("memory error\n");
        return;
    }

    printf("enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("sum: %d\n", sum);
    printf("average: %.2f\n", (float)sum / size);
    free(arr);
}

void task5_2_realloc_array() {
    int *arr = (int*)malloc(3 * sizeof(int));
    if (arr == NULL) return;
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    printf("original array: %d %d %d\n", arr[0], arr[1], arr[2]);

    arr = (int*)realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        printf("realloc failed\n");
        return;
    }
    arr[3] = 4; arr[4] = 5;
    printf("extended array: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
}

#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    void* p = malloc(size);
    if (p != NULL && allocated_count < MAX_PTRS) {
        allocated_ptrs[allocated_count++] = p;
    }
    return p;
}

void my_free(void *ptr) {
    for (int i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            free(ptr);
            allocated_ptrs[i] = allocated_ptrs[--allocated_count];
            return;
        }
    }
}

void report_leaks() {
    if (allocated_count == 0) {
        printf("no memory leaks detected\n");
    } else {
        printf("memory leaks detected: %d pointers unfreed\n", allocated_count);
    }
}

void task5_3_leak_detector() {
    void *p1 = my_malloc(10);
    void *p2 = my_malloc(20);
    my_free(p1);
    report_leaks();
}





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
    printf("booth 5 * 3 = %d\n", booth_multiply(5, 3));
    printf("booth 5 * -3 = %d\n", booth_multiply(5, -3));
    printf("booth -5 * 3 = %d\n", booth_multiply(-5, 3));
    printf("booth -5 * -3 = %d\n", booth_multiply(-5, -3));
    printf("booth 0 * 100 = %d\n", booth_multiply(0, 100));
}

int main() {
    task1_1();
    int a = 5, b = 10;
    swap(&a, &b);
    printf("swapped: a=%d, b=%d\n", a, b);
    task1_3();

    printf("len = %d\n", my_strlen("Hello"));
    char buf[100];
    my_strcpy(buf, "World");
    printf("copied: %s\n", buf);
    printf("strcmp result: %d\n", my_strcmp("hello", "Hello"));
    printf("palindrome? %s\n", is_palindrome("Madam") ? "Yes" : "No");

    task3_1_macros();
    task3_2_fileio();

    task4_1_linkedlist();

    task5_1_dynamic_array();
    task5_2_realloc_array();
    task5_3_leak_detector();

    test_booth();

    return 0;
}
