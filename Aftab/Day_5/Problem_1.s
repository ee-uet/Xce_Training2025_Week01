.global _start
.section .text

# Program: Compute absolute difference using bge

_start:
    li t2, 1         # Load num1 into t2
    li t3, 2         # Load num2 into t3

    bge t2, t3, sub1     # if num1 >= num2, go to sub1
    sub t4, t3, t2       # t4 = num2 - num1
    j exit

sub1:
    sub t4, t2, t3       # t4 = num1 - num2

exit:
    # Exit code for Spike simulator (DO NOT REMOVE)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Infinite loop in case simulator does not exit
1:  j 1b

.section .tohost
.align 3
tohost:     .dword 0
fromhost:   .dword 0
