    .global _start
    .section .text
_start:
    # Initialize input values
    li a0, 7      # x
    li a1, 12     # y

    # Compute absolute difference using branch
    bge a0, a1, x_ge_y
    sub t0, a1, a0        # t0 = |x - y|
    j store
x_ge_y:
    sub t0, a0, a1        # t0 = |x - y|

store:
    # Store result at fixed memory address 0x80001000
    li t1, 0x80001000
    sd t0, 0(t1)

    # Exit for Spike (use different registers, not t0)
    li t2, 1
    la t3, tohost
    sd t2, 0(t3)

    # Loop forever if Spike does not exit
1:  j 1b

    .section .data
    .align 3
result: .dword 0

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
