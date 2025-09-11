#include <stdio.h>
#include "functions.h"

int main() {
    printf("Hello from main!\n");
    
    int result = add_numbers(5, 3);
    printf("5 + 3 = %d\n", result);
    
    greet("World");
    
    return 0;
}