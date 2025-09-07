# RISC-V Bit Manipulation Program
# Set or clear a specific bit in a 32-bit number

.section .text
.globl _start

_start:
    li a0, 0x12345678      # Test number
    li a1, 5               # Bit position to modify
    li a2, 1               # Operation: 1=set, 0=clear
    
    # Create bit mask
    li t0, 1               
    sll t0, t0, a1         # mask = 1 << position
    
    # Branch based on operation
    beq a2, x0, clear_bit  
    
    # Set bit operation
    or a0, a0, t0          # number |= mask
    j done
    
clear_bit:
    # Clear bit operation
    not t0, t0             # Invert mask
    and a0, a0, t0         # number &= ~mask
    
done:
    # Result is in a0
    
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
