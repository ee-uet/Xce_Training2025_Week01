.global _start
.section .text
_start:
    li t0, 6         # Number to calculate factorial (5! = 120)
    li t1, 1          # Result
    li t2, 1          # Counter

factorial_loop:
    bgt t2, t0, done
    mul t1, t1, t2
    addi t2, t2, 1
    j factorial_loop

done:
    # Signal test pass
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .tohost
.align 3    
tohost: .dword 0
fromhost: .dword 0
