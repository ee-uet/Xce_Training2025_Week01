    .data
dividend:   .word 13
divisor:    .word 3
quotient:   .word 0
remainder:  .word 0

    .text
    .globl _start

_start:
    # Load Dividend (Q) and Divisor (M)
    la t0, dividend
    lw t1, 0(t0)       # t1 = Q (dividend = 13)
    la t0, divisor
    lw t2, 0(t0)       # t2 = M (divisor = 3)

    li t3, 0           # t3 = A (accumulator = 0)
    li t4, 32          # number of bits = 32

loop:
    beqz t4, done      # if count == 0, exit

    # Step 1: Shift (A,Q) left by 1
    slli t1, t1, 1     # shift Q left
    slli t3, t3, 1     # shift A left

    # bring MSB of Q into A
    srli t5, t1, 32    # extract bit (only works conceptually)
    or t3, t3, t5

    # Step 2: A = A - M
    sub t3, t3, t2

    # Step 3: Check if A < 0
    bltz t3, restore

    # If A >= 0: set LSB of Q = 1
    ori t1, t1, 1
    j next

restore:
    # If A < 0, restore A = A + M
    add t3, t3, t2
    # LSB of Q already 0 (do nothing)

next:
    addi t4, t4, -1    # decrement counter
    j loop

done:
    # Store results
    la t0, quotient
    sw t1, 0(t0)       # quotient
    la t0, remainder
    sw t3, 0(t0)       # remainder

    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
