    .section .text
    .globl _start

_start:

    # Setup array pointers
    la t0, array         # t0 = address of first element (start pointer)
    li t1, 5             # t1 = length of array (number of elements)

    # Pointers: start = t0, end = t2
    slli t3, t1, 2       # t3 = t1 * 4 bytes (size of int)
    add t2, t0, t3       # t2 points just past last element
    addi t2, t2, -4      # t2 points to last element

reverse_loop:
    # Check if start pointer has passed end pointer
    blt t2, t0, done     # if end < start, we are done

    # Swap *start and *end 
    lw t3, 0(t0)         # load integer at start pointer
    lw t4, 0(t2)         # load integer at end pointer
    sw t4, 0(t0)         # store end value at start
    sw t3, 0(t2)         # store start value at end

    # Move pointers towards center
    addi t0, t0, 4       # start pointer += 4 bytes (next int)
    addi t2, t2, -4      # end pointer -= 4 bytes (previous int)
    j reverse_loop       # repeat loop

done:
    # Optional: return pointer to array in a0
    la a0, array

    # Signal Spike simulator that program finished
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b                  # infinite loop (safety)

    .section .data
array:
    .word 1, 2, 3, 4, 5   # 32-bit integer array

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0

