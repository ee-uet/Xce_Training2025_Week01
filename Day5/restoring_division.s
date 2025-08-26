.global _start
.section .text
_start:
    li x1,13     # dividend
    li x2,0       # quotient
    li x3,0       # remainder
    li x4,3       # divisor
    li x5,4      # size 
loop:
     slli x3,x3,1
     srl  x6,x1,x5
     andi x6,x6,1
     or   x3,x3,x6
     sub  x7,x3,x4      # temp = remainder - divisor
     blt  x7,zero,restore
     mv   x3,x7         # remainder = temp
     li   x8,1
     sll  x8,x8,x5      # shift for quotient
     or x2,x2,x8        # set quotient bit = 1
restore:
     add x3,x3,x4       # restore remainder if negative
     li x8,0
     sll x8,x8,x5
     or x2,x2,x8        # quotient bit = 0
     addi x5,x5,-1
     bge x5,zero,loop  # loop until x5 < 0
done:
    # Signal test pass to Spike
    li x6, 1
    la x7, tohost
    sd x6, 0(x7)
1: j 1b
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
