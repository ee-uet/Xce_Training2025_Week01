    .section .data
dividend:   .word 100       
divisor:    .word 7         
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

    # Initialize variables
    li t3, 0            # t3 = remainder 
    li t4, 32           # t4 = iteration 
    li t5, 0            # t5 = quotient 

loop:
    # Shift left: (remainder, dividend) as combined 64-bit value
    slli t3, t3, 1      # remainder = remainder << 1
    srli t6, t1, 31     
    or   t3, t3, t6     # remainder[0] = dividend[31] (combine shift)
    slli t1, t1, 1      # dividend = dividend << 1

    # Check sign of remainder to decide operation
    bltz t3, add_divisor    # If remainder < 0, add divisor

sub_divisor:
    sub t3, t3, t2      # remainder = remainder - divisor
    slli t5, t5, 1      # quotient = quotient << 1
    ori  t5, t5, 1      # quotient[0] = 1 (set quotient bit)
    addi t4, t4, -1     
    bnez t4, loop       
    j   check_remainder 

add_divisor:
    #--------------------Add Path (Remainder < 0)----------
    add t3, t3, t2      # remainder = remainder + divisor
    slli t5, t5, 1      # quotient = quotient << 1 (quotient[0] = 0)
    addi t4, t4, -1     # Decrement iteration counter
    bnez t4, loop       

check_remainder:
    bltz t3, fix_rem    # If remainder < 0, need to fix it
    j store_result      # Remainder is correct, store results

fix_rem:
    add t3, t3, t2      # remainder = remainder + divisor (final correction)


store_result:
    # Store quotient
    la t0, quotient
    sw t5, 0(t0)        # Save final quotient

    # Store remainder  
    la t0, remainder
    sw t3, 0(t0)        # Save final remainder

    # Verification for test case: 100 ÷ 7 = 14 remainder 2
    # Check: 14 × 7 + 2 = 98 + 2 = 100 



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
