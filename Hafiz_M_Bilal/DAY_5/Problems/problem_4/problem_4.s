.data
array: .word 1,2,3,4,5
size: .word 5

.global _start
 
.section .text
_start:
    #--------------######################---------------------
    #--------------------This is code region------------------
    
    la a0, array
    la t5, size
    lw a1, 0(t5)         

    addi t0, a1, -1  # size -1 for last address 
    slli a2, t0, 2   # word offset
    add a2, a0, a2   # address of last element
                

loop:
    
    # load data 
    lw a3, 0(a0)        
    lw a4, 0(a2)         

    # store data 
    sw a4, 0(a0)
    sw a3, 0(a2)

    # increment and decrement 
    addi a0, a0, 4       
    addi a2, a2, -4     
    
    # check 
    blt a0, a2, loop

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

