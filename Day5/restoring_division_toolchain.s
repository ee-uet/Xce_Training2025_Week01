(base) aleeza@aleeza-ThinkPad-X1-Carbon-5th:~/riscv-isa-sim/build$ gcc -S restoring_division.c -o restoring_division.s
(base) aleeza@aleeza-ThinkPad-X1-Carbon-5th:~/riscv-isa-sim/build$ 
	.file	"restoring_division.c"
	.text
	.section	.rodata
.LC0:
	.string	"Dividend = %d, Divisor = %d\n"
	.align 8
.LC1:
	.string	"Quotient = %d, Remainder = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$13, -12(%rbp)
	movl	$3, -8(%rbp)
	movl	$4, -4(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	.L2
.L5:
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %esi
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %edx
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	orl	%esi, %eax
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %eax
	subl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jns	.L3
	movl	-8(%rbp), %eax
	addl	%eax, -20(%rbp)
	sall	-24(%rbp)
	jmp	.L4
.L3:
	movl	-24(%rbp), %eax
	addl	%eax, %eax
	orl	$1, %eax
	movl	%eax, -24(%rbp)
.L4:
	subl	$1, -16(%rbp)
.L2:
	cmpl	$0, -16(%rbp)
	jns	.L5
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
