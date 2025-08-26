.globl _start

.section .text
_start:
    
    li t0, 13         # Dividend
    li t1, 3          # Divisor
    li t2, 0          # Quotient
    li t3, 0          # Remainder

    li t4, 32         

loop:
    sll t3, t3, 1         
    srl t5, t0, 31        
    or t3, t3, t5         

    sll t0, t0, 1         
    sub t6, t3, t1        

    blt t6, zero, skip    
    li t5, 1
    or t2, t2, t5         
    mv t3, t6             

skip:
    sll t2, t2, 1         

    addi t4, t4, -1
    bnez t4, loop

    srli t2, t2, 1        

    
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
