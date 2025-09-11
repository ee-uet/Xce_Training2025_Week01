#include <stdio.h>

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

int main()
{
    task06_file_io();
    return 0;
}