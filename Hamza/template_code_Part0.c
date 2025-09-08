#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void task01_datatypes() {
    int myint;
    float myfloat;
    double mydouble;
    char mychar;

    printf("int size: %zu\n", sizeof(myint));
    printf("float size: %zu\n", sizeof(myfloat));
    printf("double size: %zu\n", sizeof(mydouble));
    printf("char size: %zu\n", sizeof(mychar));
    
    int a = 10;
    float b = (float)a;
    printf("casted value: %f\n", b);
}

void task02_calculator() {
    int x, y;
    char op;
    printf("enter two integers and an operator: ");
    scanf("%d %c %d", &x, &op, &y);

    switch (op) {
        case '+':
            printf("result: %d\n", x + y);
            break;
        case '-':
            printf("result: %d\n", x - y);
            break;
        case '*':
            printf("result: %d\n", x * y);
            break;
        case '/':
            printf("result: %f\n", (float)x / y);
            break;
        default:
            printf("invalid operator\n");
    }
}

void task03_fibonacci() {
    int n, i, a = 0, b = 1, next;
    printf("enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void task03_guessing_game() {
    int number, guess;
    number = rand() % 100 + 1;

    do {
        printf("guess a number (1-100): ");
        scanf("%d", &guess);
        if (guess > number) {
            printf("too high\n");
        } else if (guess < number) {
            printf("too low\n");
        }
    } while (guess != number);

    printf("you got it!\n");
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void task04_prime_numbers() {
    printf("primes between 1 and 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void task05_reverse_string() {
    char str[100];
    int len, i;
    printf("enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("reversed string: %s\n", str);
}

void task05_second_largest() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int first, second;

    first = second = -2147483648;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -2147483648) {
        printf("no second largest element\n");
    } else {
        printf("second largest: %d\n", second);
    }
}

void task06_file_io() {
    FILE *fp;
    int nums[5] = {10, 20, 30, 40, 50};
    int read_nums[5];

    fp = fopen("numbers.txt", "w");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%d\n", nums[i]);
    }
    fclose(fp);

    fp = fopen("numbers.txt", "r");
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d", &read_nums[i]);
    }
    fclose(fp);

    for (int i = 0; i < 5; i++) {
        printf("read: %d\n", read_nums[i]);
    }
}

void task07_bitwise_ops() {
    int x = 5, y = 3;
    printf("and: %d\n", x & y);
    printf("or: %d\n", x | y);
    printf("xor: %d\n", x ^ y);
    printf("not: %d\n", ~x);
    printf("left shift: %d\n", x << 1);
    printf("right shift: %d\n", x >> 1);

    int n = 8;
    if ((n & (n - 1)) == 0) {
        printf("%d is a power of 2\n", n);
    } else {
        printf("%d is not a power of 2\n", n);
    }
}

typedef enum { sun, mon, tue, wed, thu, fri, sat } weekday;
void task08_enum_weekday() {
    int day_num;
    printf("enter day number (1-7): ");
    scanf("%d", &day_num);
    
    weekday today = day_num - 1;

    switch (today) {
        case sun: printf("sunday\n"); break;
        case mon: printf("monday\n"); break;
        case tue: printf("tuesday\n"); break;
        case wed: printf("wednesday\n"); break;
        case thu: printf("thursday\n"); break;
        case fri: printf("friday\n"); break;
        case sat: printf("saturday\n"); break;
        default: printf("invalid day\n"); break;
    }
}

struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    struct Point p1, p2;
    double distance;
    printf("enter point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("enter point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("distance: %f\n", distance);
}

void task10_cmd_args(int argc, char *argv[]) {
    if (argc != 3) {
        printf("usage: %s <int1> <int2>\n", argv[0]);
        return;
    }
    
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("sum: %d\n", num1 + num2);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    task01_datatypes();
    task02_calculator();
    task03_fibonacci();
    task03_guessing_game();
    task04_prime_numbers();
    printf("factorial of 5 = %d\n", factorial(5));
    task05_reverse_string();
    task05_second_largest();
    task06_file_io();
    task07_bitwise_ops();
    task08_enum_weekday();
    task09_struct_distance();
    task10_cmd_args(argc, argv);

    return 0;
}
