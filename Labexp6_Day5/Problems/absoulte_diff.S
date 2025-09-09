# RISC-V Absolute Difference Program
# Computes |num1 - num2| and stores result

.data
num1:   .word 25
num2:   .word 40
result: .word 0

.global _start
 
.section .text
_start:
    # Load first number
    la t0, num1
    lw t1, 0(t0)      # t1 = num1 (25)
    
    # Load second number
    la t0, num2
    lw t2, 0(t0)      # t2 = num2 (40)
    
    # Calculate difference
    sub t3, t1, t2    # t3 = num1 - num2 (25 - 40 = -15)
    
    # Check if result is negative
    blt t3, x0, neg   # If t3 < 0, jump to neg
    j done
    
neg:
    # Make negative result positive (two's complement)
    sub t3, x0, t3    # t3 = 0 - t3 (negate the result)
    
done:
    # Store absolute difference
    la t0, result
    sw t3, 0(t0)      # Store |num1 - num2| = 15
    
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
