	.file	"lab6__t2.c"
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
	.globl	bit_manipulation
	.type	bit_manipulation, @function
bit_manipulation:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	mv	a5,a0
	mv	a3,a1
	mv	a4,a2
	sw	a5,-20(s0)
	mv	a5,a3
	sw	a5,-24(s0)
	mv	a5,a4
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	sext.w	a5,a5
	beq	a5,zero,.L2
	lw	a5,-24(s0)
	lw	a4,-28(s0)
	sllw	a5,a4,a5
	sw	a5,-28(s0)
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-28(s0)
	or	a5,a4,a5
	sw	a5,-20(s0)
	j	.L4
.L2:
	lw	a5,-28(s0)
	addiw	a5,a5,1
	sw	a5,-28(s0)
	lw	a5,-24(s0)
	lw	a4,-28(s0)
	sllw	a5,a4,a5
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	not	a5,a5
	sw	a5,-28(s0)
	lw	a5,-20(s0)
	mv	a4,a5
	lw	a5,-28(s0)
	and	a5,a4,a5
	sw	a5,-20(s0)
.L4:
	nop
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	bit_manipulation, .-bit_manipulation
	.align	1
	.globl	_start
	.type	_start, @function
_start:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,3
	sw	a5,-20(s0)
	li	a5,4
	sw	a5,-24(s0)
	li	a5,1
	sw	a5,-28(s0)
	lw	a3,-28(s0)
	lw	a4,-24(s0)
	lw	a5,-20(s0)
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
	call	bit_manipulation
	lui	a5,%hi(tohost)
	li	a4,1
	sw	a4,%lo(tohost)(a5)
.L6:
	j	.L6
	.size	_start, .-_start
	.ident	"GCC: (14.2.0+19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
