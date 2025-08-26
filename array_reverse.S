    .data
array:  .word 1, 2, 3, 4, 5    
n:      .word 5                

    .text
    .globl _start

_start:
    
    la   t0, array     

    # load n
    la   t1, n
    lw   t1, 0(t1)       

   
    addi t2, x0, 0      
    add  t3, t1, x0      
    addi t3, t3, -1      

rev_loop:
    bge  t2, t3, done       

  
    slli t4, t2, 2     
    add  t5, t0, t4
    lw   t6, 0(t5)      

  
    slli t4, t3, 2     
    add  t7, t0, t4
    lw   t8, 0(t7)       

    
    sw   t8, 0(t5)      
    sw   t6, 0(t7)    
   
    addi t2, t2, 1
    addi t3, t3, -1
    j    rev_loop
done:
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