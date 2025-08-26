	.file	"task_1.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	restoring_division
	.type	restoring_division, @function
restoring_division:
	addi	sp,sp,-80
	sd	s0,72(sp)
	addi	s0,sp,80
	mv	a5,a0
	mv	a4,a1
	sd	a2,-64(s0)
	sd	a3,-72(s0)
	sw	a5,-52(s0)
	mv	a5,a4
	sw	a5,-56(s0)
	sw	zero,-20(s0)
	lw	a5,-52(s0)
	sw	a5,-24(s0)
	lw	a5,-56(s0)
	sw	a5,-32(s0)
	li	a5,32
	sw	a5,-36(s0)
	sw	zero,-28(s0)
	j	.L2
.L5:
	lw	a5,-20(s0)
	slliw	a5,a5,1
	sext.w	a4,a5
	lw	a5,-24(s0)
	srliw	a5,a5,31
	sext.w	a5,a5
	or	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-24(s0)
	slliw	a5,a5,1
	sw	a5,-24(s0)
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-32(s0)
	subw	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	bge	a5,zero,.L3
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-32(s0)
	addw	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-24(s0)
	andi	a5,a5,-2
	sw	a5,-24(s0)
	j	.L4
.L3:
	lw	a5,-24(s0)
	ori	a5,a5,1
	sw	a5,-24(s0)
.L4:
	lw	a5,-28(s0)
	addiw	a5,a5,1
	sw	a5,-28(s0)
.L2:
	lw	a5,-28(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L5
	ld	a5,-64(s0)
	lw	a4,-24(s0)
	sw	a4,0(a5)
	ld	a5,-72(s0)
	lw	a4,-20(s0)
	sw	a4,0(a5)
	nop
	ld	s0,72(sp)
	addi	sp,sp,80
	jr	ra
	.size	restoring_division, .-restoring_division
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,37
	sw	a5,-20(s0)
	li	a5,5
	sw	a5,-24(s0)
	addi	a3,s0,-32
	addi	a2,s0,-28
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	mv	a1,a4
	mv	a0,a5
	call	restoring_division
	li	a5,0
	mv	a0,a5
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
