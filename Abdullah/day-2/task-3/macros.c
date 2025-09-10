#include <stdio.h>
#include <stdlib.h>

// Macros
#define SQUARE(x) (x*x)                                 // Square of x
#define MAX2(a,b) (a>b?a:b)                             // Maximum of 2 values
#define MAX3(a,b,c) (MAX2(a,b)> c? MAX2(a,b): c)        // Maximum of 3 values
#define MAX4(a,b,c,d) (MAX3(a,b,c) > d? MAX3(a,b,c):d)  // Maximum of 4 values
#define TO_UPPER(c) (c-32)   // Convert to uppercase. Logic: lowercase - 32 = uppercase

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    printf("Square of x = 5 is : %d\n", SQUARE(5));
    printf("The Maximum of (2,3) is: %d\n", MAX2(2,3));
    printf("The Maximum of (2,4,6) is : %d\n", MAX3(2,4,6));
    printf("The Maximum of (2,4,6,9) is : %d\n", MAX4(2,4,6,9));
    printf("The To Upper of d is : %d\n", TO_UPPER('d'));    
}

int main() {
    task3_1_macros();
    return 0;
}