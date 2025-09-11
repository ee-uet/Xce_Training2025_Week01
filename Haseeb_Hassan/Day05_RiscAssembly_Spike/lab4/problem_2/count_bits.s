    .section .text
    .global _start

_start:
    

    li t0, 0b101101   
    li t1, 0         
    li t2, 32         

loop:
    andi t3, t0, 1    
    add  t1, t1, t3   
    srli t0, t0, 1    
    addi t2, t2, -1   
    bnez t2, loop     

exit:
    # Spike exit code
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

    j exit            # infinite loop if Spike does not exit

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
/*

    .section .text
    .global _start

_start:
    li t0, 0b101101
    li t1,0
    li t2,32

loop:
    andi t3 ,t0,1
    add t1,t1,t3
    srli t0,t0,1
    addi t2,t2, -1
    bnez t2, loop
done:
    ebreak
    j done
    */