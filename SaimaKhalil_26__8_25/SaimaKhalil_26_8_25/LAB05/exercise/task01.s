#Write an assembly program for restoring division algorithm in RISC-V assembly language.bare metal for RISC-V.
.global _start
.section .text
_start:
    li t0, 20          # Dividend
    li t1, 3           # Divisor
    li t2, 0           # Quotient
    li t3, 0           # Remainder
    li t4, 32          # Bit counter (assuming 32-bit integers)
division_loop:
    sll t2, t2, 1      # Shift left quotient
    sll t3, t3, 1      # Shift left remainder
    or t3, t3, t0      # Bring down next bit of dividend
    blt t3, t1, skip_subtract # If remainder < divisor, skip subtraction
    sub t3, t3, t1     # Remainder = Remainder - Divisor
    ori t2, t2, 1      # Set least significant bit of quotient
skip_subtract:
    slli t0, t0, 1     # Shift left dividend
    addi t4, t4, -1    # Decrement bit counter
    bnez t4, division_loop # Repeat for all bits
# Result: Quotient in t2, Remainder in t3
halt:
    j halt
    
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
