.data
    .align 2
    my_array: .word 5, 2, 8, 1, 9
    arr_size: .word 5
.text
.global main
main:
    la a0, my_array
    lw a1, arr_size
    addi t0, x0, 0
    addi t1, a1, -1
reverse_loop:
    bge t0, t1, end_reverse
    slli t2, t0, 2
    slli t3, t1, 2
    add t2, a0, t2
    add t3, a0, t3
    lw t4, 0(t2)
    lw t5, 0(t3)
    sw t5, 0(t2)
    sw t4, 0(t3)
    addi t0, t0, 1
    addi t1, t1, -1
    j reverse_loop
end_reverse:
    li a7, 93
    ecall
