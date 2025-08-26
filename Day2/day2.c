#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
// ======================= Part 1: Pointer Basics and Arithmetic =======================

// Task 1.1: Basic pointer usage
void task1_1() {
    // TODO: Declare int variable, pointer to it
    // Print value using direct and pointer
    // Modify via pointer and print new value
    int x = 10;
    int *ptr = &x;
    *ptr = 20;
    printf("Modified Value: %d\n", *ptr);
}

// Task 1.2: Swap two integers using pointers
void swap(int *a, int *b) {
    // TODO: Implement swap using pointers
    printf("Current Values: a = %d, b = %d\n", *a, *b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("After Swapping: a = %d, b = %d\n", *a, *b);
}

// Task 1.3: Pointer arithmetic on array
#define ARR_SIZE 5
void task1_3() {
    // TODO: Create an array
    // Print all elements using pointers
    // Calculate sum
    // Reverse in place
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *ptr = arr; 
    printf("Array Elements: ");

    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", *(ptr + i)); 
        sum += *(ptr + i); // Summing elements
    }
    printf("\nSum: %d\n", sum);

    // Reverse the array in place
    for (int i = 0; i < ARR_SIZE / 2; i++) {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + (ARR_SIZE - 1 - i));
        *(ptr + (ARR_SIZE - 1 - i)) = temp;
    } 
    printf("Reversed Array: ");
    
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", *(ptr + i)); 
    } 
    printf("\n");
}

// ======================= Part 2: Pointers and Arrays/Strings =======================

// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    const char *ptr = s;
    int length = 0;
    while (*ptr) {
        length++;
        ptr++;
    }
    return length;
}


// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    int i = 0;
    char temp;
    while((*dest++ = *src++)) {
      //temp = *(src+i);
      //*(dest + i) = temp;
      //i++; 
    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    while ((*s1 == *s2) && *s1 == '\0' && *s2 == '\0'){
      s1++;
      s2++;
    }
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // Pointers to the first and last characters of the string
    const char *start = s;
    const char *end = s + strlen(s) - 1; // Assuming you have strlen

    // Loop until the pointers meet or cross
    while (start < end) {
      // Dereference pointers to compare the actual characters
      if (*start != *end) {
        return 0; // Not a palindrome
      }
      
      // Move pointers inward
      start++;
      end--;
    }

    return 1; // It's a palindrome
}


// ======================= Part 3: Preprocessor & File I/O =======================

// Macros
#define SQUARE(x) (x*x)     
#define MAX2(a,b) (a>b?a:b)
#define MAX3(a,b,c) (MAX2(a,b)> c? MAX2(a,b): c)
#define MAX4(a,b,c,d) (MAX3(a,b,c) > d? MAX3(a,b,c):d)
#define TO_UPPER(c) (c-32) 

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("Square of x = 5 is : %d\n", SQUARE(5));
    printf("The Maximum of (2,3) is: %d\n", MAX2(2,3));
    printf("The Maximum of (2,4,6) is : %d\n", MAX3(2,4,6));
    printf("The Maximum of (2,4,6,9) is : %d\n", MAX4(2,4,6,9));
    printf("The To Upper of d is : %d\n", TO_UPPER('d'));    
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
    
    struct Student student[5];
    struct Student *highest_gpa = &student[0];
    
    for (int i = 0; i<5; i++) {
      printf("Enter the name of Student %d: ",i+1);
      scanf("%49s", student[i].name);
      printf("Enter the GPA of Student %d: ",i+1);
      scanf("%f", &student[i].gpa);
      printf("Enter the roll of Student %d: ", i+1);
      scanf("%d", &student[i].roll);
      
      if (student[i].gpa > highest_gpa->gpa) {
        highest_gpa = &student[i];}     
    }
    printf("The Student with highest GPA is: %s , %d, %f.\n", highest_gpa->name, highest_gpa->roll, highest_gpa->gpa);
  
    FILE *studentsfile = fopen("students.txt", "w");
    if (studentsfile == NULL) {
      printf("Failed to open.");
    }
    for (int i = 1; i < 5; i++) { 
    fprintf(studentsfile, "%s %d %f\n", student[i].name, student[i].roll, student[i].gpa); 
    } 
    fclose(studentsfile);
    
    struct Student temp;
    FILE *students_file = fopen("students.txt", "r");
    if (students_file == NULL) {
      printf("Failed to open.");
    }
    for (int i = 1; i < 5; i++) { 
    fscanf(students_file, "%s %d %f\n", temp.name, &temp.roll, &temp.gpa); 
    printf("Read from students.txt : %s, %d, %f", temp.name, temp.roll, temp.gpa);
    }
    fclose(students_file);
    
}



