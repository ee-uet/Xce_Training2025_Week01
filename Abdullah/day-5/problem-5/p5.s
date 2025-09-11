    .globl _start
    .section .data

array: .word 4,5,3,6,1,2     
size:  .word 6              

    .section .text
_start:

    la t0, array        
    lw t1, size         
    li t2, 1            # t2 = outer loop index (i = 1, start from 2nd element)


outer_loop:
    
    bge t2, t1, done    # Exit if i >= size (all elements processed)
    
    
    la t3, array        
    slli t4, t2, 2      # t4 = i * 4 (convert index to byte offset)
    add t3, t3, t4      
    lw t5, 0(t3)        # t5 = arr[i] (key value to insert)

    
    addi t6, t2, -1     # t6 = j = i - 1 


inner_loop:
    
    blt t6, zero, insert    # If j < 0, insert at beginning of array
    
    # Get arr[j] for comparison
    la s0, array        
    slli s1, t6, 2      # s1 = j * 4 (convert index to byte offset)
    add s0, s0, s1      # s0 = address of arr[j]
    lw s2, 0(s0)        # s2 = arr[j] (element to compare)
    
    ble s2, t5, insert  # If arr[j] <= key, found insertion position
    
    
    sw s2, 4(s0)        # Store arr[j] at position j+1
    addi t6, t6, -1     # j-- (move to previous element)
    j inner_loop        # Continue searching for position



insert:
    # Insert key at position j+1
    la s0, array        
    addi t6, t6, 1      # t6 = j + 1 (insertion position)
    slli s1, t6, 2      
    add s0, s0, s1      
    sw t5, 0(s0)        # arr[j+1] = key (insert the key)

    # Move to next element in outer loop
    addi t2, t2, 1      # i++ (process next element)
    j outer_loop        

done:
    # Code to exit for Spike    
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
