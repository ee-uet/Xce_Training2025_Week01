#include <stdio.h>

// ======================= Task 0.5 =======================
void task05_second_largest() {
    // TODO: Find the second largest element in an array
    int p[10] = {7,8,5,9,15,2,3,4,10,11};

    // Assume first element is the largest
    int large = p[0]; 

    // Variable to store second largest
    int second = 0;
    int length = 10;

    // Traverse array to find largest and second largest
    for(int i = 0;i < length;i++){
        
        if(large < p[i]){
            // If new larger element found, update both largest and second
            second = large;
            large = p[i];
        }
        else if (p[i] > second && p[i] != large) {
             // If element is smaller than largest but bigger than second
            second = p[i];
        }        
    }
    printf("Second largest number is: %d\n",second);
}

// ======================= Main =======================
int main() {

    task05_second_largest();
    
    return 0;
}