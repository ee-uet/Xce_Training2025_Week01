.globl _start
_start:
    j main

	.file	"restoring_division.c"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sd	s0,40(sp)
	.cfi_offset 8, -8
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	li	a5,13
	sw	a5,-28(s0)
	li	a5,3
	sw	a5,-24(s0)
	li	a5,4
	sw	a5,-20(s0)
	sw	zero,-40(s0)
	sw	zero,-36(s0)
	lw	a5,-20(s0)
	addiw	a5,a5,-1
	sw	a5,-32(s0)
	j	.L2
.L5:
	lw	a5,-36(s0)
	slliw	a5,a5,1
	sext.w	a4,a5
	lw	a5,-32(s0)
	lw	a3,-28(s0)
	sraw	a5,a3,a5
	sext.w	a5,a5
	andi	a5,a5,1
	sext.w	a5,a5
	or	a5,a4,a5
	sw	a5,-36(s0)
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-24(s0)
	subw	a5,a4,a5
	sw	a5,-36(s0)
	lw	a5,-36(s0)
	sext.w	a5,a5
	bge	a5,zero,.L3
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-24(s0)
	addw	a5,a4,a5
	sw	a5,-36(s0)
	lw	a5,-40(s0)
	slliw	a5,a5,1
	sw	a5,-40(s0)
	j	.L4
.L3:
	lw	a5,-40(s0)
	slliw	a5,a5,1
	sext.w	a5,a5
	ori	a5,a5,1
	sw	a5,-40(s0)
.L4:
	lw	a5,-32(s0)
	addiw	a5,a5,-1
	sw	a5,-32(s0)
.L2:
	lw	a5,-32(s0)
	sext.w	a5,a5
	bge	a5,zero,.L5
.L6:
	nop
	j	.L6
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
