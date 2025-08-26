    .data
array:  .word 5,2,4,6,1,3
size:   .word 6

    .text
    .globl _start
_start:
    # Load size
    la t0, size
    lw t1, 0(t0)       # t1 = size
    li t2, 1           # i = 1

outer_loop:
    bge t2, t1, done_sort

    # key = array[i]
    la t3, array
    slli t4, t2, 2
    add t5, t3, t4
    lw t6, 0(t5)       # t6 = key

    # j = i - 1
    addi t7, t2, -1

inner_loop:
    blt t7, x0, insert_key

    # array[j]
    slli t8, t7, 2
    add t9, t3, t8
    lw t10, 0(t9)

    blt t10, t6, insert_key

    # array[j+1] = array[j]
    addi t11, t9, 4
    sw t10, 0(t11)

    addi t7, t7, -1
    j inner_loop

insert_key:
    # array[j+1] = key
    slli t8, t7, 2
    add t9, t3, t8
    addi t9, t9, 4
    sw t6, 0(t9)

    addi t2, t2, 1
    j outer_loop

done_sort:
    li a7, 93
    li a0, 0
    ecall

