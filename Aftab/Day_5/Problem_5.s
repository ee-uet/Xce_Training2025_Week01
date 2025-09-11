.global _start

.section .data
array: .word 4,8,3,9,1,7
size: .word 6

.section .text

_start:
    la t2, array        # array starting address
    la t3, size
    lw t4, 0(t3)        # array size
    li t5, 1            # i = 1 (outer loop counter)

outer_loop:
    bge t5, t4, exit    # if i >= size, exit

    # Load array[i] into a2
    slli s0, t5, 2      # i * 4 (word offset)
    add  a1, t2, s0     # address of array[i]
    lw   a2, 0(a1)      # a2 = array[i] (key)

    addi t6, t5, -1     # j = i - 1 (inner loop counter)

inner_loop:
    blt  t6, zero, insert_key  # if j < 0, exit inner loop

    # Load array[j] into a4
    slli s1, t6, 2      # j * 4
    add  a3, t2, s1     # address of array[j]
    lw   a4, 0(a3)      # a4 = array[j]

    ble  a4, a2, insert_key  # if array[j] <= key, exit inner loop

    # Shift array[j] to array[j+1]
    addi a5, t6, 1      # j + 1
    slli s2, a5, 2      # (j+1) * 4
    add  a6, t2, s2     # address of array[j+1]
    sw   a4, 0(a6)      # array[j+1] = array[j]

    addi t6, t6, -1     # j = j - 1
    j inner_loop

insert_key:
    # Store key at array[j+1]
    addi a5, t6, 1      # j + 1
    slli s2, a5, 2      # (j+1) * 4
    add a6, t2, s2      # address of array[j+1]
    sw a2, 0(a6)        # array[j+1] = key

    addi t5, t5, 1      # i = i + 1
    j outer_loop

exit:
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
