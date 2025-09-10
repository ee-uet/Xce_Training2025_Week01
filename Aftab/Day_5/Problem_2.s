.global _start
.section .text

_start:

    li t2,7     #32-bit word
    li t3,31
    li t4,1     #for loop counter
    li t5,0     #count
    li t6,1     #temp for shift
    li a0,0     #temp

    and a0,t6,t2
    bnez a0,t
    j loop
t:
    addi t5,t5,1

loop:
    slli t6,t6,1
    and a0,t6,t2
    bnez a0,countplus1
    j label
countplus1:    
    addi t5,t5,1
label:    
    addi t4,t4,1
    blt t4,t3,loop


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