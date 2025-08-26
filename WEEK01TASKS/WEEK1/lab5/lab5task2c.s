	.file	"lab5task2c.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	s0,24(sp)
	addi	s0,sp,32
	li	a5,32
	sw	a5,-20(s0)
	li	a5,6
	sw	a5,-24(s0)
	sw	zero,-28(s0)
	lw	a5,-24(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sw	a5,-32(s0)
	lw	a5,-28(s0)
	sext.w	a5,a5
	bne	a5,zero,.L2
	lw	a5,-32(s0)
	not	a5,a5
	sw	a5,-32(s0)
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-32(s0)
	and	a5,a4,a5
	sw	a5,-20(s0)
	j	.L3
.L2:
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-32(s0)
	or	a5,a4,a5
	sw	a5,-20(s0)
.L3:
	li	a5,0
	mv	a0,a5
	ld	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
