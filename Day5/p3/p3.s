    .globl _start
    .section .text

_start:

    li t0, 5
    li t1, 1
    jal ra, factorial

factorial:
    beqz t0, done
    mul t1, t1, t0
    addi t0, t0, -1

done:

#Code to exit for Spike    
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

