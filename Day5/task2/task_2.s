.data
number: .word 0x00000002
position: .word 5
result: .word 0

.global _start
 
.section .text
_start:
    #--------------######################---------------------
    #--------------------This is code region------------------
    la t0, number
    lw a0, 0(t0)
    la t0, position
    lw a1, 0(t0)

    # set bit
    li t3, 1
    sll t3, t3, a1
    or t3, t3, a0 

    # clear bit
    li t4, 1
    sll t4, t4, a1
    not t4, t4
    and t4, t4, t3

    la t0, result
    sw t4, 0(t0)


    #-------------#######################----------------------
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

