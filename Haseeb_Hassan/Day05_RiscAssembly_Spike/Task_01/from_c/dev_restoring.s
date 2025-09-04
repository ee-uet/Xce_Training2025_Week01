	.file	"dev_restoring.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	divu_restoring
	.type	divu_restoring, @function
divu_restoring:
	addi	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	addi	s0,sp,48
	mv	a5,a0
	mv	a4,a1
	sd	a2,-48(s0)
	sw	a5,-36(s0)
	mv	a5,a4
	sw	a5,-40(s0)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	sw	zero,-28(s0)
	j	.L2
.L5:
	lw	a5,-36(s0)
	srliw	a5,a5,31
	sw	a5,-32(s0)
	lw	a5,-24(s0)
	slliw	a5,a5,1
	sext.w	a5,a5
	lw	a4,-32(s0)
	or	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-36(s0)
	slliw	a5,a5,1
	sw	a5,-36(s0)
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-40(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	bltu	a4,a5,.L3
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-40(s0)
	subw	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-20(s0)
	slliw	a5,a5,1
	sext.w	a5,a5
	ori	a5,a5,1
	sw	a5,-20(s0)
	j	.L4
.L3:
	lw	a5,-20(s0)
	slliw	a5,a5,1
	sw	a5,-20(s0)
.L4:
	lw	a5,-28(s0)
	addiw	a5,a5,1
	sw	a5,-28(s0)
.L2:
	lw	a5,-28(s0)
	sext.w	a4,a5
	li	a5,31
	ble	a4,a5,.L5
	ld	a5,-48(s0)
	lw	a4,-24(s0)
	sw	a4,0(a5)
	lw	a5,-20(s0)
	mv	a0,a5
	ld	ra,40(sp)
	ld	s0,32(sp)
	addi	sp,sp,48
	jr	ra
	.size	divu_restoring, .-divu_restoring
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,50
	sw	a5,-20(s0)
	li	a5,7
	sw	a5,-24(s0)
	addi	a3,s0,-32
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
	call	divu_restoring
	mv	a5,a0
	sw	a5,-28(s0)
	li	a5,0
	mv	a0,a5
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (14.2.0+19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
