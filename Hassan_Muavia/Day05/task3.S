.data
dividend: .word 11       # Dividend (Q)
divisor:  .word 3        # Divisor (M)

.global _start

.section .text
_start:
    # any code here
    # Load initial values
    lw a0, dividend       # a0 = Q 
    lw a1, divisor        # a1 = M 
    li a2, 0              # a2 = A 
    li a3, 32             # a3 = n = 32 iterations

loop:
    beqz a3, done         

    bltz a2, case_negative    # if (A < 0) go to negative case

case_positive:                # A >= 0 case
    srli t0, a0, 31           # t0 = (Q >> 31) & 1
    slli a2, a2, 1            # A = A << 1
    or   a2, a2, t0           # insert msbQ into A
    slli a0, a0, 1            # Q = Q << 1
    sub  a2, a2, a1           # A = A - M
    j update_Q

case_negative:                 
    srli t0, a0, 31            
    slli a2, a2, 1             
    or   a2, a2, t0
    slli a0, a0, 1          
    add  a2, a2, a1         

update_Q:
    bltz a2, set_Q0         
    ori  a0, a0, 1           
    j dec_n

set_Q0:
    andi a0, a0, -2            

dec_n:
    addi a3, a3, -1         
    j loop

done:
    bltz a2, fix_remainder    
    j finish

fix_remainder:
    add a2, a2, a1

finish:

    # Exit code for Spike
    # DONT REMOVE IT
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b               # loop forever if Spike does not exit

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

