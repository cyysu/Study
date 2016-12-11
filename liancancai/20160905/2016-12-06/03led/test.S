
#define  GPM4CON   0x110002E0

.global _start
_start:
	stmfd sp! , {r0-r12  , lr}
	
	@1.配置

	bl	led_configure

	loop:

	bl	led_on
	bl	delay
	bl	led_off
	bl	delay

	b	loop

	ldmfd sp! , {r0-r12 , pc}

.global delay
delay:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x7FFFFFF

	delay_loop:
	sub	r0 , #1
	cmp	r0 , #0
	bne	delay_loop

	ldmfd sp! , {r0-r12 , pc}

.global led_on
led_on:
	stmfd sp! , {r0-r12 , lr}
	
	@1.read
	ldr	r0 , =GPM4CON
	ldr	r1 , [r0 , #4]
	@2.clear
	bic	r1 , r1 , #0xF
	@3.write
	str	r1 , [r0 , #4]

	ldmfd sp! , {r0-r12 , pc}

.global led_off
led_off:
	stmfd sp! , {r0-r12 , lr}
	
	@1.read
	ldr	r0 , =GPM4CON
	ldr	r1 , [r0 , #4]
	@2.clear
	orr r1 , r1 , #0xF
	@3.write
	str	r1 , [r0 , #4]
	
	ldmfd sp! , {r0-r12 , pc}

.global led_configure
led_configure:
	stmfd sp! , {r0-r12 , lr}
	
	@1.configure as output pin

	ldr	r0 , =GPM4CON
	@read
	ldr	r1 , [r0]
	@bic
	ldr	r2 , =0xFFFF
	bic	r1 , r1 , r2
	ldr	r2 , =0x1111
	orr	r1 , r1 , r2
	@write
	str	r1 , [r0]

	@2.set default mode
	bl	led_off

	ldmfd sp! , {r0-r12 , pc}

