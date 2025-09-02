.global _start
 
.section .text
_start:
    # Any code here
    
    # void insertion_sort(int *arr, int n)
# a0 = base address of array
# a1 = number of elements

insertion_sort:
    addi t0, x0, 1         # i = 1

outer_loop:
    bge  t0, a1, done      # if i >= n, stop

    # key = arr[i]
    slli t1, t0, 2         # offset = i*4
    add  t2, a0, t1        # &arr[i]
    lw   t3, 0(t2)         # key = arr[i]

    addi t4, t0, -1        # j = i-1

inner_loop:
    blt  t4, x0, insert    # if j < 0, break

    # load arr[j]
    slli t5, t4, 2
    add  t6, a0, t5
    lw   t7, 0(t6)         # arr[j]

    ble  t7, t3, insert    # if arr[j] <= key, break

    # shift arr[j] -> arr[j+1]
    sw   t7, 4(t6)

    addi t4, t4, -1        # j--
    j    inner_loop

insert:
    addi t4, t4, 1         # j+1
    slli t5, t4, 2
    add  t6, a0, t5
    sw   t3, 0(t6)         # arr[j+1] = key

    addi t0, t0, 1         # i++
    j    outer_loop

done:
    ret



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
