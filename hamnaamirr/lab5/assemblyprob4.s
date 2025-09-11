.section .text
.globl _start
_start:
    la t0, array       
    li t1, 0    #starting index 
    la x2,n     
    lw x1, 0(x2)  #value of n
    addi t2,x1,-1   # n-1 (last index)     

loop:
    blt t2, t1, done   # if end < start, done

    # Load 
    add t3, t0, t1    
    lb  t4, 0(t3)      

    add t5, t0, t2    
    lb  t6, 0(t5)     

    # Swap
    sb t6, 0(t3)       
    sb t4, 0(t5)      

    addi t1, t1, 1     # start++
    addi t2, t2, -1    # end--
    j loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
    nop

.section .data
array: .byte 10, 20, 30, 40
n: .byte 4

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
