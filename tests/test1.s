! copyright (c) fenugrec 2018
!
! Various pathological code patterns to test nislib sh_track_reg etc.

	.section	.text.test1,"ax",@progbits

	.global	test_main
	.type	test_main, @function

.BALIGN 2

test_main:
! initial garbage to simulate non-code stuff. IVT, data, etc.
	.word 0
	.word 0xCACA
	.word 0xFFFF
	.word 0x7FFC
	nop
	nop
eloop0:
	bra	eloop0
	nop
eloop1:
	bt	eloop1
	bt/s	eloop1
	nop
	jsr	@r0
	nop
	bsr	eloop1
	nop
	bsr	test_6001
	nop
	rts
	nop

.BALIGN 4

test_6001:
! clobber @(R0,Rn) dest var
	mov.w	u16var, r6
	mov	#1, r0
	mov.b	@(r0, r6), r0
	nop
	nop

test_6002:
!logic.b ##, @(r0, gbr)
!2 hits
	mov.w	u16var, r0
	ldc	r0, gbr
	mov	#2, r0
	and.b #0x55, @(r0, gbr)
	ldc	r0, gbr	!swap gbr and r0 roles
	mov.w	u16var, r0
	and.b #0x55, @(r0, gbr)
	nop
	nop

test_6003:
!basic addr modes :
!	Rm, @Rn
!	Rm, @(disp,Rn)
!	Rm, @(R0, Rn)
!	R0, @(disp, gbr)
!8 hits
	mov.w	u16var, r0
	mov.w	test_6003_data, r1
	bra	test_6003_b
	nop
test_6003_data:
	.word	0x6003
test_6003_b:
	mov	#3, r2
	mov.b	@r1, r5
	mov.b	r5, @r1
	mov.b	r0, @(3, r0)
	mov.b	@(3, r0), r0
	mov.w	u16var, r0
	mov.b	r5, @(r0, r2)
	mov.b	@(r0, r2), r5
	ldc	r0, gbr
	mov.b	r0, @(3, gbr)
	mov.b	@(3, gbr), r0
	nop
	nop


test_6004:
!add imm, Rn before access
	mov.w	u16var, r0
	add	#4, r0
	mov.b	@r0, r1
	nop
	nop


test_6005:
!stc gbr + add imm
	mov.w	u16var, r0
	ldc	r0, gbr
	stc	gbr, r2
	add	#5, r2
	mov	#0, r0
	mov.b	@(r0, r2), r3
	nop
	nop

test_6006:
!second copy in "post-visited" opcode
!(i.e. r11 is never tracked)
	mov.w	u16var, r0
	mov	r0, r1
	mov r0, r11
	mov	#6, r2
	add	r2, r1
	mov.b	@(6, r11), r0
	nop
	nop

test_6007:
!reg addition before @Rm, Rn
	mov.w	u16var, r1
	mov	#7, r2
	add	r2, r1
	mov.b	@r1, r5
	nop
	nop

test_6008:
!imm add before @Rm, Rn
	mov.w	u16var, r0
	add	#8, r0
	mov.b	@r0, r5
	nop
	nop


test_6009:
!recursive death by cross-jump
	mov.w	u16var, r0
	bt	test_6009_a
	nop
test_6009_a:
	bt	test_6009_b
	nop
test_6009_b:
	bt	test_6009_a
	mov.b	r0, @(9, r0)
	nop
	nop


test_600a:
!access in delay slot
!4 hits
	mov.w	u16var, r0
	bt/s	test_600a_b
	mov.b	r0, @(0x0a, r0)
	nop
test_600a_b:
	jsr	@r4
	mov.b	r0, @(0x0a, r0)
	nop
	bra	test_600a_c
	mov.b	r0, @(0x0a, r0)
test_600a_c:
	rts
	mov.b	r0, @(0x0a, r0)
	nop
	nop


test_footer:
!just for ida analysis
	rts
	nop

.BALIGN 4
u16var:
	.word 0x6000
s16var:
	.word 0xa000
