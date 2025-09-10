    .global _start

    .section .text
_start:
    la  t0, array          # t0 = base address
    li  t1, 5              # t1 = n (elements)
    jal ra, insertion_sort

exit:
    li  a0, 1
    la  a1, tohost
    sd  a0, 0(a1)
    j   exit

# insertion_sort(base=t0, n=t1)
insertion_sort:
    li  t2, 1              # i = 1
outer:
    bge t2, t1, done       # if i >= n -> done

    # key = A[i]
    slli t3, t2, 2         # t3 = i*4
    add  t4, t0, t3        # t4 = &A[i]
    lw   t5, 0(t4)         # t5 = key

    addi t6, t2, -1        # j = i-1
shift:
    blt  t6, zero, place   # if j < 0 -> place key

    slli s0, t6, 2         # s0 = j*4
    add  s1, t0, s0        # s1 = &A[j]
    lw   s2, 0(s1)         # s2 = A[j]

    ble  s2, t5, place     # if A[j] <= key -> place
    sw   s2, 4(s1)         # A[j+1] = A[j]
    addi t6, t6, -1        # j--
    j    shift

place:
    slli s0, t6, 2         # s0 = j*4
    add  s1, t0, s0        # s1 = &A[j]
    sw   t5, 4(s1)         # A[j+1] = key

    addi t2, t2, 1         # i++
    j    outer

done:
    ret

    .section .data
array: .word 5,3,4,1,2

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
