#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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


// ======================= Main =======================
int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random numbers

   
     task06_file_io();
   

    return 0;
}
