
.global _start
 
.section .text
_start:
    #--------------######################---------------------
    #--------------------This is code region------------------
 
    li a0, 15       
    li a1, 10       
    sub a2, a0, a1  
    
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

