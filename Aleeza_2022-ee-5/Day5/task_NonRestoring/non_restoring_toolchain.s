	.file	"non_restoring.c"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	nonRestoringDivision
	.type	nonRestoringDivision, @function
nonRestoringDivision:
.LFB0:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sd	s0,56(sp)
	.cfi_offset 8, -8
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	mv	a5,a0
	mv	a4,a1
	sd	a2,-48(s0)
	sd	a3,-56(s0)
	sw	a5,-36(s0)
	mv	a5,a4
	sw	a5,-40(s0)
	sw	zero,-28(s0)
	sw	zero,-24(s0)
	li	a5,31
	sw	a5,-20(s0)
	j	.L2
.L5:
	lw	a5,-28(s0)
	slliw	a5,a5,1
	sext.w	a4,a5
	lw	a5,-20(s0)
	lw	a3,-36(s0)
	srlw	a5,a3,a5
	sext.w	a5,a5
	andi	a5,a5,1
	sext.w	a5,a5
	or	a5,a4,a5
	sext.w	a5,a5
	sw	a5,-28(s0)
	lw	a5,-24(s0)
	slliw	a5,a5,1
	sw	a5,-24(s0)
	lw	a5,-28(s0)
	sext.w	a5,a5
	blt	a5,zero,.L3
	lw	a5,-28(s0)
	lw	a4,-40(s0)
	subw	a5,a5,a4
	sext.w	a5,a5
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	sext.w	a5,a5
	blt	a5,zero,.L4
	lw	a5,-24(s0)
	ori	a5,a5,1
	sw	a5,-24(s0)
	j	.L4
.L3:
	lw	a5,-28(s0)
	lw	a4,-40(s0)
	addw	a5,a4,a5
	sext.w	a5,a5
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	sext.w	a5,a5
	blt	a5,zero,.L4
	lw	a5,-24(s0)
	ori	a5,a5,1
	sw	a5,-24(s0)
.L4:
	lw	a5,-20(s0)
	addiw	a5,a5,-1
	sw	a5,-20(s0)
.L2:
	lw	a5,-20(s0)
	sext.w	a5,a5
	bge	a5,zero,.L5
	lw	a5,-28(s0)
	sext.w	a5,a5
	bge	a5,zero,.L6
	lw	a5,-28(s0)
	lw	a4,-40(s0)
	addw	a5,a4,a5
	sext.w	a5,a5
	sw	a5,-28(s0)
.L6:
	ld	a5,-48(s0)
	lw	a4,-24(s0)
	sw	a4,0(a5)
	lw	a4,-28(s0)
	ld	a5,-56(s0)
	sw	a4,0(a5)
	nop
	ld	s0,56(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE0:
	.size	nonRestoringDivision, .-nonRestoringDivision
	.section	.rodata
	.align	3
.LC0:
	.string	"Enter Dividend: "
	.align	3
.LC1:
	.string	"%u"
	.align	3
.LC2:
	.string	"Enter Divisor: "
	.align	3
.LC3:
	.string	"Quotient = %u, Remainder = %u\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sd	ra,40(sp)
	sd	s0,32(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	la	a5,__stack_chk_guard
	ld	a4, 0(a5)
	sd	a4, -24(s0)
	li	a4, 0
	lla	a0,.LC0
	call	printf@plt
	addi	a5,s0,-40
	mv	a1,a5
	lla	a0,.LC1
	call	__isoc99_scanf@plt
	lla	a0,.LC2
	call	printf@plt
	addi	a5,s0,-36
	mv	a1,a5
	lla	a0,.LC1
	call	__isoc99_scanf@plt
	lw	a5,-40(s0)
	lw	a4,-36(s0)
	addi	a3,s0,-28
	addi	a2,s0,-32
	mv	a1,a4
	mv	a0,a5
	call	nonRestoringDivision
	lw	a5,-32(s0)
	lw	a4,-28(s0)
	mv	a2,a4
	mv	a1,a5
	lla	a0,.LC3
	call	printf@plt
	li	a5,0
	mv	a4,a5
	la	a5,__stack_chk_guard
	ld	a3, -24(s0)
	ld	a5, 0(a5)
	xor	a5, a3, a5
	li	a3, 0
	beq	a5,zero,.L9
	call	__stack_chk_fail@plt
.L9:
	mv	a0,a4
	ld	ra,40(sp)
	.cfi_restore 1
	ld	s0,32(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
