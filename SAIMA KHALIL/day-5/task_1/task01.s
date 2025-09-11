.section .text
.globl _start

_start:
    # Initialize  
    li t0, 22      # Q    
    li t1, 3       # M  
    li t3, 0       # A  
    li t4, 5       # n = 5 iterations

loop:
    # A:Q combined shift left  
    slli t3, t3, 1           # A << 1  
    
    # Get MSB of Q (bit 4) BEFORE shifting Q
    srli t5, t0, 4           # Get bit 4 of Q (MSB)
    andi t5, t5, 1           # Isolate the bit
    or t3, t3, t5            # Put in LSB of A
    
    slli t0, t0, 1           # Q << 1  
    
    # A = A - M  
    sub t3, t3, t1
    
    # Check if negative (using 5-bit arithmetic)
    bge t3, zero, positive
    
    # Restore A (A + M)
    add t3, t3, t1
    j next

positive:
    # Set LSB of Q to 1
    ori t0, t0, 1

next:
    addi t4, t4, -1
    bnez t4, loop

done:
    # Masking  results to 5 bits only
    andi t0, t0, 0x1F        # Keep only 5 bits of quotient
    andi t3, t3, 0x1F        # Keep only 5 bits of remainder
    
    li t5, 1
    la t6, tohost
    sd t5, 0(t6)

1: j 1b

.section .tohost
tohost: .dword 
