#include <stdio.h>
#include <stdlib.h>

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back
    // Get 5 integers from user input

    int arr[5];
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize file pointer
    FILE *file_ptr;
    
// ==========WRITING TO FILE==========
    // Open file "number.txt" in write mode
    file_ptr = fopen("number.txt","w");
    // Error handling
    if(file_ptr == NULL){
        printf("Error opening file for writing!\n");
        return;
    }
    // Write integers to file
    for (int i = 0; i < 5; i++) {
        fprintf(file_ptr,"%d\n",arr[i]);
    }
    // Close the file
    fclose(file_ptr);

    // Confirmation message
    printf("Numbers written to numbers.txt\n");

    // Reset array values to zero
    for (int i = 0; i < 5; i++) {
        arr[i] = 0;
    }
    // ==========READING FROM FILE==========
    printf("Numbers read from file:\n");
    // Open file "number.txt" in read mode
    file_ptr = fopen("number.txt","r");
    for (int i = 0; i < 5; i++) {
        fscanf(file_ptr,"%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    // Close the file
    fclose(file_ptr);
    printf("\n");
}

int main() {
    task06_file_io();
    return 0;
}