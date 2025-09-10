.global _start
 
.section .text
_start:
    la a0, array #starting address of array
    la a1, array_size
    addi a1, a1, -4 # address of last element
    jal reverse_array

    
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    
1:  j 1b

reverse_array:
    mv t3, a0 # save start address of array

while:
    bge a0, a1, return
    lw t0, 0(a0) 
    lw t1, 0(a1)
    sw t0, 0(a1)
    sw t1, 0(a0)
    addi a0, a0, 4
    addi a1, a1, -4
    j while
return:
    ret
    
.section .data

array: .word 1,2,3,4,5
array_size: .word 5
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0