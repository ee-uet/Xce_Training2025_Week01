.text
.global main
main:
    li a0, 5
    li a1, 1
    li t0, 1
factorial_loop:
    beq a0, x0, end_factorial_loop
    mul a1, a1, a0
    addi a0, a0, -1
    j factorial_loop
end_factorial_loop:
    mv a0, a1
    li a7, 93
    ecall
