// Unsigned restoring division: returns quotient, writes remainder via *rem_out

unsigned divu_restoring(unsigned n, unsigned d, unsigned *rem_out) {
    unsigned q = 0, r = 0;
    for (int i = 0; i < 32; ++i) {
        unsigned msb = (n >> 31) & 1;
        r = (r << 1) | msb;
        n <<= 1;
        if (r >= d) {
            r -= d;
            q = (q << 1) | 1u;
        } else {
            q <<= 1;
        }
    }
    *rem_out = r;
    return q;
}
int main(){
    unsigned n = 50;    // dividend
    unsigned d = 7;     // divisor
    unsigned remainder; // will hold remainder

    unsigned quotient = divu_restoring(n, d, &remainder);

    

    return 0;

}