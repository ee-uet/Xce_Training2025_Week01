	.file	"t2.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
# GNU C17 () version 13.2.0 (riscv64-unknown-elf)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version none
# warning: GMP header version 6.2.1 differs from library version 6.3.0.
# warning: MPFR header version 4.1.0 differs from library version 4.2.1.
# warning: MPC header version 1.2.1 differs from library version 1.3.1.
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=rocket -mabi=lp64d -misa-spec=20191213 -march=rv64imafdc_zicsr_zifencei -O0
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"Original: 0x%08X\n"
	.align	3
.LC1:
	.string	"Set bit %d: 0x%08X\n"
	.align	3
.LC2:
	.string	"Clear bit %d: 0x%08X\n"
	.align	3
.LC3:
	.string	"Toggle bit %d: 0x%08X\n"
	.align	3
.LC4:
	.string	"Bit %d is: %d\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48	#,,
	sd	ra,40(sp)	#,
	sd	s0,32(sp)	#,
	addi	s0,sp,48	#,,
# t2.c:5:     uint32_t number = 0x12345678;
	li	a5,305418240		# tmp155,
	addi	a5,a5,1656	#, tmp154, tmp155
	sw	a5,-20(s0)	# tmp154, number
# t2.c:6:     uint8_t bit_position = 5;
	li	a5,5		# tmp156,
	sb	a5,-21(s0)	# tmp156, bit_position
# t2.c:8:     uint32_t set_result = number | (1 << bit_position);
	lbu	a5,-21(s0)	# tmp157, bit_position
	sext.w	a5,a5	# _1, tmp157
	li	a4,1		# tmp159,
	sllw	a5,a4,a5	# _1, tmp158, tmp159
	sext.w	a5,a5	# _2, tmp158
	sext.w	a5,a5	# _3, _2
# t2.c:8:     uint32_t set_result = number | (1 << bit_position);
	lw	a4,-20(s0)		# tmp161, number
	or	a5,a4,a5	# tmp162, tmp163, tmp160
	sw	a5,-28(s0)	# tmp163, set_result
# t2.c:10:     uint32_t clear_result = number & ~(1 << bit_position);
	lbu	a5,-21(s0)	# tmp164, bit_position
	sext.w	a5,a5	# _4, tmp164
	li	a4,1		# tmp166,
	sllw	a5,a4,a5	# _4, tmp165, tmp166
	sext.w	a5,a5	# _5, tmp165
# t2.c:10:     uint32_t clear_result = number & ~(1 << bit_position);
	not	a5,a5	# tmp168, tmp167
	sext.w	a5,a5	# _6, tmp168
	sext.w	a5,a5	# _7, _6
# t2.c:10:     uint32_t clear_result = number & ~(1 << bit_position);
	lw	a4,-20(s0)		# tmp170, number
	and	a5,a4,a5	# tmp171, tmp172, tmp169
	sw	a5,-32(s0)	# tmp172, clear_result
# t2.c:12:     uint32_t toggle_result = number ^ (1 << bit_position);
	lbu	a5,-21(s0)	# tmp173, bit_position
	sext.w	a5,a5	# _8, tmp173
	li	a4,1		# tmp175,
	sllw	a5,a4,a5	# _8, tmp174, tmp175
	sext.w	a5,a5	# _9, tmp174
	sext.w	a5,a5	# _10, _9
# t2.c:12:     uint32_t toggle_result = number ^ (1 << bit_position);
	lw	a4,-20(s0)		# tmp177, number
	xor	a5,a4,a5	# tmp178, tmp179, tmp176
	sw	a5,-36(s0)	# tmp179, toggle_result
# t2.c:14:     uint8_t check_result = (number >> bit_position) & 1;
	lbu	a5,-21(s0)	# tmp180, bit_position
	sext.w	a5,a5	# _11, tmp180
	lw	a4,-20(s0)		# tmp184, number
	srlw	a5,a4,a5	# tmp181, tmp182, tmp183
	sext.w	a5,a5	# _12, tmp182
# t2.c:14:     uint8_t check_result = (number >> bit_position) & 1;
	andi	a5,a5,0xff	# _13, tmp185
# t2.c:14:     uint8_t check_result = (number >> bit_position) & 1;
	andi	a5,a5,1	#, tmp186, _13
	sb	a5,-37(s0)	# tmp186, check_result
# t2.c:16:     printf("Original: 0x%08X\n", number);
	lw	a5,-20(s0)		# tmp187, number
	mv	a1,a5	#, tmp187
	lui	a5,%hi(.LC0)	# tmp188,
	addi	a0,a5,%lo(.LC0)	#, tmp188,
	call	printf		#
# t2.c:17:     printf("Set bit %d: 0x%08X\n", bit_position, set_result);
	lbu	a5,-21(s0)	# tmp189, bit_position
	sext.w	a5,a5	# _14, tmp189
	lw	a4,-28(s0)		# tmp190, set_result
	mv	a2,a4	#, tmp190
	mv	a1,a5	#, _14
	lui	a5,%hi(.LC1)	# tmp191,
	addi	a0,a5,%lo(.LC1)	#, tmp191,
	call	printf		#
# t2.c:18:     printf("Clear bit %d: 0x%08X\n", bit_position, clear_result);
	lbu	a5,-21(s0)	# tmp192, bit_position
	sext.w	a5,a5	# _15, tmp192
	lw	a4,-32(s0)		# tmp193, clear_result
	mv	a2,a4	#, tmp193
	mv	a1,a5	#, _15
	lui	a5,%hi(.LC2)	# tmp194,
	addi	a0,a5,%lo(.LC2)	#, tmp194,
	call	printf		#
# t2.c:19:     printf("Toggle bit %d: 0x%08X\n", bit_position, toggle_result);
	lbu	a5,-21(s0)	# tmp195, bit_position
	sext.w	a5,a5	# _16, tmp195
	lw	a4,-36(s0)		# tmp196, toggle_result
	mv	a2,a4	#, tmp196
	mv	a1,a5	#, _16
	lui	a5,%hi(.LC3)	# tmp197,
	addi	a0,a5,%lo(.LC3)	#, tmp197,
	call	printf		#
# t2.c:20:     printf("Bit %d is: %d\n", bit_position, check_result);
	lbu	a5,-21(s0)	# tmp198, bit_position
	sext.w	a5,a5	# _17, tmp198
	lbu	a4,-37(s0)	# tmp199, check_result
	sext.w	a4,a4	# _18, tmp199
	mv	a2,a4	#, _18
	mv	a1,a5	#, _17
	lui	a5,%hi(.LC4)	# tmp200,
	addi	a0,a5,%lo(.LC4)	#, tmp200,
	call	printf		#
# t2.c:22:     return 0;
	li	a5,0		# _31,
# t2.c:23: }
	mv	a0,a5	#, <retval>
	ld	ra,40(sp)		#,
	ld	s0,32(sp)		#,
	addi	sp,sp,48	#,,
	jr	ra		#
	.size	main, .-main
	.ident	"GCC: () 13.2.0"
