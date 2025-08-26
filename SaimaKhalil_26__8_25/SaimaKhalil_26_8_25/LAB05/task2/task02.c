#include <stdio.h>

int main() {
    unsigned int num;
    int pos, choice;

    printf("Enter a 32-bit number: ");
    scanf("%u", &num);

    printf("Enter bit position to modify (0-31): ");
    scanf("%d", &pos);

    if(pos < 0 || pos > 31) {
        printf("Invalid position!\n");
        return 1;
    }

    printf("Choose operation: 1 = Set, 2 = Clear: ");
    scanf("%d", &choice);

    if(choice == 1) {
        num = num | (1 << pos);  // set bit
        printf("After setting bit %d: %u\n", pos, num);
    } 
    else if(choice == 2) {
        num = num & ~(1 << pos); // clear bit
        printf("After clearing bit %d: %u\n", pos, num);
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
