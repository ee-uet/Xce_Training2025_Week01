#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    printf("Task 8\n");
    enum weekdays {MON = 1, TUE = 2, WED = 3, THURS = 4 ,FRI = 5, SAT = 6, SUN = 7};
    printf("Enter number\n");
    int i;
    scanf("%d",&i);
    switch(i) {
    case MON:
      printf("Monday\n");
      break;
    case TUE:
    printf("Tuesday\n");
     break;
    case WED:
       printf("Wednesday\n");
       break;
    case THURS:
       printf("Thursday\n");
       break;
    case FRI:
       printf("Friday\n");
       break;
    case SAT:
       printf("Saturday\n");
       break;
    case SUN:
       printf("Sunday\n");
}
}
// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
    // task08_enum_weekday();
   

    return 0;
}
