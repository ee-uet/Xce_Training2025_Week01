.globl _start
.section .text
_start:
    li a0, 10          # load first number into a0
    li a1, 20          # load second number into a1

    sub a2, a0, a1     # a2 = a0 - a1
    bgt a2, zero, done # if result > 0, skip negation
    neg a2, a2         # else, make it positive (absolute value)

done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)
1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

