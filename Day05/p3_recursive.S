.global _start
.section .text

_start:
    # Initialize stack pointer
    la sp, stack_top
    
    li a0, 5
    jal ra, factorial
    j exit

factorial:
    addi sp, sp, -16    # Allocate stack space for 2 doublewords
    sd ra, 8(sp)        # Save return address (64-bit)
    sd s0, 0(sp)        # Save s0 (64-bit)

    mv s0, a0           # Save argument in s0
    li t0, 1            # Initialize result to 1
    ble s0, t0, done    # If n <= 1, return 1
    
    addi a0, s0, -1     # n - 1
    jal ra, factorial    # Recursive call
    mul a0, a0, s0      # n * factorial(n-1)

done:
    ld s0, 0(sp)        # Restore s0 (64-bit)
    ld ra, 8(sp)        # Restore return address (64-bit)
    addi sp, sp, 16     # Deallocate stack space
    ret                 # Return

exit:
    # Code to exit for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

    # Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

# Stack memory allocation
.section .data
.align 4
stack_bottom:
    .space 1024        # 1KB stack space
stack_top: