    .section .text
    .globl _start

_start:
    li a0, 0x12345678      # number
    li a1, 5               # bit position to modify
    li a2, 1               # op: 1=set, 0=clear

    li t0, 1               # prepare mask
    sll t0, t0, a1         # mask = 1 << pos

    beq a2, x0, clear_bit  # if op==0 -> clear
    or a0, a0, t0          # set: num |= mask
    j done

clear_bit:
    not t0, t0             # invert mask
    and a0, a0, t0         # clear: num &= ~mask

done:
    # result is in a0
    # exit for spike pk
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
