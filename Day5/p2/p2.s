    .globl _start
    .section .text

_start:
    li a0, 0xA01B0C01
    jal ra, count
    
#Code to exit for Spike    
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1: j 1b

count:
    mv t0, a0
    li t1, 0

loop:
    beqz t0, done      # while t0 != 0
    andi t2, t0, 1           # extract LSB
    add  t1, t1, t2          # add to counter
    srli t0, t0, 1           # shift right
    j loop


done:
    mv a0, t1
    ret


.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
