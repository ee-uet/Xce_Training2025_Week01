.section .text
.global _start
_start:
    li x1, 32 #number
    li x2, 5 #location
    li x3, 0#setbit

    li x4, 1
    sll x4, x4, x2

    beq x3, x0, clear_bit
set_bit:
    or x1, x1, x4
    j done

clear_bit:
    xori x4, x4, -1
    and x1, x1, x4

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
1:  j 1b


.section .data
n: .word 7
my_array: .word 1,2,3,4,5,6,7

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
