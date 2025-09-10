#include <stdio.h>  

void task01_datatypes() 
{
   int a=1;
   float b=1.1f;
   double c=21.132232;
   char d='s';

   printf("Int value is %d and size is %zu bytes respectively.\n",a,sizeof(a)); //zu : sizeof returns unsigned 
   printf("Float  value is %f and size is %zu bytes respectively.\n",b,sizeof(b));//f : for float
   printf("Double  value is %.5lf and size is %zu bytes respectively.\n",c,sizeof(c));//lf : for double 
   printf("Char value %c and size is %zu bytes respectively.\n",d,sizeof(d));

   printf("Typecasting int to float : %.3f \n",(float)a);
   printf("Typecasting float to int : %d \n",(int)b);
   printf("Typecasting double to int : %d \n",(int)c);
   printf("Typecasting int to double : %.3lf \n",(double)a);
   
}

int main()
{
    task01_datatypes();
    return 0;
}
