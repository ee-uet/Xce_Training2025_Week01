.global _start

.section .text

_start:
    li x1, 43      # dividend
    li x2, 0       # quotient
    li x3, 0       # remainder
    li x4, 4       # divisor
    li x5, 31      # bit index

loop:
    slli x3, x3, 1         # shift remainder left by 1
    srl  x6, x1, x5        # get current dividend bit
    andi x6, x6, 1
    or   x3, x3, x6        # add bit to remainder

    blt  x3, x4, set0      # if remainder < divisor, quotient bit = 0
    sub  x3, x3, x4        # remainder -= divisor
    li   x6, 1
    sll  x6, x6, x5
    or   x2, x2, x6        # set quotient bit = 1
    j    next_bit

set0:
    li   x6, 0
    sll  x6, x6, x5
    or   x2, x2, x6        # quotient bit = 0

next_bit:
    addi x5, x5, -1
    bge  x5, zero, loop

done:
    # store quotient & remainder to memory
    la x7, quotient
    sw x2, 0(x7)
    la x7, remainder
    sw x3, 0(x7)

    # signal completion to Spike via HTIF
    li x6, 1
    la x7, tohost
    sd x6, 0(x7)

1:  j 1b

.section .data
    .global quotient
    .global remainder
quotient:   .word 0
remainder:  .word 0

.section .tohost,"aw",@progbits
    .align 3
tohost:   .dword 0
fromhost: .dword 0
