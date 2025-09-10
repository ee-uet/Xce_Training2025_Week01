.section .data

reverse_array: .word 1, 2, 3, 4, 5, 6, 7, 8
reverse_size: .word 8

.global _start

.section .text

_start:
	# Test array reverse
	la a0, reverse_array    # Load address of array
	lw a1, reverse_size     # Load size
	jal reverse_array_func
	jal print
    
	# Code to exit for Spike (DONT REMOVE IT)
	li t0, 1
	la t1, tohost
	sd t0, (t1)

print:
    # Load array base address and size
    la   t0, reverse_array          # t0 = base address of array
    lw   t1, reverse_size     	 # t1 = array size
    li   t2, 0           	# t2 = loop counter (i = 0)

loop:
    # Check if we've processed all elements
    bge  t2, t1, exit       # if i >= array_size, exit loop
    
    # Calculate address of current element: base + (i * 4)
    slli t3, t2, 2          # t3 = i * 4 (shift left by 2 bits)
    add  t4, t0, t3         # t4 = base address + offset
    lw   t5, 0(t4)          # t5 = array[i]
    
    # Print the current element
    mv   a0, t5             # Move array element to a0 for printing
    
    # Increment loop counter
    addi t2, t2, 1          # i++
    j    loop               # Jump back to beginning of loop

exit:
    # Exit program
    ret

reverse_array_func:
    # Handle edge cases
    li t0, 2
    blt a1, t0, reverse_done    # If size < 2, nothing to do
    
    # Initialize pointers
    mv t0, a0               # t0 = start pointer (left)
    addi t1, a1, -1         # t1 = size - 1
    slli t1, t1, 2          # t1 = (size-1) * 4 (byte offset)
    add t1, a0, t1          # t1 = end pointer (right)
    
reverse_loop:
    # Check if pointers have crossed
    bgeu t0, t1, reverse_done
    
    # Load values
    lw t2, 0(t0)            # t2 = left value
    lw t3, 0(t1)            # t3 = right value
    
    # Swap values
    sw t3, 0(t0)            # store right value at left position
    sw t2, 0(t1)            # store left value at right position
    
    # Move pointers
    addi t0, t0, 4          # left pointer++
    addi t1, t1, -4         # right pointer--
    
    j reverse_loop

reverse_done:
    ret

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0    


