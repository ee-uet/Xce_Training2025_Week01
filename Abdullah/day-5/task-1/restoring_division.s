.globl _start

.section .text

_start:
    li s0, 20          # Dividend stored in Quotient register (Q)
    li s1, 3           # Divisor (M)
    li s2, 0           # Partial remainder (A), initialized to 0
    li s3, 32          # Iteration counter (number of bits)
    li s4, 1           # Used to generate a mask
    slli s4, s4, 63    # Mask with only MSB set

division_loop:
    blez s3, finished   # Stop after all bits processed

    # Merge A and Q into a 64-bit temporary register
    slli t0, s2, 32     # Shift A to upper half
    or   t0, t0, s0     # Place Q in lower half
    slli t0, t0, 1      # Left shift whole AQ pair

    # Align divisor in high 32 bits
    slli t1, s1, 32     

    sub  t2, t0, t1     # Candidate = (AQ << 1) − (M << 32)

    # Check sign of candidate using MSB
    and  t3, t2, s4     
    bnez t3, negative_case  # If negative, skip update

    ori  t2, t2, 1      # If non-negative, set LSB of Q
    j update_regs

negative_case:
    mv   t2, t0         # Restore previous AQ when subtraction invalid

update_regs:
    srli s2, t2, 32     # Update A (upper 32 bits of combined register)

    slli s0, t2, 32     # Mask out upper half
    srli s0, s0, 32     # Update Q (lower 32 bits)

    addi s3, s3, -1     # Decrement loop counter
    j division_loop

finished:
    # Signal Spike to exit
    li   a0, 1
    la   a1, tohost
    sd   a0, (a1)

halt:
    j halt

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0

