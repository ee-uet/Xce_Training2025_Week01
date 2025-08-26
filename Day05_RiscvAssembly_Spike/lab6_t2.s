.global _start
 
.section .text
_start:
    li a0, 3 #value 
    li a1, 4 # bit number to set/clear
    li a3, 1 # a3 = 1 (set), a3=2 (clear)
    jal ra, bit_manipulation

    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    
1:  j 1b

bit_manipulation:
    beq a3, zero, clear_op
    sll a3, a3, a1
    or a0, a0, a3
    ret

clear_op: 
    addi a3, a3, 1 #make a3=1
    sll a3, a3, a1
    not a3, a3
    and a0, a0, a3
    ret



.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0