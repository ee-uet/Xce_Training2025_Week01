#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n;i++) 
    {
        if (i == 1) {
            printf("%d \n", t1);}
        else if (i == 2) {
            printf("%d \n", t2);}
        else if (i > 2) {
             
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("%d \n", nextTerm);
        }
        else
        {
            printf("Invalid input\n");
            return;
        }
        
    }
}

int main() {
    task03_fibonacci();
    return 0;
}