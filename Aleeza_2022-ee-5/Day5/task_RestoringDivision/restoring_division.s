.global _start
.section .text

_start:
    li t0, 13       # dividend
    li t1, 3        # divisor
    li t2, 0        # quotient
    li t3, 0        # remainder
    li t4, 4        # bit count

loop_bits:
    slli t3, t3, 1          # shift remainder
    srl t5, t0, t4
    andi t5, t5, 1
    or t3, t3, t5           # bring next bit

    sub t6, t3, t1          #  subtracting divisor
    blt t6, zero, skip       # if negative, skip subtraction

    mv t3, t6               # update remainder
    slli t2, t2, 1
    ori t2, t2, 1           # set quotient bit
    j next

skip:
    slli t2, t2, 1          # shift quotient, bit = 0

next:
    addi t4, t4, -1
    bge t4, zero, loop_bits

done:
    # quotient = t2, remainder = t3

    li t5, 1
    la t6, tohost
    sw t5, 0(t6)            # store as word

hang:
    j hang

.section .tohost
.align 2                   # word alignment (4 bytes)
tohost:   .word 0
fromhost: .word 0

