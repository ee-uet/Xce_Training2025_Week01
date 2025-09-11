.data
array: .word 3, 7, 2, 9, 1, 5
size: .word 6
.text
.global _start
_start:
    lw t2, size
    la t4, array
    li t1, 0
    add t1, t1, t4
    li t3, 1
    li t6, 4
last_addr:
    add t1, t1, t6
    sub t2, t2, t3
    beq t2, t3, revese
    j last_addr
revese:
    lw t0, 0(t4)
    lw t5, 0(t1)
    sw t0, 0(t1)
    sw t5, 0(t4) 
    add t4, t4, t6
    sub t1, t1, t6
    bgt t4, t1, done
    j revese
done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0



