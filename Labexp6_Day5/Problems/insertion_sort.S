# RISC-V Insertion Sort Algorithm
# Sorts array in ascending order using insertion sort

.data
array:  .word 7, 3, 5, 2, 9, 1   # Unsorted array
n:      .word 6                  # Number of elements

.text
.globl _start

_start:
    # Initialize base address and size
    la   s0, array          # s0 = base address of array
    la   t0, n
    lw   s1, 0(t0)          # s1 = n = 6
    
    # Start outer loop with i = 1
    addi s2, x0, 1          # s2 = i = 1 (start from second element)

outer_loop:
    bge  s2, s1, done       # If i >= n, sorting is complete
    
    # Get current key = array[i]
    slli t1, s2, 2          # t1 = i * 4 (word offset)
    add  t2, s0, t1         # t2 = address of array[i]
    lw   t3, 0(t2)          # t3 = key = array[i]
    
    # Initialize inner loop index j = i - 1
    addi s3, s2, -1         # s3 = j = i - 1

inner_loop:
    blt  s3, x0, insert     # If j < 0, insert key at position j+1
    
    # Compare array[j] with key
    slli t4, s3, 2          # t4 = j * 4
    add  t5, s0, t4         # t5 = address of array[j]
    lw   t6, 0(t5)          # t6 = array[j]
    ble  t6, t3, insert     # If array[j] <= key, insert key
    
    # Shift element: array[j+1] = array[j]
    sw   t6, 4(t5)          # Store array[j] at position j+1
    
    # Move to previous element
    addi s3, s3, -1         # j--
    j    inner_loop

insert:
    # Insert key at correct position: array[j+1] = key
    addi s3, s3, 1          # Position = j + 1
    slli t4, s3, 2          # Calculate offset
    add  t5, s0, t4         # Get address
    sw   t3, 0(t5)          # Store key
    
    # Move to next element in outer loop
    addi s2, s2, 1          # i++
    j    outer_loop

done:
    # Array is now sorted: [1, 2, 3, 5, 7, 9]
    
    # Exit for spike pk
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
