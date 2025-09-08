.section .text
.global _start

_start:
    li a0, 14          # dividend
    li a1, 3           # divisor

    call non_restoring_division

non_restoring_division:
    mv t1, a0          # Q = dividend
    mv t2, a1          # M = divisor
    li t0, 0           # A = 0 (accumulator)
    li t3, 32          # n = 32 (loop counter)

div_loop:
    sll t0, t0, 1      # A <<= 1
    srl t4, t1, 31     # t4 = MSB of Q
    or t0, t0, t4      # A |= (Q >> 31)

    srai t4, t0, 31    # t4 = sign bit of A (arithmetic)
    beqz t4, a_pos     # if A >= 0 jump to a_pos (A = A - M)
                      # else fall-through to add M

    add t0, t0, t2     # A = A + M   (A was negative)

    j update_q

a_pos:
    sub t0, t0, t2     # A = A - M   (A was non-negative)

update_q:
    sll t1, t1, 1      # Q <<= 1

    srai t4, t0, 31    # sign(A)
    beqz t4, set_q_bit # if A >= 0 set Q LSB = 1
    j next

set_q_bit:
    ori t1, t1, 1      # Q |= 1

next:
    addi t3, t3, -1    # n--
    bnez t3, div_loop  # loop if n != 0

    # After loop, if A < 0 adjust remainder: A = A + M
    srai t4, t0, 31
    beqz t4, done
    add t0, t0, t2

done:
    mv a0, t1          # a0 = quotient
    mv a1, t0          # a1 = remainder

 
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b

.section .tohost
.align 3
tohost:    .dword 0
fromhost:  .dword 0

