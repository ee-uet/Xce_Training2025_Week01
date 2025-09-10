#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting 
    int a = 32;
    float b = 2.7182818;
    double c = 3.14159;
    char d = 'A';

    printf("Integer size: \t %zu \n", sizeof(int)); 
    printf("Float Size: \t %zu \n", sizeof(float));
    printf("Double Size: \t %zu \n", sizeof(double));
    printf("Char Size: \t %zu \n", sizeof(char));       
}

// ======================= Task 0.2 =======================
void task02_calculator(int arg1, int arg2, char op) {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    switch(op)
    {
    case '+':
        printf("Sum:\t %d\n", arg1+arg2);
        break;
    case '-':
        printf("Difference:\t %d\n", arg1-arg2);
        break;
    case '*':
        printf("Product:\t %d\n", arg1*arg2);
        break;
    case '/':
        printf("Quotient:\t %d\n", arg1/arg2);
        break;   
    case '%':
        printf("Remainder:\t %d\n", arg1%arg2);
        break;     
    default:
        printf("Invalid argument or operator.");
        break;
    }
}

// ======================= Task 0.3 =======================
void task03_fibonacci(int n) {
    // TODO: Print Fibonacci sequence up to n terms
    int i = 1; int j = 1;

    printf("The first two terms of the sequence are 1.\n");

    for (int idx = 3; idx <= n; idx++)
    {
        printf("The %dth term is:\t %d \n", idx, i+j);
        j += i;
        i = j-i;
    }
    
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number

    int random = rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    while (1) {
        printf("Guess a number between 1 and %d: ", 100);
        scanf("%d", &guess);

        if (guess == -1) {
            printf("Exiting the game.\n");
            printf("The random number was: %d\n", random);
            break;
        }

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Please try again.\n");
            continue;
        }

        if (guess < random) {
            printf("Too low!\n");
        } else if (guess > random) {
            printf("Too high!\n");
        }
        else {
            printf("Congratulations! You guessed the number!\n");
            break;
        }   
    }
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    // Check if n is 1 or 0
    if (n <= 1)
        return 0;

    // Check if n is 2 or 3
    if (n == 2 || n == 3)
        return 1;

    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    for (int i = 2; i <= 100; i++)
    {
        if (isPrime(i)){ printf("%d is prime.\n", i);}
    }
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n==1) {return 1;}
    else {return n*factorial(n-1);}
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char str[] = "Hello, World!";
    int len = strlen(str);
    char reversed[len + 1]; // +1 for null terminator           
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0'; // Null-terminate the reversed string
    printf("Reversed string: %s\n", reversed);
}

void task05_second_largest(int arr[], int n) {
    // TODO: Find the second largest element in an array
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return;
    }

    int key, j;
    for (int idx = 1; idx < n; idx++)
    {
        key = arr[idx];
        j = idx-1;
        while ((j >= 0) && (arr[j] < key))
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[idx+j] = key;
    }

    printf("Second largest element:\t %d \n",arr[1]);
    
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *fptr;
    int array[5];
    fptr = fopen("task06.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        array[i] = rand() % 100; // Generate random integers
        fprintf(fptr, "%d\n", array[i]); // Write to file
    }
    
    fclose(fptr);
    fptr = fopen("task06.txt", "r");
    printf("Integers read from file:\n");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fptr, "%d", &array[i]); // Read from file
        printf("%d\n", array[i]);       
    }
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops(int i, int j) {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    
    printf("AND:\t%d\n", i&j);

    printf("OR:\t%d\n", i|j);

    printf("XOR:\t%d\n", i^j);

    printf("NOT:\t%d\n", ~i);

    printf("Shift by 1:\t %d \n", i<<1);

}

// ======================= Task 0.8 =======================
void task08_enum_weekday(int day) {
    // TODO: Map number (1–7) to day of week using enum
    enum days {
        Monday = 1,
        Tuesday = 2,
        Wednesday = 3,
        Thursday = 4,
        Friday = 5,
        Saturday = 6,
        Sunday = 7
    };

    if (day < 1 || day > 7) {
        printf("Invalid day number.\n");
        return;
    }       

    switch(day) {
        case Monday:
            printf("Monday\n");
            break;
        case Tuesday:
            printf("Tuesday\n");
            break;
        case Wednesday:
            printf("Wednesday\n");
            break;
        case Thursday:
            printf("Thursday\n");
            break;
        case Friday:
            printf("Friday\n");
            break;
        case Saturday:
            printf("Saturday\n");
            break;
        case Sunday:
            printf("Sunday\n");
            break;
    }
}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance(struct Point *u, struct Point *v) {
    // TODO: Take two points and calculate Euclidean distance
    printf("Distance:\t%f\n", sqrt(((v->x) - (u->x))*((v->x) - (u->x)) + ((v->y) - (u->y))*((v->y) - (u->y))));
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    printf("Command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    if (argc < 3) {
        printf("Please provide two integers as arguments.\n");
        return;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("Sum of %d and %d is: %d\n", num1, num2, num1 + num2);               
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers
    
    struct Point p1 = {3, 4};
    struct Point p2 = {6, 8};

    int arr[] = {12, 45, 23, 67, 34};

    // Uncomment tasks as you implement them
    task01_datatypes();
    task02_calculator(50 , 5, '/');
    task03_fibonacci(10);
    task03_guessing_game();
    task04_prime_numbers();
    printf("Factorial of 5 = %d\n", factorial(5));
    task05_reverse_string();
    task05_second_largest(arr, sizeof(arr)/sizeof(int));
    task06_file_io();
    task07_bitwise_ops(5, 3);
    task08_enum_weekday(3);
    task09_struct_distance(&p1, &p2);
    task10_cmd_args(argc, argv);

    return 0;
}
