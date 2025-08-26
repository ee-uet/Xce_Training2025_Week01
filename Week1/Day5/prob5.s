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

# ---------------------------
# Print sorted array
# ---------------------------
print_array:
    la t0, array       # base address
    li t1, 6           # number of elements
    li t2, 0           # index

print_loop:
    bge t2, t1, done   # done printing
    slli t3, t2, 2
    add t4, t0, t3
    lw t5, 0(t4)       # load element

    # convert to ASCII (single-digit assumption)
    addi t5, t5, 48
    li t6, 0x10000000
    sb t5, 0(t6)       # write to HTIF

    addi t2, t2, 1
    j print_loop

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
