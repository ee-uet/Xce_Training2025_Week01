.section .text
.global _start
_start:
    la   sp, stack_top     # initialize a valid stack

    call main              # call your main()

    # prepare Spike exit: (exit_code << 1) | 1  ; exit_code = 0
    li   t0, 0
    slli t0, t0, 1
    ori  t0, t0, 1
    la   t1, tohost
    sd   t0, (t1)          # tell Spike to exit
    # no infinite loop needed

.section .tohost
.align 3
.globl tohost
.globl fromhost
tohost:   .dword 0
fromhost: .dword 0

# Reserve a simple 4 KiB stack
.section .bss
.align 12
stack_area:
    .skip 4096
stack_top:
