#include <stdio.h>

// ======================= Task 0.3 =======================
void task03_fibonacci() {
    // TODO: Print Fibonacci sequence up to n terms
    int n;

    printf("Enter number ");
	scanf("%d", &n);

    printf("The Fibonacci sequence up to %dth terms is:  ", n );

    int b = 0;
    int first = 0;
    int second = 0;

    for(int i = 0 ;i < n ; i++){
        
        if(i == 0){
            printf("%d ",i);
        }
        else if(i == 1){
            printf("%d ",i);
            second = i;
        }
        else{
            printf("%d ",first + second);
        }
        b = first;
        first = first + second;
        second = b;
    }
    printf("\n");
}



// ======================= Main =======================
int main() {
       
    task03_fibonacci();

    return 0;
}