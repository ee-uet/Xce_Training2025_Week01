.data
array:  .word 5, 3, 4, 1, 2
size:   .word 5

.global _start
 
.section .text
_start:

#--------------######################---------------------
#--------------------This is code region------------------
 
    la a0, array
    la t0, size
    lw a1, 0(t0)

    addi t1, a0, 4  # 2nd element address
    addi t2, a1, -1 # for outer loop iterations (size -1)

outer_loop:
    beqz t2, finish

    lw t3, 0(t1) # load element 
    mv t4, t1    # address 

inner_loop:
    beq t4, a0, insert
    addi t5, t4, -4
    lw t6, 0(t5)
    ble t6, t3, insert
    sw t6, 0(t4)
    mv t4, t5
    j inner_loop

insert:
    sw t3, 0(t4)
    addi t1, t1, 4
    addi t2, t2, -1
    j outer_loop

#-------------#######################----------------------

finish:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
