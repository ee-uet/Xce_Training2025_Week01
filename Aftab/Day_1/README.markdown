
## Task 0.1: Data Types
**TODO**: Demonstrate basic data types and type casting.

**Working**: 
Declares an `int`, `float`, `double`, and `char`. Prints their values, sizes (using `sizeof`), and demonstrates type casting (e.g., `int` to `float`, `float` to `int`).

**Test Case**: Call `task01_datatypes()`.

```
int a = 10;
float b = 2.0;
double c = 5.12481632;
char grade = 'B';
printf("Integer is %d and its float type is %f with size %zu\n", a, (float)a, sizeof(a));    
printf("float is %f and its integer type is %d with size %zu\n", b, (int)b, sizeof(b));
printf("Double is %f and its size is %zu\n", c, sizeof(c));
printf("String is %c and its size is %zu\n", grade, sizeof(grade));
```

**Output**:
```
Integer is 10 and its float type is 10.000000 with size 4
float is 2.000000 and its integer type is 2 with size 4
Double is 5.124816 and its size is 8
String is B and its size is 1
```

## Task 0.2: Calculator
**TODO**: Implement a basic calculator with arithmetic operations.

**Working**: 
Prompts user for two integers and an operator (`+`, `-`, `*`, `/`, `%`). Performs the operation using a `switch` statement and handles division/modulus by zero errors.

**Test Case**: Call `task02_calculator()` with inputs `a = 10`, `b = 5`, operation `+`.

```
printf("Enter first number: ");
scanf("%d", &a);
printf("Enter second number: ");
scanf("%d", &b);
printf("What type of operation do you want to operate? (+, -, *, /, %): ");
scanf(" %c", &operation);
```

**Output**:
```
Enter first number: 10
Enter second number: 5
What type of operation do you want to operate? (+, -, *, /, %): +
Sum: 15
```

## Task 0.3: Fibonacci Sequence
**TODO**: Print Fibonacci sequence up to `n` terms.

**Working**: 
Takes user input for `n`. Prints the first `n` Fibonacci numbers using a loop, handling edge cases (`n <= 0`).

**Test Case**: Call `task03_fibonacci()` with input `n = 5`.

```
printf("Enter number: ");
scanf("%d", &n);
```

**Output**:
```
Enter number: 5
Fibonacci seq up to 5 term is 
0
1
1
2
3
```

## Task 0.3: Guessing Game
**TODO**: Implement a number guessing game with a random number.

**Working**: 
Generates a random number between 1 and 100. User guesses until correct or 20 tries are exhausted. Provides feedback (`Too Low`, `Too High`) if guess is off by more than 10.

**Test Case**: Call `task03_guessing_game()` with guesses approaching random number (e.g., 50).

```
printf("Guess the number: ");
scanf("%d", &guess);
```

**Output** (assuming random number is 50):
```
Guess the number: 30
Too Low
Guess the number: 60
Too High
Guess the number: 50
Correct guess!
```

## Task 0.4: Prime Numbers
**TODO**: Find and print prime numbers up to 100.

**Working**: 
Uses `isPrime` function to check primality by testing divisibility up to the square root. Stores primes in an array and prints them.

**Test Case**: Call `task04_prime_numbers()`.

```
for (int i = 2; i <= 100; i++) {
    if (isPrime(i) == 1) {
        arr[size] = i;
        size += 1;
    }
}
```

**Output**:
```
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```

## Task 0.4: Factorial
**TODO**: Implement a recursive factorial function.

**Working**: 
Recursively calculates factorial of `n`, with base case `n = 1`.

**Test Case**: Call `factorial(5)`.

```
printf("Factorial of 5 = %d\n", factorial(5));
```

**Output**:
```
Factorial of 5 = 120
```

## Task 0.5: Reverse String
**TODO**: Reverse a string without library functions.

**Working**: 
Uses a pointer to calculate string length, then swaps characters from ends to middle to reverse the string `Aftab`.

**Test Case**: Call `task05_reverse_string()`.

```
char arr[] = "Aftab";
```

**Output**: 
```
batfA
```


## Task 0.5: Second Largest
**TODO**: Find the second largest element in an array.

**Working**: 
Iterates through array `{2, 6, 16, 5, 7, 3}` twice: first to find the largest, then to find the second largest (excluding the largest).

**Test Case**: Call `task05_second_largest()`.

```
int arr[] = {2, 6, 16, 5, 7, 3};
```

**Output**:
```
7    16
```

## Task 0.6: File I/O
**TODO**: Write 5 integers to a file and read them back.

**Working**: 
Writes integers `0, 1, 2, 3, 4` to `integer.txt`, then reads and prints the file content. Handles file opening errors.

**Test Case**: Call `task06_file_io()`.

```
fprintf(file, "%d %d %d %d %d\n", 0, 1, 2, 3, 4);
```

**Output**:
```
After reading 0 1 2 3 4
```

## Task 0.7: Bitwise Operations
**TODO**: Demonstrate bitwise AND, OR, XOR, NOT, and shifts, plus check if a number is a power of 2.

**Working**: 
Performs bitwise operations on `a = 5` and `b = 3`. Checks if `n = 16` is a power of 2 using `n & (n - 1)`.

**Test Case**: Call `task07_bitwise_ops()`.

```
int a = 5;      // 00000101
int b = 3;      // 00000011
printf("a & b = %d\n", a & b);       // 00000001
printf("a or b = %d\n", a | b);      // 00000111
printf("a xor b = %d\n", a ^ b);     // 00000110
printf("not a = %d\n", ~a);          // 11111010
printf("left_shift a = %d\n", a << 1);  // 00001010
printf("right_shift a = %d\n", a >> 1); // 00000010
int n = 16;
if ((n > 0) && ((n & (n - 1)) == 0)) {
    printf("%d is power of 2\n", n);
}
```

**Output**:
```
a & b = 1
a or b = 7
a xor b = 6
not a = -6
left_shift a = 10
right_shift a = 2
16 is power of 2
```

## Task 0.8: Enum Weekday
**TODO**: Map a number (1–7) to a day of the week using an enum.

**Working**: 
Defines an enum `WeekDay` (1 = MON, ..., 7 = SUN). Uses an array of strings to map and print the day for input `day_num = 4`.

**Test Case**: Call `task08_enum_weekday()`.

```
int day_num = 4;
if (day_num >= MON && day_num <= SUN) {
    printf("%s\n", days[day_num]);
}
```

**Output**:
```
THU
```

## Task 0.9: Struct Distance
**TODO**: Calculate Euclidean distance between two points.

**Working**: 
Defines a `struct Point` with `x` and `y`. Calculates distance between points `(2,3)` and `(4,1)` using the Euclidean formula.

**Test Case**: Call `task09_struct_distance()`.

```
struct Point p1 = {2,3};
struct Point p2 = {4,1};
float result = (((p2.x - p1.x)^2)-((p2.y - p1.y)^2))^(1/2);
```

**Output**:
```
Distance is: 0.00
```

## Task 0.10: Command Line Arguments
**TODO**: Sum two integers passed as command-line arguments.

**Working**: 
Checks for exactly two arguments, converts them to integers using `atoi`, and prints their sum.

**Test Case**: Run program with `./program 5 3`.

```
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
int sum = num1 + num2;
printf("Sum: %d\n", sum);
```

**Output**:
```
Sum: 8
```

## Notes
- Uses 32-bit integers unless specified.
- Task 0.6 creates `integer.txt` in the working directory.