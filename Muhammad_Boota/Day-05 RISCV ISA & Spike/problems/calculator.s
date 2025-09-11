.data
x: .word 5
y: .word 8
.text
.global _start
_start:
 lw t0, x
 lw t1, y
 li t2, 0

calculate:
 blt t0, t1, first
 sub t2, t0, t1
 j done

first:
 sub t2, t1, t0
 j done

done:
 li t0, 1
 la t1, tohost
 sd t0, 0(t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0


 
 


