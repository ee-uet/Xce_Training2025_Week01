#include <stdint.h>

volatile uint32_t dividend = 123456789;
volatile uint32_t divisor = 12345;
volatile uint32_t quotient = 0;
volatile uint32_t remainder = 0;

void non_restoring_div32(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    uint32_t q = 0;
    int32_t r = 0;
    for (int i = 31; i >= 0; i--) {
        r = (r << 1) | ((dividend >> i) & 1);
        if (r >= 0) {
            r -= divisor;
            q = (q << 1) | 1;
        } else {
            r += divisor;
            q = (q << 1) | 0;
        }
    }
    if (r < 0) r += divisor;
    *quotient = q;
    *remainder = r;
}

int main() {
    non_restoring_div32(dividend, divisor, &quotient, &remainder);
    while(1);   // hang
}

