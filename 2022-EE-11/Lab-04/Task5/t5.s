.section .data
# Test data for array operations
test_array: .word 64, 34, 25, 12, 22, 11, 90, 5
array_size: .word 8
newline:    .string "\n"                 # Newline character for output

.global _start

.section .text

_start:
    	# Test insertion sort
	la a0, test_array       # Load address of test array
	lw a1, array_size       # Load size
	jal insertion_sort
	jal print
    
    	# Code to exit for Spike (DONT REMOVE IT)
	li t0, 1
	la t1, tohost
	sd t0, (t1)

print:
    # Load array base address and size
    la   t0, test_array          # t0 = base address of array
    lw   t1, array_size     	 # t1 = array size
    li   t2, 0           	# t2 = loop counter (i = 0)

loop:
    # Check if we've processed all elements
    bge  t2, t1, exit       # if i >= array_size, exit loop
    
    # Calculate address of current element: base + (i * 4)
    slli t3, t2, 2          # t3 = i * 4 (shift left by 2 bits)
    add  t4, t0, t3         # t4 = base address + offset
    lw   t5, 0(t4)          # t5 = array[i]
    
    # Print the current element
    mv   a0, t5             

    # Increment loop counter
    addi t2, t2, 1          # i++
    j    loop               # Jump back to beginning of loop

exit:
    # Exit program
    ret

insertion_sort:
    # Handle edge cases
    li t0, 2
    blt a1, t0, sort_done   # If size < 2, already sorted
    
    # Initialize outer loop
    li t0, 1                # t0 = i (current index, start from 1)
    
outer_loop:
    bge t0, a1, sort_done   # If i >= size, done
    
    # Calculate address of current element
    slli t1, t0, 2          # t1 = i * 4
    add t1, a0, t1          # t1 = address of arr[i]
    lw t2, 0(t1)            # t2 = key = arr[i]
    
    # Initialize inner loop
    addi t3, t0, -1         # t3 = j = i - 1
    
inner_loop:
    bltz t3, insert_key     # If j < 0, insert key
    
    # Calculate address of arr[j]
    slli t4, t3, 2          # t4 = j * 4
    add t4, a0, t4          # t4 = address of arr[j]
    lw t5, 0(t4)            # t5 = arr[j]
    
    # Compare arr[j] with key
    ble t5, t2, insert_key  # If arr[j] <= key, insert key
    
    # Move arr[j] to arr[j+1]
    addi t6, t4, 4          # t6 = address of arr[j+1]
    sw t5, 0(t6)            # arr[j+1] = arr[j]
    
    # Decrement j
    addi t3, t3, -1         # j--
    j inner_loop

insert_key:
    # Insert key at position j+1
    addi t3, t3, 1          # j + 1
    slli t4, t3, 2          # (j+1) * 4
    add t4, a0, t4          # address of arr[j+1]
    sw t2, 0(t4)            # arr[j+1] = key
    
    # Increment i for outer loop
    addi t0, t0, 1          # i++
    j outer_loop

sort_done:
    ret
    

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
