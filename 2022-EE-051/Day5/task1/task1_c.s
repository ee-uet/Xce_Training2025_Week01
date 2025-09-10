	.file	"task1.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48
	sd	s0,40(sp)
	addi	s0,sp,48
	li	a5,77
	sw	a5,-32(s0)
	li	a5,7
	sw	a5,-36(s0)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	li	a5,31
	sw	a5,-28(s0)
	j	.L2
.L5:
	lw	a5,-24(s0)
	slliw	a5,a5,1
	sw	a5,-24(s0)
	lw	a5,-28(s0)
	lw	a4,-32(s0)
	srlw	a5,a4,a5
	sext.w	a5,a5
	andi	a5,a5,1
	sext.w	a5,a5
	beq	a5,zero,.L3
	lw	a5,-24(s0)
	ori	a5,a5,1
	sw	a5,-24(s0)
.L3:
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	bltu	a4,a5,.L4
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	subw	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-28(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sext.w	a5,a5
	lw	a4,-20(s0)
	or	a5,a4,a5
	sw	a5,-20(s0)
.L4:
	lw	a5,-28(s0)
	addiw	a5,a5,-1
	sw	a5,-28(s0)
.L2:
	lw	a5,-28(s0)
	sext.w	a5,a5
	bge	a5,zero,.L5
	li	a5,0
	mv	a0,a5
	ld	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
