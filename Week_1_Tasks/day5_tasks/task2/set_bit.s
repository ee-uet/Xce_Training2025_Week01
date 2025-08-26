.section .text
.globl _start
_start:

    li t0, 0b10101010

    # Set bit 3
    li t1, 1
    slli t1, t1, 3
    or t0, t0, t1

    # Clear bit 5 
    li t2, 1
    slli t2, t2, 5
    not t2, t2
    and t0, t0, t2

    
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

