#include <stdio.h>

// Macros
#define SQUARE(x) ((x)*(x))    
#define MAX2(a,b) ((a > b) ? a:b)
#define MAX3(a,b,c) (MAX2(MAX2(a,b),c))
#define MAX4(a,b,c,d) (MAX2(MAX3(a,b,c),d))
#define TO_UPPER(c) ((c >= 'a' && c <= 'z') ? (c-32): c )

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
    int x = 5, y = 10, z = 3, w = 15;

    printf("SQUARE(%d) = %d\n", x, SQUARE(x));
    printf("MAX2(%d, %d) = %d\n", x, y, MAX2(x, y));
    printf("MAX3(%d, %d, %d) = %d\n", x, y, z, MAX3(x, y, z));
    printf("MAX4(%d, %d, %d, %d) = %d\n", x, y, z, w, MAX4(x, y, z, w));

    char c1 = 'a', c2 = 'Z';
    printf("TO_UPPER('%c') = %c\n", c1, TO_UPPER(c1));
    printf("TO_UPPER('%c') = %c\n", c2, TO_UPPER(c2));
}

// ======================= Main =======================
int main() {
    
    task3_1_macros();
    
    return 0;
}
