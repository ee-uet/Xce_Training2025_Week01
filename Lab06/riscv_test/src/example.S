    .section .text
    .globl _start

_start:
    # Initialize registers with some values
    li   t0, 5        # Load 5 into t0
    li   t1, 10       # Load 10 into t1

    add  t2, t0, t1   # t2 = t0 + t1 (5 + 10 = 15)

    # Store result at a memory location
    la   t3, result
    sw   t2, 0(t3)

    # ---- Spike exit stub ----
    li   t0, 1
    la   t1, tohost
    sd   t0, (t1)
1:  j    1b

# ---- Data section ----
    .section .data
result:
    .word 0

    .section .tohost
    .align 3
tohost:     .dword 0
fromhost:   .dword 0

