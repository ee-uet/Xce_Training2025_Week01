# RISC-V Restoring Division Algorithm
# Divides 13 by 3 using restoring division method

.data
dividend:   .word 13
divisor:    .word 3
quotient:   .word 0
remainder:  .word 0

.text
.globl _start

_start:
    # Load dividend and divisor from memory
    la t0, dividend
    lw t1, 0(t0)       # t1 = Q (dividend = 13)
    la t0, divisor
    lw t2, 0(t0)       # t2 = M (divisor = 3)
    li t3, 0           # t3 = A (accumulator = 0)
    li t4, 32          # Bit counter = 32

loop:
    beqz t4, done      # Exit if all bits processed
    
    # Step 1: Shift (A,Q) left by 1 bit
    slli t3, t3, 1     # Shift accumulator left
    srli t5, t1, 31    # Extract MSB of quotient
    or t3, t3, t5      # Bring MSB of Q into LSB of A
    slli t1, t1, 1     # Shift quotient left
    
    # Step 2: Subtract divisor from accumulator
    sub t3, t3, t2     # A = A - M
    
    # Step 3: Check if result is negative
    bltz t3, restore   # If A < 0, restore A
    
    # A >= 0: Set quotient bit to 1
    ori t1, t1, 1      # Set LSB of Q = 1
    j next
    
restore:
    # A < 0: Restore accumulator and keep quotient bit 0
    add t3, t3, t2     # A = A + M (restore)
    
next:
    addi t4, t4, -1    # Decrement bit counter
    j loop

done:
    # Store final results in memory
    la t0, quotient
    sw t1, 0(t0)       # Store quotient (should be 4)
    la t0, remainder
    sw t3, 0(t0)       # Store remainder (should be 1)
    
    # Exit for spike pk
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
