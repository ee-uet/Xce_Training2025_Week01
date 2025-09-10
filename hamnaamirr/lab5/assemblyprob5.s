.data
my_array: .byte 12, 11, 13, 5, 6
n:        .byte 5

.text
.globl _start
_start:
    la x5, my_array
    lb x6, n
    li x7, 1

loop1:
    bge x7, x6, done
    add x10, x5, x7
    lb x11, 0(x10)
    addi x12, x7, -1

loop2:
    blt x12, zero, insert
    add x13, x5, x12
    lb x14, 0(x13)
    sub x15, x14, x11
    ble x15, zero, insert
    sb x14, 1(x13)
    addi x12, x12, -1
    j loop2

insert:
    add x13, x5, x12
    sb x11, 1(x13)
    addi x7, x7, 1
    j loop1

done:
    li x6, 1
    la x7, tohost
    sd x6, 0(x7)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
