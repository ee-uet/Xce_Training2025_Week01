    .global _start
    .section .text
_start:
    li a0, 5              # n = 5 
    li t0, 1              # factorial result = 1
    mv t1, a0             # counter = n

factorial_loop:
    beqz t1, factorial_done  # if counter == 0 then exit loop
    mul t0, t0, t1           # result = result * counter
    addi t1, t1, -1          # counter = counter - 1
    j factorial_loop

factorial_done:
    la t2, result
    sd t0, 0(t2)             # store result in memory 

    # program terminate
    li t1, 1
    la t2, tohost
    sd t1, 0(t2)
1:  j 1b                     # infinite loop (terminate)

.section .data
.align 3
result: .dword 0             
.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
