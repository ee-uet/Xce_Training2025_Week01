volatile int tohost;



void _start() {
    int R = 0;
    int dividend = 13;
    int divisor = 3;
    int Q = dividend;
    int n = 32;
    int msb;
    while(n > 0){
        msb = (1<<(n-1));
        msb = Q & msb;
        msb = (msb >> (n-1));
        R = R & (~(1<<(n-1)));
        R = R << 1;
        R = R | msb;
        Q = Q & (~(1<<(n-1)));
        Q = Q << 1;
        if(R < 0){
            R = R + divisor;
            if(R >= 0){
                Q = Q | 1;
        }
        else{
            R = R - divisor;
            if(R >= 0){
                Q = Q | 1;
            }
        }
        }
        n = n-1;
    }
    
    tohost = 1;  
    while (1); 
    
}