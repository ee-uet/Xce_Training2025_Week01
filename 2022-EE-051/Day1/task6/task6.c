#include <stdio.h>

void task06_file_io() {
    // Write 5 integers to a file, then read them back
    FILE *fp;
    int num;
    // Opening a file in write mode
    fp = fopen("numbers.txt", "w");  
    if (!fp) {
        printf("File not found\n");
        return;
    }
    // Writing integers to the file
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
    // Opening the  file in read mode and printing on console the  contents of the file
    fp = fopen("numbers.txt", "r");
    if(!fp) {  
        printf("File not found\n");
        return;
    }
    printf("Numbers read from file:\n");
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d", &num);
        printf("%d ", num);
    }
    printf("\n");
    fclose(fp);
}

int main() {

    task06_file_io();
    return 0;
}
