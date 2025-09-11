#include <stdio.h>

void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum Weekday{
        Mon  =1,
        Tue = 2,
        Wed = 3,
        Thr = 4,
        Fri = 5,
        Sat = 6,
        Sun = 7
    };
    int n;
    printf("Input day number: ");
    scanf("%d",&n);
    
    switch(n) {
        case Mon:
            printf("Monday\n");
            break;
        case Tue:
            printf("Tuesday\n");
            break;
        case Wed:
            printf("Wednesday\n");
            break;
        case Thr:
            printf("Thursday\n");
            break;
        case Fri:
            printf("Friday\n");
            break;
        case Sat:
            printf("Saturday\n");
            break;
        case Sun:
            printf("Sunday\n");
            break;
    }

}

int main()
{
    task08_enum_weekday();
    return 0;
}