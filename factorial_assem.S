    .data
n:      .word 5       
result: .word 0       

    .text
    .globl _start

_start:
    
    la   t0, n
    lw   a0, 0(t0)       

   
    jal  ra, factorial

    
    la   t1, result
    sw   a0, 0(t1)

   
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


factorial:
    li   t0, 1           
    mv   t1, a0        

fact_loop:
    beq  t1, x0, fact_done  
    mul  t0, t0, t1        
    addi t1, t1, -1       
    j    fact_loop

fact_done:
    mv   a0, t0          
    ret