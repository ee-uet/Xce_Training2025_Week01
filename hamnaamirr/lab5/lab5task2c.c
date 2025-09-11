

int main() {
    int number = 32;
    int location = 5;
    int setbit = 0;   
    int bit = 1 << location;
    if (setbit == 0) {
        bit = ~bit;
        number = number & bit;
    } else {
        number = number | bit;
    }

    printf("Result = %d\n", number);  // print result
    return 0;
}
