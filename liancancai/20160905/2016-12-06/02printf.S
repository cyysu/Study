

.global main
main:
	
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =Str
	
	ldr	r1 , =11
	ldr	r2 , =TXT
	ldr	r3 , =33

	ldr	r5 , =55 
	push {r5}
	ldr	r4 , =44
	push {r4}
	@注释
	@APCS规定   r0-r3是非保护区域
	@传参r4以后要反向压栈

	bl	printf

	pop	{r4}
	pop	{r5}

	push {r5}
	push {r4}
	ldr	r0 , =Str
	bl	printf
	pop	{r4}
	pop	{r5}

	ldmfd sp! , {r0-r12 , pc}

Str:
	.string "hello world %d %s %d %d %d\n"
	.align   2 

TXT:
	.string "kitty"
	.align   2
