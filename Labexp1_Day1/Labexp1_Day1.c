#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    int     car_no      = 1;        // Integer: whole numbers
    float   car_torque  = 54.7;     // Single precision floating point
    double  engine_V    = 12;       // Double precision floating point
    char    car_name    = 'R';      // Single character
    
    // Print their sizes and demonstrate type casting
    // Display memory size of each data type using sizeof operator
    printf("Size of car_no is:  %zu bytes\n",sizeof(car_no));
    printf("Size of car_torque: %zu bytes\n",sizeof(car_torque));
    printf("Size of engine_V:   %zu bytes\n",sizeof(engine_V));
    printf("Size of car_name:   %zu bytes\n",sizeof(car_name));
    
    // Demonstrate explicit type casting between data types
    printf("Converting int(12) ---> float:      %f\n",(float)engine_V);     // int to float
    printf("Converting float(54.7) ---> int:    %d\n",(int)car_torque);     // float to int (truncates decimal)
    
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    int a,b;            // Variables to store two integers
    char operator;      // Variable to store operator choice
    
    // TODO: Take two integers as input
    printf("Enter first  integer a: ");
    scanf("%d",&a);
    printf("Enter second integer b: ");
    scanf("%d",&b);
    
    // Perform arithmetic operations
    // Display results of all basic arithmetic operations
    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("a * b = %d\n",a*b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n",a%b);    // %% prints literal % symbol
    
    // Implement switch-case calculator
    // Interactive calculator - user chooses specific operation
    printf("Now your choice operator\n");
    printf("Enter first  integer a:          ");
    scanf("%d",&a);
    printf("Enter second integer b:          ");
    scanf("%d",&b);
    printf("Operator you want (+,-,*,/,%%):   ");
    scanf(" %c",&operator);        // Space before %c consumes any whitespace
    
    // Switch statement to perform selected operation
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
            printf("a / b = %d\n",a/b);    // Integer division (no decimal result)
            break;
        case '%':
            printf("a %% b = %d\n",a%b);   // Modulo operation (remainder)
            break;
        default :
            printf("Something is wrong");   // Handle invalid operator input
    }
}

// Recursive function to calculate nth Fibonacci number
int fib(int n) {
    if (n == 0)         // Base case: F(0) = 0
        return 0;
    else if (n == 1)    // Base case: F(1) = 1
        return 1;
    else                // Recursive case: F(n) = F(n-1) + F(n-2)
        return fib(n - 1) + fib(n - 2);
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;      // Number of terms to generate
    
    printf("Enter how many terms you want in Fibonacci series: ");
    scanf("%d",&n);
    
    printf("Fibonacci Series: ");
    // Generate and print each Fibonacci number from 0 to n-1
    for (int i = 0; i < n; i++) {
        printf("%d ",fib(i));       // Call recursive function for each position
    }
    printf("\n");   
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int number,guess;       // Random number to guess and user's guess
    int attempts = 0;       // Counter for number of attempts
    
    srand(time(0));                 // Seed random number generator with current time
    number = rand() % 100 + 1;      // Generate random number between 1-100
    
    printf("Guess the number between 1 and 100:\n");
    
    // Game loop - continues until correct guess
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;         // Increment attempt counter
        
        // Provide feedback to guide the player
        if (guess > number)
            printf("Too high! Try again.\n");
        else if (guess < number)
            printf("Too low! Try again.\n");
        else
            printf("Correct! You guessed it in %d attempts.\n", attempts);
    } while (guess != number);      // Loop until correct guess
}

// ======================= Task 0.4 =======================
// Function to check if a number is prime
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if(n <= 1)          // Numbers <= 1 are not prime
        return 0;
    
    // Check for divisors from 2 to √n (efficient prime checking)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)     // If divisible, not prime
            return 0;
    }
    return 1;               // No divisors found, it's prime
}

void task04_prime_numbers() {
    FILE *f1;               // File pointer for output file
    
    // TODO: Print prime numbers between 1 and 100
    f1 = fopen("prime_numbers.txt", "w");      // Open file for writing
    if (!f1) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Check each number from 1 to 100
    for(int i = 1; i <= 100; i++){
        if(isPrime(i)){     // If number is prime
            printf("%d ",i);            // Display on console
            fprintf(f1, "%d\n", i);     // Write to file
        }
    }
    fclose(f1);             // Close file to save data
}

