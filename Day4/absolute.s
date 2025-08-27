.section .text
.global _start

_start:

    li a0, 7                    # load 7 into a0
    li a1, 10                   # load 10 into a1

    sub a2, a0, a1                  # a2 = a0 - a1

    blt a2, x0, negative            # if (a2 < 0) goto negative
    j done

negative:
    sub a2, x0, a2                  # a2 = -a2

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
