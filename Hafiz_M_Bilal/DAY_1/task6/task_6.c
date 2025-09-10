#include <stdio.h>

// ======================= Task 0.6 =======================
void task06_file_io() {
    // TODO: Write 5 integers to a file, then read them back

    
    // Step 1: Take 5 integers from the user
    int nums[5];
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &nums[i]);
    }

    FILE *fp;

    // Step 2: Open file for writing ("w" mode)
    fp = fopen("number.txt","w");

    // Always check if file opened successfully
    if(fp == NULL){
        printf("Error opening file for writing!\n");
        return;
    }

    // Step 3: Write integers to file
    for (int i = 0; i < 5; i++) {
        fprintf(fp,"%d\n",nums[i]);
    }
    // Close the file after writing
    fclose(fp);

    printf("Numbers written to numbers.txt\n");

    // Step 4: Reset array to zero before reading back
    for (int i = 0; i < 5; i++) {
        nums[i] = 0;
    }

    printf("Numbers read from file:\n");

    // Step 5: Open file for reading ("r" mode)

    fp = fopen("number.txt","r");
    // Step 6: Read integers from file
    for (int i = 0; i < 5; i++) {
        fscanf(fp,"%d", &nums[i]);
        printf("%d ", nums[i]);
    }
    // Close file after reading
    fclose(fp);
    printf("\n");
}

// ======================= Main =======================
int main() {

    task06_file_io();
   
    return 0;
}