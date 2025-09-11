.global _start
.section .text
_start:
    la t0, array       # Base address of array
    li t1, 16          # Right index offset (last element = 4*4=16 bytes)
    li t2, 0           # Left index offset (first element = 0 bytes)
 
# Reverse array
reverse_loop:
    bge t2, t1, done   # If left >= right 
    
    add t3, t0, t2     # Left element address
    lw t4, 0(t3)       # Load left
    
    add t5, t0, t1     # Right element address
    lw t6, 0(t5)       # Load right
    
    sw t6, 0(t3)       # Swap left
    sw t4, 0(t5)       # Swap right
    
    addi t2, t2, 4
    addi t1, t1, -4
    j reverse_loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .data
array:
    .word 9, 2, 3, 4, 5

.section .tohost
.align 3    
tohost: .dword 0
fromhost: .dword 0
