.data
array: .word 10, 6, 3, 2, 9
n: .word 5

.text
.global _start

_start:
    la a0, array            # array address
    lw a1, n                # array length
    
    # Insertion sort
    li t0, 1                # i = 1
outer:
    bge t0, a1, done        # if i >= n, done
    
    slli t1, t0, 2          # i offset
    add t1, a0, t1          # array[i] address
    lw t2, 0(t1)            # key = array[i]
    
    mv t3, t0               # j = i
inner:
    blez t3, insert         # if j <= 0, insert
    
    addi t4, t3, -1          
    slli t4, t4, 2          # (j-1) offset
    add t4, a0, t4          # array[j-1] address
    lw t5, 0(t4)            # array[j-1]
    
    ble t5, t2, insert      # if array[j-1] <= key then insert
    
    sw t5, 0(t1)            # array[j] = array[j-1]
    addi t3, t3, -1         # j--
    addi t1, t1, -4         # move to previous element
    j inner

insert:
    sw t2, 0(t1)            # array[j] = key
    addi t0, t0, 1          # i++
    j outer

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0