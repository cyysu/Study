
.global _start
_start:
	stmfd sp! , {r0-r12  , lr}

	ldr	r0 , =Str
	ldr	r1 , =0xc3e11ad0
	
	mov	lr , pc
	mov	pc , r1


	ldmfd sp! , {r0-r12 , pc}



Str:
	.string  "hello u-boot .... \n"
	.align   2
