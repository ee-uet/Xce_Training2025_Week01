.data
number: .word 0x00000002    # Input number: 2 (binary: ...00000010)
position: .word 5           # Bit position to manipulate (bit 5)
result: .word 0             # Storage for final result

.global _start
 
.section .text
_start:

    # Load input values from memory
    la t0, number           # Load address of number
    lw a0, 0(t0)           # a0 = input number (0x00000002)
    la t0, position         # Load address of position
    lw a1, 0(t0)           # a1 = bit position (5)


    li t3, 1               # Load 1
    sll t3, t3, a1         # t3 = 1 << position = 0x00000020 (bit 5 set)
    or t3, t3, a0          # t3 = original | mask = set bit operation result
    # Result: 0x00000002 | 0x00000020 = 0x00000022


    li t4, 1               # Load constant 1
    sll t4, t4, a1         # t4 = 1 << position = 0x00000020 (bit 5 set)
    not t4, t4             # t4 = ~(1 << position) = 0xFFFFFFDF (bit 5 clear)
    and t4, t4, t3         # t4 = set_result & inverted_mask = clear bit result
    # Result: 0x00000022 & 0xFFFFFFDF = 0x00000002


    # Store the clear operation result (back to original value)
    la t0, result          # Load address of result storage
    sw t4, 0(t0)           # Store final result to memory
    # Final result should be 0x00000002 (original value restored)



    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
