# a0: dividend
# a1: divisor
# a0: quotient
# a1: remainder

.data
dividend_nr: .word 100
divisor_nr:  .word 10
.text
.global main
main:
    lw a0, dividend_nr # a0 = dividend
    lw a1, divisor_nr  # a1 = divisor
    li a2, 0           # a2 = quotient (Q)
    li a3, 32          # a3 = counter
    li a4, 0           # a4 = remainder (R)

    sll a4, a0, 1      # Left shift dividend into remainder once
    sub a4, a4, a1     # R = R - D
    
non_restoring_loop:
    beq a3, x0, final_correction # Loop 32 times
    
    slli a2, a2, 1     # Left shift Q

    blt a4, x0, negative_case # If R < 0, handle negative case
    # Positive case
    addi a2, a2, 1     # Set Q bit to 1
    slli a4, a4, 1     # R = R << 1
    sub a4, a4, a1     # R = R - D
    j continue_nr_loop

negative_case:
    # Set Q bit to 0
    slli a4, a4, 1     # R = R << 1
    add a4, a4, a1     # R = R + D

continue_nr_loop:
    addi a3, a3, -1    # Decrement counter
    j non_restoring_loop

final_correction:
    bge a4, x0, end_nr_division
    # Final correction if remainder is negative
    add a4, a4, a1

end_nr_division:
    mv a0, a2          # Move quotient to a0
    mv a1, a4          # Move remainder to a1

    li a7, 93
    ecall
