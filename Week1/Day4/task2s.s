.global _start
.section .text
_start:
    # Load variables from memory
    la t0, num
    lw t1, 0(t0)       # t1 = num
    la t0, pos
    lw t2, 0(t0)       # t2 = bit position
    la t0, value
    lw t3, 0(t0)       # t3 = value (1=set, 0=clear)

    # Compute mask = 1 << pos
    li t4, 1
    sll t4, t4, t2

    # Set or clear bit
    beq t3, zero, clear_bit
    or t1, t1, t4       # set bit
    j store_result

clear_bit:
    not t4, t4
    and t1, t1, t4      # clear bit

store_result:
    la t0, result
    sw t1, 0(t0)        # store result

    # Signal done for Spike
    li t1, 1
    la t2, tohost
    sw t1, 0(t2)

1:  j 1b                # infinite loop

.section .data
.align 3
num:    .word 0x55       # initial number
pos:    .word 3          # bit position
value:  .word 1          # 1=set, 0=clear
result: .word 0          # store result

.section .tohost
.align 3
tohost:   .word 0
fromhost: .word 0

