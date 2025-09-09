#include <stdio.h>

// Function declaration
int add(int a, int b);

int main(void) {
	int a = 1;
	int b = 1;
	
	// Call add function and store result
	int x = add(a, b);
	printf("%d\n", x);
	return 0;
}
