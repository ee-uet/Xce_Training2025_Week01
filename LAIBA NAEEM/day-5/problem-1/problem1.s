.section .text
.globl _start

_start:
    # Load numbers
    li x3, 30          # first number
    li x1, 40          # second number

    # Compute absolute difference
    sub x2, x3, x1
    bltz x2, negate


negate:
    neg x2, x2

exit:

    la x8, a
    sb x2,0(x8)

    # Exit program
    li t0, 1
    la t1, tohost
    sd t0, (t1)
1: j 1b

.section .data
a: .byte 0

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

