.global _start
.section .text

_start:
        
    li t2,3     #num
    add t3,zero,t2
    li t4,1     #counter
    add t5,zero,t2

loop:
    addi t2,t2,-1
    mul t5,t5,t2

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

