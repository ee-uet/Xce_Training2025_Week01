.globl _start

.section .text

_start:
    li t0, 20         # Dividend (Q)
    li t1, 3          # Divisor (M)
    li t2, 0          # Remainder/accumulator (A)
    li a2, 32         # counter
    li t6, 1          # mask 
    slli t6, t6, 63   # Create MSB 

division_cycle:
    blez a2, completion  # Exit 

    # Combine A and Q into 64-bit value
    slli t3, t2, 32     # Shift A to upper 32 bits
    or t3, t3, t0       # Combine with Q in lower 32 bits
    slli t3, t3, 1      # Shift left entire AQ combination

    # Prepare divisor in upper 32 bits for comparison
    slli t4, t1, 32     # Shift M to upper 32 bits
    
    sub t5, t3, t4      # Compute (AQ << 1) - (M << 32)
    
    # Check if result is negative (MSB set)
    and a0, t5, t6      # Extract sign bit
    bnez a0, skip_subtract  # Skip if subtraction gives negative result
    
    ori t5, t5, 1       # Set least significant bit
    j update_registers

skip_subtract:
    mv t5, t3

update_registers:
   
    srli t2, t5, 32     # Update remainder (A)
    
    slli t0, t5, 32     # Clear upper bits
    srli t0, t0, 32     # Update quotient (Q)
    
  
    addi a2, a2, -1
    j division_cycle

completion:

    li t0, 1
    la t1, tohost
    sd t0, (t1)


infinite_loop:
    j infinite_loop

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
