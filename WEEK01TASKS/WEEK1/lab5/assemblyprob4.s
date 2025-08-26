.section .text
.globl _start
_start:
    la t0, array       
    li t1, 0     
    la x2,n     
    lw x1, 0(x2)  
    addi t2,x1,-1        

loop:
    blt t2, t1, done   # if end < start, done

    # Load bytes to swap
    add t3, t0, t1     # address of array[start]
    lb  t4, 0(t3)      # t4 = array[start]

    add t5, t0, t2     # address of array[end]
    lb  t6, 0(t5)      # t6 = array[end]

    # Swap
    sb t6, 0(t3)       # array[start] = array[end]
    sb t4, 0(t5)       # array[end] = array[start]

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
