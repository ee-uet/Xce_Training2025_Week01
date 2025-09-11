#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    printf("----------------DataTypes and their size-----------------\n");
 
    int a;     //declaring int
    float b;   //declaring float
    double c;  //declaring double
    char d;    //declaring char
 // printing sizes of different datatypes
    printf("Size of int is: %zu\n", sizeof(a));
    printf("Size of float is: %zu\n", sizeof(b));
    printf("Size of double is: %zu\n", sizeof(c));
    printf("Size of char is: %zu\n", sizeof(d));       
  
  // Type casting demo 1
    char str1[6] = "Hello"; //initializing array
    int num = 123;          //initializing int 
    char str2 = (char)num;  //typecasting int to char
    char temp[2];           //decalring char
    temp[0]=str2;           //assigning typecasted string to 1st index
    temp[1]='\0';           //assigning null character to 2nd index
    strcat(str1,temp);      //concatenating both strings
    printf("type-casted from int to char and concatenated to another string: %s\n", str1); // ASCI of 123 is {
    // Type casting demo 2
    int int1=20, int2=3;  //initializing int
    printf("Without TypeCasting, 20/3 = %d\n",int1/int2);
    float int3 = (float)int1; //typecasting int to float
    printf("After TypeCasting, 20/3 = %f\n", int3/int2);
}
// ======================= Task 0.2 =======================
int task02_calculator(int arg1,int arg2)
{
    printf("--------------calculator---------------\n");
    // initializing int variables and assigning them different operations 
    int sum = arg1 + arg2; 
    int subtract = arg1 -  arg2;
    int product = arg1*arg2;
    int quotient = arg1/arg2;
    int remainder = arg1%arg2;
    char operator;
    // asking user which operation to perform
    printf("Two numbers are %d and %d, choose operator(+,-,*,/,%%): \n",arg1,arg2);
    scanf("%c",&operator);
    // using switch-case to print desired operation's answer
    switch(operator)
    {
        case'+':
        printf("Sum of these two numbers is: %d\n", sum);
        break;

        case '-':
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
	printf("-----------------fibonacci numbers----------------\n-");
    int f1 = 0, f2 = 1; // initializing first two fibonacci numbers
    int next,n; 
    // taking input from user upto which fibonacci series is to be printed
    printf("Enter a number: ");
    scanf("%d", &n);
    // for n=0, f1=0 will be printed
    if (n == 0){
        printf("Fibonacci Series: 0\n");
    }
    // 
    else{    
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ,", f1);
        next = f1 + f2; // calculate next fibonacci number
        f1 = f2;        // 2nd fn comes to the place of 1st fn
        f2 = next;      // next calculated fn comes to the place of 2nd fn
    }
    printf("\n");
    }
}
void task03_guessing_game() {
    printf("--------------guessing game--------------\n");
    // TODO: Implement guessing game with random number
    int number, guess;           // rand() defined in stdlib.h
    number = (rand() % 100) + 1; // takin mod of random num with 100 and adding 1, ensuring the number is in range 1-100
    // taking user's guess
    printf("Guess the number (between 1 and 100):\n");
    scanf("%d", &guess);
    // while guess is not correct. giving hints to user and taking input again
    while (guess != number) {
        if (guess > number) {
            printf("High! Try again.\n");
        }
        else {
        printf("Low! Try again.\n");
        }
        scanf("%d", &guess); 
    }
    // print this if correct number has been guessed
    printf("Correct! The number was %d\n", number);
}


int task04_prime_numbers(int n) {
    printf("----------------prime numbers-----------------\n");
    // print 1 if number is prime and 0 otherwise
        if (n <= 1) {
            printf("0\n");
        }
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                printf("%d is not a Prime Number\n",n);
            }
        }
        printf("%d is a prime number\n",n);
    
    // Print prime numbers between 1 and 100
    printf("Prime Numbers between 1 and 100 are: ");
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
    else if (n == 0 || n == 1) { // factorial of 0 and 1 is 1
        return 1;
    }
    return n * factorial(n - 1); // multiplying number with its preceding numbers
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    char str[100]; // declaring string
    printf("-------------string reversal-----------\n");
    printf("Enter a string: "); // taking input string from user
    scanf("%s", str);   
    
    // finding length of string
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // reverse in place
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i] ; // temp variable to store 1st index
        str[i] = str[j];     // putting last index to first place
        str[j] = temp;       // putting first index stored in temp to last index place
        i++;                 // incrementing starting index
        j--;                 // decrementing last index
    }

    printf("Reversed string: %s\n", str);
}

