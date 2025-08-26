    .globl _start
    .section .data

array: .word 4,5,3,6,1,2
size:  .word 6

    .section .text
_start:
    la t0, array        # t0 = start pointer
    lw t1, size         # t2 = array size (n)

    li t2, 1               #i=1

outer_loop:
    bge t2, t1, done
    la t3, array
    slli t4, t2, 2
    add t3, t3, t4
    lw t5, 0(t3)

    addi t6, t2, -1     #j = i-1


inner_loop:
    bge t6, zero, insert
    la s0, array        #A[j]
    slli s1, t6, 2      #j*2

    add s0, s0, s1      
    lw s2, 0(s0)

    ble s2, t5, insert

    sw s2, 4(s0)
    addi t6, t6, -1
    
    j inner_loop

insert:
    la s0, array
    add t6, t6, 1
    slli s1, t6, 2
    add s0, s0, s1
    sw t5, 0(s0)

    addi t2, t2, 1 
    j outer_loop

done:
    # Code to exit for Spike    
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
