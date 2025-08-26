.data
    .align 2
    my_array_sort: .word 5, 2, 8, 1, 9
    arr_size_sort: .word 5
.text
.global main
main:
    la a0, my_array_sort
    lw a1, arr_size_sort
    addi t0, x0, 1
outer_loop:
    bge t0, a1, end_sort_outer
    slli t1, t0, 2
    add t1, a0, t1
    lw t2, 0(t1)
    addi t3, t0, -1
inner_loop:
    blt t3, x0, end_inner_loop
    slli t4, t3, 2
    add t4, a0, t4
    lw t5, 0(t4)
    bge t5, t2, shift_right
    j end_inner_loop
shift_right:
    addi t6, t4, 4
    sw t5, 0(t6)
    addi t3, t3, -1
    j inner_loop
end_inner_loop:
    addi t1, t3, 1
    slli t1, t1, 2
    add t1, a0, t1
    sw t2, 0(t1)
    addi t0, t0, 1
    j outer_loop
end_sort_outer:
    li a7, 93
    ecall
