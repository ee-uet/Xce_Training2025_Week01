.globl _start
    .section .text


_start:
    # Load test number 0xA01B0C01 into a0
    li a0, 0xA01B0C01
    # Call count function to count set bits
    jal ra, count
    
    # Exit for Spike simulator
    li t0, 1          # Load 1 to signal exit
    la t1, tohost     # Load tohost address
    sd t0, (t1)       # Store 1 to tohost

    # Infinite loop to stop execution

1: j 1b

count:
    mv t0, a0         # Copy input to t0
    li t1, 0          # Initialize counter to 0

loop:
    beqz t0, done      # while t0 != 0
    andi t2, t0, 1           # extract LSB
    add  t1, t1, t2          # add to counter
    srli t0, t0, 1           # shift right
    j loop

done:
    mv a0, t1         # Move count to a0
    ret               # Return to caller

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
