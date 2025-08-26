.global _start

.section .data
array: .word 3,7,2,9,1,5
size: .word 6

.section .text

_start:
    la t2,array     #array staring address
    la t3,size
    lw t4,0(t3)
    addi t4,t4,-1   # size-1
    li t5,0     # counter loop1

loop1:
    bge t5,t4,exit
    #code here
    li t6,0     # counter loop2
    addi a0,t5,-1 

    
    slli s0,t5,2
    add a1,t2,s0
    lw a2,0(a1)

loop2:
    bge t6,a0,loop2_exit
    #code here
    slli s1,t6,2
    add a3,t2,s1
    lw a4,0(a3)
    bgt a2,a4,label
    add a5,a4,zero
    sw a2,0(a3)

label:
    addi t6,t6,1
    j loop2

loop2_exit:
    addi t5,t5,1
    j loop1
    
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

