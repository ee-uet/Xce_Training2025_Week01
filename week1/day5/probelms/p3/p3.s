.globl _start

.section .text
_start:
    li t0, 5          # number to calculate factorial of (n = 5)
    li t1, 1          # accumulator for factorial result

factorial_loop:
    beq t0, zero, done    # if t0 == 0, factorial is complete
    mul t1, t1, t0        # multiply result by current n
    addi t0, t0, -1       # decrement n by 1
    j factorial_loop      # repeat until t0 reaches 0

done:
   
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)

1:  j 1b   

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

