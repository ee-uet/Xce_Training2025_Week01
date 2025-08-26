.text
.global main
main:
    li a0, 10
    li a1, 25
    sub a0, a0, a1
    bge x0, a0, end_abs
    sub a0, x0, a0
end_abs:
    li a7, 93
    ecall
