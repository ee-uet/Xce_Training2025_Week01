.section .text
.global _start

_start:

    li a0, 0        # load 0 to count (a0)
    li a1, 27       # load integer value in a1

    loop:
        beq a1, x0, done            # if a1 == 0 jump to done
        addi a2, a1, -1               # a2 = a1 - 1
        and a1, a1, a2              # a1 = a1 & a2
        addi a0, a0, 1              # count++
        j loop

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
