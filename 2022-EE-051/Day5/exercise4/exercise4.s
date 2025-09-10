    .section .text
    .globl _start

_start:
    la t0, array        # t0 = base address of array
    li t1, 0            # t1 = start index (i = 0)
    li t2, 3            # t2 = end index   (j = 3 for 4 elements)

loop:
    bge t1, t2, done    # if i >= j, stop (array fully reversed)

    # Calculate address of array[i], t3
    add t3, t0, t1
    lb  t4, 0(t3)       # t4 = array[i]

    # Calculate address of array[j], t5
    add t5, t0, t2
    lb  t6, 0(t5)       # t6 = array[j]

    # Swap array[i] and array[j]
    sb  t6, 0(t3)       # array[i] = t6
    sb  t4, 0(t5)       # array[j] = t4

    addi t1, t1, 1      # i++
    addi t2, t2, -1     # j--
    j loop              # repeat

done:
    li t0, 1            
    la t1, tohost
    sd t0, 0(t1)        
    nop

    .section .data
array: 
    .byte 10, 20, 30, 40    # array to reverse 

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
