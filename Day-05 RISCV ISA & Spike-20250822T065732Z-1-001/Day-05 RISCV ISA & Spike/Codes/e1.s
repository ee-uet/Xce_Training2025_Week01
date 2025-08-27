.section .text
.globl _start
.globl restoring_divide

_start:
    	# Test case: divide 100 by 7
    	li a0, 100          # dividend
    	li a1, 7            # divisor
    
    	jal restoring_divide
    
    	# Results are in a0 (quotient) and a1 (remainder)
   	# For testing, we'll store results and exit
    	mv t0, a0           # quotient
    	mv t1, a1           # remainder
    
   	# Code to exit for Spike (DONT REMOVE IT)
   	li t0, 1
	la t1, tohost
	sd t0, (t1)
    
    
# Restoring Division Algorithm
# Input: a0 = dividend (32-bit), a1 = divisor (32-bit)
# Output: a0 = quotient, a1 = remainder
# Uses: t0-t6 as temporary registers

restoring_divide:
    # Check for division by zero
    beqz a1, div_by_zero
    
    # Initialize variables
    mv t0, a0           # dividend (will become remainder)
    mv t1, a1           # divisor
    li t2, 0            # quotient
    li t3, 32           # bit counter
    li t4, 0            # temporary remainder (AQ register)
    
    # Main division loop
div_loop:
    # Shift left AQ (t4:t0) by 1 bit
    slli t4, t4, 1      # Shift A left
    srli t5, t0, 31     # Get MSB of Q
    or t4, t4, t5       # Set LSB of A to MSB of Q
    slli t0, t0, 1      # Shift Q left
    
    # Subtract divisor from A
    sub t5, t4, t1      # A = A - divisor
    
    # Check if result is negative
    bltz t5, restore    # If negative, restore and set Q[0] = 0
    
    # Result is positive, keep subtraction and set Q[0] = 1
    mv t4, t5           # Keep the subtraction result
    ori t0, t0, 1       # Set Q[0] = 1
    j next_bit
    
restore:
    # A is already correct (original value), Q[0] is already 0
    # No action needed for restoring division
    
next_bit:
    addi t3, t3, -1     # Decrement bit counter
    bnez t3, div_loop   # Continue if more bits to process
    
    # Results: t0 = quotient, t4 = remainder
    mv a0, t0           # Return quotient
    mv a1, t4           # Return remainder
    ret

div_by_zero:
    li a0, -1           # Error code for division by zero
    li a1, -1
    ret

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
