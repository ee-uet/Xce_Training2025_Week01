.global _start
 
.section .text
_start:
    la a0, array
    la a1, array_size
    lw a1, 0(a1) # a1 = array size = 5

    li t0, -4
    li t1, 0
    li s0, 0
    jal ra, insertion_sort
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    
1:  j 1b
    

insertion_sort:
    li t6, 1
    addi s0, s0, 1
    bge s0, a1, return
    
    addi t0, t0, 4
    addi t1, t1, 4

    add t2, a0, t0  
    add t3, a0, t1 
for_loop:
    
    lw t4, 0(t2) #t2 = 1st element
    lw t5, 0(t3) #t1 - 2nd element
    bgt t4, t5, sort
here:
    beq s0, t6, insertion_sort
    addi t6, t6, 1
    addi t2, t2, -4
    addi t3, t3, -4
    j for_loop

sort:
    sw t4, 0(t3)
    sw t5, 0(t2)
    j here
    

return:
    ret

.section .data
array: .word 5,4,3,2,1
array_size: .word 5
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0