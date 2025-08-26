# a0: dividend
# a1: divisor
# a0: quotient
# a1: remainder

.data
dividend: .word 100
divisor:  .word 10
.text
.global main
main:
    lw a0, dividend # a0 = dividend
    lw a1, divisor  # a1 = divisor
    li a2, 0        # a2 = quotient (Q)
    li a3, 32       # a3 = counter for 32 bits

    # Initial shift of dividend into remainder (not needed for this algorithm)
    # The remainder is the dividend initially.
    mv a4, a0

restoring_loop:
    beq a3, x0, end_division  # Loop 32 times
    slli a4, a4, 1            # Left shift remainder
    slli a2, a2, 1            # Left shift quotient

    sub a4, a4, a1            # Remainder = Remainder - Divisor
    blt a4, x0, restore       # If Remainder < 0, restore
    
    addi a2, a2, 1            # Set quotient bit to 1
    j continue_loop

restore:
    add a4, a4, a1            # Remainder = Remainder + Divisor
    # Quotient bit remains 0

continue_loop:
    addi a3, a3, -1           # Decrement counter
    j restoring_loop

end_division:
    mv a0, a2                 # Move quotient to a0
    mv a1, a4                 # Move remainder to a1
    
    li a7, 93                 # exit syscall
    ecall
