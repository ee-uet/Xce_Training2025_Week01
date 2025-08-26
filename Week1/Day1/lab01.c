#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
   // TODO: Declare int, float, double, char
  // Print their sizes and demonstrate type casting
    int w = 13;
    float x = 3.1439;
    double y = 2.3589;
    char z = 'Z';

    printf("Integer value is %d, size = %zu bytes\n", w, sizeof(w));
    printf("Float value is %f, size = %zu bytes\n", x, sizeof(x));
    printf("Double value is %f, size = %zu bytes\n", y, sizeof(y));
    printf("Char value is %c, size = %zu bytes\n", z, sizeof(z));

    printf("Integer to float: %f\n", (float)w);
    printf("Double to integer: %d\n", (int)y);
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    int a = 3;
    int b = 4;
    char op;
    // Perform arithmetic operations
    printf("%d + %d = %d\n",a , b, a + b);
    printf("%d + %d = %d\n",a , b, a + b);
    printf("%d * %d = %d\n",a , b, a * b);
    printf("%d / %d = %d\n",a , b, a / b);
    printf("%d %% %d = %d\n",a , b, a % b);

    // Implement switch-case calculator
    printf("Enter Operation");
    scanf("%c", &op);
    switch(op){
        case '+': printf("%d + %d = %d\n", a, b, a + b); break;
        case '-': printf("%d - %d = %d\n", a, b, a - b); break;
        case '*': printf("%d * %d = %d\n", a, b, a * b); break;
        case '/': printf("%d / %d = %d\n", a, b, a / b); break;
        case '%': printf("%d %% %d = %d\n", a, b, a % b);break;
        default: printf("Invalid operation!\n"); break;
    }

}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;
    int t1 = 0; 
    int t2 = 1; 
    int next;

    printf("Number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
  
   srand(time(0));
    int target = rand() % 101;
    int guess;
   
    while(1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < 1 || guess > 100) {
            printf("Out of range!\n");
            continue;
        }

        if(guess < target)
            printf("Too Low!\n");
        else if(guess > target)
            printf("Too High!\n");
        else {
            printf("Correct! The number was %d.\n", target);
            break;
        }
    }
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if(n <= 1) return 0;
    for(int i = 2; i <= n/2; i++)
        if(n % i == 0) return 0;
    return 1;
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100

    FILE *fp = fopen("primes.txt", "w");
    if(!fp) {
        printf("File not found!\n");
        //return;
    }

    printf("Prime numbers between 1 and 100:\n");
    for(int i = 1; i <= 100; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            fprintf(fp, "%d\n", i);
        }
    }
    fclose(fp);
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while(str[len] != '\0') len++;

    printf("Reversed String: ");
    for(int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void task05_second_largest() {
    // Find the second largest element in an array
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int largest = a[0], second = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Second largest element is: %d\n", second);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *fp;
    int num;

    fp = fopen("numbers.txt", "w");  
    if (!fp) {
        printf("File not found\n");
        return;
    }
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);

    fp = fopen("numbers.txt", "r");
    if(!fp) {  
        printf("File not found\n");
        return;
    }
    printf("Numbers read from file:\n");
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d", &num);
        printf("%d ", num);
    }
    printf("\n");
    fclose(fp);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    int x = 5;
    int y = 9;

    printf("x = %d, y = %d\n", x, y);
    printf("x & y = %d\n", x & y);
    printf("x | y = %d\n", x | y);
    printf("x ^ y = %d\n", x ^ y);
    printf("~x = %d\n", ~x);
    printf("x << 1 = %d\n", x << 1);
    printf("y >> 2 = %d\n", y >> 2);

    // Bonus: Check if number is power of 2
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("%d is NOT a power of 2\n", num);
        return;
    }

    while (num % 2 == 0) {
        num /= 2;
    }

    if (num == 1) {
        printf("YES, it is a power of 2\n");
    } else {
        printf("NO, not a power of 2\n");
    }

}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum

    enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
    int day;
    printf("Enter a number for the weekday: ");
    scanf("%d", &day);

    enum Weekday wd = day - 1;  

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


// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
    
};
void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
     struct Point p1, p2;

    printf("Enter coordinates of first point (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of second point (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) +
                           (p2.y - p1.y) * (p2.y - p1.y));

    printf("Euclidean Distance = %.2f\n", distance);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
	if (argc < 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
    }
    // TODO: Take 2 integers as command line args and print sum
    int num1 = atoi(argv[1]);  
    int num2 = atoi(argv[2]);  
    int sum = num1 + num2;

    printf("Sum = %d\n", sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    task01_datatypes();
    task02_calculator();
    task03_fibonacci();
    task03_guessing_game();
    task04_prime_numbers();
    printf("Factorial of 5 = %d\n", factorial(5));
    task05_reverse_string();
    task05_second_largest();
    task06_file_io();
    task07_bitwise_ops();
    task08_enum_weekday();
    task09_struct_distance();
    task10_cmd_args(argc, argv);

    return 0;
}
