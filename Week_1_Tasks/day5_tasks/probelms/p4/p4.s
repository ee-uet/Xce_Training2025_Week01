globl _start

.section .data
array: .word 1, 2, 3, 4, 5
arr_len: .word 5

.section .text

_start:
    la t0, array
    la t1, arr_len
    lw t2, 0(t1)
    li t3, 4
    mul t4, t2, t3
    addi t4, t4, -4

loop:
    lw t5, 0(t0)    
    lw t6, 0(t4)
    sw t6, 0(t0)
    sw t5, 0(t4)

    addi t0, t0, 4
    addi t4, t4, -4

    j loop

done:
   
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b 

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

