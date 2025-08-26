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
# options passed: -mtune=rocket -mabi=lp64d -misa-spec=20191213 -march=rv64imafdc_zicsr_zifencei -O2
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
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
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
# t2.c:16:     printf("Original: 0x%08X\n", number);
	li	a1,305418240		#,
	lui	a0,%hi(.LC0)	# tmp136,
# t2.c:4: int main() {
	addi	sp,sp,-16	#,,
# t2.c:16:     printf("Original: 0x%08X\n", number);
	addi	a1,a1,1656	#,,
	addi	a0,a0,%lo(.LC0)	#, tmp136,
# t2.c:4: int main() {
	sd	ra,8(sp)	#,
# t2.c:16:     printf("Original: 0x%08X\n", number);
	call	printf		#
# t2.c:17:     printf("Set bit %d: 0x%08X\n", bit_position, set_result);
	li	a2,305418240		#,
	lui	a0,%hi(.LC1)	# tmp138,
	addi	a2,a2,1656	#,,
	li	a1,5		#,
	addi	a0,a0,%lo(.LC1)	#, tmp138,
	call	printf		#
# t2.c:18:     printf("Clear bit %d: 0x%08X\n", bit_position, clear_result);
	li	a2,305418240		#,
	lui	a0,%hi(.LC2)	# tmp140,
	addi	a2,a2,1624	#,,
	li	a1,5		#,
	addi	a0,a0,%lo(.LC2)	#, tmp140,
	call	printf		#
# t2.c:19:     printf("Toggle bit %d: 0x%08X\n", bit_position, toggle_result);
	li	a2,305418240		#,
	lui	a0,%hi(.LC3)	# tmp142,
	addi	a2,a2,1624	#,,
	li	a1,5		#,
	addi	a0,a0,%lo(.LC3)	#, tmp142,
	call	printf		#
# t2.c:20:     printf("Bit %d is: %d\n", bit_position, check_result);
	lui	a0,%hi(.LC4)	# tmp143,
	li	a2,1		#,
	li	a1,5		#,
	addi	a0,a0,%lo(.LC4)	#, tmp143,
	call	printf		#
# t2.c:23: }
	ld	ra,8(sp)		#,
	li	a0,0		#,
	addi	sp,sp,16	#,,
	jr	ra		#
	.size	main, .-main
	.ident	"GCC: () 13.2.0"
