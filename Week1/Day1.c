#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    printf("------Function 1-------\n");
    // TODO: Declare int, float, double, char
    int a;
    float b;
    double c;
    char d;
    printf("Size of int is: %zu\n", sizeof(a));
    printf("Size of float is: %zu\n", sizeof(b));
    printf("Size of double is: %zu\n", sizeof(c));
    printf("Size of char is: %zu\n", sizeof(d));       
    // Print their sizes and demonstrate type casting
    // Type casting demo 1
    char str1[6] = "Hello";
    int num = 123;
    char str2 = (char)num;
    char temp[2];
    temp[0]=str2;
    temp[1]='\0';
    strcat(str1,temp);
    printf("type-casted from int to char and concatenated to another string: %s\n", str1); // ASCI of 123 is {
    // Type casting demo 2
    int int1=20, int2=3;
    printf("Without TypeCasting, 20/3 = %d\n",int1/int2);
    float int3 = (float)int1;
    printf("After TypeCasting, 20/3 = %f\n", int3/int2);
}
// ======================= Task 0.2 =======================
int task02_calculator(int arg1,int arg2) {
    printf("------Function 2-------\n");
    // TODO: Take two integers as input
    // Perform arithmetic operations
    int sum = arg1 + arg2;
    int subtract = arg1 -  arg2;
    int product = arg1*arg2;
    int quotient = arg1/arg2;
    int remainder = arg1%arg2;
    char operator;
    // Implement switch-case calculator
    printf("Two numbers are %d and %d, choose operator(+,-,*,/,%%): \n",arg1,arg2);
    scanf("%c",&operator);
    switch(operator)
    {
        case'+':
        printf("Sum of these two numbers is: %d\n", sum);
        break;

        case '-':int next;
        printf("Subtraction of these two numbers is: %d\n", subtract);
        break;

        case '*':
        printf("Product of these two numbers is: %d\n", product);
        break;

        case '/':
        printf("Quotient of these two numbers is: %d\n", quotient);
        break;

        case '%':
        printf("Remainder of these two number is: %d\n", remainder);
        break;
    }

}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    int f1 = 0, f2 = 1;
    int next,n;
    printf("------Function 3-------\n");
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 0){
        printf("Fibonacci Series: 0\n");
    }
    else{    
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ,", f1);
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    printf("\n");
    }
}
void task03_guessing_game() {
    printf("------Function 4-------\n");
    // TODO: Implement guessing game with random number
    int number, guess;
    number = (rand() % 100) + 1;

    printf("Guess the number (between 1 and 100):\n");
    scanf("%d", &guess);
    while (guess != number) {
        if (guess > number) {
            printf("High! Try again.\n");
        }
        else {
        printf("Low! Try again.\n");
        }
        scanf("%d", &guess); 
    }
    printf("Correct! The number was %d.\n", number);
}


int task04_prime_numbers(int n) {
    printf("------Function 5-------\n");
        if (n <= 1) {
            printf("0\n");
        }
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                printf("0\n");
            }
        }
        printf("1\n");
    
    // TODO: Print prime numbers between 1 and 100
    for (int j = 2; j <= 100; j++) {
        int isPrime = 1; // assume prime
        for (int k = 2; k <= j/2; k++) {
            if (j % k == 0) {
                isPrime = 0; // not prime
                break;
            }
        }
        if (isPrime) {
            printf("%d ", j);
        }
    }
    printf("\n");
}


int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1); 
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    char str[100];
    printf("------Function 6-------\n");
    printf("Enter a string: ");
    scanf("%s", str);   
    
    // find length manually
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // reverse in place
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string: %s\n", str);
}



void task05_second_largest() {
    printf("------Second Largest-------\n");

    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }

    int largest = arr[0];
    int second = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;   // update second largest
            largest = arr[i];   // update largest
        } else if (arr[i] > second && arr[i] < largest) {
            second = arr[i];    // update second largest
        }
    }

    if (second == INT_MIN) {
        printf("No second largest element (all elements equal).\n");
    } else {
        printf("Second largest element = %d\n", second);
    }
}

// ======================= Task 0.6 =======================
void task06_file_io() {
        printf("------Function 8-------\n");
    
        FILE *fp;
        int nums[5];
    

        printf("Enter 5 integers: ");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &nums[i]);
        }
    
        fp = fopen("numbers.txt", "w");
        if (fp == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
    
        for (int i = 0; i < 5; i++) {
            fprintf(fp, "%d\n", nums[i]);
        }
        fclose(fp);
    

        fp = fopen("numbers.txt", "r");
        if (fp == NULL) {
            printf("Error opening file for reading.\n");
            return;
        }
    
        printf("Numbers read from file:\n");
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%d", &nums[i]);
            printf("%d ", nums[i]);
        }
        printf("\n");
    
        fclose(fp);
    }


// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    int isPowerOf2(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    printf("------Function 9-------\n");

    int x = 5; 
    int y = 9; 

    printf("x = %d, y = %d\n", x, y);
    printf("x & y  = %d\n", x & y);   
    printf("x | y  = %d\n", x | y);  
    printf("x ^ y  = %d\n", x ^ y);
    printf("~x     = %d\n", ~x);  
    printf("x << 1 = %d\n", x << 1);
    printf("y >> 1 = %d\n", y >> 1);

    // Bonus: Check if number is power of 2
    int testNums[] = {1, 2, 3, 4, 16, 18, 32};
    int size = sizeof(testNums) / sizeof(testNums[0]);

    printf("\nCheck if numbers are power of 2:\n");
    for (int i = 0; i < size; i++) {
        printf("%d -> %s\n", testNums[i], isPowerOf2(testNums[i]) ? "Yes" : "No");
    }
}

void task08_enum_weekday() {
    printf("------Function 10-------\n");

    enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

    int num;
    printf("Enter a number (1–7): ");
    scanf("%d", &num);

    if (num == MON) printf("Day: Monday\n");
    else if (num == TUE) printf("Day: Tuesday\n");
    else if (num == WED) printf("Day: Wednesday\n");
    else if (num == THU) printf("Day: Thursday\n");
    else if (num == FRI) printf("Day: Friday\n");
    else if (num == SAT) printf("Day: Saturday\n");
    else if (num == SUN) printf("Day: Sunday\n");
    else printf("Invalid input! Please enter 1–7.\n");
}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    struct Point p1, p2;
    double distance;

    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("Euclidean Distance = %.2f\n", distance);
}
//power of Two
bool isPowerOfTwo(unsigned int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc < 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return;
    }

    int num1 = atoi(argv[1]);  
    int num2 = atoi(argv[2]);

    printf("Sum = %d\n", num1 + num2);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {


    // Uncomment tasks as you implement them
    // task01_datatypes();
    // task02_calculator(6,2);
    // task03_fibonacci();
    // task03_guessing_game();
    // task04_prime_numbers(2);
    // printf("------Function 7-------\n");
    // printf("Factorial of 5 = %d\n", factorial(5));
    // task05_reverse_string();
     task05_second_largest();
    // task06_file_io();
    // task07_bitwise_ops();
    // task08_enum_weekday();
    // task09_struct_distance();
    for (int i = 0; i <= 20; i++) {
        printf("%d -> %s\n", i, isPowerOfTwo(i) ? "Power of 2" : "Not Power of 2");
    }
     task10_cmd_args(argc, argv);

    return 0;
}
