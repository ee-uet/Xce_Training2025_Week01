.globl _start

.section .text
_start:

#--------------######################---------------------
#--------------------This is code region------------------
    li t0,37    # Dividend(Q)
    li t1,5     # Divisor(M)
    li t2,0     # Remainder(A)
    li a2,32    # Number of bits 

    li t6,1         
    slli t6,t6,63   # MSB is set for checking sign of A

loop:
    #check
    ble a2,zero,exit

    slli t3,t2,32   # A shifted by 32 bits left
    add t3,t3,t0    # Combine AQ
    slli t3,t3,1    # Combine left shift AQ 

    slli t4,t1,32   # M shifted left by 32 bits & rest are zero.
    sub t5,t3,t4    # A-M at upper 32 bits and Q remains unchanged

    and a0,t5,t6

    # MSB will be set if A is -ve    
    
    beq a0,t6,label
    ori t5,t5,1
    j update

label:
    mv t5,t3

update:
    srli t2,t5,32   # Update A
    slli t0,t5,32
    srli t0,t0,32   # Upade Q

    addi a2,a2,-1
    j loop

#-------------#######################----------------------
exit:
    # Done, exit via tohost
    li a0, 1
    la a1, tohost
    sd a0, 0(a1)


1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

