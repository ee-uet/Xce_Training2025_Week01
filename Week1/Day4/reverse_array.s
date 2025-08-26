.section .text
.globl _start
_start:
  la t0, array       # Load address of the array into register t0
  li t1, 0           # Initialize t1 to 0 (not used in this snippet, placeholder)
  li t2, 3           # Load the index of the last element of the array into t2

loop:
  blt t2, x0, done   # If t2 < 0 (index below 0), exit loop

  add t4, t0, t2     # Compute address of array[t2] by adding base address t0 + t2
  lb  t3, 0(t4)      # Load byte from memory at address t4 into t3
  addi t2, t2, -1    # Decrement index t2 by 1
  j loop             # Jump back to start of loop

done:
  li t0, 1           # Prepare exit code 1
  la t1, tohost      # Load address of tohost variable
  sd t0, 0(t1)       # Store exit code to tohost (used by spike to terminate)
  nop                # No operation (placeholder)

.section .data
array: .byte 10, 20, 30, 40   # Original array of 4 bytes

.section .tohost
.align 3
tohost: .dword 0             
fromhost: .dword 0            
