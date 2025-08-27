	.file	"setclear.c"
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
	li	a5,1230139392
	addi	sp,sp,-32
	addi	a5,a5,1296
	sw	a5,12(sp)
	li	a5,5
	sw	a5,16(sp)
	lw	a4,16(sp)
	li	a5,1
	sllw	a5,a5,a4
	sw	a5,20(sp)
	lw	a5,12(sp)
	lw	a4,20(sp)
	or	a5,a5,a4
	sw	a5,24(sp)
	lw	a5,20(sp)
	lw	a4,12(sp)
	not	a5,a5
	and	a5,a5,a4
	sw	a5,28(sp)
	lw	a0,24(sp)
	lw	a5,28(sp)
	addi	sp,sp,32
	addw	a0,a0,a5
	jr	ra
	.size	main, .-main
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
