    .data
num:   .word 5           # initial number
pos:   .word 1           # bit position to set/clear

    .global _start
    .section .text

_start:
    # any code here
    # Load inputs
    lw   t0, num         # t0 = 5
    lw   t1, pos         # t1 = 1

    # set bit
    li   t2, 1
    sll  t2, t2, t1      # t2 = (1 << pos)
    or   t3, t0, t2      # t3 = num | (1 << pos)   -> set bit result

    # clear bit
    li   t4, 1
    sll  t4, t4, t1      # t4 = (1 << pos)
    not  t4, t4          # t4 = ~(1 << pos)
    and  t5, t0, t4      # t5 = num & ~(1 << pos)  -> clear bit result

    # t3 = set bit result
    # t5 = clear bit result

done:
    # Code to exit for Spike (DONT REMOVE IT)
    # Exit for Spike
    li   t0, 1
    la   t1, tohost
    sd   t0, (t1)

1:  j 1b

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
