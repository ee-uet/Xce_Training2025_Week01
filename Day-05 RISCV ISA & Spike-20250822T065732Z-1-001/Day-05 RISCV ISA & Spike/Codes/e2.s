.section .text
.globl _start
.globl set_bit
.globl clear_bit

_start:
    # Test cases
    li t0, 0x12345678   # Test number
    
    # Test set_bit: set bit 4 in 0x12345678
    mv a0, t0           # number
    li a1, 4            # bit position
    jal set_bit
    mv t1, a0           # save result
    
    # Test clear_bit: clear bit 6 in the result
    mv a0, t1           # number from previous operation
    li a1, 6            # bit position
    jal clear_bit
    mv t2, a0           # save result
    
    # Code to exit for Spike (DONT REMOVE IT)
   	li t0, 1
	la t1, tohost
	sd t0, (t1)
    
    
# Set bit function
# Input: a0 = number, a1 = bit position (0-31)
# Output: a0 = result with bit set
# Modifies: t0
set_bit:
    # Validate bit position (0-31)
    li t0, 31
    bltu t0, a1, invalid_bit_pos
    
    # Create mask: 1 << bit_position
    li t0, 1
    sll t0, t0, a1      # t0 = 1 << a1
    
    # Set the bit using OR operation
    or a0, a0, t0       # a0 = a0 | (1 << bit_pos)
    
    ret

# Clear bit function  
# Input: a0 = number, a1 = bit position (0-31)
# Output: a0 = result with bit cleared
# Modifies: t0
clear_bit:
    # Validate bit position (0-31)
    li t0, 31
    bltu t0, a1, invalid_bit_pos
    
    # Create mask: ~(1 << bit_position)
    li t0, 1
    sll t0, t0, a1      # t0 = 1 << a1
    not t0, t0          # t0 = ~(1 << a1)
    
    # Clear the bit using AND operation
    and a0, a0, t0      # a0 = a0 & ~(1 << bit_pos)
    
    ret

invalid_bit_pos:
    # Return original number unchanged for invalid bit position
    ret

# Additional utility functions for testing

# Get bit function
# Input: a0 = number, a1 = bit position (0-31)
# Output: a0 = bit value (0 or 1)
get_bit:
    # Validate bit position
    li t0, 31
    bltu t0, a1, invalid_bit_pos_get
    
    # Extract the bit
    srl a0, a0, a1      # Shift right by bit_position
    andi a0, a0, 1      # Mask to get only the LSB
    
    ret

invalid_bit_pos_get:
    li a0, -1           # Error indicator
    ret

# Toggle bit function
# Input: a0 = number, a1 = bit position (0-31)  
# Output: a0 = result with bit toggled
toggle_bit:
    # Validate bit position
    li t0, 31
    bltu t0, a1, invalid_bit_pos
    
    # Create mask and toggle
    li t0, 1
    sll t0, t0, a1      # t0 = 1 << a1
    xor a0, a0, t0      # a0 = a0 ^ (1 << bit_pos)
    
    ret

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

