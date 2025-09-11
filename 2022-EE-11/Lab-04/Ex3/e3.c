//#include <stdio.h>

void division(int Q, int M) {
    int A = 0; 
    int n = 32; // 32 bit dividend
    while(n > 0) {
        A = (A << 1) | ((Q >> 31) & 1); Q = Q << 1;

        A = (A < 0) ? (A + M) : (A - M);
        Q = (A < 0) ? (Q & ~1) : (Q | 1);

        n--;
    }

    A = (A < 0) ? (A + M) : A;
    /*
    printf("Remainder: %d\n", A);
    printf("Quotient: %d\n", Q);
    printf("Check: %d\n", A + Q * M);
    */
}

int main() {
    int Q, M;
    /*
    printf("Enter Dividend (Q): ");
    scanf("%d", &Q);
    printf("Enter Divisor (M): ");
    scanf("%d", &M);
    */
    Q = 57;
    M = 10;
    
    if (M == 0) {
        //printf("Error: Division by zero.\n");
        return 1;
    }

    division(Q, M);
    return 0;
}