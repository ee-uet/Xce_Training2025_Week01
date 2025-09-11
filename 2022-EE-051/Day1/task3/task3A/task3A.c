#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void task03_fibonacci() {
    // Print Fibonacci sequence up to n terms
    int n;
    int t1 = 0; 
    int t2 = 1; 
    int next;

    printf("Number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
}

int main() {
    task03_fibonacci();
    return 0;
}

