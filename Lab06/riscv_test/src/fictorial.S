# src/factorial.S
    .data
n:       .word 5
result:  .word 1

    .text
    .globl _start
_start:
    la t0, n
    lw t0, 0(t0)       # t0 = n
    li t1, 1           # t1 = factorial accumulator

fact_loop:
    blez t0, done_fact
    mul t1, t1, t0
    addi t0, t0, -1
    j fact_loop

done_fact:
    la t2, result
    sw t1, 0(t2)

    li a7, 93
    li a0, 0
    ecall

