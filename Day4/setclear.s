.section .text
.globl _start

_start:

    li t1, 0x49527510    # t1 = original number

    # Set bit 
    li t0, 1             # t0 = 1
    li t2, 5             # t2 = bit position
    sll t0, t0, t2       # t0 = 1 << 5
    or t3, t1, t0        # t3 = t1 | t0 (bit set result)

    # Clear bit 
    not t0, t0           # t0 = ~mask
    and t4, t1, t0       # t4 = t1 & ~mask (bit clear result)

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0