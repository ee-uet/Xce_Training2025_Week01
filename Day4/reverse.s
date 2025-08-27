.data
array:  .word 1, 2, 3, 4, 5, 6         # array of 5 integer     


.section .text
.global _start

_start:

    la a0, array        # points to the first integer (start)
    li a1, 6            # array size
    addi a1, a1, -1     # last index    
    slli a1, a1, 2      # convert index to byte offset
    add a2, a0, a1      # points to the end of array (end)

    loop:
        bge a0, a2, done        # if a0 >= a2 then jump to done        
        lw t0, 0(a0)            # load start in t0
        lw t1, 0(a2)            # load end in t1
        sw t1, 0(a0)            # store end at start
        sw t0, 0(a2)            # store start at end
        addi a0, a0, 4          # start++ 
        addi a2, a2, -4         # end++
        j loop

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
