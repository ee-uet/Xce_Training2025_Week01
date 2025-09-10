.global _start
 
.section .text
_start:
    li t0, 0x10000000
    li t1, 5
    li t2, 7
    sub t3, t1, t2
    blt t3, zero, negate
    j here
negate:
    neg t3, t3
here:
    li t1, 0
    li t2, 4
print:
    beq t1, t2, done
    sb t3, 0(t0)
    addi t0, t0, 1
    addi t1, t1, 1
    j print
done:
    li t1, 1
    la t2, tohost
    sd t1, 0(t2)

    
1:  j 1b
 

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0