.section .text

_start:
    	# Test factorial function
    	li a0, 5            # Calculate factorial of 5
    	jal factorial
    	mv t0, a0           # Store result (should be 120)
    	
    	# Code to exit for Spike (DONT REMOVE IT)
	li t0, 1
	la t1, tohost
	sd t0, (t1)

    	
factorial:
    # Handle edge cases
    li t0, 1
    blez a0, fact_return_one    # If n <= 0, return 1
    beq a0, t0, fact_return_one # If n == 1, return 1
    
    # Initialize for iterative calculation
    mv t1, a0           # t1 = n (counter)
    li t2, 1            # t2 = result (accumulator)
    
fact_loop:
    mul t2, t2, t1      # result = result * counter
    addi t1, t1, -1     # counter--
    bnez t1, fact_loop  # Continue if counter != 0
    
    mv a0, t2           # Return result
    ret

fact_return_one:
    li a0, 1
    ret


# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0





