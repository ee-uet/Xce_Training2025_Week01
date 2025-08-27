#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h> 

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    int integer=24;
    float flt=65.4;
    double doub=10244344;
    char grade='A';
    // Print their sizes 
    printf("Value of integer %i and size is %zu bytes\n",integer,sizeof(integer));
    printf("Value of float %f and size is %zu bytes\n",flt,sizeof(flt));
    printf("Value of double %f and size is %zu bytes\n",doub,sizeof(doub));
    printf("Value of char %c and size is %zu byte\n",grade,sizeof(grade));
    // demonstrate type casting
    printf ("TYPE CASTING\n");
    printf("int->float = %i-> %f\n",integer,(float)integer);
    printf("float->integer = %f-> %i \n",flt,(int)flt);

}

// ======================= Task 0.2 =======================
void task02_calculator() {
    printf("-----------------task2----------------------\n");
    int a;
    int b;
    char op;
    // TODO: Take two integers as input
    printf("Enter first integer:");
    scanf("%i",&a);
    printf("Enter second integer:");
    scanf("%i",&b);
    // Perform arithmetic operations
    printf("Addition=%i\n",a+b);
    printf("Subtration=%i\n",a-b);
    printf("Multiplication=%i\n",a*b);
    printf("Quotient=%i\n",a/b);
    printf("Remainder=%i\n",a%b);
    // Implement switch-case calculator
    printf("Enter operation:");
    scanf(" %c",&op);
    switch (op)
    {
    case'+':
        printf("\nAddition=%i\n",a+b);
        break;
    case'-':
        printf("\nSubtration=%i\n",a-b);
        break; 
    case'*':
        printf("\nMultiplication=%i\n",a*b);
        break; 
    case'/':
        printf("\nQuotient=%i\n",a/b);
        break;
    case'%':
        printf("\nRemainder=%i\n",a%b);
        break;
    default:
        printf("\ninvalid operation\n");
        break;
    }

}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    printf("-----------------task3----------------------\n");
    // TODO: Print Fibonacci sequence up to n terms
    int a,b;
    int prev=0,curr=0;

    printf("please enter the number of terms of fibonacci sequence=");
    scanf("%i",&a);
    for (int i = 0; i < a; i++)
    {
        if(i==0){
            printf("%i",curr++);
        }
        else if(i==1){
            printf(",%i",curr);
        }
        else{
            printf(",%i",curr+prev);
            b=curr;
            curr=curr+prev;
            prev=b;

        }

    }
    printf("\n");
    
}

void task03_guessing_game() {
    // TODO: Implement guessing game with random number
    int num,guess;
    num=rand()% 101;
    while (num!=guess){
        printf("guess the number=");
        scanf(" %i",&guess);
        if(guess<num){
            printf("Your guess is TOO LOW\n");
        }
        else{
            printf("Your guess is TOO HIGH\n");
        }
    }
    printf("Your guess is correct\n");
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    // TODO: Return 1 if n is prime, else 0
    if (n<=1){
        return 0;
    }else if (n==2 || n==3)
    {
        return 1;
    }
    else{
        for (int i = 5; i < n; i++)
        {
            if (n%i==0)
            {
                return 0;
            }
            
        }
        
    }
    
    return 1;
}

void task04_prime_numbers() {
    printf("-----------------task4----------------------\nPrime numbers are\n");
    // TODO: Print prime numbers between 1 and 100
    for (int i = 1; i < 100; i++)
    {
        if (isPrime(i))
        {
            printf("%d,",i);
        }
        
    }
    printf("\n");
    
}

int factorial(int n) {
    // TODO: Implement recursive factorial function
    if (n<=1)
    {
        return 1;
    }else
    {
        return n*factorial(n-1);
    }
    
    
    
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char name []="Boota";
    printf("before reversing the string=%s\n",name);
    char* ptr=name;
    char temp='\n';
    char* end=ptr+(sizeof(name)/sizeof(char))-2;
    while (end>ptr)
    {
        temp= *ptr;
        *ptr = *end;
        *end = temp;
        end--;
        ptr++;
    }
    printf("after reversing the string=%s\n",name);
    
}

void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int arr[]={1,25,43,14,35,66};
    int large=0;
    int second=0;
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        if (arr[i]>large)
        {
            second=large;
            large=arr[i];
        }
        
    }
    printf("second largest no:%d\n",second);
    
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    FILE* fw=fopen("integerfile.txt","w");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fw,"%d\n",i);
    }
    fclose(fw);
    FILE* fr=fopen("integerfile.txt","r");
    int num;
    while (fscanf(fr,"%d",&num)==1)
    {
        printf("%d,",num);
    }
    fclose(fr);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops(int x ,int y, int num) {
    // TODO: Demonstrate AND, OR, XOR, NOT, shifts
    printf("x=%d,y=%d\nx&y=%d\nx|y=%d\nx^y=%d\n~y=%d\nx<<y=%d\n",x,y,x&y,x|y,x^y,~y,x<<y);
    // Bonus: Check if number is power of 2
    if ((num&(num-1))==0)
    {
        printf("number=%d is power of 2\n",num);
    }else
    {
        printf("number=%d is not power of 2\n",num);
    }
    

}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    // TODO: Map number (1–7) to day of week using enum
    enum DAYS
    {
       MONDAY=1,
       TUESDAY,
       WEDNESDAY,
       THURSDAY,
       FRIDAY,
       SATURDAY,
       SUNDAY
    };
    enum DAYS day;
    printf("please enter day no:");
    scanf("%d",&day);
    switch (day)
    {
    case MONDAY:printf("Its MONDAY\n"); break;
    case TUESDAY:printf("Its TUESDAY\n"); break;
    case WEDNESDAY:printf("Its WEDNESDAY\n"); break;
    case THURSDAY:printf("Its THURSDAY\n"); break;
    case FRIDAY:printf("Its FRIDAY\n"); break;
    case SATURDAY:printf("Its SATURDAY\n"); break;
    case SUNDAY:printf("Its SUNDAY\n"); break;
    default: printf("Invalid number\n");    break;
    }

}

// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    // TODO: Take two points and calculate Euclidean distance
    struct Point p1;
    struct Point p2;
    printf("Please enter two points\nPoint 1\nx=");
    scanf("%d",&p1.x);
    printf("y=");scanf("%d",&p1.y);
    printf("Point 2 \nx=");
    scanf("%d",&p2.x);
    printf("y=");scanf("%d",&p2.y);
    float dx=(p2.x-p1.x);
    float dy=(p2.y-p1.y);
    double distance=sqrt(dx*dx+dy*dy);
    printf("Euclidean distance=%f\n",distance);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    // TODO: Take 2 integers as command line args and print sum
    if (argc==3)
    {
        int a=atoi(argv[1]);
        int b=atoi(argv[2]);
        printf("sum is %d\n",a+b);
    }else
    {
        printf("Invalid arguments\n");
    }
    
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
     task01_datatypes();
     task02_calculator();
     task03_fibonacci();
     task03_guessing_game();
     task04_prime_numbers();
     printf("Factorial of 5 = %d\n", factorial(5));
     task05_reverse_string();
     task05_second_largest();
     task06_file_io();
     task07_bitwise_ops(5,6,1024);
     task08_enum_weekday();
     task09_struct_distance();
     task10_cmd_args(argc, argv);

    return 0;
}
