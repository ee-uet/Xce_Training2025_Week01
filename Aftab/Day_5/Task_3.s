.global _start
.section .text

_start:
    li t0, 21       # Dividend (Q)
    li t1, 3        # Divisor (M)
    li t2, 0        # Remainder (A)
    li a2, 32       # Number of bits

    li t6, 1
    slli t6, t6, 31  
    li s0, 1
    slli s0, s0, 63  

non_restoring_loop:
    ble a2, zero, exit

    # Check if A is negative or non-negative
    and a0, t2, t6      # Check sign of A (bit 31)

    slli t3, t2, 32     # A << 32
    add t3, t3, t0      # AQ = (A<<32) | Q
    slli t3, t3, 1      # AQ << 1
    slli t4, t1, 32     # M << 32

    beq a0, t6, A_negative

    # A >= 0: subtract M
    sub t5, t3, t4      # AQ - M<<32 = (A-M)<<32 | Q
    j update

A_negative:
    # A < 0: add M
    add t5, t3, t4      # AQ + M<<32 = (A+M)<<32 | Q

update:
    # Check the new sign to set quotient bit
    and a0, t5, s0      # Check sign of new 64-bit result (bit 63)
    beq a0, s0, set_q0  # If negative, set Q0=0

    # New A >= 0: Set Q0=1
    ori t5, t5, 1
    j extract_results

set_q0:
    # New A < 0: Q0 remains 0 (already 0 from shift)

extract_results:
    # Extract new A and Q
    srli t2, t5, 32     # Update A (upper 32 bits)
    slli t0, t5, 32     # Update Q (lower 32 bits)
    srli t0, t0, 32

    addi a2, a2, -1
    j non_restoring_loop

exit:
    # Final correction: If A is negative, add M back
    and a0, t2, t6      # Check final sign of A (bit 31)
    beq a0, t6, final_correction
    j done

final_correction:
    add t2, t2, t1      # A = A + M

done:

    li a0, 1            
    la a1, tohost
    sd a0, (a1)

    # Loop forever
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0