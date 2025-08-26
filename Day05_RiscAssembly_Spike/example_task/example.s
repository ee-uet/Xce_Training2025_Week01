.global _start

.section .text
_start:
    li a0, 0          # Initialize counter
    li a1, 10         # Set maximum count

loop: 
    addi a0, a0, 1    # Increment counter
    blt a0, a1, loop  # Loop if counter < max

    # Exit for Spike (DONT REMOVE)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b              # Loop forever if spike does not exit

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
