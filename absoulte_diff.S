.data
num1:   .word 25
num2:   .word 40
result: .word 0

.global _start

 
.section .text
_start:
    
    la t0, num1
    lw t1, 0(t0)
    la t0, num2
    lw t2, 0(t0)

    sub t3, t1, t2
    blt t3, x0, neg
    j done

neg:
    
    sub t3, x0, t3

done:

    la t0, result
    sw t3, result

    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
