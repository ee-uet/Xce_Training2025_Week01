#include <stdio.h>

// ======================= Task 0.6 =======================
void task06_file_io() {
    FILE *fptr;
    int num[5];

    // Take 5 integers from user
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num[i]);
    }

    // Open file in write mode
    fptr = fopen("numbers.txt", "w");
    if (fptr == NULL) { // check file open error
        printf("Error opening file for writing.\n");
        return;
    }

    // Write integers to file (each on new line)
    for (int i = 0; i < 5; i++) {
        fprintf(fptr, "%d\n", num[i]);
    }
    fclose(fptr);
    printf("Numbers written to 'numbers.txt'\n");

    int n;

    // Reopen file in read mode
    fptr = fopen("numbers.txt", "r");
    if (fptr == NULL) { // check file open error
        printf("Error opening file for reading.\n");
        return;
    }

    // Read integers until EOF (end of file)
    printf("Numbers read from 'numbers.txt':\n");
    while (fscanf(fptr, "%d", &n) == 1) { // fscanf returns count of matched items
        printf("%d ", n);
    }

    fclose(fptr);
    printf("\n");
}

// Main function to test Task 0.6
int main() {
    task06_file_io();
    return 0;
}

