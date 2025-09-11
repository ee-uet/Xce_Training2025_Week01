#include <stdio.h>

void task08_enum_weekday() {
    // Map number (1–7) to day of week using enum
    enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
    int day;
    printf("Enter a number for the weekday: ");
    scanf("%d", &day);

    enum Weekday wd = day - 1;  
     // Enter the number of the day and get the name 
    switch (wd) {
        case MON: printf("Monday\n"); break;
        case TUE: printf("Tuesday\n"); break;
        case WED: printf("Wednesday\n"); break;
        case THU: printf("Thursday\n"); break;
        case FRI: printf("Friday\n"); break;
        case SAT: printf("Saturday\n"); break;
        case SUN: printf("Sunday\n"); break;
        default: printf("Invalid input!\n"); break;
    }
}

int main() {
    task08_enum_weekday();
    return 0;
}