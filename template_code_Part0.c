#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    int     car_no      = 1;
    float   car_torque  = 54.7;
    double  engine_V    = 12;
    char    car_name    = 'R';
    // Print their sizes and demonstrate type casting
    printf("Size of car_no is:  %zu bytes\n",sizeof(car_no));
    printf("Size of car_torque: %zu bytes\n",sizeof(car_torque));
    printf("Size of engine_V:   %zu bytes\n",sizeof(engine_V));
    printf("Size of car_name:   %zu bytes\n",sizeof(car_name));

    printf("Converting int(12) ---> float:      %f\n",(float)engine_V);
    printf("Converting float(54.7) ---> int:    %d\n",(int)car_torque);
    
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    int a,b;
    char operator;
    // TODO: Take two integers as input
    printf("Enter first  integer a: ");
    scanf("%d",&a);
    printf("Enter second integer b: ");
    scanf("%d",&b);
    // Perform arithmetic operations
    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("a * b = %d\n",a*b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n",a%b);
    // Implement switch-case calculator
    printf("Now your choice operator\n");
    printf("Enter first  integer a:          ");
    scanf("%d",&a);
    printf("Enter second integer b:          ");
    scanf("%d",&b);
    printf("Operator you want (+,-,*,/,%%):   ");
    scanf(" %c",&operator);

    switch(operator){
        case '+':
            printf("a + b = %d\n",a+b);
            break;
        case '-':
            printf("a - b = %d\n",a-b);
            break;
        case '*':
            printf("a * b = %d\n",a*b);
            break;
        case '/':
            printf("a / b = %d\n",a/b);
            break;
        case '%':
            printf("a %% b = %d\n",a%b);
            break;
        default :
            printf("Something is wrong");
    }
}

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;
    printf("Enter how many terms you want in Fibonacci series: ");
    scanf("%d",&n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",fib(i));
    }
    printf("\n");   
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int number,guess;
    int attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Guess the number between 1 and 100:\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > number)
            printf("Too high! Try again.\n");
        else if (guess < number)
            printf("Too low! Try again.\n");
        else
            printf("Correct! You guessed it in %d attempts.\n", attempts);
    } while (guess != number);
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if(n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void task04_prime_numbers() {
    FILE *f1;
    // TODO: Print prime numbers between 1 and 100
    f1 = fopen("prime_numbers.txt", "w");
    if (!f1) {
        printf("Error opening file for writing.\n");
        return;
    }
    for(int i = 1; i <= 100; i++){
        if(isPrime(i)){
            printf("%d ",i);
            fprintf(f1, "%d\n", i);
        }
    }
    fclose(f1);
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);

    return 1;
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    int len = 0;
    // TODO: Reverse a string without library functions
    char str[10] = "abcdefg";

    while(str[len] != '\0'){
        len++;
    }
    char str1[len+1];

    for (int i = 0; i < len; i++) {
        str1[i] = str[len - 1 - i];
    }
    str1[len] = '\0';

    printf("%s",str1);
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int largest, second;
    if (arr[0] > arr[1]) {
        largest = arr[0];
        second  = arr[1];
    } else {
        largest = arr[1];
        second  = arr[0];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (largest == second)
        printf("No distinct second largest element.\n");
    else
        printf("Second largest = %d\n", second);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *f;
    int nums[5] = {10, 20, 30, 40, 50};
    int readnums[5];

    f = fopen("numbers.txt", "w");
    if (!f) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(f, "%d\n", nums[i]);
    }
    fclose(f);

    f = fopen("numbers.txt", "r");
    if (!f) {
        printf("Error opening file for reading.\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fscanf(f, "%d", &readnums[i]);
    }
    fclose(f);

    // Print read values
    printf("Numbers read from file:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", readnums[i]);
    }
    printf("\n");
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    int a = 5;
    int b = 3;

    printf("a & b  = %d\n", a & b);
    printf("a | b  = %d\n", a | b);
    printf("a ^ b  = %d\n", a ^ b);
    printf("~a     = %d\n", ~a);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    // Bonus: Check if number is power of 2
    int num;
    printf("Enter number to check power of 2: ");
    scanf("%d", &num);
    if (num > 0 && (num & (num - 1)) == 0)
        printf("%d is power of 2\n", num);
    else
        printf("%d is NOT power of 2\n", num);
    
}

// ======================= Task 0.8 =======================
enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    int num;
    printf("Enter a number (1-7): ");
    scanf("%d", &num);

    enum Weekday day = num;

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
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double distance = sqrt(dx * dx + dy * dy);

    printf("Euclidean Distance = %.2f\n", distance);
}

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

void task09_check_power_of_two() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPowerOfTwo(num))
        printf("%d is a power of 2.\n", num);
    else
        printf("%d is NOT a power of 2.\n", num);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc != 3) {
        printf("Usage: ./a.out <num1> <num2>\n");
        return;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int sum = a + b;

    printf("Sum = %d\n", sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    // task01_datatypes();
    // task02_calculator();
    // task03_fibonacci();
    // task03_guessing_game();
    // task04_prime_numbers();
    // printf("Factorial of 5 = %d\n", factorial(5));
    // task05_reverse_string();
    // task05_second_largest();
    // task06_file_io();
    // task07_bitwise_ops();
    // task08_enum_weekday();
    // task09_struct_distance();
    // task09_check_power_of_two();
    // task10_cmd_args(argc, argv);

    return 0;
}
