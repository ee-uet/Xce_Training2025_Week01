.globl _start

.section .text
_start:
    li t0, 5          
    li t1, 1          

factorial_loop:
    beq t0, zero, done    
    mul t1, t1, t0        
    addi t0, t0, -1     
    j factorial_loop

done:
    
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b   

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