void task05_second_largest() {
    printf("----------------Second Largest--------------\n");

    int arr[] = {2,6,3,8,6};
    int n = sizeof(arr) / sizeof(arr[0]); // calculating no. of elements of array
    if (n < 2) {
        printf("Array must have at least two elements.\n"); // edge case empty or only one element handled
        return;
    }

    int largest = arr[0];
    int second = 0;            // value doesn't matter until foundSecond==true
    bool foundSecond = false;  // track whether we have a valid second largest

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {       // if next element is greater than prior, store it in largest
            second = largest;         // store prior largest in second (as second largest)
            largest = arr[i];     
            foundSecond = true;         // set found second flag to true
        } else if (arr[i] < largest) {  // if next element is not greater than current largest
            if (!foundSecond || arr[i] > second) { // and if next element is greater than second, set it to second largest  
                second = arr[i];       
                foundSecond = true;        
            }
        }
    }

    if (!foundSecond) {
        printf("No second largest element (all elements equal).\n");
    } else {
        printf("Second largest element in {2,6,3,8,6} is %d\n", second);
    }
}


// ======================= Task 0.6 =======================
void task06_file_io() {
        printf("----------Writing to and reading from file-------\n");
    
        FILE *fp;     // file pointer
        int nums[5];  // declaring array of int
        // taking input from user
        printf("Enter 5 integers: ");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &nums[i]);
        }
        // opening file in write mode
        fp = fopen("numbers.txt", "w");
	// print error msg if file not opened(return NULL)
        if (fp == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
        // print the numbers taken from user in file 
        for (int i = 0; i < 5; i++) {
            fprintf(fp, "%d\n", nums[i]);
        }
        fclose(fp);
        // now open that file in read mode
        fp = fopen("numbers.txt", "r");
        if (fp == NULL) {
            printf("Error opening file for reading.\n"); // print error msg if file not opened
            return;
        }
        // printing numbers read from file
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
    printf("-----------bitwise operators-------\n");

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
	    // passing elements of array to the func and prints yes/no based on 1 or 0
        printf("%d -> %s\n", testNums[i], isPowerOf2(testNums[i]) ? "Yes" : "No");
    }
}

void task08_enum_weekday() {
    printf("------------enum weekday---------\n");
    // nummbers starting from 1 (default 0)
    enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

    int num;
    printf("Enter a number (1–7): ");
    scanf("%d", &num);
    // comparing user input with enum variables
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
	printf("-----------------Euclidean Distance--------------------\n");
    struct Point p1, p2;   // two points (x,y) to store coordinates
    double distance;       // to store the calculated distance

    // take input for first point
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    // take input for second point
    printf("Enter coordinates of Point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    // apply Euclidean distance formula
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    // print the result with 2 decimal places
    printf("Euclidean Distance = %.2f\n", distance);
}

//power of Two
bool isPowerOfTwo(unsigned int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
	printf("-------------------command-line arguments-----------------------\n");
    // argc = argument count 
    // argv = argument vector

    // If fewer than 2 numbers are provided
    if (argc < 3) {
        printf("Please enter two command-line arguments\n");
        return; 
    }

    // argv[1] and argv[2] are strings, so we need to convert them to integers
    int num1 = atoi(argv[1]);  
    int num2 = atoi(argv[2]);  

    // Print the sum of the two numbers
    printf("Sum of command-line arguments = %d\n", num1 + num2);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {


    // Uncomment tasks as you implement them
     task01_datatypes();
     task02_calculator(6,2);
     task03_fibonacci();
     task03_guessing_game();
     task04_prime_numbers(2);
     printf("-----------------factorial-------------------\n");
     printf("Factorial of 5 = %d\n", factorial(5));
     task05_reverse_string();
     task05_second_largest();
     task06_file_io();
     task07_bitwise_ops();
     task08_enum_weekday();
     task09_struct_distance();
    for (int i = 0; i <= 20; i++) {
        printf("%d -> %s\n", i, isPowerOfTwo(i) ? "Power of 2" : "Not Power of 2");
    }
     task10_cmd_args(argc, argv);

    return 0;
}
