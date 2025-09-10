#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    
    int      a = 10;
    float    b = 2.0;
    double   c = 5.12481632;
    char grade = 'B';

    // Print their sizes and demonstrate type casting
    printf("Integer is %d and its float type is %f with size %zu\n", a, (float)a, sizeof(a));    
    printf("float is %f and its integer type is %d with size %zu\n", b, (int)b, sizeof(b));
    printf("Double is %f and its size is %zu\n", c, sizeof(c));
    printf("String is %c and its size is %zu\n", grade, sizeof(grade));

}

// ======================= Task 0.2 =======================
void task02_calculator() {
    int a, b;
    int sum, mul, sub, remainder;
    float div;
    char operation;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("What type of operation do you want to operate? (+, -, *, /, %%): ");
    scanf(" %c", &operation); 

    switch (operation) {
        case '+':
            sum = a + b;
            printf("Sum: %d\n", sum);
            break;

        case '-':
            sub = a - b;
            printf("Subtraction: %d\n", sub);
            break;

        case '*':
            mul = a * b;
            printf("Multiplication: %d\n", mul);
            break;

        case '/':
            if (b != 0) {
                div = (float)a / b;
                printf("Division: %.2f\n", div);
            } else {
                printf("Error: Division by zero\n");
            }
            break;

        case '%':
            if (b != 0) {
                remainder = a % b;
                printf("Modulus: %d\n", remainder);
            } else {
                printf("Error: Modulus by zero\n");
            }
            break;

        default:
            printf("Invalid operator entered.\n");
    }
}


// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n1 = 0;
    int n2 = 1;
    int n3, n;
    printf("Enter number: ");
    scanf("%d", &n);
    if (n == 0 || n < 0){         // fibonacci seq is not negative 
        printf("Invalid input\n");
    }
    else {
    for (int i=0 ; i<n ; i++){

    if (i == 0){
        printf("Fibonaci seq upto %d term is \n%d\n", n, n1);
    } else if (i == 1){
        printf("%d\n", i);
    } else if (i > 1){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d\n", n3);
    }
    }
}
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int r1 = rand() % 100 + 1;
    int guess=0, try = 0; 
    
    while ( guess != r1){
        if (try < 20){
            printf("Guess the number: ");
            scanf("%d", &guess);
            try += 1 ;

            if (guess < r1-10){
                printf("Too Low\n");
            } else if ( guess > r1+10){
                printf("Too High\n");
            } else if (guess == r1){
                printf("Correct guess!\n");
                break;
        }
        } 
        else {
            printf("You have used your trials.\nBetter luck next time!");
            break;
        }    
    }
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    for (int i = 2; i < sqrt(n); i++) {  // for a x b = n, a or b
    if (n % i == 0) {                    // must be less than sqrt(n)
        return 0;                    
        }
    }
    return 1;    
}

void task04_prime_numbers() {
    int arr[100];  
    int size = 0;

    for (int i = 2; i <= 100; i++) {
        if (isPrime(i) == 1) {
            arr[size] = i;
            size += 1;
        }
    }

    // Print stored prime numbers
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n == 1) {
        return 1;
    } else {
        return n*factorial(n-1);
    }    
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char arr[] = "Aftab";
    char *ptr = arr;
    char swap;
    int size = 0;
    while (*ptr != 0) {
        size += 1;
        *ptr++;
    }
    for (int i=0; i<(size/2); i++) {
        swap = arr[size-1-i];
        arr[size-1-i] = arr[i];
        arr[i] = swap;
    }
    for (int n = 0; n < size; n++) {
        printf("%c", arr[n]);
    }
    printf("\n");
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int arr[] = {2,6,16,5,7,3};
    int largest = arr[0];
    int large   = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<size; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }
    for (int n=0; n<size; n++) {
        if ( large < arr[n] && arr[n] != largest) {
            large = arr[n];
        }
    }
    printf("%d\t %d\n", large, largest);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    char buffer[100];
    FILE *file = fopen("integer.txt", "w"); 
    if (file == NULL) { 
        printf("Error opening file\n"); 
        return; 
    } 

    fprintf(file, "%d %d %d %d %d\n", 0, 1, 2, 3, 4);
    fclose(file); 
    
    file = fopen("integer.txt", "r"); 
    if (file == NULL) { 
        printf("Error opening file\n"); 
        return; 
    } 
    while (fgets(buffer, sizeof(buffer), file) != NULL) { 
        printf("After reading %s", buffer); 
    } 
    
    fclose(file);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    int a = 5;      // 00000101 in binary
    int b = 3;      // 00000011 in binary
    printf("a & b = %d\n", a & b);       // 00000101 & 00000011 = 00000001
    printf("a or b = %d\n", a | b);      // 00000101 | 00000011 = 00000111
    printf("a xor b = %d\n", a ^ b);     // 00000101 ^ 00000011 = 00000110
    printf("not a = %d\n", ~a);          // ~00000101 = 11111010
    printf("left_shift a = %d\n", a << 1);  // 00000101 becomes 00001010
    printf("right_shift a = %d\n", a >> 1); // 00000101 becomes 00000010

    // Bonus: Check if number is power of 2
    int n=16;        
    if ((n > 0) && ((n & (n - 1)) == 0)) {
        printf("%d is power of 2\n", n);
    };
}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum WeekDay {
    MON = 1,
    TUE = 2,
    WED = 3,
    THU = 4,
    FRI = 5,
    SAT = 6,
    SUN = 7
    };

    const char *days[] = {
        "",       // index 0 unused
        "MON", // 1
        "TUE",
        "WED",
        "THU",
        "FRI",
        "SAT",
        "SUN"
    };
    int day_num = 4;
    if (day_num >= MON && day_num <= SUN) {
        printf("%s\n", days[day_num]);
    } else {
        printf("Invalid day number!\n");
    }

}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    struct Point p1 = {2,3};
    struct Point p2 = {4,1};
    float result = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Distance is: %.2f\n", result);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc != 3) {
        printf("Give two integers as argument.\n");
        return;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int sum = num1 + num2;
    printf("Sum: %d\n", sum);
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
    task05_reverse_string();
    // task05_second_largest();
    // task06_file_io();
    // task07_bitwise_ops();
    // task08_enum_weekday();
    // task09_struct_distance();
    // task10_cmd_args(argc, argv);
    // printf("%d\n",isPrime(93));
    return 0;
}
