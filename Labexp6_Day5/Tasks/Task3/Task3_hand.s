# RISC-V Bare-Metal: 32-bit Unsigned Non-Restoring Division Algorithm
# Input: a0 = dividend, a1 = divisor
# Output: a0 = quotient, a1 = remainder

.section .text
.global non_restoring_divide

# Non-restoring division algorithm
# Input: a0 = dividend (N), a1 = divisor (D)
# Output: a0 = quotient (Q), a1 = remainder (R)
non_restoring_divide:
    # Check for division by zero
    beqz a1, div_by_zero
    
    # Initialize working registers
    mv t0, a0               # t0 = dividend (N) - will be shifted
    mv t1, a1               # t1 = divisor (D)
    li t2, 0                # t2 = quotient (Q)
    li t3, 0                # t3 = remainder (R)
    li t4, 32               # t4 = bit counter (32 bits)
    
    # Main division loop - process 32 bits
division_loop:
    # Left shift remainder and bring down next bit from dividend
    slli t3, t3, 1          # R = R << 1
    srli t5, t0, 31         # Extract MSB of dividend
    or t3, t3, t5           # R = R | MSB(N)
    slli t0, t0, 1          # N = N << 1 (remove processed bit)
    
    # Left shift quotient to make room for next bit
    slli t2, t2, 1          # Q = Q << 1
    
    # Check sign of remainder
    bgez t3, remainder_positive
    
remainder_negative:
    # R < 0: R = R + D, quotient bit = 0
    add t3, t3, t1          # R = R + D
    j loop_continue
    
remainder_positive:
    # R >= 0: R = R - D
    sub t3, t3, t1          # R = R - D
    
    # If result is non-negative, set quotient bit to 1
    bgez t3, set_quotient_bit
    j loop_continue
    
set_quotient_bit:
    ori t2, t2, 1           # Set LSB of quotient to 1
    
loop_continue:
    addi t4, t4, -1         # Decrement bit counter
    bnez t4, division_loop  # Continue if more bits to process
    
    # Post-processing: Ensure remainder is positive
    bgez t3, division_complete
    
    # If final remainder is negative, correct it
    add t3, t3, t1          # R = R + D
    addi t2, t2, -1         # Q = Q - 1
    
division_complete:
    # Return results
    mv a0, t2               # Return quotient in a0
    mv a1, t3               # Return remainder in a1
    jr ra                   # Return to caller

div_by_zero:
    # Handle division by zero
    li a0, 0                # Return 0 for quotient
    li a1, 0                # Return 0 for remainder
    jr ra

    # Exit for spike pk
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
