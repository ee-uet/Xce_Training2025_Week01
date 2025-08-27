#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    
    // Declaration of variables
    int Marks = 65;
    float pi = 3.14;
    double Pi = 3.14159265359;
    char Grade = 'B';
    
    // Printing values
    printf("Integer = %d\n", Marks);
    printf("Float = %f\n", pi);
    printf("Double = %lf\n", Pi);
    printf("Character = %c\n", Grade);

    // Printing sizes
    printf("Size of int: %zu bytes\n", sizeof(Marks)); 
    printf("Size of float: %zu bytes\n", sizeof(pi)); 
    printf("Size of double: %zu bytes\n", sizeof(Pi)); 
    printf("Size of char: %zu bytes\n", sizeof(Grade));

    // typecasting
    float I2F = (float) Marks;
    int F2I = (int) pi;

    printf("int to float: %d -> %f\n", Marks, I2F); 
    printf("float to int: %f -> %d\n", pi, F2I);
}

// ======================= Task 0.2 =======================
void task02_calculator() {

    // Declaring variables
    int inp1, inp2;
    char op;

    // input from user
    printf("Enter first integer:");
    scanf("%d", &inp1);
    printf("Enter second integer:");
    scanf("%d", &inp2);
    printf("Enter the arithimatic operation:");
    scanf(" %c", &op);

    // switch case statement calculator
    switch (op){
        case '+':
            printf("Result is: %d + %d = %d\n", inp1, inp2, inp1 + inp2);
            break;
        case '-':
            printf("Result is: %d - %d = %d\n", inp1, inp2, inp1 - inp2);
            break;
        case '*':
            printf("Result is: %d * %d = %d\n", inp1, inp2, inp1 * inp2);
            break;
        case '/':
            if (inp2 == 0){
                printf("Error: division by zero\n");
            }
            else{
                printf("Result is: %d / %d = %f\n", inp1, inp2, (float) inp1 / inp2);
            }
            break;
        case '%':
            if (inp2 == 0){
                printf("Error: modulus by zero\n");
            }
            else{
                printf("Result is: %d %% %d = %d\n", inp1, inp2, inp1 % inp2);  
            }
            break;
        default:
            printf("Invalid operator!\n");      
    }
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
   
    // Declaring variables
    int n, result, i;
    int a = 0;
    int b = 1;

    // input from user
    printf("How many terms of fibonacci to print:");
    scanf("%d", &n);

    if (n <= 0){
        printf("Negative numbers or Zero not allowed\n");
    }
    else{
        if (n == 1){
            printf("Fibonacci terms are: 0\n");
        }
        else if (n >= 2){
            printf("Fibonacci terms are: %d,%d", a, b);
            for (i = 3; i <= n; i++){
                result = a + b;
                printf(",%d", result);
                a = b;
                b = result;
                }
            }
            printf("\n");
        }
}

void task03_guessing_game() {
    
    // Declaring variables
    int number, guess;
    number = rand() % 100 + 1;

    // input from user
    printf("Guess the number: ");
    scanf("%d", &guess);

    while (guess != number){
        if (guess > number){
            printf("Too High, guess the number again: ");
            scanf("%d", &guess);
        }
        else{
            printf("Too Low, guess the number again: ");
            scanf("%d", &guess);
        }    
    }
    if (guess == number){
        printf("You guessed it right, it was %d\n", number);
    }  
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    
    int i;

    // return 0 if not negative or 1
    if (n <= 1){
        return 0;
    }
    // return 1 if equal to 2
    else if (n == 2){
        return 1;
    }
    // check if number is greater than 2
    else{
        for (i = 2; i <= sqrt(n); i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

void task04_prime_numbers() {
    
    int i;

    // print first 100 prime number using isPrime function 
    printf("The prime numbers from 1 to 100 are:");
    for (i = 1; i <= 100; i++){
        if (isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

// recursive factorial function
int factorial(int n) {
    
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    
    // Declaring variables
    int start, end, len, temp;
    char str[50];

    // input from user
    printf("Enter a string: ");
    scanf("%s", str);

    len = 0;
    while (str[len] != '\0'){
        len++;
    }
    start = 0;
    end = len - 1;

    // swap
    while (start < end){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("The reverse string is: %s\n", str);
}

void task05_second_largest() {
    
    int n, i;
    int array[50];
    int largest, secondLargest;

    // Input size
    printf("Enter number of elements (max 50): ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    largest = secondLargest = -2147483648; // Smallest possible 32 bit int

    for (i = 0; i < n; i++) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } 
        else if (array[i] > secondLargest && array[i] < largest) {
            secondLargest = array[i];
        }
    }
    printf("The second largest element is: %d\n", secondLargest);
    
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    int i, n;
    FILE *file; 
    
    // open file in read mode
    file = fopen("numbers.txt", "w");

    // enter data
    for (i = 0; i < 5; i++){
        printf("Enter an integer:");
        scanf("%d", &n);
        fprintf(file, "%d\n", n);
    }

    // close file
    fclose(file);

    // open file in read mode
    file = fopen("numbers.txt", "r");

    // read data from file and print it
    printf("\nThe ints in numbers.txt are: ");
    for (i = 0; i < 5; i++){
        fscanf(file, "%d", &n);
        printf("%d ", n);
    }
    printf("\n");
    fclose(file);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
     
    // declaration of variable
    int x = 2; 
    int y = 4;
    int number, v;
    
    // printing bitwise ops result
    printf("The AND operation is: %d & %d = %d\n", x, y, x & y);
    printf("The OR operation is: %d | %d = %d\n", x, y, x | y);
    printf("The XOR operation is: %d ^ %d = %d\n", x, y, x ^ y);
    printf("The NOT operation is: ~%d = %d\n", x, ~x);
    printf("The Right bit shifting operation is: %d >> %d = %d\n", x, y, x >> y);
    printf("The Left bit shifting operation is: %d << %d = %d\n", x, y, x << y);

    printf("Enter a number: ");
    scanf("%d", &number);

    // check if power of two or not
    v = 1;
    while (v != number){
        if (v > number){
            printf("No, it is not power of 2\n");
            break;
        } 
        else{
            v = v << 1;
        }
    }
    if (number == v){
        printf("Yes, it is power of 2\n");
    } 
}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    enum weekdays {MON, TUE, WED, THU, FRI, SAT, SUN};
    int num; 

    // input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // out of range
    if (num < 1 || num > 7){
        printf("Invalid input\n");
    }
    else{
        enum weekdays day = num - 1;

        switch (day) {
            case MON: 
                printf("The corresponding weekday is Monday\n"); 
                break;
            case TUE: 
                printf("The corresponding weekday is Tuesday\n"); 
                break;
            case WED: 
                printf("The corresponding weekday is Wednesday\n"); 
                break;
            case THU: 
                printf("The corresponding weekday is Thursday\n"); 
                break;
            case FRI: 
                printf("The corresponding weekday is Friday\n"); 
                break;
            case SAT: 
                printf("The corresponding weekday is Saturday\n"); 
                break;
            case SUN: 
                printf("The corresponding weekday is Sunday\n"); 
                break;
    }
}
}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    
    struct Point p1 = {1, 2};
    struct Point p2 = {4, 6};

    // euclidean distance
    double dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    printf("The Eucledian Distance is: %f\n", dist);

}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    
    int a1, a2;

    if (argc != 3){
        printf("Error! Invalid arguments\n");
    }
    else{
        a1 = atoi(argv[1]); // convert string to int
        a2 = atoi(argv[2]);
        printf("The sum is: %d\n", a1 + a2);
    }
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

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
