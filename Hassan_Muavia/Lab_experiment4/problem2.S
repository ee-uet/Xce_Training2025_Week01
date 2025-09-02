.global _start
 
.section .text
_start:
    # Any code here
    # int count_bits(int x)
    # Argument: a0 = x
    # Return:   a0 = number of set bits

count_bits:
    addi sp, sp, -16       # allocate stack frame
    sw ra, 12(sp)          # save return address
    li t0, 0               # counter = 0
    li t1, 32              # loop counter = 32

loop:
    andi t2, a0, 1         # t2 = x & 1
    add  t0, t0, t2        # if LSB=1, increment count
    srli a0, a0, 1         # shift right logical (x >>= 1)
    addi t1, t1, -1        # decrement loop counter
    bnez t1, loop          # repeat until t1 == 0

    mv a0, t0              # move count into return register
    lw ra, 12(sp)          # restore return address
    addi sp, sp, 16        # deallocate stack
    ret


    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
