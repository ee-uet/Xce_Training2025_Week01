#include <stdio.h>
#include <stdlib.h>

void task08_enum_weekday() {
    int day;
    enum Weekday { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
    printf("Enter a number from 1 to 7 for the day of the week: ");
    scanf("%d", &day);
    switch (day) {
        case MONDAY:
            printf("Monday\n");
            break;
        case TUESDAY:
            printf("Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Wednesday\n");
            break;
        case THURSDAY:
            printf("Thursday\n");
            break;
        case FRIDAY:
            printf("Friday\n");
            break;
        case SATURDAY:
            printf("Saturday\n");
            break;
        case SUNDAY:
            printf("Sunday\n");
            break;
        default:
            printf("Something went wrong here!\n");
    }
}

int main ()
{
    task08_enum_weekday();
    return 0;
}