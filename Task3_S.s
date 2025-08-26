    .section .data
dividend:   .word 123456789
divisor:    .word 12345
quotient:   .word 0
remainder:  .word 0

    .section .text
    .globl _start
_start:
    lw t0, dividend
    lw t1, divisor
    li t2, 0          # quotient
    li t3, 0          # remainder
    li t4, 31         # loop counter i

loop:
    slli t3, t3, 1
    srli t5, t0, t4
    andi t5, t5, 1
    or t3, t3, t5

    bgez t3, ge_branch
    add t3, t3, t1
    slli t2, t2, 1
    j end_loop

ge_branch:
    sub t3, t3, t1
    slli t2, t2, 1
    ori t2, t2, 1

end_loop:
    addi t4, t4, -1
    bgez t4, loop

    bltz t3, fix_remainder
    j done

fix_remainder:
    add t3, t3, t1

done:
    sw t2, quotient
    sw t3, remainder

hang: j hang

