	.file	"non_restoring.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	tohost
	.section	.sbss,"aw",@nobits
	.align	2
	.type	tohost, @object
	.size	tohost, 4
tohost:
	.zero	4
	.text
	.align	1
	.globl	_start
	.type	_start, @function
_start:
	addi	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	addi	s0,sp,48
	sw	zero,-20(s0)
	li	a5,13
	sw	a5,-32(s0)
	li	a5,3
	sw	a5,-36(s0)
	lw	a5,-32(s0)
	sw	a5,-24(s0)
	li	a5,32
	sw	a5,-40(s0)
	sw	zero,-28(s0)
	j	.L2
.L5:
	lw	a5,-40(s0)
	addiw	a5,a5,-1
	sext.w	a5,a5
	li	a4,1
	sllw	a5,a4,a5
	sw	a5,-44(s0)
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-44(s0)
	and	a5,a4,a5
	sw	a5,-44(s0)
	lw	a5,-40(s0)
	addiw	a5,a5,-1
	sext.w	a5,a5
	lw	a4,-44(s0)
	sraw	a5,a4,a5
	sw	a5,-44(s0)
	lw	a5,-20(s0)
	slliw	a5,a5,1
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-44(s0)
	or	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-40(s0)
	addiw	a5,a5,-1
	sext.w	a5,a5
	li	a4,1
	sllw	a5,a4,a5
	sext.w	a5,a5
	not	a5,a5
	sext.w	a5,a5
	lw	a4,-24(s0)
	and	a5,a5,a4
	sw	a5,-24(s0)
	lw	a5,-24(s0)
	slliw	a5,a5,1
	sw	a5,-24(s0)
	lw	a5,-20(s0)
	sext.w	a5,a5
	blt	a5,zero,.L3
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	subw	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	sext.w	a5,a5
	blt	a5,zero,.L4
	lw	a5,-24(s0)
	ori	a5,a5,1
	sw	a5,-24(s0)
	j	.L4
.L3:
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	addw	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	sext.w	a5,a5
	blt	a5,zero,.L4
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
	lw	a5,-40(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L5
	lui	a5,%hi(tohost)
	li	a4,1
	sw	a4,%lo(tohost)(a5)
.L6:
	j	.L6
	.size	_start, .-_start
	.ident	"GCC: (14.2.0+19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
