# RISC-V Array Reversal Program
# Reverses an array of integers in-place

.data
array:  .word 1, 2, 3, 4, 5    # Input array [1,2,3,4,5]
n:      .word 5                # Array size

.text
.globl _start

_start:
    # Load array base address
    la   t0, array     
    
    # Load array size
    la   t1, n
    lw   t1, 0(t1)       # t1 = n = 5
   
    # Initialize indices
    addi t2, x0, 0       # t2 = left index = 0
    add  t3, t1, x0      # t3 = right index = n
    addi t3, t3, -1      # t3 = n-1 = 4
    
rev_loop:
    # Check if indices have crossed
    bge  t2, t3, done    # If left >= right, array is reversed
  
    # Calculate address of left element
    slli t4, t2, 2       # t4 = left_index * 4 (word size)
    add  t5, t0, t4      # t5 = base + offset
    lw   t6, 0(t5)       # t6 = array[left]
  
    # Calculate address of right element
    slli t4, t3, 2       # t4 = right_index * 4
    add  t7, t0, t4      # t7 = base + offset
    lw   t8, 0(t7)       # t8 = array[right]
    
    # Swap elements
    sw   t8, 0(t5)       # array[left] = array[right]
    sw   t6, 0(t7)       # array[right] = array[left]
   
    # Move indices toward center
    addi t2, t2, 1       # left++
    addi t3, t3, -1      # right--
    j    rev_loop        # Continue loop
    
done:
    # Array is now reversed: [5,4,3,2,1]
    
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
