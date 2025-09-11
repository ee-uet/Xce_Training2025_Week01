.globl _start
    .section .text

_start:
    # Initialize factorial calculation
    li t0, 5            # Load input number (n = 5)
    li t1, 1            # Initialize result accumulator (result = 1)
    jal ra, factorial   # Call factorial function


factorial:
    beqz t0, done       # If n == 0, factorial is complete
    mul t1, t1, t0      # result = result * n
    addi t0, t0, -1     # n = n - 1 (decrement counter)
    j factorial         # Continue iteration (Note: this creates a loop, not recursion)

done:
    # Signal successful completion to Spike simulator
    # Final result is stored in t1 register
    
    
    # Code to exit for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
