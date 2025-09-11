.global _start

.section .text
_start:
    li a0, 25
    li a1, 4
    li t2, 0
    jal ra, div_algo
    blt t2, zero, fix_rem
finish:
    li t5, 1
    la t1, tohost
    sd t5, (t1)

halt:  j halt
fix_rem:
    add t2, t2, t1
    j finish

div_algo:
    li t3, 32
    mv t0, a0
    mv t1, a1
    li t5, 1
    slli t5, t5, 31
    not t5, t5

repeat:
    beq t3, zero, done_div
    li t4, 1
    slli t4, t4, 31
    and t4, t4, t0
    srli t4, t4, 31
    slli t2, t2, 1
    and t0, t0, t5
    or t2, t2, t4
    and t0, t0, t5
    slli t0, t0, 1
    bge t2, zero, sub_case
    add t2, t2, t1
    bge t2, zero, set_bit
    j step_end

sub_case:
    sub t2, t2, t1
    bge t2, zero, set_bit
    j step_end

set_bit:
    ori t0, t0, 1
    j step_end

step_end:
    addi t3, t3, -1
    j repeat

done_div:
    ret

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0