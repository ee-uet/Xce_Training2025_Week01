volatile int tohost;

void bit_manipulation(int number, int bit_pos, int one){
    if(one){
        one = one << bit_pos;
        number = number | one;
    }
    else{
        one = one + 1;
        one = one << bit_pos;
        one = ~one;
        number = number & one;
    }

}

void _start() {
    int number = 3;
    int bit_pos = 4;
    int one = 1;
    bit_manipulation(number, bit_pos, one);


    
    tohost = 1;  
    while (1); 
}