.global _start
 
.section .text
_start:
    li t0, 0 # R=0
    li t1, 13 # dividend=13
    li t2, 3 #  divisor=3
    li t3, 0 # Q
    li t4, 4 # number of bits
    jal ra, restoring_division

    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    
1:  j 1b

restoring_division:
    li t5, 0; # counter
    li s1, 1;
while:
    ble t4, zero, return
    addi t6, t4, -1
    sll s0, s1, t6 # shift s1=1 by n-1 times
    and s2, t1, s0 # dividend & 1000, s2 = msb
    srl s2, s2, t6
    slli t0, t0, 1 # R = R << 1
    or t0, t0, s2 # R = R | msb = s2
    sub t0, t0, t2 # R = R - divisor
    blt t0, zero, restore
    or t3, t3, s0
    addi t4, t4, -1
    j while

restore:
    add t0, t0, t2
    addi t4, t4, -1
    j while


return:
    ret

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0