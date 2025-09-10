.section .text
.globl _start
_start:

    li t0, 0b10101010        # t0 = initial 8-bit pattern (0xAA)

    # Set bit 3 
    li t1, 1                 # t1 = 1
    slli t1, t1, 3           # t1 <<= 3 -  mask for bit 3 (0x08)
    or t0, t0, t1            # t0 |= mask - set bit 3

    # Clear bit 5 
    li t2, 1                 # t2 = 1
    slli t2, t2, 5           # t2 <<= 5  mask for bit 5 (0x20)
    not t2, t2               # t2 = ~mask (pseudoinstruction xori t2, t2, -1)
    and t0, t0, t2           # t0 &= ~mask -> clear bit 5

    
    li t3, 1
    la t4, tohost
    sd t3, 0(t4)

1:  j 1b  

.section .tohost
.align 3
.globl tohost
.globl fromhost
tohost:   .dword 0
fromhost: .dword 0

