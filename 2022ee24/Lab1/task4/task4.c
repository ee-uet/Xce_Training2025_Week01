#include <stdio.h>

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
    if (n == 1 || n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }

}

int main()
{
    task04_prime_numbers();
    printf("Factorial of 5 = %d\n", factorial(5));
    return 0;
}