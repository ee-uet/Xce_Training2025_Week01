    .section .text
    .globl _start
_start:
    # Input number
    li t0, 0xF1F0F0F0     # Example 32-bit input

    # Counter = 0
    li t1, 0

loop:
    beqz t0, done          # If t0 == 0, exit loop
    andi t2, t0, 1         # Extract LSB
    add  t1, t1, t2        # Add to counter
    srli t0, t0, 1         # Shift right
    j loop

done:
    # Result = t1
    mv a0, t1

    # Signal Spike to exit
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b                   # loop forever (safety)

# Required for Spike
    .section .tohost
    .align 3
tohost: .dword 0
fromhost: .dword 0

