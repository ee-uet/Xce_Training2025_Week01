#include <stdio.h>

// ======================= Task 0.1 =======================
void task01_datatypes() {
    // TODO: Declare int, float, double, char
    // Print their sizes and demonstrate type casting


	int i = 42;
	float f = 3.14;
	double d = 1.23456;
	char c = 'A';
	
	printf("Integer i = %d\n", i);
	printf("Float f = %f\n", f);
	printf("Double d = %f\n", d);
	printf("Char c = %c\n\n", c);
	
	printf("Size of Integer i = %zu bytes\n", sizeof(i));
	printf("Size of Float f = %zu bytes\n", sizeof(f));
	printf("Size of Double d = %zu bytes\n", sizeof(d));
	printf("Size of Char c = %zu bytes\n\n", sizeof(c));

	printf("i = %f\n", (float)i);
	printf("f = %d\n", (int)f);
    printf("d = %d\n", (int)d);
    printf("c = %d\n", (int)c);
}

// ======================= Main =======================
int main() {
    
    task01_datatypes();

    return 0;
}