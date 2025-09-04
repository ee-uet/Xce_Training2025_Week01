    .section .text
    .global _start

_start:
    

    li t0, 15        
    li t1, 6        

    bge t0, t1, a_ge_b

    sub t2, t1, t0   
    j exit

a_ge_b:
    sub t2, t0, t1   

exit:
    # Spike exit code
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

    j exit           # infinite loop if Spike does not exit

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
/*

    .section .text
    .global _start

_start :
    li t0,15 #a=15
    li t1,6 #b

    bge t0,t1, a_ge_b

    sub t2,t1,t0
    j done

a_ge_b :
    sub t2,t0,t1
done:
    ebreak
    j done

*/