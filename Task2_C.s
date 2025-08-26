	.file	"Task2_C.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.global _start
	.globl	bit_modify
	.type	bit_modify, @function
start:
	call main
bit_modify:
	addi	sp,sp,-48
	sd	s0,40(sp)
	addi	s0,sp,48
	mv	a5,a0
	mv	a3,a1
	mv	a4,a2
	sw	a5,-36(s0)
	mv	a5,a3
	sw	a5,-40(s0)
	mv	a5,a4
	sw	a5,-44(s0)
	lw	a5,-40(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sw	a5,-20(s0)
	lw	a5,-44(s0)
	sext.w	a4,a5
	li	a5,1
	bne	a4,a5,.L2
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-20(s0)
	or	a5,a4,a5
	sw	a5,-36(s0)
	j	.L3
.L2:
	lw	a5,-20(s0)
	not	a5,a5
	sext.w	a5,a5
	lw	a4,-36(s0)
	and	a5,a4,a5
	sw	a5,-36(s0)
.L3:
	lw	a5,-36(s0)
	mv	a0,a5
	ld	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	bit_modify, .-bit_modify
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,305418240
	addi	a5,a5,1656
	sw	a5,-20(s0)
	li	a5,5
	sw	a5,-24(s0)
	li	a5,1
	sw	a5,-28(s0)
	lw	a3,-28(s0)
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
	call	bit_modify
	mv	a5,a0
	sw	a5,-32(s0)
	lw	a5,-32(s0)
	mv	a0,a5
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
	
	li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
