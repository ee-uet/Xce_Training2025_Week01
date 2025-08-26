	.file	"task1.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
	li	a3,31
	li	a5,0
	li	a2,0
	li	a7,77
	li	a6,6
	li	a0,1
	li	a1,-1
.L3:
	srlw	a4,a7,a3
	andi	a4,a4,1
	slliw	a5,a5,1
	or	a5,a4,a5
	sext.w	a5,a5
	sllw	a4,a0,a3
	or	a4,a2,a4
	addiw	a3,a3,-1
	bleu	a5,a6,.L2
	addiw	a5,a5,-7
	sext.w	a2,a4
.L2:
	bne	a3,a1,.L3
	li	a4,1
	slli	a4,a4,31
	sw	a2,0(a4)
	sw	a5,4(a4)
	li	a0,0
	ret
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
