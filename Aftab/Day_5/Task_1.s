.global _start
.section .text

# This program is using Restore Division Algorithm to find qoutient and remainder

_start:
    li t0,16        # Dividend(Q)
    li t1,3         # Divisor(M)
    li t2,0         # Remainder(A)
    li a2,32        # Number of bits in dividend(N)
    li t6,1         # temp
    slli t6,t6,63   # MSB is set, t6 = 0x8000000000000000

loop:
    ble a2,zero,exit

    slli t3,t2,32   # shifting A to upper 32bit
    add t3,t3,t0    # AQ 
    slli t3,t3,1    # AQ << 1
    slli t4,t1,32   # M0
    sub t5,t3,t4    # AQ - M0 = (A-M)Q 
    and a0,t5,t6    # MSB will be set if A is -ve
    beq a0,t6,label
    ori t5,t5,1     # setting Q0 
    j label_end

label:
    mv t5,t3

label_end:
    srli t2,t5,32   # Update A
    slli t0,t5,32
    srli t0,t0,32   # Upade Q

    addi a2,a2,-1
    j loop

exit:
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
