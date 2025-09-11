    .section .text
    .global _start

_start:
    # Load initial values
    li x1, 32          # put 32 in x1 (the number we’ll modify)
    li x2, 6           # put 6 in x2 (the bit position we want to work with)
    li x3, 0           # put 0 in x3 (flag: 0 = clear bit, nonzero = set bit)

    # Prepare a mask for the target bit
    li x4, 1           # x4 = 1
    sll x4, x4, x2     # shift left by x2 : mask = (1 << 6)

    # Decide whether to clear or set the bit
    beq x3, x0, clear_bit   # if x3 == 0 → jump to clear_bit

set_bit:
    or x1, x1, x4      # set bit: x1 = x1 OR mask
    j done             # skip the clear_bit code

clear_bit:
    xori x4, x4, -1    # invert mask 
    and x1, x1, x4     # clear bit: x1 = x1 AND

done:
    # Program exit (write to simulator’s tohost)
    li t0, 1           # exit code = 1
    la t1, tohost      # load address of tohost
    sd t0, 0(t1)       # store exit code → program finishes
1:  j 1b               # infinite loop (halt)

.section .data
n: .word 7             # store integer 7
my_array: .word 1,2,3,4,5,6,7   # array of 7 integers

.section .tohost
.align 3
tohost: .dword 0       # used by simulator to detect exit
fromhost: .dword 0

