.global _start
.section .text

_start:
    li t0, 21           # Dividend value (Q)
    li t1, 3            # Divisor value (M)
    li t2, 0            # Remainder accumulator (A)
    li a2, 32           # Bit processing counter
    
    # Create sign detection masks
    li t6, 1
    slli t6, t6, 31     # 32-bit sign mask (bit 31)
    li s0, 1
    slli s0, s0, 63     # 64-bit sign mask (bit 63)

division_iteration:
    blez a2, finish_division

    # Determine current remainder sign
    and a0, t2, t6      # Check MSB of A (32-bit sign)

    # Construct 64-bit AQ value and shift left
    slli t3, t2, 32     # Move A to upper 32 bits
    or t3, t3, t0       # Combine with Q in lower bits
    slli t3, t3, 1      # Shift entire AQ left by 1
    
    slli t4, t1, 32     # Shift M to upper 32 bits

    # Branch based on current remainder sign
    bnez a0, negative_remainder

    # Positive remainder case: subtract divisor
    sub t5, t3, t4      # (AQ << 1) - (M << 32)
    j determine_quotient_bit

negative_remainder:
    # Negative remainder case: add divisor
    add t5, t3, t4      # (AQ << 1) + (M << 32)

determine_quotient_bit:
    # Check sign of new 64-bit result to set quotient bit
    and a0, t5, s0      # Examine MSB of 64-bit result
    beqz a0, set_quotient_one  

    # Negative result: Q0 remains 0 
    j extract_registers

set_quotient_one:
    # set LSB to 1
    ori t5, t5, 1

extract_registers:
    # Update remainder from upper 32 bits
    srli t2, t5, 32     # New A value
    
    # Update quotient from lower 32 bits
    slli t0, t5, 32     # Clear upper bits
    srli t0, t0, 32     # New Q value

    # Continue with next bit
    addi a2, a2, -1
    j division_iteration

finish_division:
    and a0, t2, t6      # Check final remainder sign
    beqz a0, division_complete
    
    # Negative remainder correction: add divisor back
    add t2, t2, t1

division_complete:
   
    li a0, 1
    la a1, tohost
    sd a0, (a1)

   
termination_loop:
    j termination_loop

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
