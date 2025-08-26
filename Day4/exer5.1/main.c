#include <stdio.h>
#include "add.h"
#include "product.h"
int main(){
int a=2,b=3;
printf("Sum of %d and %d is: %d \n",a,b,add(a,b));
printf("Product of %d and %d is: %d \n",a,b,product(a,b));
return 0;
}
