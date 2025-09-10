#include <stdio.h>

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    // MON=1, then automatically TUE=2, WED=3, etc.
    enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

    int day;
    printf("Enter a number (1-7): ");
    scanf("%d", &day);

    // Switch-case to print the correct weekday
    switch (day) {
        case MON: printf("Monday\n"); break;
        case TUE: printf("Tuesday\n"); break;
        case WED: printf("Wednesday\n"); break;
        case THU: printf("Thursday\n"); break;
        case FRI: printf("Friday\n"); break;
        case SAT: printf("Saturday\n"); break;
        case SUN: printf("Sunday\n"); break;
        default: printf("Invalid input! Please enter 1-7.\n"); break;
    }

}

// ======================= Main =======================
int main() {

    task08_enum_weekday();
    
    return 0;
}