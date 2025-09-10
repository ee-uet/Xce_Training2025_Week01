.section .data
N:	.word 15
Count:	.word 0

.global _start

.section .text
_start:
	la t0, N
	lw a0, 0(t0)
	la t0, Count
	lw a1, 0(t0)

loop:
	addi a2, a0, -1
	and a0, a0, a2
	addi a1, a1, 1
	bnez a0, loop

	sw a1, 0(t0)

	# Code to exit for Spike (DONT REMOVE IT)
	li t0, 1
	la t1, tohost
	sd t0, (t1)

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
