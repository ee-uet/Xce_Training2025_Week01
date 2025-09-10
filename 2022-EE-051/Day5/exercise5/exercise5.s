.global _start
.section .text
_start:
    la   t0, array        # base address of array
    li   t1, 5            # length of array
    li   t2, 1            # i = 1 (start from second element)

outer_loop:
    bge  t2, t1, done     # if i >= n, done
    slli t3, t2, 3        # offset = i * 8
    add  t4, t0, t3       # addr = base + offset
    ld   t5, 0(t4)        # key = array[i]
    addi t6, t2, -1       # j = i - 1

inner_loop:
    blt  t6, zero, insert_key    # if j < 0, insert key
    slli s2, t6, 3               # offset = j * 8
    add  s3, t0, s2              # addr = base + offset
    ld   s4, 0(s3)               # temp = array[j]

    ble  s4, t5, insert_key      # if array[j] <= key, stop shifting

    addi s5, s3, 8               # addr(j+1)
    sd   s4, 0(s5)               # array[j+1] = array[j]
    addi t6, t6, -1              # j--
    j inner_loop

insert_key:
    slli s2, t6, 3
    add  s3, t0, s2
    addi s3, s3, 8               # addr(j+1)
    sd   t5, 0(s3)               # array[j+1] = key
    addi t2, t2, 1               # i++
    j outer_loop

done:
    li   t1, 1
    la   t2, tohost
    sd   t1, 0(t2)               
1:  j    1b                      # infinite loop

.section .data
.align 3
array: .dword 5, 3, 4, 1, 2       # unsorted array

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
