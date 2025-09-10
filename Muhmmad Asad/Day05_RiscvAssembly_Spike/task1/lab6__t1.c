
volatile int tohost;

void _start() {
    int dividend = 13;
    int divisor = 3;
    int Q = 0;
    int R = 0;
    int n = 4;
    int msb;
    int s_0;
    while( n > 0){
        s_0 = 1<<(n-1);
        msb = dividend & s_0;
        msb = msb >> (n-1);
        R = R | msb;
        R = R - divisor;
        if(R < 0){
            R = R + divisor;
        }
        else{
            Q = Q | (1<<(n-1));
        }
        n = n-1;
    }

    
    tohost = 1;  
    while (1); 
}