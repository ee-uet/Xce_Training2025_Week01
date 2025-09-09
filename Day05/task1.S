    .data
dividend:   .word 13        # Q (initial dividend)
divisor:    .word 3         # M
n_bits:     .word 4         # number of bits in dividend

Q:          .word 0         # quotient register
A:          .word 0         # remainder

    .global _start

    .section .text
_start:
    # any code here
    # Load dividend into Q
    la   t0, dividend
    lw   t1, 0(t0)          # t1 = dividend
    la   t2, Q
    sw   t1, 0(t2)          # Q = dividend

    # Load divisor
    la   t0, divisor
    lw   t3, 0(t0)          # t3 = M (divisor)

    # Load number of bits
    la   t0, n_bits
    lw   t4, 0(t0)          # t4 = n

    # Initialize A = 0
    li   t5, 0              # t5 = A

    # i = 0
    li   t6, 0              # loop counter

outer_loop:
    bge  t6, t4, done       # if i >= n, stop

    # Shift left AQ
    
    la   t0, Q
    lw   t1, 0(t0)          # load Q

    addi t7, t4, -1         # t7 = n-1
    srl  t8, t1, t7         # msbQ = (Q >> (n-1)) & 1
    andi t8, t8, 1

    slli t5, t5, 1          # A = A << 1
    or   t5, t5, t8         # A = (A << 1) | msbQ

    slli t1, t1, 1          # Q = Q << 1
    sw   t1, 0(t0)

    # A = A - M
   
    sub  t5, t5, t3

    # If A < 0 → restore A, set Q(0)=0
    # Else set Q(0)=1

    blt  t5, x0, restore

set_Q_bit:
    lw   t1, 0(t0)
    ori  t1, t1, 1          # set LSB = 1
    sw   t1, 0(t0)
    j    continue_loop

restore:
    add  t5, t5, t3         # restore A
    lw   t1, 0(t0)
    andi t1, t1, -2         # clear LSB
    sw   t1, 0(t0)

continue_loop:
    addi t6, t6, 1          # i++
    j outer_loop

done:
    # Code to exit for Spike (DONT REMOVE IT)
    # Store final A back into memory
    la   t0, A
    sw   t5, 0(t0)

    # Exit Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b                    # loop forever if Spike doesn’t exit

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
