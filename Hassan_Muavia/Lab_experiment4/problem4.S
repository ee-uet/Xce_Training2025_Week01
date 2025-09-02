.global _start
 
.section .text
_start:
    # Any code here
    # void reverse(int *arr, int n)
# a0 = base address of array
# a1 = number of elements

reverse:
    addi t0, x0, 0        # i = 0
    addi t1, a1, -1       # j = n - 1

loop:
    bge  t0, t1, done     # if i >= j, exit loop

    # Load arr[i] into t2
    slli t3, t0, 2        # t3 = i * 4 (word offset)
    add  t3, a0, t3       # t3 = &arr[i]
    lw   t2, 0(t3)        # t2 = arr[i]

    # Load arr[j] into t4
    slli t4, t1, 2        # t4 = j * 4
    add  t4, a0, t4       # t4 = &arr[j]
    lw   t5, 0(t4)        # t5 = arr[j]

    # Swap arr[i] and arr[j]
    sw   t5, 0(t3)        # arr[i] = t5
    sw   t2, 0(t4)        # arr[j] = t2

    # Update i and j
    addi t0, t0, 1        # i++
    addi t1, t1, -1       # j--
    j    loop             # repeat

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
