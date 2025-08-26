.section .data
num1:   .word 25
num2:   .word 40
result: .word 0

.section .text
.globl _start
_start:
    lw a0, num1
    lw a1, num2

    sub a2, a0, a1
    bltz a2, neg

    la t0, result
    sw a2, 0(t0)
    j done

neg:
    sub a2, a1, a0
    la t0, result
    sw a2, 0(t0)

done:
    li a7, 93
    li a0, 0
    ecall

