.global _start

.section .text
my_number: .word 4

_start: 
    la x5, my_number      
    lw x1, 0(x5)       # x1 = number
    addi x4, x1, -1    # x4 = number - 1

loop:
    mul x1, x1, x4     # x1 = x1 * x4
    addi x4, x4, -1    # x4 -= 1
    blt zero, x4, loop # branch to loop if x4 > 0

done:

    # Signal test pass to Spike
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

# Loop forever
1: j 1b

.section .data
message:
    .string "Hello, World!\n"

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