// ======================= Part 4: Advanced Challenge =======================

// Linked List Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_begin(struct Node *head, int value) {
    // TODO: Insert new node at beginning
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    if (new_Node == NULL){
      printf("Memory Allocation failed!");
      return head;}
    new_Node->data = value;
    new_Node->next = head;
    head = new_Node;
    return head;
}

struct Node* delete_value(struct Node *head, int value) {
    // TODO: Delete node by value
    struct Node *current = head;
    struct Node *prev = NULL;

    //if head is to be deleted
    if ((current != NULL) && (current->data == value)) {
      head = current->next;
      free(current);
      return head;
      }
    while ((current != NULL)&&(current->data != value)) {
      prev = current;
      current = current->next;
    }
    if (current == NULL) {
      return head;
      }
      
    prev->next = current->next;
    free(current);
    return head;
}

void print_list(struct Node *head) {
    // TODO: Print linked list
    struct Node *current = head;
    while (current != NULL) {
      printf("%d \n", current->data);
      current = current->next;
      }
    printf("End of Linked List!\n");      
}

void task4_1_linkedlist() {
    // TODO: Test insert, delete, print
    struct Node *head = NULL;
    
    head = insert_begin(head, 10);
    head = insert_begin(head, 20);
    head = insert_begin(head, 30);
    
    print_list(head);
    head = delete_value(head, 30);
    print_list(head);
}


// ======================= Part 5: Dynamic Memory Allocation =======================

// Task 5.1: Dynamic array, sum, average
void task5_1_dynamic_array() {
    // TODO: malloc array, input elements, compute sum and avg
    int size = 0;
    printf("Enter the number size of arrray: ");
    scanf("%d",&size);
    int *ptr = (int *) malloc(size * sizeof(int));
    int sum = 0;
    if (ptr==NULL) {
      printf("Memory Allocation Failed!");
      }
    for (int i = 0; i < size ; i++) {
      printf("Enter number %d :", i+1);
      scanf("%d",(ptr+i));
      sum = sum + *(ptr+i);
    }printf ("Sum of the Elements: %d\nAverage of the Elements: %d\n", sum, sum/size);
    free(ptr);
}


void task5_2_realloc_array() {
    // TODO: realloc to extend existing array
    int n1 = 5, n2 = 10, i;
    int *arr;

    // Initial allocation
    arr = (int *)malloc(n1 * sizeof(int));
    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return;
    }

    printf("Initially allocated for %d elements.\n", n1);
    for (i = 0; i < n1; i++) {
        arr[i] = i + 1; // Fill with some data
    }

    // Extend the array using realloc
    printf("Reallocating to hold %d elements.\n", n2);
    int *temp = (int *)realloc(arr, n2 * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        free(arr); // Free the original block
        return;
    }
    arr = temp; // Point to the new, possibly moved, block

    // Fill the new part of the array
    for (i = n1; i < n2; i++) {
        arr[i] = i + 1;
    }

    // Print the final array
    printf("Final array contents: ");
    for (i = 0; i < n2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}


// Note: These global variables are part of the template
#define MAX_PTRS 100
void* allocated_ptrs[MAX_PTRS];
int allocated_count = 0;

