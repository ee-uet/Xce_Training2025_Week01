# src/reverse_array.S
    .data
array:  .word 1, 2, 3, 4, 5
len:    .word 5

    .text
    .globl _start
_start:
    la t0, array       # start address
    lw t1, len         # length
    add t1, t1, x0     # t1 = len
    addi t2, x0, -1    # t2 = end index (will adjust)

    add t3, t0, t1     # pointer to end element (not exact yet)
    slli t1, t1, 2     # multiply length by 4 (word size)
    add t3, t0, t1     # t3 = address of end element + 4
    addi t3, t3, -4    # t3 = address of last element

rev_loop:
    bge t0, t3, done_rev
    lw t4, 0(t0)
    lw t5, 0(t3)
    sw t5, 0(t0)
    sw t4, 0(t3)
    addi t0, t0, 4
    addi t3, t3, -4
    j rev_loop

done_rev:
    li a7, 93
    li a0, 0
    ecall

