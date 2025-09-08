.globl _start
.section .data
array:
    .word 5, 3, 4, 1, 2         # initial unsorted array

.section .text
_start:
    la t0, array                # base address of array
    li t2, 5                    # array length = 5
    li t1, 1                    # outer loop index i = 1 (insertion sort starts from 2nd element)


outer_loop:
    bge t1, t2, done            # if i >= n → sorting done

    # key = arr[i]
    slli s1, t1, 2              # offset = i * 4
    add s2, t0, s1              # arr[i] address
    lw t3, 0(s2)                # key = arr[i]

    addi t4, t1, -1             # j = i - 1


inner_loop:
    blt t4, zero, insert_key     # if j < 0 → break
    slli s3, t4, 2              # offset = j * 4
    add s4, t0, s3              # arr[j] address
    lw t5, 0(s4)                # load arr[j]

    ble t5, t3, insert_key      # if arr[j] <= key → stop shifting

    sw t5, 4(s4)                # arr[j+1] = arr[j] (shift element right)
    addi t4, t4, -1             # j--
    j inner_loop                # repeat


insert_key:
    slli s3, t4, 2              # offset = j * 4
    add s4, t0, s3              # arr[j] address
    sw t3, 4(s4)                # arr[j+1] = key

    addi t1, t1, 1              # i++
    j outer_loop                # next iteration


done:
   
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b                        

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0

