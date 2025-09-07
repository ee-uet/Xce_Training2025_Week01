	.file	"Task3_C.c"
	.text
	.globl	dividend
	.data
	.align 4
	.type	dividend, @object
	.size	dividend, 4
dividend:
	.long	123456789
	.globl	divisor
	.align 4
	.type	divisor, @object
	.size	divisor, 4
divisor:
	.long	12345
	.globl	quotient
	.bss
	.align 4
	.type	quotient, @object
	.size	quotient, 4
quotient:
	.zero	4
	.globl	remainde_r
	.align 4
	.type	remainde_r, @object
	.size	remainde_r, 4
remainde_r:
	.zero	4
	.text
	.globl	non_restoring_div32
	.type	non_restoring_div32, @function
non_restoring_div32:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -8(%rbp)
	movl	$31, -4(%rbp)
	jmp	.L2
.L5:
	movl	-8(%rbp), %eax
	leal	(%rax,%rax), %esi
	movl	-4(%rbp), %eax
	movl	-20(%rbp), %edx
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	orl	%esi, %eax
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	js	.L3
	movl	-8(%rbp), %eax
	subl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	addl	%eax, %eax
	orl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	.L4
.L3:
	movl	-8(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	sall	-12(%rbp)
.L4:
	subl	$1, -4(%rbp)
.L2:
	cmpl	$0, -4(%rbp)
	jns	.L5
	cmpl	$0, -8(%rbp)
	jns	.L6
	movl	-8(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
.L6:
	movq	-32(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movl	-8(%rbp), %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	non_restoring_div32, .-non_restoring_div32
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	divisor(%rip), %esi
	movl	dividend(%rip), %eax
	leaq	remainde_r(%rip), %rdx
	movq	%rdx, %rcx
	leaq	quotient(%rip), %rdx
	movl	%eax, %edi
	call	non_restoring_div32
.L8:
	nop
	jmp	.L8
	.cfi_endproc
.LFE1:
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
