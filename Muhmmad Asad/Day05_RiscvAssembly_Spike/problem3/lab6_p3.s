.global _start

.section .text
_start:
    la sp, stack_top
    li a0, 3
    jal ra, fact
    mv t2, a0

    
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b

fact:
    addi sp, sp, -16      
    sd ra, 8(sp)          
    sd a0, 0(sp)           

    li t0, 1
    beq a0, t0, base_case

    addi a0, a0, -1
    jal ra, fact

    ld t1, 0(sp)           
    mul a0, a0, t1
    j end_fact

base_case:
    li a0, 1

end_fact:
    ld ra, 8(sp)          
    addi sp, sp, 16       
    ret

.section .bss
.align 4
stack: .skip 1024
stack_top:

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
