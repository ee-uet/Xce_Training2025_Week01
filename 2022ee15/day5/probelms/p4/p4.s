.globl _start

.section .data
array: .word 1, 2, 3, 4, 5   # original array
arr_len: .word 5             # array length

.section .text
_start:
    la t0, array             # t0 → start of array
    la t1, arr_len           
    lw t2, 0(t1)             # load array length into t2
    li t3, 4                 # size of each element (4 bytes)
    mul t4, t2, t3           # total size in bytes
    addi t4, t4, -4          # offset to last element (end pointer)

loop:
    bge t0, t4, done         # if start pointer >= end pointer, stop
    lw t5, 0(t0)             # load element from start
    lw t6, 0(t4)             # load element from end
    sw t6, 0(t0)             # store end to start
    sw t5, 0(t4)             # store start to end

    addi t0, t0, 4           # move start pointer forward
    addi t4, t4, -4          # move end pointer backward

    j loop                  

done:
    # signal completion to Spike
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

