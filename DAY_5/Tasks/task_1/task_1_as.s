.globl _start

.section .text
_start:

#--------------######################---------------------
#--------------------This is code region------------------
    # Assume: dividend = 25, divisor = 3
    li t0, 25         # Dividend
    li t1, 3          # Divisor
    li t2, 0          # Quotient
    li t3, 0          # Remainder

    li t4, 32         # Bit count for 32-bit division

loop:
    sll t3, t3, 1         # Shift remainder left by 1
    srl t5, t0, 31        # Extract MSB of dividend
    or t3, t3, t5         # Append MSB to remainder

    sll t0, t0, 1         # Shift dividend left
    sub t6, t3, t1        # t6 = remainder - divisor

    blt t6, zero, skip    # If negative, don't set bit
    li t5, 1
    or t2, t2, t5         # Set LSB of quotient
    mv t3, t6             # Update remainder

skip:
    sll t2, t2, 1         # Shift quotient left

    addi t4, t4, -1
    bnez t4, loop

    srl t2, t2, 1         # Final quotient adjustment
#-------------#######################----------------------

    # Done, exit via tohost
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)


1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

