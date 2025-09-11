    .section .text
    .globl _start
_start:
    li t0, 5          # number to calculate factorial
    li t1, 1          # result = 1

fact_loop:
    beqz t0, done     # if t0 == 0, stop
    mul t1, t1, t0    # result = resutl * t0
    addi t0, t0, -1   # t0--
    j fact_loop

done:
    mv a0, t1

    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

    .section .tohost
    .align 3
tohost: .dword 0
fromhost: .dword 0

