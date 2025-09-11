.global _start
.section .text

# Program: Factorial using C-style while loop (n > 1)

_start:
    li t2, 4         # t2 = n = 4
    li t5, 1         # t5 = result = 1
    li t6, 2         # t6 = constant 2 (for comparison)

fact_loop:
    blt t2, t6, exit # if t2 < 2, exit loop (i.e., n <= 1)
    mul t5, t5, t2   # result *= n
    addi t2, t2, -1  # n--
    j fact_loop      # repeat

exit:
    # Code to exit for Spike (DO NOT REMOVE)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Loop forever if Spike doesn't exit
1:  j 1b

.section .tohost
.align 3
tohost:     .dword 0
fromhost:   .dword 0
