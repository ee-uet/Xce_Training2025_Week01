#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


int poweroftwo (int i) {
 if (i<=0) {
    return 0;
}
   return (i & (i-1)) == 0;
}
// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    printf("Task 7\n");
    int a,b,j;
    printf("Enter value of a:");
    scanf("%d",&a);
   printf("Enter value of b:");
    scanf("%d",&b);
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf(" a & b = %d\n",a&b);
    printf(" a | b = %d\n",a|b);
    printf(" a ^ b = %d\n",a^b);
    printf(" ~a = %d\n",~a);
    printf(" ~b = %d\n",~b);
    printf(" a << 1 = %d\n", a <<1);
    printf(" b << 1 = %d\n",b <<1);
    printf("Enter value to check if it is power of two or not:");
    scanf("%d",&j);
    if (poweroftwo( j )) {
      printf("Number is power of 2\n");
}
   else {
   printf("Number is not power of 2\n");
}

}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

     task07_bitwise_ops();

    return 0;
}

