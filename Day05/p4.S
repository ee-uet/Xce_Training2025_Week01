.global _start

.section .data
array: .word 3,7,2,9,1,5,10
size: .word 7

.section .text

_start:
    la t2,array
    la t3,size
    lw t3,0(t3)
    addi a0,t3,-1   #size-1
    slli a0,a0,2
    add a1,t2,a0   # address of last element
    li t5,2
    div t3,t3,t5
    addi t3,t3,-1   # (size/2) - 1
    li t4,0      #counter   

loop:
    bgt t4,t3,exit
    
    #code here
    lw a2,0(t2)
    lw a3,0(a1)

    sw a3,0(t2)
    sw a2,0(a1)
        
    addi a1,a1,-4
    addi t2,t2,4

    addi t4,t4,1
    j loop
    
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

