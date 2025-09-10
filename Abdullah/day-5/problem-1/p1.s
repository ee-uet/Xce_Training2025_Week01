.globl _start      
    .section .text     

_start:
    # Load immediate value -5 into register a0 (first number)
    li a0, -5
    # Load immediate value 10 into register a1 (second number)
    li a1, 10
    # Jump to the abs_diff label to compute |a0 - a1|
    j abs_diff

# Function to compute the absolute difference between a0 and a1
abs_diff:
    # Subtract a1 from a0, store result in a2 (a2 = a0 - a1)
    sub a2, a0, a1
    # Branch to pos if a2 < 0 (x0 is zero register), i.e., if result is negative
    blt a2, x0, pos

    # If a2 >= 0, move a2 to a0 (a0 = a2, the absolute difference)
    mv a0, a2
    # Jump to done to exit
    j done

# Handle negative result case
pos:
    # Negate a2 by subtracting it from x0 (zero), store in a0 (a0 = -a2)
    sub a0, x0, a2

#Code to exit for Spike
done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
