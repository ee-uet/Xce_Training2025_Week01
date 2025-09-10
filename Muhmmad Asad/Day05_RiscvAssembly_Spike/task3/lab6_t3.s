.global _start
 
.section .text
_start:
    li a0, 13 #a0 = quotient
    li a1, 3 # divisor
    li t2, 0 # remainder
    jal ra, non_restoring_div
    blt t2, zero, update_R
done:
    li t6, 1
    la t1, tohost
    sd t6, (t1)
 
    
1:  j 1b
update_R:
    add t2, t2, t1
    j done

non_restoring_div:
    li t3, 32 #counter
    mv t0, a0 #t0 = quotient
    mv t1, a1 #t1 = divisor
    li t6, 1
    slli t6, t6, 31
    not t6, t6
    
while:
    beq t3, zero, return
    li t5, 1
    slli t5, t5, 31
    and t5, t5, t0 # t5 = msb
    srli t5, t5, 31
    slli t2, t2, 1
    and t0, t0, t6 #clear msb
    or t2, t2, t5 # R = R | msb of Q
    and t0, t0, t6 #clear msb
    slli t0, t0, 1 # Q = Q << 1
    bge t2, zero, sub_R
    add t2, t2, t1 # R = R + D
    bge t2 ,zero, set_Q
    j loop_end


sub_R:
    sub t2, t2, t1 # R = R - D
    bge t2, zero, set_Q
    j loop_end

set_Q:
    ori t0, t0, 1
    j loop_end
loop_end:
    addi t3, t3, -1
    j while

return:
    ret



.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0