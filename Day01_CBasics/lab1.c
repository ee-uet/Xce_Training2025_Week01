#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void task01_datatypes() {
    int integerValue = 10;
    float floatValue = 20.5;
    double doubleValue = 30.75;
    char characterValue = 'A';

   // printf("Let's check the size of each data type!\n");
    printf("An integer uses: %zu bytes\n", sizeof(integerValue));
    printf("A float uses: %zu bytes\n", sizeof(floatValue));
    printf("A double uses: %zu bytes\n", sizeof(doubleValue));
    printf("A character uses: %zu bytes\n", sizeof(characterValue));
    
    printf("\nNow for some type casting magic!\n");
    
    float integerAsFloat = (float)integerValue;
    printf("When we cast int %d to a float, we get: %.2f\n", integerValue, integerAsFloat);

    int floatAsInteger = (int)floatValue;
    printf("When we cast float %.2f to an int, we lose the decimal and get: %d\n", floatValue, floatAsInteger);

    int charAsInteger = (int)characterValue;
    printf("Casting the character '%c' to an integer gives its ASCII value: %d\n", characterValue, charAsInteger);
}

void task02_calculator() {
    int firstNumber, secondNumber;
    char operation;

    
    printf("Please enter the operation you'd like to perform (+, -, *, /): ");
    scanf(" %c", &operation);
    
    printf("Now, enter two numbers, separated by a space: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    
    switch (operation) {
        case '+':
            printf("%d plus %d is %d\n", firstNumber, secondNumber, firstNumber + secondNumber);
            break;
        case '-':
            printf("%d minus %d is %d\n", firstNumber, secondNumber, firstNumber - secondNumber);
            break;
        case '*':
            printf("%d times %d is %d\n", firstNumber, secondNumber, firstNumber * secondNumber);
            break;
        case '/':
            if (secondNumber != 0) {
                printf("%d divided by %d is %.2f\n", firstNumber, secondNumber, (float)firstNumber / secondNumber);
            } else {
                printf("Oops! You can't divide by zero.\n");
            }
            break;
        default:
            printf("Sorry, that's not a valid operation.\n");
    }
}

void task03_fibonacci() {
    int numberOfTerms, i;
    int term1 = 0, term2 = 1;
    int nextTerm;

    printf("How many Fibonacci numbers would you like to see? ");
    scanf("%d", &numberOfTerms);

    printf("Here is the Fibonacci series:\n");
    
    if (numberOfTerms >= 1) {
        printf("%d", term1);
    }
    if (numberOfTerms >= 2) {
        printf(", %d", term2);
    }
    
    for (i = 3; i <= numberOfTerms; ++i) {
        nextTerm = term1 + term2;
        printf(", %d", nextTerm);
        term1 = term2;
        term2 = nextTerm;
    }
    printf("\n");
}

void task03_guessing_game() {
    int targetNumber, playerGuess, guessCount = 0;
    
    targetNumber = rand() % 100 + 1;
    
    printf("guess the num\n");
    
    do {
        printf("What's your guess? ");
        scanf("%d", &playerGuess);
        guessCount++;
        
        if (playerGuess > targetNumber) {
            printf("Your guess is a bit too high! Try again.\n");
        } else if (playerGuess < targetNumber) {
            printf("That's too low! Try again.\n");
        } else {
            printf("You got it! The number was %d. It only took you %d tries!\n", targetNumber, guessCount);
        }
    } while (playerGuess != targetNumber);
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void task04_prime_numbers() {
    printf("Here are all the prime numbers between 1 and 100:\n");
    for (int number = 1; number <= 100; number++) {
        if (isPrime(number)) {
            printf("%d ", number);
        }
    }
    printf("\n");
}

int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void task05_reverse_string() {
    char inputString[100];
    int stringLength, leftIndex, rightIndex;
    char temporaryChar;

    printf("Enter a word to reverse it: ");
    scanf("%s", inputString);

    stringLength = 0;
    while (inputString[stringLength] != '\0') {
        stringLength++;
    }

    for (leftIndex = 0, rightIndex = stringLength - 1; leftIndex < rightIndex; leftIndex++, rightIndex--) {
        temporaryChar = inputString[leftIndex];
        inputString[leftIndex] = inputString[rightIndex];
        inputString[rightIndex] = temporaryChar;
    }

    printf("The reversed word is: %s\n", inputString);
}

void task05_second_largest() {
    int numbers[] = {10, 5, 20, 8, 15};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    int largest, secondLargest;


    largest = secondLargest = -2147483648;

    for (int i = 0; i < arraySize; i++) {
        if (numbers[i] > largest) {
            secondLargest = largest;
            largest = numbers[i];
        } else if (numbers[i] > secondLargest && numbers[i] != largest) {
            secondLargest = numbers[i];
        }
    }
    
    if (secondLargest == -2147483648) {
        printf("There is no second largest element in the array.\n");
    } else {
        printf("The second largest number in the array is: %d\n", secondLargest);
    }
}

void task06_file_io() {
    FILE *filePointer;
    int dataToWrite[] = {100, 200, 300, 400, 500};
    int dataRead[5];
    int i;

    filePointer = fopen("my_numbers.txt", "w");
    
    printf("Writing some numbers to a file called 'my_numbers.txt'...\n");
    for (i = 0; i < 5; i++) {
        fprintf(filePointer, "%d\n", dataToWrite[i]);
    }
    fclose(filePointer);
    printf("Done writing. The file is now closed.\n");

    filePointer = fopen("my_numbers.txt", "r");
    
    printf("\nNow reading those numbers back from the file...\n");
    for (i = 0; i < 5; i++) {
        fscanf(filePointer, "%d", &dataRead[i]);
        printf("Just read: %d\n", dataRead[i]);
    }
    fclose(filePointer);
    printf("All numbers read. The file is closed again.\n");
}

void task07_bitwise_ops() {
    int x = 5;
    int y = 3;
    
    printf("Our numbers are x = %d (binary: 0101) and y = %d (binary: 0011)\n\n", x, y);

    printf("ANDing x and y: %d\n", x & y);
    printf("ORing x and y: %d\n", x | y);
    printf("XORing x and y: %d\n", x ^ y);
    printf("Flipping the bits of x: %d\n", ~x);
    printf("Shifting x left by 1 bit (x * 2): %d\n", x << 1);
    printf("Shifting x right by 1 bit (x / 2): %d\n", x >> 1);

    int checkNumber;
    printf("\nEnter a number to see if it's a power of 2: ");
    scanf("%d", &checkNumber);
    
    if (checkNumber > 0 && (checkNumber & (checkNumber - 1)) == 0) {
        printf("Yes! %d is a power of 2.\n", checkNumber);
    } else {
        printf("Nope, %d is not a power of 2.\n", checkNumber);
    }
}

void task08_enum_weekday() {
    enum Weekday {
        MONDAY = 1,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
    };

    int dayNumber;
    printf("Enter a number from 1 to 7: ");
    scanf("%d", &dayNumber);
    
    switch (dayNumber) {
        case MONDAY:
            printf("It's Monday.\n");
            break;
        case TUESDAY:
            printf("It's Tuesday.\n");
            break;
        case WEDNESDAY:
            printf("It's Wednesday.\n");
            break;
        case THURSDAY:
            printf("It's Thursday.\n");
            break;
        case FRIDAY:
            printf("It's Friday.\n");
            break;
        case SATURDAY:
            printf("It's Saturday.\n");
            break;
        case SUNDAY:
            printf("It's Sunday.\n");
            break;
        default:
            printf("That number is not a day of the week.\n");
    }
}

void task09_struct_distance() {
    struct Point {
        int xCoordinate;
        int yCoordinate;
    };
    struct Point point1, point2;
    double calculatedDistance;
    
    printf("Enter the X and Y coordinates for the first point  ");
    scanf("%d %d", &point1.xCoordinate, &point1.yCoordinate);
    
    printf("Enter the X and Y coordinates for the second point: ");
    scanf("%d %d", &point2.xCoordinate, &point2.yCoordinate);
    
    calculatedDistance = sqrt(pow(point2.xCoordinate - point1.xCoordinate, 2) + pow(point2.yCoordinate - point1.yCoordinate, 2));
    
    printf("The distance between your two points is: %.2f\n", calculatedDistance);
}

void task10_cmd_args(int argc, char *argv[]) {
    if (argc != 3) {
        printf("To use this, please run it like this: %s <number1> <number2>\n", argv[0]);
        return;
    }
    
    int firstArg = atoi(argv[1]);
    int secondArg = atoi(argv[2]);
    int totalSum = firstArg + secondArg;
    
    printf("You entered %d and %d. Their sum is %d.\n", firstArg, secondArg, totalSum);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

   // task01_datatypes();
 //  task02_calculator();
  //  task03_fibonacci();
   // task03_guessing_game();
  //  task04_prime_numbers();
  //  printf("Factorial of 5 = %d\n", factorial(5));
  //  task05_reverse_string();
  //  task05_second_largest();
   //task06_file_io();
   // task07_bitwise_ops();
   // task08_enum_weekday();
  // task09_struct_distance();
  //  task10_cmd_args(argc, argv);

    return 0;
}