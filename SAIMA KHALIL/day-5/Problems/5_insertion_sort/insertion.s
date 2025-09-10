.global _start
.section .text
_start:
    la t0, array       # base address of array
    li t1, 6           # number of elements
    li t2, 1           # i = 1
 
outer_loop:
    bge t2, t1, done   # if i >= n → go print

    slli a0, t2, 2 # i*4
    add a1, t0, a0
    lw a2, 0(a1)       # key

    addi a3, t2, -1    # j = i-1

inner_loop:
    blt a3, x0, insert
    slli a4, a3, 2
    add a5, t0, a4
    lw a6, 0(a5)

    bge a2, a6, insert

    sw a6, 4(a5)
    addi a3, a3, -1
    j inner_loop

insert:
    addi a3, a3, 1
    slli a4, a3, 2
    add a5, t0, a4
    sw a2, 0(a5)

    addi t2, t2, 1
    j outer_loop
 
 

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .data
array:
    .word 5, 2, 9, 1, 5, 6

.section .tohost
.align 3
tohost:    .dword 0
fromhost:  .dword 0