void* my_malloc(size_t size) {
    if (allocated_count >= MAX_PTRS) {
        printf("Leak detector can't track any more pointers.\n");
        return malloc(size); // Allocate without tracking
    }
    
    void *ptr = malloc(size);
    if (ptr != NULL) {
        // Track the allocated pointer
        allocated_ptrs[allocated_count] = ptr;
        allocated_count++;
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) return;

    int i, found = -1;
    // Find the pointer in our tracking array
    for (i = 0; i < allocated_count; i++) {
        if (allocated_ptrs[i] == ptr) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        // Shift remaining pointers to fill the gap
        for (i = found; i < allocated_count - 1; i++) {
            allocated_ptrs[i] = allocated_ptrs[i + 1];
        }
        allocated_count--;
    }
    
    free(ptr); // Free the actual memory
}

void report_leaks() {
    printf("--- Memory Leak Report ---\n");
    if (allocated_count == 0) {
        printf("No memory leaks detected. Well done!\n");
    } else {
        printf("Warning! %d block(s) of memory were not freed:\n", allocated_count);
        for (int i = 0; i < allocated_count; i++) {
            printf("  - Leaked block at address: %p\n", allocated_ptrs[i]);
        }
    }
    printf("--------------------------\n");
}

void task5_3_leak_detector() {
    printf("\nMemory leak detection...\n");
    
    // Allocate three blocks of memory
    int *p1 = (int*)my_malloc(sizeof(int));
    char *p2 = (char*)my_malloc(10 * sizeof(char));
    int *p3 = (int*)my_malloc(5 * sizeof(int));
    
    printf("Allocated 3 blocks.\n");
    
    // Free only two of them
    printf("Freeing 2 blocks.\n");
    my_free(p1);
    my_free(p3);
    
    // Generate the report
    report_leaks(); // This should report that p2 was leaked
        printf("Freeing remaining blocks.\n");
    // Cleanup the intentionally leaked block for a clean run
    my_free(p2);
}


// ======================= Final Task: Booth's Multiplication =======================

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    while (b!=0) {
      int carry = (a&b)<<1;
      a = a^b;
      b = carry;
    }
    return a;
}
    // Arithimatic Right Shifter
void arithmatic_right_shifter(int *A,int *Q, int *Q1) {
    *Q1 = *Q & 1;
    // Safer and cleaner way to combine
    long long combined = ((long long)*A << 32) | (unsigned int)*Q;
    combined >>= 1;
    *A = (int)(combined >> 32);
    *Q = combined;
}

int twos_complement(int M){
      int num = M;
      num = ~num;
      num = num + 0x00000001;
      return num;
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    int M = multiplicand;
    int Q = multiplier;
    int n_bits = 32;
    int A = 0;
    int Q1 = 0;

    for (int i = 0; i<n_bits; i++) {
      int Q0 = 1 & Q;
      if (Q0 == 0 && Q1 == 1) {
        A = add(M,A);
      }
      else if (Q0 == 1 && Q1 == 0) {
        int neg_M = twos_complement(M);
        A = add(A,neg_M);
      }
      arithmatic_right_shifter(&A,&Q,&Q1);
      }
    //return Q;
    return ((long long)A << 32) | (unsigned int)Q;
}
    

    


void test_booth() {
    int a, b;

    // Positive numbers
    a = 7; b = 3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Negative * Positive
    a = -7; b = 3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Positive * Negative
    a = 7; b = -3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Negative * Negative
    a = -7; b = -3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Multiplication by Zero
    a = 1234; b = 0;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Multiplication by One
    a = 999; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: INT_MAX * 1
    a = INT_MAX; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: INT_MIN * 1
    a = INT_MIN; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: Overflow (note: result may overflow 32-bit int!)
    a = 50000; b = 50000;
    printf("Test %d * %d = %d (Expected %d, may overflow)\n", a, b, booth_multiply(a, b), a * b);
}



// ======================= Main =======================
int main() {
    // Uncomment and run tasks as you implement

    // --- Part 1 ---
    // task1_1();
    // int a=5, b=10; swap(&a,&b);
    // task1_3();

    // --- Part 2 ---
     printf("Len = %d\n", my_strlen("Helllo"));
     char buf[100]; my_strcpy(buf,"World");
     printf("Copied: %s\n", buf);
     printf("Palindrome? %s\n", is_palindrome("mama") ? "Yes":"No");

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
    // test_booth();

    return 0;
}
