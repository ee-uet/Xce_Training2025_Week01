#include <stdio.h>

// ======================= Task 0.8 =======================
// Define enumeration for weekdays (0-based: MON=0, ..., SUN=6)
enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };

void task08_enum_weekday() {
    // Ask user for input (1–7)
    printf("Enter a number (1-7): ");
    int dayNumber;
    scanf("%d", &dayNumber);

    // Convert 1–7 into enum values (0–6)
    enum Weekday day = (enum Weekday)(dayNumber - 1);

    // Switch-case to print corresponding weekday
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
            // Handles invalid inputs (e.g., <1 or >7)
            printf("Invalid input. Enter a number from 1 to 7.\n");
    }
}

// Main function to test Task 0.8
int main() {
    task08_enum_weekday();
    return 0;
}

