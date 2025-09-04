    .section .text
    .globl _start

_start:
    

    li t0, 5       
    li t1, 1        

loop:
    beqz t0, exit   
    mul  t1, t1, t0 
    addi t0, t0, -1 
    j    loop

exit:
    # Spike exit code
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

    j exit          # infinite loop if Spike does not exit

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
/*
    .section .text
    .globl _start

_start:
    li   t0, 5        
    li   t1, 1        

loop:
    beqz t0, done     
    mul  t1, t1, t0  
    addi t0, t0, -1  
    j    loop         

done:
    ebreak
    j done            
*/