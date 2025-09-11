#include <stdio.h>
#include <stdlib.h>

void task06_file_io() {
    FILE *file; 
    int numbers[5];
    file = fopen("saima.txt", "w");
    
    //WRITING TO FILE
    printf("Enter 5 integers :\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        fprintf(file, "%d\n", numbers[i]); // writing in file , i-e giving input to file
    }
    fclose(file); //closing file after writing

    //READING FROM FILE
    file = fopen("saima.txt", "r");
    printf("Numbers read from file are:\n");    
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%d", &numbers[i]); // reading from file i-e to get input from file
        printf("%d ", numbers[i]);
    }
    printf("\n");
    fclose(file); // closing file after reading

    printf("File operations completed successfully.\n");
    printf("Okbye!\n");   
}

int main()
{
    task06_file_io();
    return 0;
}