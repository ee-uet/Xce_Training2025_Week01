.global _start
.section .text

_start:

    li t2,1     #num1
    li t3,2     #num2

    sub t4,t2,t3    #num1-num1
    blt t4,zero,abs
    j exit

abs:
    sub t4,zero,t4

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
