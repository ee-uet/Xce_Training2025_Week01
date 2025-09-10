.section .text
.global _start
_start:
    call main        # Call your main function
    li a0, 0         # Return code 0
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)      # Signal Spike to exit
1:  j 1b             # Infinite loop if exit fails

.section .tohost
.align 3
.globl tohost
.globl fromhost

tohost:   .dword 0
fromhost: .dword 0

