.data
array:  .word 5, 3, 4, 1, 2    # Array to be sorted
size:   .word 5                 # Number of elements in array

.global _start
 
.section .text
_start:
    # Initialize array pointer and size
    la a0, array                # Load address of array into a0
    la t0, size                 # Load address of size variable
    lw a1, 0(t0)                # Load actual size value into a1

    addi t1, a0, 4              # t1 = address of 2nd element (current element pointer)
    addi t2, a1, -1             # t2 = outer loop counter (size - 1)

outer_loop:
    beqz t2, finish             # If outer loop counter == 0, sorting is done

    lw t3, 0(t1)                # t3 = current element value to be inserted
    mv t4, t1                   # t4 = current position pointer 

inner_loop:
    beq t4, a0, insert          # If we reached start of array, insert element
    addi t5, t4, -4             # t5 = address of previous element
    lw t6, 0(t5)                # t6 = value of previous element
    ble t6, t3, insert          # If previous element <= current, found insertion point
    sw t6, 0(t4)                # Shift previous element to current position
    mv t4, t5                   # Move current pointer backward
    j inner_loop                # Continue inner loop

insert:
    sw t3, 0(t4)                # Insert current element at correct position
    addi t1, t1, 4              # Move to next element in array
    addi t2, t2, -1             # Decrement outer loop counter
    j outer_loop                

finish:
   
    li t0, 1                    
    la t1, tohost               
    sd t0, (t1)                

1:  j 1b                 

.section .tohost
.align 3
tohost: .dword 0               
fromhost: .dword 0             
