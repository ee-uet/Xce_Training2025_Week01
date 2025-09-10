#include<stdio.h>

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

int main()
{
    task01_datatypes();
    return 0;
}