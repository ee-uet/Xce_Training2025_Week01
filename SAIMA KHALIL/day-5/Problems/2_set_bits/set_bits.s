.global _start

.section .text
_start:
    li t0, 0b11010101100101010010101010101010  # any 32-bit number
    li t1, 0          # count of set bits
    li t2, 32         # number of bits to check
 
# Count set bits loop
count_loop: 
    beqz t2, done           # If all bits checked, exit loop
    andi t3, t0, 1          # Extract LSB 
    add t1, t1, t3          # Increment count if bit is set
    srli t0, t0, 1          # Shift right
    addi t2, t2, -1         # Decrement bit counter
    j count_loop

 
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
halt:
    j halt
done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
