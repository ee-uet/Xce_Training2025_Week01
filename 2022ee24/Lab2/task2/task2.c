#include <stdio.h>
#include <stdlib.h>


// Custom strlen using pointers
int my_strlen(const char *s) {
    // TODO: Implement strlen
    int i = 0;
    while( *(s+i) != '\0')
    {
        i += 1;
    }
    return i;
}

// Custom strcpy using pointers
void my_strcpy(char *dest, const char *src) {
    // TODO: Implement strcpy
    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest+i) = *(src+i);
        i += 1;
    }
}

// Custom strcmp using pointers
int my_strcmp(const char *s1, const char *s2) {
    // TODO: Implement strcmp
    int i = 0;
    while ( (*(s1+i)!='\0') && (*(s2+i)!='\0') )
    {
        int temp = (int)(*(s1+i) - *(s2+i));
        if (temp && temp!=32 && temp!=-32)
        {
            return temp;       
        }
        i += 1;
    }
    return 0;
}

// Task 2.2: Palindrome checker (case-insensitive)
int is_palindrome(const char *s) {
    // TODO: Implement palindrome check
    int len = my_strlen(s);
    int check;
    char* rs = (char*)malloc(len);
    my_strcpy(rs,s);
    for (int i=0;i<len;i++)
    {
        *(rs+i) = *(s+len-1-i);
    }
    check = my_strcmp(s,rs);
    free(rs);
    if (check)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
    printf("Len = %d\n", my_strlen("Hello"));
    char buf[100]; my_strcpy(buf,"World");
    printf("Copied: %s\n", buf);
    printf("%d\n",my_strcmp("aDc","adg"));
    printf("%d\n",my_strcmp("ahmad","ahmaddd"));
    printf("Palindrome? %s\n", is_palindrome("Mam") ? "Yes":"No");
    return 0;
}