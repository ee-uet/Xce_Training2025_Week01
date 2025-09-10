
.global _start
 
.section .text
_start:
    #--------------######################---------------------
    #--------------------This is code region------------------
    
    li a0, 0b101101     
    li t0, 0            

loop:
   
    andi t1, a0, 1      
    add t0, t0, t1      
    srli a0, a0, 1     
    bnez a0, loop


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

