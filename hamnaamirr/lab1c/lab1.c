#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    int a = 10;
    float b = 7.66;
    char i = 'b';
    double d = 23.44;
    
    printf("character %c\n",i);
    printf("integer %d\n",a);
    printf("double %f\n",d);
    printf("float %f\n",b);

    printf("character to int %d\n",(int)i);
    printf("integer to float %f\n",(float)a);
    printf("double to integer %d\n",(int)d);
    printf("float to char %c\n",(char)b);

    printf("character size = %zu bytes\n",sizeof(i));
    printf("integer size = %zu bytes\n",sizeof(a));
    printf("double size = %zu bytes\n",sizeof(d));
    printf("float size = %zu bytes\n",sizeof(b));
}

// ======================= Task 0.2 =======================
void task02_calculator() {
    int a = 10;
    int b = 20;
    printf("add %d\n",a+b);
    printf("sub %d\n",a-b);
    printf("mult %d\n",a*b);
    printf("quotient %d\n",a/b);
    printf("remainder %d\n",a%b); 

    
    char operation = 'a'; 
    switch(operation){
    case 'a':
      printf("addition %d\n",a+b);
      break;
    case 's':
      printf("subtract %d\n",a-b);
      break;
    case 'm':
      printf("multiplicate %d\n",a*b);
      break;
    case 'd':
      printf("division %d\n",a/b);
      break;
    case 'r':
      printf("quotient %d\n",a%b);
      break;
    }
}

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    int num, i;
    printf("input a num for fib");
    scanf("%d", &num);

    int a = 0, b = 1, c;

    for (i = 0; i < num; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}


void task03_guessing_game() {
   int random_number = rand()%(100-1)+1; 
   int num;
  while(1){
    scanf("%d",&num);
    if( num == random_number){
     printf("correct number\n");
     break;
   }
    else if ( num > random_number ){
     printf("too high\n");
    }
    else if ( num < random_number){
     printf("too low\n");
    }
  }
}

// ======================= Task 0.4 =======================
int isPrime(int n) {
    if(n < 2) return 0;
    for(int i=2;i*i<=n;i++){
      if(n%i == 0)
         return 0;
    }
    return 1;
}

void task04_prime_numbers() {
    int n, i;
    int isPrime;

    for (n = 2; n <= 100; n++) {
        isPrime = 1;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime= 0;
                break;
            }
        }
        if (isPrime == 1) {
            printf("%d ", n);
        }
    }
    printf("\n");
}

int factorial(int n) {
    if (n==0 || n==1){
      return 1;
    }
    else{
     n=n*factorial(n-1);
     return n; 
    }
}

// ======================= Task 0.5 =======================
void task05_reverse_string() {
    int i;
    char a [] = "apple";
    int length = sizeof(a) / sizeof(a[0]); 

    for(i=length-2;i>=0;i--){ 
      printf("%c",a[i]);
   }
   printf("\n");
}

void task05_second_largest() {
    int i;
    int largest;
    int scndlarg = 0; // second largest
    int a [] = {1,2,3,4,5};
    
    int len = sizeof(a) / sizeof(a[0]);
    largest = a[0];
    for(i=0;i<len;i++){
      if ( a[i] > largest){
           scndlarg = largest ;
           largest = a[i];
      } 
      else if (a[i] < largest && scndlarg < a[i]){
           scndlarg = a[i];
      }
    }
    printf("Second largest = %d\n", scndlarg);
}

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
     FILE *fp;
    int arr[5];
    int i;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    
    fp = fopen("numbers.txt", "w");  
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (i = 0; i < 5; i++) {
        fprintf(fp, "%d ", arr[i]);  
    }
    fclose(fp);
    printf("Numbers written to file successfully!\n");

   
    fp = fopen("numbers.txt", "r");  
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    printf("Numbers read from file:\n");
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        printf("%d\n ", num);  
    }

    fclose(fp);
}

// ======================= Task 0.7 =======================
void task07_bitwise_ops() {
  int x = 4;
  int y = 9;
  printf("%d\n",x&y);
  printf("%d\n",x|y);
  printf("%d\n",x^y);
  printf("%d\n",~y);
  printf("%d\n",y>>1);
  printf("%d\n",x<<1);

  int n = 4;
  if ((n & (n-1)) == 0){ 
   printf("it is a power of 2\n");
  }
  else{ 
    printf("it is not a power of 2\n");
  }
}

// ======================= Task 0.8 =======================
void task08_enum_weekday() {
    int no;
    enum weekday {monday=0, tuesday=1, wednesday=2, thursday=3, friday=4, saturday=5, sunday=6};
    enum weekday day;

    printf("Input a number between 0 and 6: ");
    scanf("%d", &no);

    if (no < 0 || no > 6) {
        printf("Invalid input! Please enter between 0 and 6.\n");
        return;
    }

    day = no;

    switch(day) {
        case monday:    printf("Day is Monday\n"); break;
        case tuesday:   printf("Day is Tuesday\n"); break;
        case wednesday: printf("Day is Wednesday\n"); break;
        case thursday:  printf("Day is Thursday\n"); break;
        case friday:    printf("Day is Friday\n"); break;
        case saturday:  printf("Day is Saturday\n"); break;
        case sunday:    printf("Day is Sunday\n"); break;
    }
}


// ======================= Task 0.9 =======================
struct Point {
    int x;
    int y;
};

void task09_struct_distance() {
    struct Point p1={0,0}, p2={3,4};
    double dist = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    printf("Distance = %f\n", dist);
}

// ======================= Task 0.10 =======================
void task10_cmd_args(int argc, char *argv[]) {
    int a;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    a = num1 + num2;
    printf("%d\n",a); 
}

// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

    // Uncomment tasks as you implement them
     // task01_datatypes();
     // task02_calculator();
      //task03_fibonacci();
      //task03_guessing_game();
      //task04_prime_numbers();
     //printf("Factorial of 5 = %d\n", factorial(5));
     //task05_reverse_string();
    
     //task05_second_largest();
      
     // task06_file_io()  ;
     //task07_bitwise_ops();
     //task08_enum_weekday();
    // task09_struct_distance();
    //task10_cmd_args(argc, argv);

    return 0;
}
