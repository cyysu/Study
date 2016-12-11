
.global _start
_start:
	stmfd sp! , {r0-r12  , lr}

	nop  @ mov  r0 , r0

	ldmfd sp! , {r0-r12 , pc}
