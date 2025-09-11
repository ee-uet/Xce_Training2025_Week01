	.file	"clear_set_bit.c"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"Original: 0x%08X\n"
	.align	3
.LC1:
	.string	"Modified: 0x%08X\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sd	ra,24(sp)
	sd	s0,16(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	li	a5,305418240
	addi	a5,a5,1656
	sw	a5,-28(s0)
	li	a5,5
	sw	a5,-24(s0)
	li	a5,1
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,1
	bne	a4,a5,.L2
	lw	a5,-24(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sext.w	a5,a5
	lw	a4,-28(s0)
	or	a5,a4,a5
	sw	a5,-32(s0)
	j	.L3
.L2:
	lw	a5,-24(s0)
	mv	a4,a5
	li	a5,1
	sllw	a5,a5,a4
	sext.w	a5,a5
	not	a5,a5
	sext.w	a5,a5
	lw	a4,-28(s0)
	and	a5,a4,a5
	sw	a5,-32(s0)
.L3:
	lw	a5,-28(s0)
	mv	a1,a5
	lla	a0,.LC0
	call	printf@plt
	lw	a5,-32(s0)
	mv	a1,a5
	lla	a0,.LC1
	call	printf@plt
	li	a5,0
	mv	a0,a5
	ld	ra,24(sp)
	.cfi_restore 1
	ld	s0,16(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
