.global _start

.section .data
array: .word 4,6,3,7,1,5,9
size: .word 7
.section .text

_start:
    la   t2,array          # load array base
    la   t3,size           # load size address
    lw   t3,0(t3)          # load size value
    addi a0,t3,-1          # size - 1
    slli a0,a0,2           # multiply by 4
    add  a1,t2,a0          # last element addr
    li   t5,2              # load divisor 2
    div  t3,t3,t5          # size / 2
    li   t4,1              # init counter

loop:
    bgt  t4,t3,exit        # if counter > half exit

    lw   a2,0(t2)          # load start element
    lw   a3,0(a1)          # load end element

    sw   a3,0(t2)          # store end at start
    sw   a2,0(a1)          # store start at end

    addi a1,a1,-4          # move end backward (byte adressible)
    addi t2,t2,4           # move start forward (byte adressible)

    addi t4,t4,1           # increment counter
    j    loop              # jump back to loop

exit:
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1               
    la t1, tohost          
    sd t0, (t1)            

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
