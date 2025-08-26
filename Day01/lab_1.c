#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting
    int var1 = 10;
    float var2 = 10.0;
    double var3 = (float)10/3;
    char var4 = 'G'; 

    printf("size of var1: %zu\n",sizeof(var1));
    printf("size of var2: %zu\n",sizeof(var2));
    printf("size of var3: %zu\n",sizeof(var3));
    printf("size of var4: %zu\n",sizeof(var4));

    printf("var2 = %f\n",var2);
    printf("var3 = %f\n",var3);
    printf("var3 = %d\t \\type casted to int\n",(int)var3);
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    // TODO: Take two integers as input
    // Perform arithmetic operations
    // Implement switch-case calculator
    
    int num1,num2;
    char op;

    printf("Enter num1 = ");
    scanf("%d",&num1);
    printf("Enter num2 = ");
    scanf("%d",&num2);
    printf("Enter op = ");
    scanf(" %c",&op);

    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n",num1,num2,num1+num2);
        break;
    case '-':
        printf("%d - %d = %d\n",num1,num2,num1-num2);
        break;
    case '*':
        printf("%d * %d = %d\n",num1,num2,num1*num2);
        break;
    case '/':
        printf("%d / %d = %d\n",num1,num2,num1/num2);
        break;
    default:
        printf("invalid op!\n");
        break;
    }

}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;
    int num1 = 0;
    int num2 = 1;

    printf("Enter n = ");
    scanf("%d",&n);

    printf("%d,%d,",num1,num2);

    for (int i=0;i<n-2;i++)
    {   
        int temp = num1+num2;
        printf("%d,",temp);
        num1 = num2;
        num2 = temp;
    }
    printf("\n");
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int random_num = rand() % 101;  //random num b/w 0 to 100
    int guess = 101;
    int count = 0;
    while (guess != random_num)
    {
        printf("Enter guess(again): ");
        scanf("%d",&guess);
        count += 1;

        if ((guess-random_num) >= 25)
        {
            printf("guess is too high\n");
        }

        else if ((guess-random_num) <= -25)
        {
            printf("guess is too low\n");
        }
        
    }
    printf("You took %d tries\n",count);
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    
    if (n == 1)
    {
        return 0;
    }
    
    for (int i=2;i<n;i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void task04_prime_numbers() {
    // TODO: Print prime numbers between 1 and 100
    int min = 1;
    int num = min;
    int max = 100;
    while (num < max)
    {
        if (isPrime(num))
        {
            printf("%d ",num);
        }
        num += 1;
    }
    printf("\n");
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }

}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char string[20];
    int len = 0;
    char i = string[0];

    printf("Enter string: ");
    scanf("%s",string);

    while(i != '\0')
    {
        len += 1;
        i = string[len];
    }
    //printf("%d\n",len);
    for (int x=0;x<len/2;x++)
    {
        i = string[x];
        string[x] = string[len-1-x];
        string[len-1-x] = i;
    }

    printf("%s\n",string);

}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
     int array[10] = {1,2,3,4,5,90,7,8,6,10};
     int len = 10;
     int max1 = array[0];
     int max2 = array[0];
     for (int i=0;i<len;i++)
     {
        if (max1  < array[i])
        {
            max1 = array[i];
        }
     }
     for (int j=0;j<len;j++)
     {
        if ((max2 < array[j]) && (array[j]!=max1))
        {
            max2 = array[j];
        }
     }
     printf("2nd largest number: %d\n",max2);
     printf("largest number: %d\n",max1);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    int n = 5;
    int num;
    FILE *file = NULL;
    file = fopen("numbers.txt","w");
    
    if (file == NULL)
    {
        printf("Error opening file\n");
    }    

    for (int i=0;i<n;i++)
    {
        printf("Enter number%d: ",i);
        scanf("%d",&num);
        fprintf(file,"%d\n",num);
    }
    fclose(file);
    file = fopen("numbers.txt","r");
    for (int j=0;j<n;j++)
    {
        fscanf(file,"%d",&num);
        printf("%d\n",num);
    }
    fclose(file);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    // Bonus: Check if number is power of 2
    int x,y;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d",&y);
    printf("x & y = %d\n",x & y);
    printf("x | y = %d\n",x | y);
    printf("~x = %d\n",~x);
    printf("x<<2 = %d\n",x<<2);

    printf("is a power of 2: ");
    scanf("%d",&x);
    if ((x>0) && ((x & (x-1))==0))
    {
        printf("is a power of 2\n");
    }
    else{
        printf("is not a power of 2\n");
    }

}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum Weekday{
        Mon  =1,
        Tue = 2,
        Wed = 3,
        Thr = 4,
        Fri = 5,
        Sat = 6,
        Sun = 7
    };
    int n;
    printf("Input day number: ");
    scanf("%d",&n);
    
    switch(n) {
        case Mon:
            printf("Monday\n");
            break;
        case Tue:
            printf("Tuesday\n");
            break;
        case Wed:
            printf("Wednesday\n");
            break;
        case Thr:
            printf("Thursday\n");
            break;
        case Fri:
            printf("Friday\n");
            break;
        case Sat:
            printf("Saturday\n");
            break;
        case Sun:
            printf("Sunday\n");
            break;
    }

}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    float dist;
    int temp1,temp2;
    struct Point p1;
    struct Point p2;
    printf("Enter P1(x,y) = ");
    scanf("%d,%d",&p1.x,&p1.y);
    printf("Enter P2(x,y) = ");
    scanf("%d,%d",&p2.x,&p2.y);
    temp1 = p2.y - p1.y;
    temp2 = p2.x - p1.x;
    dist = sqrt((temp1*temp1)+(temp2*temp2));
    printf("dist = %f\n",dist);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc > 3)
    {
        printf("Error! only 2 arguments can be passed\n");
    }
    int sum = atoi(argv[1]) + atoi(argv[2]);
    printf("sum = %d\n",sum);
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
    //task01_datatypes();
    //task02_calculator();
    //task03_fibonacci();
    //task03_guessing_game();
    //task04_prime_numbers();
    //printf("Factorial of 5 = %d\n", factorial(5));
    //task05_reverse_string();
    // task05_second_largest();
    // task06_file_io();
     task07_bitwise_ops();
    // task08_enum_weekday();
    // task09_struct_distance();
    // task10_cmd_args(argc, argv);

    return 0;
}