
#define  GPM4CON   0x110002E0
#define  GPD0CON   0x114000A0
#define  GPX3CON   0x11000C60
#define  PRINT     0xc3e11ad0

.global _start
_start:
	stmfd sp! , {r0-r12  , lr}
	
	bl	key_configure
	bl	led_configure
	bl	buzzer_configure

	


	loop_ever:

		bl	led_off
		bl	buzzer_off

		loop:
		
		bl	key_status
		cmp	r0 , #0xF
		beq	loop

		ldr	r0 , =Str	
		ldr	r1 , =PRINT
		mov	lr , pc
		mov	pc , r1

		bl	led_on
		bl	buzzer_on

		bl	delay

	b	loop_ever


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

.global buzzer_on
buzzer_on:
	stmfd sp! , {r0-r12 , lr}
	
	ldr	r0 , =GPD0CON
	ldr	r1 , [r0 , #4]
	orr	r1 , r1 , #0x1
	str	r1 , [r0 , #4]

	ldmfd sp! , {r0-r12 , pc}

.global buzzer_off
buzzer_off:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =GPD0CON
	ldr	r1 , [r0 , #4]
	bic	r1 , r1 , #0x1
	str	r1 , [r0 , #4]

	ldmfd sp! , {r0-r12 , pc}


.global buzzer_configure
buzzer_configure:

	stmfd sp! , {r0-r12 , lr}
	
	@1.read
	ldr	r0 , =GPD0CON
	ldr	r1 , [r0]
	bic	r1 , r1 , #0xF
	orr	r1 , r1 , #0x1
	str	r1 , [r0]

	bl	buzzer_off

	ldmfd sp! , {r0-r12 , pc}

.global key_configure
key_configure:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =GPX3CON
	ldr	r1 , [r0]

	ldr	r2 , =(0xFFFF<<8)
	bic	r1 , r1 , r2

	str	r1 , [r0]

	ldmfd sp! , {r0-r12 , pc}


.global	key_status
key_status:
	stmfd sp! , {r1-r12 , lr}
	
	ldr	r0 , =GPX3CON
	ldr	r1 , [r0 , #4]
	
	lsr	r1 , r1 , #2
	and	r1 , r1 , #0xF
	
	mov	r0 , r1

	ldmfd sp! , {r1-r12 , pc}


Str:
	.string "someone press ... \n"
	.align  2