// Recursive function to calculate factorial of n
int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n == 0 || n == 1)      // Base case: 0! = 1 and 1! = 1
        return 1;
    else                       // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    return 1;                  // Unreachable code (after recursive return)
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    int len = 0;                    // Variable to store string length
    
    // TODO: Reverse a string without library functions
    char str[10] = "abcdefg";       // Original string to reverse
    
    // Manual length calculation (replaces strlen())
    while(str[len] != '\0'){
        len++;
    }
    
    char str1[len+1];               // Array for reversed string (size = length + 1 for '\0')
    
    // Copy characters in reverse order
    for (int i = 0; i < len; i++) {
        str1[i] = str[len - 1 - i]; // Map: str1[0] = str[6], str1[1] = str[5], etc.
    }
    str1[len] = '\0';               // Add null terminator to complete string
    printf("%s",str1);              // Display reversed string
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int n;          // Size of array
    printf("Enter size of array: ");
    scanf("%d",&n);
    
    int arr[n];     // Variable length array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int largest, second;        // Variables to track largest and second largest
    
    // Initialize with first two elements
    if (arr[0] > arr[1]) {
        largest = arr[0];
        second  = arr[1];
    } else {
        largest = arr[1];
        second  = arr[0];
    }
    
    // Process remaining elements starting from index 2
    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {         // Found new largest
            second = largest;           // Old largest becomes second
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {  // Found new second (avoiding duplicates)
            second = arr[i];
        }
    }
    
    // Handle edge case where all elements are the same
    if (largest == second)
        printf("No distinct second largest element.\n");
    else
        printf("Second largest = %d\n", second);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *f;                                // File pointer
    int nums[5] = {10, 20, 30, 40, 50};     // Array to write to file
    int readnums[5];                        // Array to store numbers read from file
    
    // Write phase: Open file for writing
    f = fopen("numbers.txt", "w");
    if (!f) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Write each number to file (one per line)
    for (int i = 0; i < 5; i++) {
        fprintf(f, "%d\n", nums[i]);
    }
    fclose(f);                              // Close file after writing
    
    // Read phase: Open same file for reading
    f = fopen("numbers.txt", "r");
    if (!f) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    // Read numbers back from file into array
    for (int i = 0; i < 5; i++) {
        fscanf(f, "%d", &readnums[i]);
    }
    fclose(f);                              // Close file after reading
    
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
    int a = 5;      // Binary: 101
    int b = 3;      // Binary: 011
    
    // Basic bitwise operations
    printf("a & b  = %d\n", a & b);     // AND: 101 & 011 = 001 (1)
    printf("a | b  = %d\n", a | b);     // OR:  101 | 011 = 111 (7)
    printf("a ^ b  = %d\n", a ^ b);     // XOR: 101 ^ 011 = 110 (6)
    printf("~a     = %d\n", ~a);        // NOT: ~101 = ...11111010 (-6)
    
    // Bit shift operations
    printf("a << 1 = %d\n", a << 1);    // Left shift: 101 << 1 = 1010 (10)
    printf("a >> 1 = %d\n", a >> 1);    // Right shift: 101 >> 1 = 10 (2)
    
    // Bonus: Check if number is power of 2
    int num;
    printf("Enter number to check power of 2: ");
    scanf("%d", &num);
    
    // Power of 2 trick: n & (n-1) == 0 for powers of 2
    if (num > 0 && (num & (num - 1)) == 0)
        printf("%d is power of 2\n", num);
    else
        printf("%d is NOT power of 2\n", num);
    
}

// ======================= Task 0.8 =======================
// Enum definition: MON=1, TUE=2, WED=3, THU=4, FRI=5, SAT=6, SUN=7
enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    int num;                        // User input number
    printf("Enter a number (1-7): ");
    scanf("%d", &num);
    
    enum Weekday day = num;         // Cast integer to enum type
    
    // Switch statement using enum constants
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
// Structure to represent a 2D point
struct Point {
    int x;      // X coordinate
    int y;      // Y coordinate
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    struct Point p1, p2;       // Two point structures
    
    // Input coordinates for both points
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);
    
    // Calculate differences in x and y coordinates
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    
    // Apply Euclidean distance formula: √((x2-x1)² + (y2-y1)²)
    double distance = sqrt(dx * dx + dy * dy);
    printf("Euclidean Distance = %.2f\n", distance);
}

// Function to check if number is power of 2 using bitwise trick
int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);    // n & (n-1) == 0 for powers of 2
}

void task09_check_power_of_two() {
    int num;        // Number to check
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Check and display result
    if (isPowerOfTwo(num))
        printf("%d is a power of 2.\n", num);
    else
        printf("%d is NOT a power of 2.\n", num);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    
    // Check if exactly 2 arguments provided (argc=3: program name + 2 args)
    if (argc != 3) {
        printf("Usage: ./a.out <num1> <num2>\n");
        return;
    }
    
    // Convert string arguments to integers
    int a = atoi(argv[1]);      // First argument (string to int)
    int b = atoi(argv[2]);      // Second argument (string to int)
    int sum = a + b;            // Calculate sum
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
