.text
.global main
main:
    li a0, 29
    li a1, 0
count_loop:
    beq a0, x0, end_count_loop
    andi t0, a0, 1
    add a1, a1, t0
    srli a0, a0, 1
    j count_loop
end_count_loop:
    mv a0, a1
    li a7, 93
    ecall
