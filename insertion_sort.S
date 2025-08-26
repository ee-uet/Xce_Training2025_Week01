    .data
array:  .word 7, 3, 5, 2, 9, 1   # unsorted array
n:      .word 6                  # number of elements

    .text
    .globl _start

_start:
    # Load array base
    la   s0, array          # s0 = base address of array
    la   t0, n
    lw   s1, 0(t0)          # s1 = n

    # Outer loop index i = 1
    addi s2, x0, 1

outer_loop:
    bge  s2, s1, done       # if i >= n → done

    # key = array[i]
    slli t1, s2, 2          # offset = i*4
    add  t2, s0, t1
    lw   t3, 0(t2)          # t3 = key

    # j = i - 1
    addi s3, s2, -1

inner_loop:
    blt  s3, x0, insert     # if j < 0 → insert key

    # if array[j] <= key → insert
    slli t4, s3, 2
    add  t5, s0, t4
    lw   t6, 0(t5)          # t6 = array[j]
    ble  t6, t3, insert

    # shift array[j] → array[j+1]
    sw   t6, 4(t5)

    # j--
    addi s3, s3, -1
    j    inner_loop

insert:
    # array[j+1] = key
    addi s3, s3, 1
    slli t4, s3, 2
    add  t5, s0, t4
    sw   t3, 0(t5)

    # i++
    addi s2, s2, 1
    j    outer_loop

done:
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