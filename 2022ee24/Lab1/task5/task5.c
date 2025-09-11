#include <stdio.h>

void task05_reverse_string() {
    // TODO: Reverse a string without library functions
    char string[20];
    int len = 0;
    
    printf("Enter string: ");
    scanf("%s",string);

    char i = string[0];

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

int main()
{
    task05_reverse_string();
    task05_second_largest();
    return 0;
}