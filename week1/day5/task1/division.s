	.file	"division.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	restoring_division
	.type	restoring_division, @function
restoring_division:
	li	a6,32
	li	a5,0
.L3:
	slliw	a4,a5,1
	srliw	a5,a0,31
	or	a5,a5,a4
	slliw	a0,a0,1
	subw	a4,a5,a1
	addiw	a6,a6,-1
	ori	a7,a0,1
	sext.w	a5,a5
	blt	a4,zero,.L2
	sext.w	a0,a7
	mv	a5,a4
.L2:
	bne	a6,zero,.L3
	sw	a0,0(a2)
	sw	a5,0(a3)
	ret
	.size	restoring_division, .-restoring_division
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
	li	a5,524288
	addi	a5,a5,1
	slli	a5,a5,12
	li	a4,1
	sw	a4,0(a5)
	li	a0,0
	ret
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
