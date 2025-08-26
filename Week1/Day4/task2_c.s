	.file	"task2.c"
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
	addi	sp,sp,-16
	li	a5,85
	sw	a5,4(sp)
	li	a5,3
	sw	a5,8(sp)
	li	a5,1
	sw	a5,12(sp)
	lw	a3,8(sp)
	lw	a4,12(sp)
	sllw	a5,a5,a3
	beq	a4,zero,.L2
	sext.w	a3,a5
	lw	a5,4(sp)
	or	a5,a5,a3
	sw	a5,4(sp)
.L3:
	lw	a0,4(sp)
	addi	sp,sp,16
	jr	ra
.L2:
	lw	a4,4(sp)
	not	a5,a5
	and	a5,a4,a5
	sext.w	a5,a5
	sw	a5,4(sp)
	j	.L3
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
