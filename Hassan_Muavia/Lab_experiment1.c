#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void task01_datatypes(){
    int a = 11;
    float b = 1.567;
    double c = 2.111344;
    char g = 'A';
    printf("size: %d bytes\n",sizeof(a));
    printf("size: %d bytes\n",sizeof(b));
    printf("size: %d bytes\n",sizeof(c));
    printf("size: %d bytes\n",sizeof(g));

    int m = (int)(a/b);
    printf("value of m: %d",m);
}

void task02_calculator(){
    int num1,num2;
    char p;
    printf("Enter the integers: ");
    scanf("%d %c %d",&num1,&p,&num2);
    

    switch(p){
        case '+':
            printf("sum is: %d",num1+num2);
            break;
        case '-':
            printf("difference is: %d",num1-num2);
            break;
        case '*':
            printf("multiplication is: %d",num1*num2);
            break;
        case '/':
            printf("division is: %d",num1/num2);
            break;
        default:
            printf("Invalid operator!");
    }
}

void task03_fibonacci(){
    int a = 0;
    int b = 1;
    int next = 0;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("The numbers are:0 1 ");
    for (int i=2;i<n;i++){
        next = a + b;
        printf("%d ",next);
        a = b;
        b = next;
          
    }
}

void task03_guessing_game() {
    srand(time(0)); 
    int randomNum = (rand() % 100) + 1;
    int a;

    printf("Guess a number between 1 and 100: ");
    scanf("%d", &a);

    while (a != randomNum) {
        if (a > randomNum && a - randomNum > 30) {
            printf("Too high! Try again: ");
        } 
        else if (a < randomNum && randomNum - a > 30) {
            printf("Too low! Try again: ");
        } 
        else if (a > randomNum) {
            printf("High, but close! Try again: ");
        } 
        else {
            printf("Low, but close! Try again: ");
        }

        scanf("%d", &a);
    }

    printf(" Congratulations! You guessed the number %d correctly!\n", randomNum);
}

int isPrime(int n) {
    if (n <= 1) return 0;        
    if (n == 2) return 1;        
    if (n % 2 == 0) return 0;    

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;  
    }
    return 1;
}

void task04_prime_numbers() {
    printf("Prime numbers between 1 and 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int factorial(int n) {
    if (n == 0 || n == 1) 
        return 1;
    return n * factorial(n - 1);
}


void task05_reverse_string() {
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    scanf("%s", str);  

   
    while (str[len] != '\0') {
        len++;
    }

    
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
}

void task05_second_largest() {
    int arr[] = {5, 12, 7, 20, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int max1 = arr[0], max2 = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }

    printf("Second largest = %d\n", max2);
}

void task06_file_io() {
    int num[5];
    FILE *file;

    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(file, "%d\n", i);  
    }
    fclose(file); 

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }

    printf("Numbers read from file:\n");
    for (int j = 0; j < 5; j++) {
        fscanf(file, "%d", &num[j]); 
        printf("%d\n", num[j]);
    }
    fclose(file); 
}

void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int a=7;
    int b=4;

    printf("a&b: %d\n",a&b);
    printf("a|b: %d\n",a|b);
    printf("a^b: %d\n",a^b);
    printf("~a: %d\n",~a);
    printf("a<<1: %d\n",a<<1);
    printf("a>>1: %d\n",a>>1);

}

void power(int n){
    if ((n & (n-1))==0){
        printf("number is power of 2");
    }
    else{
        printf("number is not power of 2");
    }
}
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum weekday{MONDAY=1,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY};
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    if (num>=1 && num<=7){
        enum weekday day = num;
        switch (day)
        {
        case MONDAY:
            printf(" MONDAY");
            break;
        case TUESDAY:
            printf(" TUESDAY");
            break;
        case WEDNESDAY:
            printf(" WEDNESDAY");
            break;
        case THURSDAY:
            printf(" THURSDAY");
            break;
        case FRIDAY:
            printf(" FRIDAY");
            break;
        case SATURDAY:
            printf(" SATURDAY");
            break;
        case SUNDAY:
            printf(" SUNDAY");
            break;
        default:
            break;
        }
    }
}
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    struct Point p1;
    struct Point p2;
    float distance;

    printf("enter 1st point: ");
    scanf("%d %d",&p1.x,&p1.y);
    printf("enter 2nd point: ");
    scanf("%d %d",&p2.x,&p2.y);

    distance = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));

    printf("distance: %f",distance);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc == 3){
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        int sum = num1+num2;
        printf("sum is %d",sum);
    }
    else {
        printf("arguments are not complete");
    }
}
int main(){
    
    //task01_datatypes();
    //task02_calculator();
  //task03_fibonacci();
//task03_guessing_game();
//task04_prime_numbers();
//task05_second_largest();
//task05_reverse_string();
//task06_file_io();
//task07_bitwise_ops();
//task08_enum_weekday();
//task09_struct_distance();
//task10_cmd_args(argc,argv);

power(12);
    return 0;
}