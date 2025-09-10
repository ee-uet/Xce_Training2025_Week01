.globl _start
    .section .data


array: .word 1,2,3,4,5  # Array to reverse: [1,2,3,4,5] -> [5,4,3,2,1]
size:  .word 5          # Array size (number of elements)

    .section .text

_start:
    # Setup array reversal using two-pointer technique
    la t0, array        # t0 = start pointer (points to first element)
    lw t2, size         # t2 = array size (n = 5)

    # Calculate end pointer (last element address)
    la t1, array        # t1 = base address again
    slli t3, t2, 2      # t3 = n * 4 (convert size to bytes, each word = 4 bytes)
    add t1, t1, t3      # t1 = base + (n * 4) = address past last element
    addi t1, t1, -4     # t1 = address of last element (adjust back by 4)

# Algorithm: Swap elements at start and end, move pointers toward center
# Registers used: t0 (start ptr), t1 (end ptr), t4 (start value), t5 (end value)

loop:
    blt t1, t0, done    # Exit when end pointer < start pointer (pointers crossed)

    # Swap elements pointed to by start and end pointers
    lw t4, 0(t0)        # Load value from start position
    lw t5, 0(t1)        # Load value from end position
    sw t5, 0(t0)        # Store end value at start position
    sw t4, 0(t1)        # Store start value at end position

    # Move pointers toward center
    addi t0, t0, 4      # Move start pointer forward (next element)
    addi t1, t1, -4     # Move end pointer backward (previous element)
    j loop              # Continue until pointers meet


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
