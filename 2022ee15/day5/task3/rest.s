	.file	"rest.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	non_restoring_division
	.type	non_restoring_division, @function
non_restoring_division:
	li	a6,32
	li	a5,0
	li	a7,0
.L5:
	srliw	a4,a0,31
	slliw	a5,a5,1
	or	a4,a4,a5
	slliw	a0,a0,1
	subw	a5,a4,a1
	addiw	a6,a6,-1
	ori	t1,a0,1
	sext.w	a4,a4
	bge	a7,zero,.L3
	addw	a5,a1,a4
.L3:
	sext.w	a7,a5
	blt	a5,zero,.L4
	sext.w	a0,t1
.L4:
	bne	a6,zero,.L5
	bge	a7,zero,.L6
	addw	a5,a1,a5
.L6:
	sw	a5,0(a3)
	sw	a0,0(a2)
	ret
	.size	non_restoring_division, .-non_restoring_division
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
