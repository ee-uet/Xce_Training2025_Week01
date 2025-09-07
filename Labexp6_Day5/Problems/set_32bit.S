# RISC-V Bit Counting Program
# Counts the number of 1 bits in a 32-bit number

.data
test_number: .word 0x12345678    # Test value with multiple 1 bits
result:      .word 0             # Storage for result

.text
.global _start

_start:
    # Load test number
    la t0, test_number
    lw a0, 0(t0)              # a0 = number to count bits in
    
    # Call bit counting function
    jal ra, count_bits
    
    # Store result
    la t0, result
    sw a0, 0(t0)              # Store bit count
    
    # Exit for spike pk
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b

# Function to count 1 bits in a 32-bit number
# Input: a0 = number to analyze
# Output: a0 = count of 1 bits
count_bits:
    addi t0, x0, 0            # t0 = bit counter = 0
    addi t1, x0, 32           # t1 = loop counter = 32 bits
    
loop:
    andi t2, a0, 1            # t2 = LSB of current number
    add  t0, t0, t2           # Add bit to counter (0 or 1)
    srli a0, a0, 1            # Shift number right by 1 bit
    addi t1, t1, -1           # Decrement loop counter
    bnez t1, loop             # Continue if more bits to process
    
    mv   a0, t0               # Return bit count in a0
    ret                       # Return to caller

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
