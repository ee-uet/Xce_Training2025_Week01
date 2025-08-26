

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    int age = 22;
    float height = 5.10;
    double roll_no = 169;
    char name_initial = 'A';
    // Print their sizes and demonstrate type casting
    printf("size of age = %ld bytes\n", sizeof(age));
    printf("size of height = %ld bytes\n", sizeof(height));
    printf("size of roll_no = %ld bytes\n", sizeof(roll_no));
    printf("size of name_initial = %ld bytes\n", sizeof(name_initial));
    int a = 1, b = 2;
    printf("answer = %d\n", a/b);
    printf("answer = %f\n", (float)a/b);
    
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    int alpha;
    int beta;
    printf("enter 1st value: ");
    scanf("%d", &alpha);
    printf("enter 2st value: ");
    scanf("%d", &beta);
    char op;
    printf("enter which operation you want: ");
    scanf(" %c", &op);
    // Perform arithmetic operations
    int sum = alpha + beta;
    int sub = alpha - beta;
    int mul = alpha * beta;
    int quotient = alpha / beta;
    int reminder = alpha % beta;
    // Implement switch-case calculator
   
    switch (op){
        case '+': 
            printf("sum = %d\n",alpha+beta); 
            break; 
        case '-': 
            printf("subtract = %d \n",alpha-beta); 
            break; 
            
        case '/': 
            printf("division  = %d\n",alpha/beta); 
            break; 
        case '*': 
            printf("multiplication = %d \n",alpha*beta); 
            break; 
        case '%': 
            printf("reminder = %d\n",alpha%beta); 
            break; 
        

    }
    
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n, seq=0;
    printf("Enter the number: ");
    scanf("%d", &n);
    for(int i=1;i <= n;i++){
        seq = seq + i;
    }
    printf("%d\n", seq);
    
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int random_number, user_guess;
     
    random_number = rand() % 100 + 1; 

    printf("Guess the number between 1 and 100!\n");
    while (1){
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        if (user_guess > random_number) {
            printf("Too High! Try again.\n");
        } else if (user_guess < random_number) {
            printf("Too Low! Try again.\n");
        } else {
            printf("Correct!");
            break;
        }
    }
    

}

// ======================= Task 0.4 =======================
int task04_Isprime(int n){
    // TODO: Return 1 if n is prime, else 0
    
    if (n <= 1) return 0;      
    if (n == 2) return 1;      
    if (n % 2 == 0) return 0;  

    for (int i = 3; i * i <= n; i += 2) {  
        if (n % i == 0)
            return 0;  
    }
    return 1;  
   
        
}

 

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    for(int i =1;i<=100;i++){
        if(task04_Isprime(i)){
            printf("%d\n", i);
        }
    }
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    int len = 0;
    int temp;
    char string[50];
    printf("Enter a string: ");
    scanf("%s", string);
    while(string[len] != '\0'){
        len++;
    }
    for(int i=0; i<len/2;i++){
        temp = string[i];
        string[i] = string[len-i-1];
        string[len-i-1] = temp;
        
    }
    printf("%s\n", string);
    
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int arr[5] = {1, 2, 3, 4, 5};
    int len = 5;
    int largest, secondLargest;

    if (arr[0] > arr[1]) {
        largest = arr[0];
        secondLargest = arr[1];
    } else {
        largest = arr[1];
        secondLargest = arr[0];
    }

    for (int i = 2; i < len; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Largest = %d\tSecond Largest = %d\n", largest, secondLargest);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE *fp;
    int nums[5];

    
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &nums[i]);
    }

    
    fp = fopen("numbers.txt", "w");
    
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%d ", nums[i]);
    }
    fclose(fp);
    printf("Numbers written to numbers.txt successfully!\n");

    
    fp = fopen("numbers.txt", "r");
    
    printf("Numbers read from file:\n");
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d", &nums[i]);
        printf("%d ", nums[i]);
    }
    fclose(fp);
    printf("\n");

    
    fp = fopen("prime_results.txt", "w");
    
    for (int i = 0; i < 5; i++) {
        if (task04_Isprime(nums[i])) {
            fprintf(fp, "%d is Prime\n", nums[i]);
        } else {
            fprintf(fp, "%d is NOT Prime\n", nums[i]);
        }
    }
    fclose(fp);
    printf("Prime results written to prime_results.txt\n");
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    
    int x = 5;   
    int y = 9;   

    printf("x = %d, y = %d\n\n", x, y);
    printf("x & y  = %d\n", x & y);   
    printf("x | y  = %d\n", x | y);   
    printf("x ^ y  = %d\n", x ^ y);   
    printf("~x     = %d\n", ~x);     
    printf("~y     = %d\n", ~y);     

    
    printf("x << 1 = %d\n", x << 1);  
    printf("y << 1 = %d\n", y << 1);  

    
    printf("x >> 1 = %d\n", x >> 1);  
    printf("y >> 1 = %d\n", y >> 1);  

    
    // Bonus: Check if number is power of 2
    int n;
    int a=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(a<=n){
        if(a==n){
            printf("entered number is a power of 2");
        }
        a = a<<1;
       
    }
    
}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum Weekday { mon = 1, tue, wed, thu, fri, sat, sun };

    int num;
    printf("Enter a number between 1 to 7: ");
    scanf("%d", &num);

    enum Weekday day = num;  

    switch (day) {
        case mon: 
            printf("Monday\n"); 
            break;
        case tue: 
            printf("Tuesday\n"); 
            break;
        case wed: 
            printf("Wednesday\n"); 
            break;
        case thu: 
            printf("Thursday\n"); 
            break;
        case fri: 
            printf("Friday\n"); 
            break;
        case sat: 
            printf("Saturday\n"); 
            break;
        case sun: 
            printf("Sunday\n"); 
            break;
        default: printf("Day number exceeded\n"); 
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
    double distance;
    printf("Enter the coordinates of 1st point: ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter the coordinates of 2nd point: ");
    scanf("%d %d", &p2.x, &p2.y);

    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Euclidean Distance = %.2f\n", distance);   

   
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    // printf("%s\n", argv[0]);
    int num1, num2;
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    printf("sum of %d and %d = %d\n",num1, num2, num1 + num2);

}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers
    //int i;
    // Uncomment tasks as you implement them
    // task01_datatypes();
    //task02_calculator();
    // task03_fibonacci();
    //task03_guessing_game();
    /*i = task04_Isprime(23);
    if(i){
        printf("prime_number.\n");
    }
    else{
        printf("not a prime_number.\n");
    }*/
    //task04_prime_numbers();
  
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