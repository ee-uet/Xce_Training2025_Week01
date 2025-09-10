.global _start
 
.section .text
 
_start:
    li x1,43    # dividend
    li x2,0       # quotient
    li x3,0       # remainder
    li x4,4       # divisor
    li x5,32     # size 

loop:
     slli x3,x3,1       #shift remainder
     srl  x6,x1,x5      # to get the bits from msb side
     andi x6,x6,1       #extract the bit of dividend
     or   x3,x3,x6      # or it with the shifter remainder

     bgez x3,sub_divisor   # if remainder >= 0
     add x3,x3,x4          # if remainder < 0, add divisor
     j set_quotient

sub_divisor:
     sub x3,x3,x4          # remainder >= 0, subtract divisor

set_quotient:
     bgez x3,quotient_bit_set #if new calculated remainder >0 set q=1
     li x8,0
     sll x8,x8,x5            #to find which bit of q we are going to set
     or x2,x2,x8
     j loop_continue

quotient_bit_set:
     li x8,1
     sll x8,x8,x5
     or x2,x2,x8

loop_continue:
     addi x5,x5,-1
     bge x5,zero,loop

# Final remainder adjustment if negative
bltz x3, add_divisor_final
j done

add_divisor_final:
add x3,x3,x4

done:
    li x6,1
    la x7,tohost
    sd x6,0(x7)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
