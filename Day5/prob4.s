    .section .text
    .globl _start
_start:
    # Array setup
    la t0, array         # t0 = address of array
    li t1, 5             # t1 = length of array

    # Pointers: start = t0, end = t2
    add t2, t0, t1       # t2 points just past last element
    addi t2, t2, -1      # t2 points to last element

reverse_loop:
    blt t2, t0, done     # if end < start, done

    # Swap *start and *end
    lb t3, 0(t0)         # t3 = *start
    lb t4, 0(t2)         # t4 = *end
    sb t4, 0(t0)         # *start = t4
    sb t3, 0(t2)         # *end = t3

    addi t0, t0, 1       # start++
    addi t2, t2, -1      # end--
    j reverse_loop

done:
    # Result: array reversed in-place
    la a0, array          # return pointer to array (optional)

    # Signal Spike to exit
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b                  # loop forever (safety)

    .section .data
array:
    .byte 1, 2, 3, 4, 5   # Example array

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0

