.global _start
.section .text

_start:
    # Initialize
    li t0, 11        # Q = Dividend
    li t1, 3         # M = Divisor
    li t2, 0         # A = 0 (Accumulator)
    li t3, 4         # n = number of bits (loop count)

loop:
    # Shift Left (A,Q)  
    slli t2, t2, 1        # A << 1
    srli t4, t0, 3        # extract current MSB(Q) (bit n-1=3 for 4-bit case) ye neg num k lye b ha or srli pos k lye
    andi t4, t4, 1        # isolate the bit
    or   t2, t2, t4       # put MSB(Q) into A

    slli t0, t0, 1        # Q << 1

    #  Check sign of A  
    blt  t2, x0, neg_case   # if A < 0 -> A = A + M
    sub  t2, t2, t1         # else A = A - M
    j update_Q

neg_case:
    add  t2, t2, t1         # A = A + M

update_Q:
    #  Set Q0 depending on sign of A  
    blt  t2, x0, setQ0_zero
    ori  t0, t0, 1          # Q0 = 1
    j check_done

setQ0_zero:
    andi t0, t0, -2         # Q0 = 0 ,-2 mtlb lsb 0 ha bs

check_done:
    addi t3, t3, -1         # n = n - 1
    bnez t3, loop           # repeat until n = 0

# Final correction 
final_correction:
    blt  t2, x0, do_correction
    j done

do_correction:
    add  t2, t2, t1         # A = A + M

done:
    # Keep only 4 bits of quotient and remainder
    andi t0, t0, 0xF      # Quotient masked to 4 bits
    andi t2, t2, 0xF      # Remainder masked to 4 bits

    
    li t6, 1
    la t5, tohost
    sd t6, 0(t5)

halt:
    j halt

.section .data
quotient:   .dword 0
remainder:  .dword 0

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
