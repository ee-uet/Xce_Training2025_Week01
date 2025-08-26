.global _start
.section .text

_start:

    li t0, 0x12345678       # Original number (32-bit)
    li t1, 5                # Bit position to modify (0-31)
    
    # 1. Set bit example
    li t2, 1                # Load constant 1
    sll t2, t2, t1          # Create mask: 1 << bit_position
    or t3, t0, t2           # Set bit: number | mask
    
    # 2. Clear bit example  
    li t2, 1                # Load constant 1
    sll t2, t2, t1          # Create mask: 1 << bit_position
    not t2, t2              # Invert mask: ~(1 << bit_position)
    and t4, t0, t2          # Clear bit: number & ~mask
    
    # 3. Toggle bit example
    li t2, 1                # Load constant 1
    sll t2, t2, t1          # Create mask: 1 << bit_position
    xor t5, t0, t2          # Toggle bit: number ^ mask
    
    # 4. Check bit example
    srl t2, t0, t1          # Shift number right by bit_position
    andi t6, t2, 1          # Mask LSB: (number >> pos) & 1
    

exit:
    # Code to exit for Spike
    li a0, 1
    la a1, tohost
    sd a0, (a1)
    
    # Loop forever
1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0