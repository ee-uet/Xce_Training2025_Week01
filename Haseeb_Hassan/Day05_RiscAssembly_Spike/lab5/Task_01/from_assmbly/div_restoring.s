    .global _start
    .section .text

_start:
    # ---- inputs ----
    li  t0, 100         # dividend (change to test)
    li  t1, 7           # divisor  (change to test)

    # ---- init ----
    li  t2, 0           # quotient
    li  t3, 0           # remainder
    li  t4, 32          # loop count (32 bits)

loop:
    # bring in MSB of dividend into remainder
    srli t5, t0, 31         # t5 = top bit of dividend
    slli t3, t3, 1          # remainder <<= 1
    or   t3, t3, t5         # remainder |= t5
    slli t0, t0, 1          # dividend <<= 1 (next bit up next iter)

    # trial subtract (unsigned compare)
    bgeu t3, t1, ge
    # remainder < divisor -> quotient next bit is 0
    slli t2, t2, 1          # quotient <<= 1
    j    cont

ge:
    sub  t3, t3, t1         # remainder -= divisor
    slli t2, t2, 1
    addi t2, t2, 1          # set low bit to 1

cont:
    addi t4, t4, -1
    bnez t4, loop

    # t2 = quotient, t3 = remainder

exit:
    # Spike/HTIF exit (your template)
    li  t0, 1
    la  t1, tohost
    sd  t0, 0(t1)
    j   exit

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
