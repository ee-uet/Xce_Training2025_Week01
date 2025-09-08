# file: t1.s
.globl _start

.section .text
_start:
    li t0, 13         # Dividend (Q)
    li t1, 3          # Divisor (M)
    li t2, 0          # Quotient (Q_out) -
    li t3, 0          # A (remainder/accumulator)

    li t4, 32         # loop counter n = 32

loop:
    sll t3, t3, 1         # A = A << 1
    srl t5, t0, 31        # extract MSB of Q (dividend)
    or t3, t3, t5         # A = (A << 1) | (Q >> 31)

    sll t0, t0, 1         # Q = Q << 1

    sub t6, t3, t1        # t6 = A - M (trial subtract)

    blt t6, zero, skip    # if (A - M) < 0 -> skip setting bit and restoring
    li t5, 1
    or t2, t2, t5         # set LSB of quotient (temporarily)
    mv t3, t6             # A = A - M  (keep subtraction result)

skip:
    sll t2, t2, 1         # shift quotient left to make room for next bit

    addi t4, t4, -1
    bnez t4, loop         # repeat until counter == 0

    srli t2, t2, 1        # correct extra left shift (final quotient)

   
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

