	.file	"e2.c"
	.option nopic
	.attribute arch, "rv64i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	set_bit
	.type	set_bit, @function
set_bit:
	li	a5,31
	bgtu	a1,a5,.L2
	li	a5,1
	sllw	a5,a5,a1
	or	a0,a0,a5
	sext.w	a0,a0
.L2:
	ret
	.size	set_bit, .-set_bit
	.align	2
	.globl	clear_bit
	.type	clear_bit, @function
clear_bit:
	li	a5,31
	bgtu	a1,a5,.L6
	li	a5,1
	sllw	a5,a5,a1
	not	a5,a5
	and	a5,a5,a0
	sext.w	a0,a5
.L6:
	ret
	.size	clear_bit, .-clear_bit
	.align	2
	.globl	get_bit
	.type	get_bit, @function
get_bit:
	li	a5,31
	bgtu	a1,a5,.L10
	srlw	a0,a0,a1
	andi	a0,a0,1
	ret
.L10:
	li	a0,-1
	ret
	.size	get_bit, .-get_bit
	.align	2
	.globl	toggle_bit
	.type	toggle_bit, @function
toggle_bit:
	li	a5,31
	bgtu	a1,a5,.L12
	li	a5,1
	sllw	a5,a5,a1
	xor	a0,a0,a5
	sext.w	a0,a0
.L12:
	ret
	.size	toggle_bit, .-toggle_bit
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
