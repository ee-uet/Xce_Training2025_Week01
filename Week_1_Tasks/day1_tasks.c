#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    int num = 10;
    float a = 3.1;
    double b =  10;
    char c = 'a';
    // Print their sizes and demonstrate type casting
    printf("size of int is: %zu\n",sizeof(num));
    printf("size of float is: %zu\n",sizeof(a));
    printf("size of double is: %zu\n",sizeof(b));
    printf("size of char is: %zu\n",sizeof(c));

    // Typecating
    printf("Typecasting From Float to Int %d\n",(int)a);
    int num_1, num_2;
    num_1 = 5;
    num_2 = 3;
    int result = num_1/num_2;
    printf("Typecasting From Int to Float %f\n",(float)result);
    float z = (float)num;
    printf("Typecasting From Int to Float %f\n",z); 
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    int a,b;
    printf("Enter 1st Int: ");
    scanf("%d",&a);
    printf("Enter 2nd Int: ");
    scanf("%d",&b);
    // Perform arithmetic operations
    printf("Add: %d\n",a+b);
    printf("Subtract: %d\n",a-b);
    printf("Multiply: %d\n",a*b);
    printf("Divide: %d\n",a/b);
    printf("Remainder: %d\n",a%b);
    // Implement switch-case calculator
    printf("switch-case calculator\n");
    char operator;
    printf("Enter Operator(+, -, *, /, %%): ");
    scanf(" %c", &operator);
    switch (operator){
        case '+':
            printf("Add: %d\n",a+b);
            break;
        case '-':
            printf("Subtract: %d\n",a-b);
            break;
        case '*':
            printf("Multiply: %d\n",a*b);
            break;
        case '/':
            printf("Divide: %d\n",a/b);
            break;
        case '%':
            printf("Remainder: %d\n",a%b);
            break;
        }
    
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;
    printf("Enter n: \n");
    scanf(" %d", &n);
    int a,b;
    a = 0;
    b = 1;
    int next;
    for (int i=0; i<n; i++)
    {
        printf("result: %d\n", a);
        next = a+b;
        a = b;
        b = next;
    }
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int random = (rand() % 100 + 1);
    int guess;
    
    do {
    printf("Guess the number");
    scanf(" %d", &guess);
    if (guess == random)
    {
        printf("Correct Guess\n");
    }
    else if(guess > random)
    {
        printf("Too High\n");
    }
    else if(guess < random)
    {
        printf("Too Low\n");
    }
    }
    while (guess != random);
    

}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if (n <=1) {
        return 0;
    }

    for (int k = 2; k<(n); k++)
    {
        if ((n%k == 0))

        {
            return 0;
        }
    }
    return 1;
    
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    for (int i = 1; i<100; i++)
    {
        if (isPrime(i))
        {
            printf("%d\t", i);
        }

    }
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char name[50] = "hello world";
    int length = 0;
    while(name[length] != '\0')
    {
        length++;
    }
    for (int i = length-1 ; i>=0; i--)
    {
        printf("%c", name[i]);
    }
    printf("\n");
    
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int arr[] = {1,5,29,7,43,40};
    int length = (sizeof(arr))/4;
    int max = arr[0];
    int second_max = arr[0];
    for (int i = 1; i<length; i++ )
    {
    
        if (arr[i] > max )
        {
            second_max = max;
            max = arr[i];
            
        }
        else if ((arr[i] > second_max) && (arr[i] != max))
        {
            second_max = arr[i];
        }
    }
    printf("Second highest is: %d\n", second_max);

}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *fptr;
    int num[5];
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
    scanf("%d",&num[i]);
    }
    fptr = fopen("numbers.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    // Write to file
    for (int i = 0; i < 5; i++) {
        fprintf(fptr, "%d\n", num[i]);
    }

    fclose(fptr);
    printf("Numbers written to 'numbers.txt'\n");

    int n;

    fptr = fopen("numbers.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("Numbers read from 'numbers.txt':\n");
    while (fscanf(fptr, "%d", &n) == 1) {
        printf("%d ", n);
    }

    fclose(fptr);
    printf("\n");

}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    int x,y;
    x = 5; y = 9;
    printf("x & y %d\n", x & y );
    printf("x | y = %d\n", x | y);  
    printf("x ^ y = %d\n", x ^ y);   
    printf("~x = %d\n", ~x);      
    printf("x << 1 = %d\n", x << 1);  
    printf("x >> 1 = %d\n", x >> 1); 

    // Bonus: Check if number is power of 2
    printf("Enter any Integer: ");
    int n;
    scanf("%d", &n);
    if ( n > 0 && ((n & n-1) == 0))
    {
        printf("%d number is the power of 2\n",n);
    }

}

// ======================= Task 0.8 =======================
enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
   

    printf("Enter a number (1-7): ");
    int dayNumber;
    scanf("%d",&dayNumber);

    enum Weekday day = (enum Weekday)(dayNumber - 1);

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
    printf("Enter coordinated of p1(x,y): ");
    scanf("%d %d",&p1.x, &p1.y);
    printf("Enter coordinated of p2(x,y): ");
    scanf("%d %d",&p2.x, &p2.y);

    double distance = sqrt ( pow(p2.x - p1.x,2) + pow(p2.y - p1.y, 2));
    printf("Eucledian Distance is %.3f\n", distance); 
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    int sum;
    int num_1 = atoi(argv[1]);
    int num_2 = atoi(argv[2]);
    sum = num_1 + num_2;
    printf("Sum is %d\n", sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    //task01_datatypes();
    //task02_calculator();
    //task03_fibonacci();
    //task03_guessing_game();
    //printf("%d\n",isPrime(8));
    //task04_prime_numbers(); printf("\n");
    //printf("Factorial of 5 = %d\n", factorial(5));
    //task05_reverse_string();
    //task05_second_largest();
    //task06_file_io();
    //task07_bitwise_ops();
    //task08_enum_weekday();
    //task09_struct_distance();
    //task10_cmd_args(argc, argv);

    return 0;
}
