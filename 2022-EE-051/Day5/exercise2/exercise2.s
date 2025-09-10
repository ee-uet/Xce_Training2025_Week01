.global _start
.section .text
_start:

    li a0, 0b11001010101100101010101010101010  # 32-bit number
    li a1, 0              # initialize counter

loop: 
    
    # If a0 == 0, all bits processed and go to 'done'
    beqz a0, done           
    addi a1, a1, 1        
    addi t0, a0, -1        
    and  a0, a0, t0    # Update a0 = a0 & (a0 - 1) removes the lowest set bit
    # Repeat until no more '1' bits   
    j loop                 

done:
    la t1, result
    sd a1, 0(t1)

    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

    # Loop forever if spike does not exit
1:  j 1b

.section .data
.align 3
result: .dword 0

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
