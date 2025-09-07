# RISC-V Factorial Program
# Calculates factorial of a number using iterative approach

.data
n:      .word 5       # Input number (5! = 120)
result: .word 0       # Storage for result

.text
.globl _start

_start:
    # Load input number
    la   t0, n
    lw   a0, 0(t0)       # a0 = n = 5
   
    # Call factorial function
    jal  ra, factorial
    
    # Store result
    la   t1, result
    sw   a0, 0(t1)       # result = 5! = 120
   
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

# Factorial function - iterative implementation
# Input: a0 = n
# Output: a0 = n!
factorial:
    li   t0, 1           # t0 = accumulator = 1
    mv   t1, a0          # t1 = counter = n
    
fact_loop:
    beq  t1, x0, fact_done  # If counter == 0, exit loop
    mul  t0, t0, t1         # accumulator *= counter
    addi t1, t1, -1         # counter--
    j    fact_loop          # Continue loop
    
fact_done:
    mv   a0, t0             # Return result in a0
    ret                     # Return to caller
