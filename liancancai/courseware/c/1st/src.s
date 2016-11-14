	.file	"src.c"
	.section	.rodata
.LC0:
	.string	"a = %d\n"
.LC2:
	.string	"PI = %f\n"
.LC3:
	.string	"this is a c program!"
	.align 8
.LC1:
	.long	1374389535
	.long	1074339512
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	$10, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	fldl	.LC1
	fstpl	4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, %eax
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
