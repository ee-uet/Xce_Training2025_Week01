    .globl _start      
    .section .text     


_start:
    li a0, -5
    li a1, 10
    j abs_diff

abs_diff:
    sub a2, a0, a1
    blt a2, x0, pos

    mv a0,a2
    j done

pos:
    sub a0, x0, a0

#Code to exit for Spike
done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
