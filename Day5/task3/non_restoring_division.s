    .section .data
dividend:   .word 100       # Example Dividend
divisor:    .word 7         # Example Divisor
quotient:   .word 0
remainder:  .word 0

    .section .text
    .globl _start
_start:
    # Load values
    la t0, dividend
    lw t1, 0(t0)        # t1 = Dividend
    la t0, divisor
    lw t2, 0(t0)        # t2 = Divisor

    li t3, 0            # remainder
    li t4, 32           # iteration counter
    li t5, 0            # quotient

loop:
    # Shift left: (remainder, dividend)
    slli t3, t3, 1
    srli t6, t1, 31
    or   t3, t3, t6
    slli t1, t1, 1

    # Decision step (signed check!)
    bltz t3, add_divisor

sub_divisor:
    sub t3, t3, t2      # remainder -= divisor
    slli t5, t5, 1
    ori  t5, t5, 1      # quotient = (quotient << 1) | 1
    addi t4, t4, -1
    bnez t4, loop
    j   check_remainder

add_divisor:
    add t3, t3, t2      # remainder += divisor
    slli t5, t5, 1      # quotient = (quotient << 1) | 0
    addi t4, t4, -1
    bnez t4, loop

check_remainder:
    bltz t3, fix_rem
    j store_result

fix_rem:
    add t3, t3, t2      # remainder += divisor

store_result:
    la t0, quotient
    sw t5, 0(t0)
    la t0, remainder
    sw t3, 0(t0)

#-------------#######################----------------------

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
