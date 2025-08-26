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
# options passed: -mtune=rocket -mabi=lp64d -misa-spec=20191213 -march=rv64imafdc_zicsr_zifencei -O2
	.text
	.align	1
	.globl	restoring_division
	.type	restoring_division, @function
restoring_division:
# res_div.c:7:     uint64_t Q = dividend;   // Dividend/Quotient (lower 32 bits)
	slli	a0,a0,32	#, Q, tmp155
# res_div.c:8:     uint64_t M = divisor;    // Divisor
	slli	a1,a1,32	#, M, tmp156
# res_div.c:7:     uint64_t Q = dividend;   // Dividend/Quotient (lower 32 bits)
	srli	a0,a0,32	#, Q, Q
# res_div.c:8:     uint64_t M = divisor;    // Divisor
	srli	a1,a1,32	#, M, M
	li	a4,32		# ivtmp_8,
# res_div.c:6:     uint64_t A = 0;          // Remainder (upper 32 bits)
	li	a5,0		# A,
.L3:
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	srliw	a6,a0,31	# tmp150, Q,
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	slli	a5,a5,1	#, _37, A
# res_div.c:14:         A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
	or	a5,a6,a5	# _37, A, tmp150
# res_div.c:18:         A = A - M;
	sub	a6,a5,a1	# A, A, M
# res_div.c:21:         if (A & 0x80000000) {  // Check if bit 31 is set (negative)
	slli	a7,a6,32	#, tmp159, A
# res_div.c:12:     for (int i = 0; i < n; i++) {
	addiw	a4,a4,-1	#, ivtmp_8, ivtmp_8
# res_div.c:15:         Q = Q << 1;                      // Shift Q left
	slli	a0,a0,1	#, Q, Q
# res_div.c:21:         if (A & 0x80000000) {  // Check if bit 31 is set (negative)
	blt	a7,zero,.L2	#, tmp159,,
# res_div.c:27:             Q = Q | 1;         // Set LSB of Q to 1
	ori	a0,a0,1	#, Q, Q
# res_div.c:18:         A = A - M;
	mv	a5,a6	# A, A
.L2:
# res_div.c:12:     for (int i = 0; i < n; i++) {
	bne	a4,zero,.L3	#, ivtmp_8,,
# res_div.c:31:     *quotient = Q;
	sw	a0,0(a2)	# Q, *quotient_18(D)
# res_div.c:32:     *remainder = A;
	sw	a5,0(a3)	# A, *remainder_20(D)
# res_div.c:33: }
	ret	
	.size	restoring_division, .-restoring_division
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	"%u / %u = %u, remainder %u\n"
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32	#,,
# res_div.c:40:     restoring_division(dividend, divisor, &quotient, &remainder);
	addi	a3,sp,12	#,,
	addi	a2,sp,8	#,,
	li	a1,3		#,
	li	a0,21		#,
# res_div.c:35: int main() {
	sd	ra,24(sp)	#,
# res_div.c:40:     restoring_division(dividend, divisor, &quotient, &remainder);
	call	restoring_division		#
# res_div.c:41:     printf("%u / %u = %u, remainder %u\n", dividend, divisor, quotient, remainder);
	lw	a4,12(sp)		#, remainder
	lw	a3,8(sp)		#, quotient
	lui	a0,%hi(.LC0)	# tmp141,
	li	a2,3		#,
	li	a1,21		#,
	addi	a0,a0,%lo(.LC0)	#, tmp141,
	call	printf		#
# res_div.c:44: }
	ld	ra,24(sp)		#,
	li	a0,0		#,
	addi	sp,sp,32	#,,
	jr	ra		#
	.size	main, .-main
	.ident	"GCC: () 13.2.0"
