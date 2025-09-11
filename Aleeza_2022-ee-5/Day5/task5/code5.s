.global _start
.section .text
      # index

_start:
    # Array setup
    la t0, array       # t0 points to start of array
    li t1, 6           # t1 = number of elements
    li t2, 1           # t2 = i = 1 (start from second element)

outer_loop:
    bge t2, t1, done   # if i >= number of elements, sorting done

    # Load key = array[i]
    slli a0, t2, 2     # a0 = i * 4 (byte offset)
    add a1, t0, a0     # a1 = location of ith index
    lw a2, 0(a1)       # a2 = element (array[i])

    # Set j = i-1
    addi a3, t2, -1    # a3 = i-1 (for inner loop)

inner_loop:
    blt a3, x0, insert # if j < 0, go insert key (if there's no more element left to check at left side)
    slli a4, a3, 2     # j (i-1) *4
    add a5, t0, a4     # a5 = position of jth element
    lw a6, 0(a5)       # a6 = array[j]

    bge a2, a6, insert # if array[i] >= array[j], insert here

    sw a6, 4(a5)       # shift array[j] to right
    addi a3, a3, -1    # now go to the previous index
    j inner_loop

insert:                # to insert
    addi a3, a3, 1     # a3 = j+1 = i
    slli a4, a3, 2     # a4 = i*4
    add a5, t0, a4     # a5 = location of ith element
    sw a2, 0(a5)       # insert key (store that element to its original place)

    addi t2, t2, 1     # increment index ( i=i+1 )
    j outer_loop       # jump to outer loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .data
array:
    .word 5, 2, 9, 1, 5, 6

.section .tohost
.align 3
tohost:    .dword 0
fromhost:  .dword 0
