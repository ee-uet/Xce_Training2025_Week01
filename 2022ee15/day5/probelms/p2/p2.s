.globl _start

.section .text
_start:
    li t0, 0xAD230FC1     # Load 32-bit word into t0 (value to check bits of)
    li t1, 0              # Initialize counter (t1) to 0

count_loop:
    beq t0, zero, done    # If t0 becomes 0 → all bits processed → jump to done
    andi t2, t0, 1        # Extract least significant bit (LSB) of t0
    add t1, t1, t2        # If LSB=1, increment counter t1
    srli t0, t0, 1        # Shift t0 right by 1 to check next bit
    j count_loop          # Repeat until t0 is zero

done:
    # At this point, t1 holds the number of set bits in the original word
    
    li a0, 1             
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b  

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

