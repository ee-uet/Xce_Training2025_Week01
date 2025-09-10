#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.8 =======================
enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    
    printf("Enter a number from 1 to 7: ");

    // Read user input and convert to enum
    int daycount;
    scanf("%d",&daycount);

    // Validate input
    if (daycount < 1 || daycount > 7) {
        printf("Invalid input. Enter a number from 1 to 7.\n");
        return;
    }
    enum Weekday day = (enum Weekday)(daycount - 1); // Adjust for 0-based index

    // Print corresponding day of the week
    switch (day) {
        case MON:
            printf("Monday\n");
            break;
        case TUE:
            printf("Tuesday\n");
            break;
        case WED:
            printf("Wednesday\n");
            break;
        case THU:
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
            break;
        default:
            printf("Invalid input. Enter a number from 1 to 7.\n");
    }
}
int main() {
    task08_enum_weekday();
    return 0;
}