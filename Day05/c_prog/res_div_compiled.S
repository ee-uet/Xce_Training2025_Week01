	.file	"res_div.c"
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
	.align	1
	.globl	restoring_division
	.type	restoring_division, @function
restoring_division:
	addi	sp,sp,-96	#,,
	sd	s0,88(sp)	#,
	addi	s0,sp,96	#,,
	mv	a5,a0	# tmp140, dividend
	mv	a4,a1	# tmp142, divisor
	sd	a2,-80(s0)	# quotient, quotient
	sd	a3,-88(s0)	# remainder, remainder
	sw	a5,-68(s0)	# tmp141, dividend
	mv	a5,a4	# tmp143, tmp142
	sw	a5,-72(s0)	# tmp143, divisor
# res_div.c:6:     uint64_t A = 0;          // Remainder (upper 32 bits)
	sd	zero,-24(s0)	#, A
# res_div.c:7:     uint64_t Q = dividend;   // Dividend/Quotient (lower 32 bits)
	lwu	a5,-68(s0)	# tmp144, dividend
	sd	a5,-32(s0)	# tmp144, Q
# res_div.c:8:     uint64_t M = divisor;    // Divisor
	lwu	a5,-72(s0)	# tmp145, divisor
	sd	a5,-48(s0)	# tmp145, M
# res_div.c:10:     int n = 32;  // Number of bits
	li	a5,32		# tmp146,
	sw	a5,-52(s0)	# tmp146, n
# res_div.c:12:     for (int i = 0; i < n; i++) {
	sw	zero,-36(s0)	#, i
# res_div.c:12:     for (int i = 0; i < n; i++) {
	j	.L2		#
.L5:
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	ld	a5,-24(s0)		# tmp147, A
	slli	a4,a5,1	#, _1, tmp147
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	ld	a5,-32(s0)		# tmp148, Q
	srli	a5,a5,31	#, _2, tmp148
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	andi	a5,a5,1	#, _3, _2
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	or	a5,a4,a5	# _3, tmp149, _1
	sd	a5,-24(s0)	# tmp149, A
# res_div.c:15:         Q = Q << 1;                      // Shift Q left
	ld	a5,-32(s0)		# tmp151, Q
	slli	a5,a5,1	#, tmp150, tmp151
	sd	a5,-32(s0)	# tmp150, Q
# res_div.c:18:         A = A - M;
	ld	a4,-24(s0)		# tmp153, A
	ld	a5,-48(s0)		# tmp154, M
	sub	a5,a4,a5	# tmp152, tmp153, tmp154
	sd	a5,-24(s0)	# tmp152, A
# res_div.c:21:         if (A & 0x80000000) {  // Check if bit 31 is set (negative)
	ld	a4,-24(s0)		# tmp155, A
	li	a5,1		# tmp157,
	slli	a5,a5,31	#, tmp156, tmp157
	and	a5,a4,a5	# tmp156, _4, tmp155
# res_div.c:21:         if (A & 0x80000000) {  // Check if bit 31 is set (negative)
	beq	a5,zero,.L3	#, _4,,
# res_div.c:23:             A = A + M;         // Restore A
	ld	a4,-24(s0)		# tmp159, A
	ld	a5,-48(s0)		# tmp160, M
	add	a5,a4,a5	# tmp160, tmp158, tmp159
	sd	a5,-24(s0)	# tmp158, A
	j	.L4		#
.L3:
# res_div.c:27:             Q = Q | 1;         // Set LSB of Q to 1
	ld	a5,-32(s0)		# tmp162, Q
	ori	a5,a5,1	#, tmp161, tmp162
	sd	a5,-32(s0)	# tmp161, Q
.L4:
# res_div.c:12:     for (int i = 0; i < n; i++) {
	lw	a5,-36(s0)		# tmp165, i
	addiw	a5,a5,1	#, tmp163, tmp164
	sw	a5,-36(s0)	# tmp163, i
.L2:
# res_div.c:12:     for (int i = 0; i < n; i++) {
	lw	a5,-36(s0)		# tmp167, i
	mv	a4,a5	# tmp166, tmp167
	lw	a5,-52(s0)		# tmp169, n
	sext.w	a4,a4	# tmp170, tmp166
	sext.w	a5,a5	# tmp171, tmp168
	blt	a4,a5,.L5	#, tmp170, tmp171,
# res_div.c:31:     *quotient = Q;
	ld	a5,-32(s0)		# tmp172, Q
	sext.w	a4,a5	# _5, tmp172
	ld	a5,-80(s0)		# tmp173, quotient
	sw	a4,0(a5)	# _5, *quotient_20(D)
# res_div.c:32:     *remainder = A;
	ld	a5,-24(s0)		# tmp174, A
	sext.w	a4,a5	# _6, tmp174
	ld	a5,-88(s0)		# tmp175, remainder
	sw	a4,0(a5)	# _6, *remainder_22(D)
# res_div.c:33: }
	nop	
	ld	s0,88(sp)		#,
	addi	sp,sp,96	#,,
	jr	ra		#
	.size	restoring_division, .-restoring_division
	.section	.rodata
	.align	3
.LC0:
	.string	"%u / %u = %u, remainder %u\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32	#,,
	sd	ra,24(sp)	#,
	sd	s0,16(sp)	#,
	addi	s0,sp,32	#,,
# res_div.c:36:     uint32_t dividend = 21;
	li	a5,21		# tmp138,
	sw	a5,-20(s0)	# tmp138, dividend
# res_div.c:37:     uint32_t divisor = 3;
	li	a5,3		# tmp139,
	sw	a5,-24(s0)	# tmp139, divisor
# res_div.c:40:     restoring_division(dividend, divisor, &quotient, &remainder);
	addi	a3,s0,-32	#, tmp140,
	addi	a2,s0,-28	#, tmp141,
	lw	a4,-24(s0)		# tmp142, divisor
	lw	a5,-20(s0)		# tmp143, dividend
	mv	a1,a4	#, tmp142
	mv	a0,a5	#, tmp143
	call	restoring_division		#
# res_div.c:41:     printf("%u / %u = %u, remainder %u\n", dividend, divisor, quotient, remainder);
	lw	a3,-28(s0)		# quotient.0_1, quotient
	lw	a4,-32(s0)		# remainder.1_2, remainder
	lw	a2,-24(s0)		# tmp144, divisor
	lw	a5,-20(s0)		# tmp145, dividend
	mv	a1,a5	#, tmp145
	lui	a5,%hi(.LC0)	# tmp146,
	addi	a0,a5,%lo(.LC0)	#, tmp146,
	call	printf		#
# res_div.c:43:     return 0;
	li	a5,0		# _8,
# res_div.c:44: }
	mv	a0,a5	#, <retval>
	ld	ra,24(sp)		#,
	ld	s0,16(sp)		#,
	addi	sp,sp,32	#,,
	jr	ra		#
	.size	main, .-main
	.ident	"GCC: () 13.2.0"
