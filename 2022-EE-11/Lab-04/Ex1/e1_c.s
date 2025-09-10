	.file	"e1.c"
	.option nopic
	.attribute arch, "rv64i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	restoring_divide
	.type	restoring_divide, @function
restoring_divide:
	addi	sp,sp,-16
	li	a3,31
	li	a5,0
	li	a2,0
	li	a7,1
	li	a6,-1
.L3:
	srliw	a4,a0,31
	slliw	a5,a5,1
	or	a5,a4,a5
	sext.w	a5,a5
	sllw	a4,a7,a3
	slliw	a0,a0,1
	or	a4,a2,a4
	addiw	a3,a3,-1
	bgtu	a1,a5,.L2
	subw	a5,a5,a1
	sext.w	a2,a4
.L2:
	bne	a3,a6,.L3
	slli	a0,a2,32
	slli	a5,a5,32
	srli	a0,a0,32
	or	a0,a0,a5
	addi	sp,sp,16
	jr	ra
	.size	restoring_divide, .-restoring_divide
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.type	main, @function
main:
	li	a0,0
	ret
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
