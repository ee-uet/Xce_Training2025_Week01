#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for 'tolower'


#define SQUARE(x) ((x)*(x))  
#define MAX2(a,b)  ((a>b)?a:b) 
#define MAX3(a,b,c)  MAX2(MAX2(a,b),c) 
#define MAX4(a,b,c,d) MAX2(MAX3(a,b,c),d)
#define TO_UPPER(c)   (toupper(c))

void task3_1_macros() {
    int x = 5, y = 10, z = 15, w = 20;
    char c = 'a';
    printf("Square of %d: %d\n", x, SQUARE(x));
    printf("Max of %d and %d: %d\n", x, y, MAX2(x, y));
    printf("Max of %d, %d and %d: %d\n", x, y, z, MAX3(x, y, z));
    printf("Max of %d, %d, %d and %d: %d\n", x, y, z, w, MAX4(x, y, z, w));
    printf("Uppercase of '%c': '%c'\n", c, TO_UPPER(c));
}

int main(){
    task3_1_macros();
    return 0;
}