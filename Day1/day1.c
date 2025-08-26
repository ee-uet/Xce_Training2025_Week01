#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting

    int a = 10;
    float b = 5.5f;
    double c = 3.14159;
    char d = 'A';

    // Print sizes of each data type
    printf("Size of int: %ld bytes\n", sizeof(a));
    printf("Size of float: %zu bytes\n", sizeof(b));
    printf("Size of double: %zu bytes\n", sizeof(c));
    printf("Size of char: %zu bytes\n", sizeof(d));

    // Type Casting
    double casted = (double)a; // int to double
    printf("Casted int to double: %f\n", casted);
    float casted_float = (float)c; // double to float
    printf("Casted double to float: %f\n", casted);
    int casted_int = (int)b; // float to int
    printf("Casted float to int: %d\n", casted_int);

}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator

    int int1, int2, result;
    printf("Enter 1st Integer: \n"); 
    scanf("%d",&int1);
    printf("Enter 2nd Integer: \n");
    scanf("%d",&int2);
    
    char operator;
    printf("Enter operator symbol (ADD, SUB, MUL, DIV, REM): \n");
    scanf(" %c", &operator);

    switch (operator) {
    case '+':
        printf("Performing Addition\n");
        result = int1 + int2;
        printf("The result is: %d", result);
        break;
    
    case '-':
        printf("Performing Subtratcion:\n");
        result = int1 - int2;
        printf("The result is: %d\n", result);
        break;
    
    case '*':
        printf("Performing Multiplication:\n");
        result = int1 * int2;
        printf("The result is: %ls\n", &result);
        break;

    case '/':
        printf("Performing Division:\n");
        result = int1 / int2;
        printf("The result is: %d\n", result);
        break;
    
    case '%':
        printf("Performing Modulo:\n");
        result = int1 % int2;
        printf("The result is: %d \n", result);
        break;
    
    default:
        printf("Invalid operator. Please use ADD, SUB, MUL, DIV, or REM.\n");
        break;
    }
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n;i++) 
    {
        if (i == 1) {
            printf("%d \n", t1);}
        else if (i == 2) {
            printf("%d \n", t2);}
        else if (i > 2) {
             
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("%d \n", nextTerm);
            }
    }
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int n, guess, attempts = 0;
    n = rand() % 100 + 1; // Random number between 1 and 100
    printf("Guess the number (1-100): ");
    do {
        scanf("%d", &guess);
        attempts++;
        if (guess < n) {
            printf("Low! Try again: ");
        } 
        else if (guess > n) { 
            printf("High! Try again: ");
        } 
        else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", n, attempts);
        }
    }
    while (guess != n);
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    if (n <= 1) {// 0 and 1 are not prime numbers
        return 0;
    } 
    for (int i = 2; i < (n); i++) {
        if (n % i == 0) 
        {   
            return 0; // n is divisible by i, hence not prime
        }
    }
    return 1; // n is prime

}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n ==0 || n == 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
        char strng[100];

    printf("Enter the string:  ");
    scanf("%s",strng);

    int length = 0;
    while(strng[length] != '\0'){
        length++;
    }
    printf("Reversed string is: ");

    char *first = &strng[0];
    char *end = &strng[length-1];
    while(first < end){
        char temp = *first;
        *first = *end;
        *end = temp;

        first++;
        end--;
    }
    

    printf("%s",strng);
    
    printf("\n");
}


void task05_second_largest() {
    // TODO: Find the second largest element in an array
        int arr[10] = {99,55,83,993,939,223,12,0};
    int large = arr[0];
    int second = 0;
    int len = 10;
    for(int i = 0;i < len;i++){
        
        if(large < arr[i]){
            second = large;
            large = arr[i];
        }
        else if (arr[i] > second && arr[i] != large) {
            second = arr[i];
        }        
    }
    printf("Second large number: %d\n",second);

}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    int arr[5];
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    FILE *file_ptr;

    file_ptr = fopen("number.txt","w");
    if(file_ptr == NULL){
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(file_ptr,"%d\n",arr[i]);
    }
    fclose(file_ptr);

    printf("Numbers written to numbers.txt\n");

    for (int i = 0; i < 5; i++) {
        arr[i] = 0;
    }

    printf("Numbers read from file:\n");

    file_ptr = fopen("number.txt","r");
    for (int i = 0; i < 5; i++) {
        fscanf(file_ptr,"%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    fclose(file_ptr);
    printf("\n");
}



// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int x,y;
    x = 8; y = 16;
    printf("x & y %d\n", x & y );
    printf("x | y = %d\n", x | y);  
    printf("x ^ y = %d\n", x ^ y);   
    printf("~x = %d\n", ~x);      
    printf("x << 1 = %d\n", x << 1);  
    printf("x >> 1 = %d\n", x >> 1); 

    // Bonus: Check if number is power of 2
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    if ( n > 0 && ((n & n-1) == 0))
    {
        printf("%d number is the power of 2\n",n);
    }
    else{
        printf("%d is not power of 2.\n", n);
    }

}


// ======================= Task 0.8 =======================
enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
        printf("Enter a number frm 1 to 7: ");
    int daycount;
    scanf("%d",&daycount);

    enum Weekday day = (enum Weekday)(daycount - 1);

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
            printf("Invalid input. Enter a number from 1 to 7.\n");
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
    printf("Enter coordinates of p1(x,y): ");
    scanf("%d %d",&p1.x, &p1.y);
    printf("Enter coordinates of p2(x,y): ");
    scanf("%d %d",&p2.x, &p2.y);

    double distance = sqrt ( pow(p2.x - p1.x,2) + pow(p2.y - p1.y, 2));
    printf("Eucledian Distance : %.3f\n", distance); 
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    int sum;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    sum = num1 + num2;
    printf("Sum is %d\n", sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    //task01_datatypes();
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
    
    
    // Also provide cmd args alongwith please
    // task10_cmd_args(argc, argv); 

    return 0;
}
