#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ======================= Part 3: Preprocessor & File I/O =======================

#define SQUARE(x) ((x)*(x))
#define MAX2(a,b) ((a) > (b) ? (a) : (b))
#define MAX3(a,b,c) (MAX2(MAX2(a,b), c))
#define MAX4(a,b,c,d) (MAX2(MAX2(MAX2(a,b), c), d))
#define TO_UPPER(c) ((c) >= 'a' && (c) <= 'z' ? ((c) - 32) : (c))

void task3_1_macros() {
    // TODO: Demonstrate macros with test cases
     // --- Part 3 ---
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("MAX2(3,7) = %d\n", MAX2(3,7));
    printf("MAX3(3,7,5) = %d\n", MAX3(3,7,5));
    printf("MAX4(3,7,5,10) = %d\n", MAX4(3,7,5,10));
    char ch1 = 'g';
    char ch2 = 'A';

    printf("%c to %c\n", ch1, TO_UPPER(ch1)); 
    printf("%c to %c\n", ch2, TO_UPPER(ch2));
}


// ======================= Main =======================
int main() {
    


   

    task3_1_macros();

    return 0;
}
