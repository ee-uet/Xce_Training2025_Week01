 
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
    printf("Size of int: %zu bytes\n", sizeof(a)); //zu=unsigned size_t k liye
    printf("Size of float: %zu bytes\n", sizeof(b));
    printf("Size of double: %zu bytes\n", sizeof(c));
    printf("Size of char: %zu bytes\n", sizeof(d));
    printf("Type casting int to float: %f\n", (float)a);    
    printf("Type casting float to int: %d\n", (int)b);
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    int num1, num2, choice;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Choose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Result: %d\n", num1 + num2); //%d prints  signed decimal integer
            break;
        case 2:
            printf("Result: %d\n", num1 - num2);
            break;
        case 3:
            printf("Result: %d\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Result: %.2f\n", (float)num1 / num2);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int number, guess, attempts = 0;
    number = rand() % 100 + 1; // Random number between 1 and 100
    printf("Guess the number (1-100): ");
    do {
        scanf("%d", &guess);
        attempts++;
        if (guess < number) {
            printf("Too low! Try again: ");
        } else if (guess > number) {
            printf("Too high! Try again: ");
        } else {
            printf("Congratulations! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != number);
    printf("The number was: %d\n", number);
    printf("Thanks for playing :D !\n");
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if (n <= 1) 
    return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0; //prime nh ha
    }
    return 1;
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    printf("Prime numbers between 1 and 100:\n");
    for (int i = 1; i <= 100; i++) {    
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n < 0) 
        return -1; // Error for negative input
    if (n == 0 || n == 1) 
        return 1; //ye Base case ha
    if (n > 1) 
        return n * factorial(n - 1); // Recursive case
    return 1;
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char str[100], reversed[100];
    int len = 0;   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //fgets input ko newline char \n ke saath store karta hai jab Enter press krty hain
    str[strcspn(str, "\n")] = 0; // Removing the  newline character (due to Enter key:fgets mn jo tha) yani ye line newline (\n) ko null character (\0) se replace karti hai.Ab str ban gaya: "hello\0"
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1]; // can also do by swapping first and last characters until the middle is reached so half array traversing hga
    }
    reversed[len] = '\0'; // Null-terminate the reversed string
    printf("Reversed string: %s\n", reversed);
    printf("Length of the string: %d\n", len);
} 

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int arr[100], n, largest, second_largest;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }
   // largest = second_largest = arr[0];//initially ye assume kr lo (glt ha :) agr 1st num sbse bra hua to 2ndlargest update nh hga  so had to write this
    if (arr[0] > arr[1]) {
    largest = arr[0];
    second_largest = arr[1];
    } else {
    largest = arr[1];
    second_largest = arr[0];
    }
 
    for (int i = 1; i < n; i++) {   
        if (arr[i] > largest) {
            second_largest = largest; //porany largest ko 2nd largest kr do 
            largest = arr[i]; //yni ab largest ha ye 
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i]; //yni 2nd largest se bra ha number or largest k equal nh to ye ab 2ndlargest hga
        }
    }
    printf("Largest element: %d\n", largest); 
    printf("Second largest element: %d\n", second_largest);//assuming k agr duplicate largest values hain to 2nd largest b largest e hga (5,5,3) (2ndlargest b 5 hga)
    
} 

// ======================= Task 0.6 ======================= 
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *file; 
    int numbers[5];
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    } 
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        fprintf(file, "%d\n", numbers[i]); // Write to file (file mn input dene ke liye)
    }
    fclose(file); // Close file after writing
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    printf("Numbers read from file:\n");    
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%d", &numbers[i]); // Read from file (file se input lene ke liye)
        printf("%d ", numbers[i]);
    }
    printf("\n");
    fclose(file); // Close file after reading
    printf("File operations completed successfully.\n");
    printf("Okbye!\n");   
}

void checkPowerOfTwo() {
    int num;    
    printf("Enter a number to check if it's a power of 2: ");
    scanf("%d", &num);
    if (num > 0 && (num & (num - 1)) == 0) { // 4 is a power of 2 because 4 & (4-1) = 0 ie 0100 & 0011 = 0000
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }
} 

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int a = 5, b = 3; // any number
    printf("Bitwise AND: %d & %d = %d\n", a, b, a & b);
    printf("Bitwise OR: %d | %d = %d\n", a, b, a | b);
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, a ^ b);
    printf("Bitwise NOT: ~%d = %d\n", a, ~a);
    printf("Left Shift: %d << 1 = %d\n", a, a << 1);
    printf("Right Shift: %d >> 1 = %d\n", a, a  >> 1);
    // Check if a number is a power of 2
    checkPowerOfTwo();
}


// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum Weekday { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
    int day;
    printf("Enter a number (1-7) for the day of the week: ");
    scanf("%d", &day);
    switch (day) {
        case MONDAY:
            printf("Monday\n");
            break;
        case TUESDAY:
            printf("Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Wednesday\n");
            break;
        case THURSDAY:
            printf("Thursday\n");
            break;
        case FRIDAY:
            printf("Friday\n");
            break;
        case SATURDAY:
            printf("Saturday\n");
            break;
        case SUNDAY:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid input! Please enter a number between 1 and 7.\n");
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
    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Distance between points (%d, %d) and (%d, %d) is: %.2f\n", p1.x, p1.y, p2.x, p2.y, distance);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) { 
    //argc: kitne arguments diye gaye hain. or argv: array of strings, jisme arguments stored hote hain.
    // TODO: Take 2 integers as command line args and print sum
    if (argc != 3) {
         //agr arguments 2 nahi hain to error print 
        printf("Please provide exactly two integers.\n");
        return;
    }
    int num1 = atoi(argv[1]); // Converting string to integer
    int num2 = atoi(argv[2]);   
    printf("Sum of %d and %d is: %d\n", num1, num2, num1 + num2);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
  
    task10_cmd_args(argc, argv);

    return 0;
} 
