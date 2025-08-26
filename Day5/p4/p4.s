    .globl _start
    .section .data

array: .word 1,2,3,4,5
size:  .word 5

    .section .text
_start:
    la t0, array        # t0 = start pointer
    lw t2, size         # t2 = array size (n)

    la t1, array        # base again
    slli t3, t2, 2      # t3 = n*4 (bytes)
    add t1, t1, t3      # end pointer (one past last element)
    addi t1, t1, -4     # adjust to last element

loop:
    blt t1, t0, done    # stop when end < start

    lw t4, 0(t0)        # load from start
    lw t5, 0(t1)        # load from end
    sw t5, 0(t0)        # swap
    sw t4, 0(t1)

    addi t0, t0, 4      # move forward
    addi t1, t1, -4     # move backward
    j loop

done:
    # Code to exit for Spike    
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
