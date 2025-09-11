.global _start
.section .text

# Program: Count the number of 1's using Kernighan's Algorithm

_start:
    li t2, 7         # Load the 32-bit word (7 = 0b000...0111)
    li t5, 0         # t5 = count = 0

loop:
    beqz t2, exit    # If t2 == 0, we're done

    addi t5, t5, 1   # count++

    addi t3, t2, -1  # t3 = t2 - 1
    and t2, t2, t3   # t2 = t2 & (t2 - 1) → clears the lowest set bit

    j loop           # Repeat

exit:
    # Exit code for Spike simulator (DO NOT REMOVE)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Infinite loop in case simulator fails to exit
1:  j 1b

.section .tohost
.align 3
tohost:     .dword 0
fromhost:   .dword 0
