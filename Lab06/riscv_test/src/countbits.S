# src/countbits.S
    .data
count:  .word 0        # store number of set bits
num:    .word 0xF1     # example number

    .text
    .globl _start
_start:
    la t0, num
    lw t1, 0(t0)       # load number into t1
    li t2, 0           # t2 = counter

loop:
    beq t1, x0, done_count
    andi t3, t1, 1
    add t2, t2, t3
    srli t1, t1, 1
    j loop

done_count:
    la t0, count
    sw t2, 0(t0)

    li a7, 93
    li a0, 0
    ecall

