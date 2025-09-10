.global _start
 
.section .text
 
_start:
    li x1,43  # dividend
    li x2,0       # quotient
    li x3,0       # remainder
    li x4,4       # divisor
    li x5,32    # size 

loop:
     slli x3,x3,1       
     srl  x6,x1,x5     
     andi x6,x6,1       
     or   x3,x3,x6      # bring down next bit
     
     sub  x7,x3,x4      # temp = remainder - divisor
     blt  x7,zero,do_restore  # only restore if subtraction negative

     # subtraction was successful

     mv   x3,x7          # remainder = temp
     li   x8,1
     sll  x8,x8,x5       # shift for quotient
     or x2,x2,x8         # set quotient bit = 1
     j continue_loop     # skip restore

do_restore:
     # restore remainder (keep it as it was after shifting in bit)
     # do NOT add x4 again
     li   x8,0
     sll  x8,x8,x5
     or x2,x2,x8         # set quotient bit = 0

continue_loop:
     addi x5,x5,-1
     bge x5,zero,loop

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
 