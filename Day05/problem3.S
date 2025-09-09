.data
array:  .word 3, 7, 2, 9, 1, 5
size:   .word 6

.text
.global _start

_start:
    la t0, array    # Load address of array
    lw t1, size     # Load size of array
    lw t2, 0(t0)    # Initialize max with first element
    li t3, 1        # Initialize counter to 1
loop:
    addi t0, t0, 4  # Move to next element
    lw t4, 0(t0)    # Load current element
    bge t2, t4, skip # If max >= current, skip update
    mv t2, t4       # Update max
skip:
    addi t3, t3, 1  # Increment counter
    blt t3, t1, loop # If counter < size, continue loop

factorial:
            addi sp, sp, -8 # Allocate stack space
           sw ra, 4(sp) # Save return address
           sw s0, 0(sp) # Save s0

           mv s0, a0 # Save argument in s0
           li t0, 1 # Initialize result to 1
           ble s0, t0, done # If n <= 1, return 1

         addi a0, s0, -1 # n - 1
         jal ra, factorial # Recursive call
        mul a0, a0, s0 # n * factorial(n-1)

done:
        lw s0, 0(sp) # Restore s0
        lw ra, 4(sp) # Restore return address
       addi sp, sp, 8 # Deallocate stack space
        ret # Return