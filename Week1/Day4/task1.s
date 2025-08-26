    .global _start

    .section .text
_start:
    li x1,43          # dividend
    li x2,0           # quotient
    li x3,0           # remainder
    li x4,4           # divisor
    li x5,31          # loop counter (32 bits)

loop:
    slli x3,x3,1
    srl  x6,x1,x5
    andi x6,x6,1
    or   x3,x3,x6

    slli x2,x2,1
    sub  x7,x3,x4
    mv   x3,x7
    blt  x7,zero,restore

    ori  x2,x2,1
    j cont

restore:
    add  x3,x3,x4

cont:
    addi x5,x5,-1
    bge  x5,zero,loop

done:
    # send quotient to host
    la   x7,tohost
    sw   x2,0(x7)

    # send remainder to host
    sw   x3,0(x7)
    
1:  j 1b

    .section .tohost,"aw",@progbits
    .align 3
tohost:   .dword 0
fromhost: .dword 0
