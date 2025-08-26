.globl _start

.section .text
_start:
    li t0, 0xAD230FC1
    li t1, 0              

count_loop:
    beq t0, zero, done    
    andi t2, t0, 1        
    add t1, t1, t2        
    srli t0, t0, 1        
    j count_loop

done:
    
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b  

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

