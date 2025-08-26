.section .text
.global _start

_start:
    li a0, 14          # dividend
    li a1, 3           # divisor

    call non_restoring_division
    

non_restoring_division:
    mv t1, a0      # Q = dividend
    mv t2, a1      # M = divisor
    li t0, 0       # A = 0
    li t3, 32      # n = 32

div_loop:
    sll t0, t0, 1       
    srl t4, t1, 31      
    or t0, t0, t4      

    srai t4, t0, 31
    beqz t4, a_pos

    add t0, t0, t2      # A = A + M
    j update_q

a_pos:
    sub t0, t0, t2      # A = A - M

update_q:
    sll t1, t1, 1       # Q <<= 1
    srai t4, t0, 31
    beqz t4, set_q_bit
    j next

set_q_bit:
    ori t1, t1, 1

next:
    addi t3, t3, -1
    bnez t3, div_loop

    srai t4, t0, 31
    beqz t4, done
    add t0, t0, t2      

done:
    mv a0, t1           # a0 = quotient
    mv a1, t0           # a1 = remainder

    
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b
    

.section .tohost
.align 3
tohost:    .dword 0
fromhost:  .dword 0

