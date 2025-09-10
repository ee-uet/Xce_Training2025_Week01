.section .text
.globl _start
.globl divide

_start: 
    li a0, 57       # Dividend
    li a1, 10       # Divisor
    jal divide      # Jump to divide
    
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

divide:
    # Mask inputs to 8-bit
    andi t0, a0, 0xFF   # Q (quotient/dividend) - 8 bits only
    andi t1, a1, 0xFF   # Divisor - 8 bits only
    li t2, 0            # A (remainder accumulator)
    li t3, 8            # Counter (8 iterations for 8-bit)
    
loop:
    # Shift A left by 1
    slli t2, t2, 1
    
    # Get MSB of Q and put it in LSB of A
    andi t4, t0, 0x80   # Extract MSB (bit 7) of Q
    srli t4, t4, 7      # Shift it to LSB position
    or t2, t2, t4       # Put it in LSB of A
    
    # Shift Q left by 1
    slli t0, t0, 1
    andi t0, t0, 0xFF   # Keep only 8 bits
    
    # Check if A is negative
    bltz t2, add
    bgez t2, sub

add:
    add t2, t2, t1
    bltz t2, next_iteration
    ori t0, t0, 1
    
    j next_iteration
    
sub:
    sub t2, t2, t1
    bltz t2, next_iteration
    ori t0, t0, 1
    
next_iteration:
    # Decrement counter and check if done
    addi t3, t3, -1
    bnez t3, loop
    
    # If remainder is still negative, add divisor
    bltz t2, final_adjust
    j done
    
final_adjust:
    add t2, t2, t1
    
done:
    # Mask results to 8-bit and return
    andi a0, t0, 0xFF   # Quotient
    andi a1, t2, 0xFF   # Remainder
    ret

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
