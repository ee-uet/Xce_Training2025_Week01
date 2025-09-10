int main(){

    unsigned int num = 0x00000002;      // Input number: 2 (binary: ...00000010)
    int position = 5;                   // Bit position to manipulate (bit 5)
    unsigned int set, clear = 0;        // Variables to store results
    
    set = num | (1U << 5);              // Set bit 5: OR with mask 0x00000020
    
    clear = set & ~(1U << 5);           // Clear bit 5: AND with inverted mask
    
    return 0;                          
}
