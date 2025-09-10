	.file	"lab5task3c.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"%d,%d"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	addi	s0,sp,48
	li	a5,4
	sw	a5,-36(s0)
	li	a5,43
	sw	a5,-40(s0)
	sw	zero,-20(s0)
	sw	zero,-24(s0)
	li	a5,32
	sw	a5,-44(s0)
	lw	a5,-44(s0)
	addiw	a5,a5,-1
	sw	a5,-28(s0)
	j	.L2
.L7:
	lw	a5,-20(s0)
	slliw	a5,a5,1
	sext.w	a4,a5
	lw	a5,-28(s0)
	lw	a3,-40(s0)
	sraw	a5,a3,a5
	sext.w	a5,a5
	andi	a5,a5,1
	sext.w	a5,a5
	or	a5,a4,a5
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	sext.w	a5,a5
	blt	a5,zero,.L3
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	subw	a5,a4,a5
	sw	a5,-32(s0)
	j	.L4
.L3:
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	addw	a5,a4,a5
	sw	a5,-32(s0)
.L4:
	lw	a5,-32(s0)
	sext.w	a5,a5
	blt	a5,zero,.L5
	lw	a5,-32(s0)
	sw	a5,-20(s0)
	lw	a5,-28(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sw	a5,-48(s0)
	lw	a5,-24(s0)
	mv	a4,a5
	lw	a5,-48(s0)
	or	a5,a4,a5
	sw	a5,-24(s0)
	j	.L6
.L5:
	lw	a5,-32(s0)
	sw	a5,-20(s0)
.L6:
	lw	a5,-28(s0)
	addiw	a5,a5,-1
	sw	a5,-28(s0)
.L2:
	lw	a5,-28(s0)
	sext.w	a5,a5
	bge	a5,zero,.L7
	lw	a5,-20(s0)
	sext.w	a5,a5
	bge	a5,zero,.L8
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-36(s0)
	addw	a5,a4,a5
	sw	a5,-20(s0)
.L8:
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	mv	a2,a4
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	li	a5,0
	mv	a0,a5
	ld	ra,40(sp)
	ld	s0,32(sp)
	addi	sp,sp,48
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
