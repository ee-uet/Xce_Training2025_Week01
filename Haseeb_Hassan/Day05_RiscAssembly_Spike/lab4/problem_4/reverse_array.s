    .global _start

    .section .text
_start:
    la t0, array          # base address of array
    li t1, 5              # number of elements

    addi t2, t1, -1       # passes = n-1
outer_loop:
    blez t2, done         # if passes <= 0, stop

    li t3, 1              # i = 1 (start from 2nd element)
inner_loop:
    bge t3, t1, next_pass # if i >= n, go to next pass

    # --- key = A[i] ---
    slli t4, t3, 2        # offset = i*4
    add t5, t0, t4        # address = base + offset
    lw t6, 0(t5)          # key = A[i]

    addi t7, t3, -1       # j = i-1

shift_loop:
    blt t7, zero, insert  # if j < 0, insert key

    # load A[j]
    slli t8, t7, 2        # offset = j*4
    add t9, t0, t8        # addr = base + offset
    lw t4, 0(t9)          # t4 = A[j]

    ble t4, t6, insert    # if A[j] <= key, insert

    # shift A[j] → A[j+1]
    sw t4, 4(t9)          # store at addr+4

    addi t7, t7, -1       # j--
    j shift_loop

insert:
    slli t8, t7, 2
    add t9, t0, t8
    sw t6, 4(t9)          # A[j+1] = key

    addi t3, t3, 1        # i++
    j inner_loop

next_pass:
    addi t2, t2, -1       # passes--
    j outer_loop

done:
    # Spike exit code
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

    j done                # infinite loop

    .section .data
array:  .word 5,3,4,1,2   # unsorted array

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
