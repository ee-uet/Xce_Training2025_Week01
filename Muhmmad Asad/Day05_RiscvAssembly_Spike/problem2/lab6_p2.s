.global _start
 
.section .text
_start:
    la t0, value
    la t1, value_size
    lw a0, 0(t0)
    lw a1, 0(t1)
    jal count_ones
    j done

count_ones:
    li t2, 0 #initial value
    li t3, 0 # result
    li t4, 0 # for and op
while:
    beq t2, a1, return
    andi t4, a0, 1
    add t3, t4, t3
    srli a0, a0, 1
    addi t2, t2, 1
    j while

return:
    ret

done:
    # Signal test pass to Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever
1:  j 1b

.section .data
value: .word 3
value_size: .word 32
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
