.global _start

.section .data
array: .word 3,7,2,9,1,5
size: .word 6

.section .text

_start:
    la t2,array
    lw t3,0(t2)
    addi t4,zero,4
    slli t4,t4,2
    add t4,t4,t2
    lw t5,0(t4)
    
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

